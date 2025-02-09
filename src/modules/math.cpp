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
 * \file math.cpp
 * \brief Math module.
 * \sa math.hpp
 */

#include "../../include/wizard_engine/modules/math.hpp"

#include <SDL3/SDL_stdinc.h>

#include <array>
#include <cstdint>

namespace wizard_engine::modules {
auto math::get() -> math& {
  static math INSTANCE{};
  return INSTANCE;
}

void math::set_mt19937_64_seed(std::uint_fast64_t seed) {
  _mt19937_64.seed(seed);
}

auto math::magnitude_2d(const std::array<float, 2>& vector) noexcept -> float {
  return SDL_sqrtf(SDL_powf(vector[0], 2) + SDL_powf(vector[1], 2));
}

auto math::magnitude_3d(const std::array<float, 3>& vector) noexcept -> float {
  return SDL_sqrtf(SDL_powf(vector[0], 2) + SDL_powf(vector[1], 2) +
                   SDL_powf(vector[2], 2));
}

auto math::angle_2d(const std::array<float, 2>& vector) noexcept -> float {
  if (static_cast<bool>(vector[0]) || static_cast<bool>(vector[1])) {
    return SDL_atan2f(vector[1], vector[0]);
  }
  return 0;
}

auto math::angle_3d(const std::array<float, 3>& vector) noexcept
    -> std::array<float, 2> {
  const auto magnitude{magnitude_3d(vector)};
  if (static_cast<bool>(magnitude)) {
    return {angle_2d({vector[0], vector[1]}), SDL_acosf(vector[2] / magnitude)};
  }
  return {0, 0};
}

auto math::normalize_2d(const std::array<float, 2>& vector) noexcept
    -> std::array<float, 2> {
  const auto magnitude{magnitude_2d(vector)};
  if (static_cast<bool>(magnitude)) {
    return {vector[0] / magnitude, vector[1] / magnitude};
  }
  return {0, 0};
}

auto math::normalize_3d(const std::array<float, 3>& vector) noexcept
    -> std::array<float, 3> {
  const auto magnitude{magnitude_3d(vector)};
  if (static_cast<bool>(magnitude)) {
    return {vector[0] / magnitude, vector[1] / magnitude,
            vector[2] / magnitude};
  }
  return {0, 0, 0};
}

auto math::resolve_x_2d(float magnitude, float angle) noexcept -> float {
  return magnitude * SDL_cosf(angle);
}

auto math::resolve_y_2d(float magnitude, float angle) noexcept -> float {
  return magnitude * SDL_sinf(angle);
}

auto math::resolve_x_3d(float magnitude,
                        const std::array<float, 2>& angle) noexcept -> float {
  return magnitude * SDL_sinf(angle[1]) * SDL_cosf(angle[0]);
}

auto math::resolve_y_3d(float magnitude,
                        const std::array<float, 2>& angle) noexcept -> float {
  return magnitude * SDL_sinf(angle[1]) * SDL_sinf(angle[0]);
}

auto math::resolve_z_3d(float magnitude,
                        const std::array<float, 2>& angle) noexcept -> float {
  return magnitude * SDL_cosf(angle[1]);
}

auto math::transformation_matrix_2d(float angle, float scale) noexcept
    -> std::array<float, 4> {
  const auto cosine_scale{SDL_cosf(angle) * scale};
  const auto sine_scale{SDL_sinf(angle) * scale};
  return {cosine_scale, -sine_scale, sine_scale, cosine_scale};
}

auto math::transformation_matrix_3d(const std::array<float, 2>& angle,
                                    float scale) noexcept
    -> std::array<float, 9> {
  const auto cosine_theta{SDL_cosf(angle[0])};
  const auto sine_theta{SDL_sinf(angle[0])};
  const auto cosine_phi{SDL_cosf(angle[1])};
  const auto sine_phi{SDL_sinf(angle[1])};
  return {sine_phi * cosine_theta * scale,
          sine_phi * sine_theta * scale,
          cosine_phi * scale,
          cosine_phi * cosine_theta * scale,
          cosine_phi * sine_theta * scale,
          -sine_phi * scale,
          -sine_theta * scale,
          cosine_theta * scale,
          0};
}

math::math() = default;
}  // namespace wizard_engine::modules
