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

/**
 * \file timer.cpp
 * \brief Timer module.
 * \sa timer.hpp
 */

#include "../../include/wizard_engine/modules/timer.hpp"

#include <SDL3/SDL_timer.h>

#include <cstdint>

namespace wizard_engine::modules {
auto timer::get_frame_time() noexcept -> std::uint8_t {
  return _frame_time;
}

void timer::set_frame_time(std::uint8_t frame_time) noexcept {
  _frame_time = frame_time;
}

auto timer::get_delta_time() noexcept -> float {
  return _delta_time;
}

void timer::set_delta_time(float delta_time) noexcept {
  _delta_time = delta_time;
}

auto timer::get_current_time() noexcept -> std::uint64_t {
  return SDL_GetTicks();
}

void timer::synchronize() noexcept {
  const auto end{_last_time + get_frame_time()};
  auto now{get_current_time()};
  if (now < end) {
    SDL_Delay(static_cast<std::uint32_t>(end - now));
    now = end;
  }
  set_delta_time(static_cast<float>(now - _last_time));
  _last_time = now;
}

std::uint8_t timer::_frame_time{};
float timer::_delta_time{};
std::uint64_t timer::_last_time{};
}  // namespace wizard_engine::modules
