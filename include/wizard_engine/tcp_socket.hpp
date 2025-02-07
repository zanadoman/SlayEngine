/*
  Wizard Engine
  Copyright (C) 2023-2024 Zana Domán

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

/**
 * @file tcp_socket.hpp
 * @brief TCP socket.
 * @sa net.hpp
 * @sa socket.hpp
 * @sa udp_socket.hpp
 */

#ifndef WIZARD_ENGINE_TCP_SOCKET_HPP
#define WIZARD_ENGINE_TCP_SOCKET_HPP

#include <wizard_engine/errors.hpp>
#include <wizard_engine/exception.hpp>
#include <wizard_engine/export.hpp>
#include <wizard_engine/net.hpp>

namespace wze {
/**
 * @brief TCP socket.
 * @tparam incoming Type of the incoming data.
 * @tparam outgoing Type of the outgoing data.
 * @sa net
 * @sa udp_socket
 * @sa tcp_socket
 */
class tcp_socket final {
  public:
    /**
     * @brief Explicit constructor.
     * @param ipv4 IPv4 address of the server.
     * @exception wze::exception tcp_socket cannot be opened.
     * @sa net::resolve(std::string const& hostname, uint16_t port = 0)
     */
    explicit tcp_socket(wze::ipv4 ipv4) {
        if (ipv4.host == INADDR_ANY || ipv4.host == INADDR_NONE) {
            throw exception<socket_error>{{"Invalid IPv4 address"}};
        }
        _socket_set = {SDLNet_AllocSocketSet(1), SDLNet_FreeSocketSet};
        if (!_socket_set) {
            throw exception<socket_error>{{SDLNet_GetError()}};
        }
        _socket = {SDLNet_TCP_Open(&ipv4), SDLNet_TCP_Close};
        if (!_socket) {
            throw exception<socket_error>{{SDLNet_GetError()}};
        }
        if (SDLNet_TCP_AddSocket(_socket_set.get(), _socket.get()) != 1) {
            throw exception<socket_error>{{SDLNet_GetError()}};
        }
    }

    /**
     * @brief Gets the wze::ipv4 address of the server.
     * @return wze::ipv4 address of the server.
     */
    [[nodiscard]] wze::ipv4 ipv4() const {
        return *SDLNet_TCP_GetPeerAddress(_socket.get());
    }

    /**
     * @brief Receives data from the server.
     * @param buffer Data buffer.
     * @return Integrity of the received data.
     * @retval true Received appropriate data.
     * @retval false Received invalid data.
     * @exception wze::exception Data cannot be received properly.
     * @sa send(outgoing const& buffer)
     */
    template <typename packet> void send(packet const& buffer) {
        static_assert(sizeof(buffer) <= std::numeric_limits<int32_t>::max());
        if (SDLNet_TCP_Send(_socket.get(), &buffer, sizeof(buffer)) !=
            sizeof(buffer)) {
            throw exception<socket_error>{{SDLNet_GetError()}};
        }
    }

    /**
     * @brief Sends data to the server.
     * @param buffer Data buffer.
     * @exception wze::exception Data cannot be sent properly.
     * @sa receive(incoming& buffer)
     */
    template <typename packet> [[nodiscard]] int32_t receive(packet& buffer) {
        static_assert(sizeof(buffer) <= std::numeric_limits<int32_t>::max());
        if (!static_cast<bool>(SDLNet_CheckSockets(_socket_set.get(), 0)) ||
            // NOLINTNEXTLINE(cppcoreguidelines-pro-type-cstyle-cast)
            !static_cast<bool>(SDLNet_SocketReady(_socket.get()))) {
            return 0;
        }
        int32_t size{SDLNet_TCP_Recv(_socket.get(), &buffer, sizeof(buffer))};
        if (size <= 0) {
            throw exception<socket_error>{{SDLNet_GetError()}};
        }
        return size;
    }

  private:
    std::shared_ptr<_SDLNet_SocketSet> _socket_set;
    std::shared_ptr<_TCPsocket> _socket;
};
} /* namespace wze */

#endif /* WIZARD_ENGINE_TCP_SOCKET_HPP */
