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
   * Deleted copy constructor.
   */
  timer(const timer&) = delete;

  /**
   * Deleted move constructor.
   */
  timer(timer&&) = delete;

  /**
   * Deleted copy assignment operator.
   */
  auto operator=(const timer&) = delete;

  /**
   * Deleted move assignment operator.
   */
  auto operator=(timer&&) = delete;

  /**
   * \brief Gets the thread local singleton instance.
   * \return Thread local singleton instance.
   */
  [[nodiscard]] static auto get() noexcept -> timer&;

  /**
   * \brief Gets the time elapsed since the UNIX epoch (milliseconds).
   * \return Time elapsed since the UNIX epoch (milliseconds).
   */
  [[nodiscard]] static auto get_current_time() noexcept -> std::int64_t;

  /**
   * \brief Gets the target frame time of the current thread (milliseconds).
   * \return Target frame time of the current thread (milliseconds).
   * \sa set_frame_time(std::uint8_t frame_time)
   */
  [[nodiscard]] auto get_frame_time() const noexcept -> std::uint8_t;

  /**
   * \brief Sets the target frame time of the current thread (milliseconds).
   * \param frame_time Target frame time of the current thread (milliseconds).
   * \sa get_frame_time()
   */
  void set_frame_time(std::uint8_t frame_time) noexcept;

  /**
   * \brief Gets the current delta time of the current thread (milliseconds).
   * \return Current delta time of the current thread (milliseconds).
   * \sa set_delta_time(float delta_time)
   */
  [[nodiscard]] auto get_delta_time() const noexcept -> float;

  /**
   * \brief Sets the current delta time of the current thread (milliseconds).
   * \param delta_time Current delta time of the current thread (milliseconds).
   * \sa get_delta_time()
   */
  void set_delta_time(float delta_time) noexcept;

  /**
   * \brief Synchronizes the current thread and calculates the next delta time.
   */
  void synchronize() noexcept;

 private:
  std::uint8_t _frame_time{};
  float _delta_time{};
  std::int64_t _last_time{};

  /**
   * \brief Default constructor.
   */
  [[nodiscard]] consteval explicit timer() noexcept = default;

  /**
   * \brief Default destructor.
   */
  constexpr ~timer() noexcept = default;
};
}  // namespace wizard_engine::modules

#endif  // WIZARD_ENGINE_MODULES_TIMER_HPP
