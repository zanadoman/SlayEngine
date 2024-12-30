/*
  Wizard Engine
  Copyright (C) 2023-2025 Doman Zana

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

use std::{
  net::{IpAddr, Ipv4Addr, SocketAddr},
  sync::OnceLock,
};

use anyhow::{anyhow, Result};
use clap::Parser;
use tokio::{
  io::{split, AsyncReadExt, AsyncWriteExt, ReadHalf, WriteHalf},
  main,
  net::{TcpListener, TcpStream},
  select,
  signal::ctrl_c,
  spawn,
  sync::broadcast::{channel, Receiver, Sender},
  try_join,
};
use tracing::{error, info, instrument, level_filters::LevelFilter, Level};
use tracing_subscriber::{
  fmt::{format::FmtSpan, layer},
  layer::SubscriberExt,
  registry,
  util::SubscriberInitExt,
};

#[derive(Parser)]
#[command(version, about = "Simple TCP broadcast server for testing purposes")]
struct Args {
  /// IPv4 address of the server
  #[arg(short, long, default_value_t = Ipv4Addr::new(127, 0, 0, 1))]
  address: Ipv4Addr,
  /// Port to listen on
  #[arg(short, long, default_value_t = 3000)]
  port: u16,
  /// Maximum message size
  #[arg(long, default_value_t = 1024)]
  buffer_size: usize,
  /// Tracing level
  #[arg(long, default_value_t = Level::INFO)]
  log_level: Level,
}

impl Args {
  #[instrument(level = "trace")]
  fn once() -> &'static Args {
    static ARGS: OnceLock<Args> = OnceLock::new();
    ARGS.get_or_init(Args::parse)
  }
}

#[instrument(level = "debug", skip(reader, sender))]
async fn input_handler(
  address: SocketAddr,
  mut reader: ReadHalf<TcpStream>,
  sender: Sender<Vec<u8>>,
) -> Result<()> {
  let mut buffer = vec![0; Args::once().buffer_size];
  loop {
    let size = match reader.read(&mut buffer).await {
      Ok(0) => return Err(anyhow!("{address} disconnected")),
      Ok(size) => size,
      Err(error) => return Err(error.into()),
    };
    let message = buffer[..size].to_vec();
    info!("{address}: {}", String::from_utf8_lossy(&message));
    sender.send(message)?;
  }
}

#[instrument(level = "debug", skip(writer, receiver))]
async fn output_handler(
  mut writer: WriteHalf<TcpStream>,
  mut receiver: Receiver<Vec<u8>>,
) -> Result<()> {
  loop {
    writer.write_all(&receiver.recv().await?).await?
  }
}

#[instrument(level = "debug", skip(listener, sender))]
async fn connection_handler(
  listener: TcpListener,
  sender: Sender<Vec<u8>>,
) -> Result<()> {
  loop {
    let (socket, address) = listener.accept().await?;
    let (reader, writer) = split(socket);
    let sender = sender.clone();
    let receiver = sender.subscribe();
    spawn(async move {
      info!("{address} connected");
      if let Err(error) = try_join!(
        input_handler(address, reader, sender),
        output_handler(writer, receiver)
      ) {
        error!("{error}")
      }
    });
  }
}

#[main]
async fn main() -> Result<()> {
  registry()
    .with(LevelFilter::from(Args::once().log_level))
    .with(layer().with_span_events(FmtSpan::NEW | FmtSpan::CLOSE))
    .init();
  let listener = TcpListener::bind(SocketAddr::new(
    IpAddr::V4(Args::once().address),
    Args::once().port,
  ))
  .await?;
  let channel = channel(u8::MAX.into()).0;
  info!("listening on {}", listener.local_addr()?);
  select! {
    result = connection_handler(listener, channel) => result,
    result = ctrl_c() => Ok(result?)
  }
  .map_err(|error| {
    error!("{error}");
    error
  })
}
