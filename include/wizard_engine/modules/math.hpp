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
 * \file math.hpp
 * \brief Math module.
 * \sa math.cpp
 */

#ifndef WIZARD_ENGINE_MODULES_MATH_HPP
#define WIZARD_ENGINE_MODULES_MATH_HPP

#include <array>
#include <limits>
#include <numbers>
#include <random>
#include <type_traits>

/**
 * \brief Modules of Wizard Engine.
 */
namespace wizard_engine::modules {
/**
 * \brief Math module.
 */
class math final {
 public:
  /**
   * \brief Deleted explicit constructor.
   */
  explicit math() = delete;

  /**
   * \brief Gets the single precision epsilon value used by the engine.
   * \return Single precision epsilon value used by the engine.
   */
  [[nodiscard]] static consteval auto epsilon() noexcept { return .01F; }

  /**
   * \brief Converts degrees to radians.
   * \param degrees Angle in degrees.
   * \return Angle in radians.
   * \sa to_degrees(float radians)
   */
  [[nodiscard]] static constexpr auto to_radians(float degrees) noexcept {
    return degrees * std::numbers::pi_v<decltype(degrees)> / 180;
  }

  /**
   * \brief Converts radians to degrees.
   * \param radians Angle in radians.
   * \return Angle in degrees.
   * \sa to_radians(float degrees)
   */
  [[nodiscard]] static constexpr auto to_degrees(float radians) noexcept {
    return radians * 180 / std::numbers::pi_v<decltype(radians)>;
  }

  /**
   * \brief Calculates the magnitude of a 2D vector.
   * \param vector 2D vector (X, Y).
   * \return Calculated magnitude of the 2D vector.
   * \sa magnitude_3d(const std::array<float, 3>& vector)
   */
  [[nodiscard]] static auto magnitude_2d(
      const std::array<float, 2>& vector) noexcept -> float;

  /**
   * \brief Calculates the magnitude of a 3D vector.
   * \param vector 3D vector (X, Y, Z).
   * \return Calculated magnitude of the 3D vector.
   * \sa magnitude_2d(const std::array<float, 2>& vector)
   */
  [[nodiscard]] static auto magnitude_3d(
      const std::array<float, 3>& vector) noexcept -> float;

  /**
   * \brief Calculates the angle of a 2D vector (Theta).
   * \param vector 2D vector (X, Y).
   * \return Calculated angle of the 2D vector (Theta).
   * \sa angle_3d(const std::array<float, 3>& vector)
   */
  [[nodiscard]] static auto angle_2d(
      const std::array<float, 2>& vector) noexcept -> float;

  /**
   * \brief Calculates the angles of a 3D vector (Theta, Phi).
   * \param vector 3D vector (X, Y, Z).
   * \return Calculated angles of the 3D vector (Theta, Phi).
   * \sa angle_2d(const std::array<float, 2>& vector)
   */
  [[nodiscard]] static auto angle_3d(
      const std::array<float, 3>& vector) noexcept -> std::array<float, 2>;

  /**
   * \brief Normalizes a 2D vector (X, Y).
   * \param vector 2D vector (X, Y).
   * \return Normalized 2D vector (X, Y).
   * \sa normalize_3d(const std::array<float, 3>& vector)
   */
  [[nodiscard]] static auto normalize_2d(
      const std::array<float, 2>& vector) noexcept -> std::array<float, 2>;

  /**
   * \brief Normalizes a 3D vector (X, Y, Z).
   * \param vector 3D vector. (X, Y, Z)
   * \return Normalized 3D vector. (X, Y, Z)
   * \sa normalize_2d(const std::array<float, 2>& vector)
   */
  [[nodiscard]] static auto normalize_3d(
      const std::array<float, 3>& vector) noexcept -> std::array<float, 3>;

  /**
   * \brief Resolves the x component of a 2D vector (X, Y).
   * \param magnitude Magnitude of the resolution.
   * \param angle Angle of the resolution (Theta).
   * \return Resolved x component of the 2D vector (X, Y).
   * \sa resolve_y_2d(float magnitude, float angle)
   */
  [[nodiscard]] static auto resolve_x_2d(float magnitude, float angle) noexcept
      -> float;

  /**
   * \brief Resolves the y component of a 2D vector (X, Y).
   * \param magnitude Magnitude of the resolution.
   * \param angle Angle of the resolution (Theta).
   * \return Resolved y component of the 2D vector (X, Y).
   * \sa resolve_x_2d(float magnitude, float angle)
   */
  [[nodiscard]] static auto resolve_y_2d(float magnitude, float angle) noexcept
      -> float;

  /**
   * \brief Resolves the x component of a 3D vector (X, Y, Z).
   * \param magnitude Magnitude of the resolution.
   * \param angles Angles of the resolution (Theta, Phi).
   * \return Resolved x component of the 3D vector (X, Y, Z).
   * \sa resolve_y_3d(float magnitude, const std::array<float, 2>& angles)
   * \sa resolve_z_3d(float magnitude, const std::array<float, 2>& angles)
   */
  [[nodiscard]] static auto resolve_x_3d(
      float magnitude,
      const std::array<float, 2>& angles) noexcept -> float;

  /**
   * \brief Resolves the y component of a 3D vector (X, Y, Z).
   * \param magnitude Magnitude of the resolution.
   * \param angles Angles of the resolution (Theta, Phi).
   * \return Resolved y component of the 3D vector (X, Y, Z).
   * \sa resolve_x_3d(float magnitude, const std::array<float, 2>& angles)
   * \sa resolve_z_3d(float magnitude, const std::array<float, 2>& angles)
   */
  [[nodiscard]] static auto resolve_y_3d(
      float magnitude,
      const std::array<float, 2>& angles) noexcept -> float;

  /**
   * \brief Resolves the z component of a 3D vector (X, Y, Z).
   * \param magnitude Magnitude of the resolution.
   * \param angles Angles of the resolution (Theta, Phi).
   * \return Resolved z component of the 3D vector (X, Y, Z).
   * \sa resolve_x_3d(float magnitude, const std::array<float, 2>& angles)
   * \sa resolve_y_3d(float magnitude, const std::array<float, 2>& angles)
   */
  [[nodiscard]] static auto resolve_z_3d(
      float magnitude,
      const std::array<float, 2>& angles) noexcept -> float;

  /**
   * \brief Creates a 2D transformation matrix (2x2).
   * \param angle Angle of the 2D transformation matrix (Theta).
   * \param scale Scale of the 2D transformation matrix.
   * \return Created 2D transformation matrix (2x2).
   * \sa transform_x_2d(const std::array<float, 2>& vector, const
   * std::array<float, 4>& transformation_matrix)
   * \sa transform_y_2d(const std::array<float, 2>& vector, const
   * std::array<float, 4>& transformation_matrix)
   */
  [[nodiscard]] static auto transformation_matrix_2d(float angle,
                                                     float scale) noexcept
      -> std::array<float, 4>;

  /**
   * \brief Transforms the x component of a 2D vector (X, Y).
   * \param vector 2D vector (X, Y).
   * \param transformation_matrix 2D transformation matrix (2x2).
   * \return Transformed x component of the 2D vector (X, Y).
   * \sa transformation_matrix_2d(float angle, float scale)
   * \sa transform_y_2d(const std::array<float, 2>& vector, const
   * std::array<float, 4>& transformation_matrix)
   */
  [[nodiscard]] static constexpr auto transform_x_2d(
      const std::array<float, 2>& vector,
      const std::array<float, 4>& transformation_matrix) noexcept {
    return (vector[0] * transformation_matrix[0]) +
           (vector[1] * transformation_matrix[1]);
  }

  /**
   * \brief Transforms the y component of a 2D vector (X, Y).
   * \param vector 2D vector (X, Y).
   * \param transformation_matrix 2D transformation matrix (2x2).
   * \return Transformed y component of the 2D vector (X, Y).
   * \sa transformation_matrix_2d(float angle, float scale)
   * \sa transform_x_2d(const std::array<float, 2>& vector, const
   * std::array<float, 4>& transformation_matrix)
   */
  [[nodiscard]] static constexpr auto transform_y_2d(
      const std::array<float, 2>& vector,
      const std::array<float, 4>& transformation_matrix) noexcept {
    return (vector[0] * transformation_matrix[2]) +
           (vector[1] * transformation_matrix[3]);
  }

  /**
   * \brief Creates a 3D transformation matrix (3x3).
   * \param angles Angles of the 3D transformation matrix (Theta, Phi).
   * \param scale Scale of the 3D transformation matrix.
   * \return Created 3D transformation matrix (3x3).
   * \sa transform_x_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   * \sa transform_y_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   * \sa transform_z_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   */
  [[nodiscard]] static auto transformation_matrix_3d(
      const std::array<float, 2>& angles,
      float scale) noexcept -> std::array<float, 9>;

  /**
   * \brief Transforms the x component of a 3D vector (X, Y, Z).
   * \param vector 3D vector (X, Y, Z).
   * \param transformation_matrix 3D transformation matrix (3x3).
   * \return Transformed x component of the 3D vector (X, Y, Z).
   * \sa transformation_matrix_3d(const std::array<float, 2>& angles, float
   * scale)
   * \sa transform_y_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   * \sa transform_z_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   */
  [[nodiscard]] static constexpr auto transform_x_3d(
      const std::array<float, 3>& vector,
      const std::array<float, 9>& transformation_matrix) noexcept {
    return (vector[0] * transformation_matrix[0]) +
           (vector[1] * transformation_matrix[1]) +
           (vector[2] * transformation_matrix[2]);
  }

  /**
   * \brief Transforms the y component of a 3D vector (X, Y, Z).
   * \param vector 3D vector (X, Y, Z).
   * \param transformation_matrix 3D transformation matrix (3x3).
   * \return Transformed y component of the 3D vector (X, Y, Z).
   * \sa transformation_matrix_3d(const std::array<float, 2>& angles, float
   * scale)
   * \sa transform_x_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   * \sa transform_z_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   */
  [[nodiscard]] static constexpr auto transform_y_3d(
      const std::array<float, 3>& vector,
      const std::array<float, 9>& transformation_matrix) noexcept {
    return (vector[0] * transformation_matrix[3]) +
           (vector[1] * transformation_matrix[4]) +
           (vector[2] * transformation_matrix[5]);
  }

  /**
   * \brief Transforms the z component of a 3D vector (X, Y, Z).
   * \param vector 3D vector (X, Y, Z).
   * \param transformation_matrix 3D transformation matrix (3x3).
   * \return Transformed z component of the 3D vector (X, Y, Z).
   * \sa transformation_matrix_3d(const std::array<float, 2>& angles, float
   * scale)
   * \sa transform_x_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   * \sa transform_y_3d(const std::array<float, 3>& vector, const
   * std::array<float, 9>& transformation_matrix)
   */
  [[nodiscard]] static constexpr auto transform_z_3d(
      const std::array<float, 3>& vector,
      const std::array<float, 9>& transformation_matrix) noexcept {
    return (vector[0] * transformation_matrix[6]) +
           (vector[1] * transformation_matrix[7]) +
           (vector[2] * transformation_matrix[8]);
  }

  /**
   * \brief Generates a random numeric value from an interval.
   * \tparam T Numeric type.
   * \param minimum Minimum inclusive value of the interval.
   * \param maximum Maximum inclusive value of the interval.
   * \return Generated numeric value.
   * \sa random(double probability)
   */
  template <typename T>
    requires(std::is_arithmetic_v<T> && !std::is_same_v<T, bool>)
  [[nodiscard]] static auto random(T minimum = std::numeric_limits<T>::lowest(),
                                   T maximum = std::numeric_limits<T>::max()) {
    if constexpr (std::is_integral_v<T>) {
      return std::uniform_int_distribution<T>{minimum, maximum}(_mt19937_64);
    } else if constexpr (std::is_floating_point_v<T>) {
      return std::uniform_real_distribution<T>{minimum, maximum}(_mt19937_64);
    }
  }

  /**
   * \brief Generates a random boolean value with a probability.
   * \tparam T Boolean type.
   * \param probability Probability of a true value.
   * \return Generated boolean value.
   * \sa random(T minimum, T maximum)
   */
  template <typename T>
    requires(std::is_same_v<T, bool>)
  [[nodiscard]] static auto random(
      double probability = std::numeric_limits<bool>::max() * .5) {
    return std::bernoulli_distribution{probability}(_mt19937_64);
  }

 private:
  static std::mt19937_64 _mt19937_64;
};
}  // namespace wizard_engine::modules

#endif  // WIZARD_ENGINE_MODULES_MATH_HPP
