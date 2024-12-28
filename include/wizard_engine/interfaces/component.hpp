/*
  Wizard Engine
  Copyright (C) 2023-2025 Zana Domán

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
 * \file component.hpp
 * \brief Component interface.
 * \sa entity.hpp
 */

#ifndef WIZARD_ENGINE_INTERFACES_COMPONENT_HPP
#define WIZARD_ENGINE_INTERFACES_COMPONENT_HPP

/**
 * \brief Interfaces of Wizard Engine.
 */
namespace wizard_engine::interfaces {
/**
 * \brief Components can be attached to entities.
 * \sa entity
 */
class component {
 public:
  /**
   * \brief Deleted explicit copy constructor.
   */
  explicit component(const component&) = delete;

  /**
   * \brief Deleted explicit move constructor.
   */
  explicit component(component&&) = delete;

  /**
   * \brief Default virtual destructor.
   */
  virtual ~component() = default;

  /**
   * \brief Deleted copy assignment operator.
   */
  auto operator=(const component&) = delete;

  /**
   * \brief Deleted move assignment operator.
   */
  auto operator=(component&&) = delete;

  /**
   * \brief Sets the X position absolute to the world.
   * \param x X position absolute to the world.
   */
  virtual void set_x(float x) = 0;

  /**
   * \brief Sets the Y position absolute to the world.
   * \param y Y position absolute to the world.
   */
  virtual void set_y(float y) = 0;

  /**
   * \brief Sets the Z position absolute to the world.
   * \param z Z position absolute to the world.
   */
  virtual void set_z(float z) = 0;

  /**
   * \brief Sets the Theta angle absolute to the world.
   * \param theta Theta angle absolute to the world.
   */
  virtual void set_theta(float theta) = 0;

  /**
   * \brief Sets the scale absolute to the world.
   * \param scale Scale absolute to the world.
   */
  virtual void set_scale(float scale) = 0;

  /**
   * \brief Gets the X position relative to the parent entity.
   * \return X position relative to the parent entity.
   */
  [[nodiscard]] virtual auto get_x_offset() const -> float = 0;

  /**
   * \brief Gets the Y position relative to the parent entity.
   * \return Y position relative to the parent entity.
   */
  [[nodiscard]] virtual auto get_y_offset() const -> float = 0;

  /**
   * \brief Gets the Z position relative to the parent entity.
   * \return Z position relative to the parent entity.
   */
  [[nodiscard]] virtual auto get_z_offset() const -> float = 0;

  /**
   * \brief Gets the Theta angle relative to the parent entity.
   * \return Theta angle relative to the parent entity.
   */
  [[nodiscard]] virtual auto get_theta_offset() const -> float = 0;

  /**
   * \brief Gets the scale relative to the parent entity.
   * \return Scale relative to the parent entity.
   */
  [[nodiscard]] virtual auto get_scale_offset() const -> float = 0;

  /**
   * \brief Gets whether the X position is attached to the parent entity.
   * \return Whether the X position is attached to the parent entity.
   */
  [[nodiscard]] virtual auto get_x_attached() const -> bool = 0;

  /**
   * \brief Gets whether the Y position is attached to the parent entity.
   * \return Whether the Y position is attached to the parent entity.
   */
  [[nodiscard]] virtual auto get_y_attached() const -> bool = 0;

  /**
   * \brief Gets whether the Z position is attached to the parent entity.
   * \return Whether the Z position is attached to the parent entity.
   */
  [[nodiscard]] virtual auto get_z_attached() const -> bool = 0;

  /**
   * \brief Gets whether the Theta angle is attached to the parent entity.
   * \return Whether the Theta angle is attached to the parent entity.
   */
  [[nodiscard]] virtual auto get_theta_attached() const -> bool = 0;

  /**
   * \brief Gets whether the scale is attached to the parent entity.
   * \return Whether the scale is attached to the parent entity.
   */
  [[nodiscard]] virtual auto get_scale_attached() const -> bool = 0;

  /**
   * \brief Gets whether the X position is transformed by the parent entity.
   * \return Whether the X position is transformed by the parent entity.
   */
  [[nodiscard]] virtual auto get_x_transformed() const -> bool = 0;

  /**
   * \brief Gets whether the Y position is transformed by the parent entity.
   * \return Whether the Y position is transformed by the parent entity.
   */
  [[nodiscard]] virtual auto get_y_transformed() const -> bool = 0;

  /**
   * \brief Gets whether the Z position is transformed by the parent entity.
   * \return Whether the Z position is transformed by the parent entity.
   */
  [[nodiscard]] virtual auto get_z_tranfromed() const -> bool = 0;

 protected:
  /**
   * \brief Default explicit constructor.
   */
  explicit consteval component() = default;
};
}  // namespace wizard_engine::interfaces

#endif  // WIZARD_ENGINE_INTERFACES_COMPONENT_HPP
