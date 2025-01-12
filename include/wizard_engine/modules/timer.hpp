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
 * \file timer.hpp
 * \brief Timer module.
 * \sa timer.cpp
 */

#ifndef WIZARD_ENGINE_MODULES_TIMER_HPP
#define WIZARD_ENGINE_MODULES_TIMER_HPP

#include <cstdint>

/**
 * \brief Modules of Wizard Engine.
 */
namespace wizard_engine::modules {
/**
 * \brief Timer module.
 */
class timer final {
 public:
  /**
   * \brief Deleted explicit constructor.
   */
  explicit timer() = delete;

  /**
   * \brief Gets the target frame time (milliseconds).
   * \details This value can be used to adjust the frame rate of the game (FPS).
   * \return Target frame time (milliseconds).
   * \sa set_frame_time(std::uint8_t frame_time)
   */
  [[nodiscard]] static auto get_frame_time() noexcept -> std::uint8_t;

  /**
   * \brief Sets the target frame time (milliseconds).
   * \details This value can be used to adjust the frame rate of the game (FPS).
   * \param frame_time Target frame time (milliseconds).
   * \sa get_frame_time()
   */
  static void set_frame_time(std::uint8_t frame_time) noexcept;

  /**
   * \brief Gets the current delta time (milliseconds).
   * \details This value can be used to adjust the pace of the game.
   * \return Current delta time (milliseconds).
   * \sa set_delta_time(float delta_time)
   */
  [[nodiscard]] static auto get_delta_time() noexcept -> float;

  /**
   * \brief Sets the current delta time (milliseconds).
   * \details This value can be used to adjust the pace of the game.
   * \param delta_time Current delta time (milliseconds).
   * \sa get_delta_time()
   */
  static void set_delta_time(float delta_time) noexcept;

  /**
   * \brief Gets the current game time (milliseconds).
   * \details Elapsed time since the engine initialized (milliseconds).
   * \return Current game time (milliseconds).
   */
  [[nodiscard]] static auto get_current_time() noexcept -> std::uint64_t;

  /**
   * \brief Synchronizes the current frame and calculates the next delta time.
   * \note This function needed to be handled manually within the game loop.
   */
  static void synchronize() noexcept;

 private:
  static std::uint8_t _frame_time;
  static float _delta_time;
  static std::uint64_t _last_time;
};
}  // namespace wizard_engine::modules

#endif  // WIZARD_ENGINE_MODULES_TIMER_HPP
