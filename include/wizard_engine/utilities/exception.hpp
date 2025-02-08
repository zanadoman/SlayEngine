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
 * \file exception.hpp
 * \brief Exception.
 * \sa exception.cpp
 * \sa errors.hpp
 */

#ifndef WIZARD_ENGINE_UTILITIES_EXCEPTION_HPP
#define WIZARD_ENGINE_UTILITIES_EXCEPTION_HPP

#include <SDL3/SDL_error.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_messagebox.h>

#include <cstdlib>
#include <exception>
#include <string>

/**
 * \brief Utilities of Wizard Engine.
 */
namespace wizard_engine::utilities {
/**
 * \brief Generic exception.
 * \tparam ERROR Error struct.
 * \sa errors.hpp
 */
template <typename ERROR>
class exception final : public std::exception {
 public:
  /**
   * \brief Explicit constructor.
   * \param what Explanatory string.
   */
  [[nodiscard]] explicit exception(const char* what) : _what{what} {
    std::set_terminate([]() noexcept {
      std::exception_ptr exception_ptr{std::current_exception()};
      const char* message{};
      if (exception_ptr) {
        try {
          std::rethrow_exception(exception_ptr);
        } catch (const std::exception& exception) {
          message = exception.what();
        } catch (...) {
          message = "Unknown exception";
        }
      } else {
        message = "Unknown error";
      }
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg,hicpp-vararg)
      SDL_Log("%s\n", message);
      if (!SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Wizard Engine",
                                    message, nullptr)) {
        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg,hicpp-vararg)
        SDL_Log("%s\n", SDL_GetError());
      }
      std::abort();
    });
  }

  /**
   * \brief Deleted copy constructor.
   */
  exception(const exception&) = delete;

  /**
   * \brief Deleted move constructor.
   */
  exception(exception&&) = delete;

  /**
   * \brief Default destructor.
   */
  ~exception() noexcept final = default;

  /**
   * \brief Deleted copy assignment operator.
   */
  auto operator=(const exception&) = delete;

  /**
   * \brief Deleted move assignment operator.
   */
  auto operator=(exception&&) = delete;

  /**
   * \brief Gets the explanatory string.
   * \return Explanatory string.
   */
  [[nodiscard]] auto what() const noexcept -> const char* final {
    return _what.c_str();
  }

 private:
  std::string _what;
};
}  // namespace wizard_engine::utilities

#endif  // WIZARD_ENGINE_UTILITIES_EXCEPTION_HPP
