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
 * \file entity.hpp
 * \brief Entity object.
 * \sa entity.cpp
 * \sa component.hpp
 */

#ifndef WIZARD_ENGINE_OBJECTS_ENTITY_HPP
#define WIZARD_ENGINE_OBJECTS_ENTITY_HPP

#include "../interfaces/component.hpp"

#include <algorithm>
#include <array>
#include <memory>
#include <vector>

/**
 * \brief Objects of Wizard Engine.
 */
namespace wizard_engine::objects {
/**
 * \brief Entities can control components.
 * \sa component
 */
class entity : public interfaces::component {
 public:
  /**
   * \brief Explicit constructor.
   * \param components Controlled components.
   * \param x X position absolute to the world.
   * \param y Y position absolute to the world.
   * \param z Z position absolute to the world.
   * \param theta Theta angle absolute to the world.
   * \param phi Phi angle absolute to the world.
   * \param scale Size scaling absolute to the world.
   * \param x_offset X position relative to the parent entity.
   * \param y_offset Y position relative to the parent entity.
   * \param z_offset Z position relative to the parent entity.
   * \param theta_offset Theta angle reltative to the parent entity.
   * \param phi_offset Phi angle relative to the parent entity.
   * \param scale_offset Size scaling relative to the parent entity.
   * \param x_attached Whether the X position is attached to the parent entity.
   * \param x_transformation_attached Whether the X position is transformed by
   * the parent entity.
   * \param y_attached Whether the Y position is attached to the parent entity.
   * \param y_transformation_attached Whether the Y position is transformed by
   * the parent entity.
   * \param z_attached Whether the Z position is attached to the parent entity.
   * \param z_transformation_attached Whether the Z position is transformed by
   * the parent entity.
   * \param theta_attached Whether the Theta angle is attached to the parent
   * entity.
   * \param phi_attached Whether the Phi angle is attached to the parent entity.
   * \param scale_attached Whether the size scaling is attached to the parent
   * entity.
   */
  [[nodiscard]] explicit entity(
      std::vector<std::weak_ptr<component>> components = {},
      float x = {},
      float y = {},
      float z = {},
      float theta = {},
      float phi = {},
      float scale = {},
      float x_offset = {},
      float y_offset = {},
      float z_offset = {},
      float theta_offset = {},
      float phi_offset = {},
      float scale_offset = {},
      bool x_attached = true,
      bool x_transformation_attached = true,
      bool y_attached = true,
      bool y_transformation_attached = true,
      bool z_attached = true,
      bool z_transformation_attached = true,
      bool theta_attached = true,
      bool phi_attached = true,
      bool scale_attached = true);

  /**
   * \brief Default copy constructor.
   * \param other Copied instance.
   */
  [[nodiscard]] entity(const entity& other);

  /**
   * \brief Default move constructor.
   * \param other Moved instance.
   */
  [[nodiscard]] entity(entity&& other) noexcept;

  /**
   * \brief Default virtual destructor.
   */
  ~entity() noexcept override;

  /**
   * \brief Default copy assignment operator.
   * \param other Copied instance.
   * \return Reference to self.
   */
  [[nodiscard]] auto operator=(const entity& other) -> entity&;

  /**
   * \brief Default move assignment operator.
   * \param other Moved instance.
   * \return Reference to self.
   */
  [[nodiscard]] auto operator=(entity&& other) noexcept -> entity&;

  /**
   * \brief Deleted member equality comparison operator.
   */
  auto operator==(const entity&) = delete;

  /**
   * \brief Deleted member unequality comparison operator.
   */
  auto operator!=(const entity&) = delete;

  /**
   * \brief Gets the controlled components.
   * \return Controlled components.
   */
  [[nodiscard]] virtual auto components() const
      -> const std::vector<std::weak_ptr<component>>&;

  /**
   * \brief Gets the controlled components.
   * \return Controlled components.
   */
  [[nodiscard]] virtual auto components()
      -> std::vector<std::weak_ptr<component>>&;

  /**
   * \brief Gets the X position absolute to the world.
   * \return X position absolute to the world.
   * \sa set_x(float x)
   */
  [[nodiscard]] virtual auto get_x() const -> float;

  /**
   * \brief Sets the X position absolute to the world.
   * \param x X position absolute to the world.
   * \sa get_x()
   */
  void set_x(float x) override;

  /**
   * \brief Gets the Y position absolute to the world.
   * \return Y position absolute to the world.
   * \sa set_y(float y)
   */
  [[nodiscard]] virtual auto get_y() const -> float;

  /**
   * \brief Sets the Y position absolute to the world.
   * \param y Y position absolute to the world.
   * \sa get_y()
   */
  void set_y(float y) override;

  /**
   * \brief Gets the Z position absolute to the world.
   * \return Z position absolute to the world.
   * \sa set_z(float z)
   */
  [[nodiscard]] virtual auto get_z() const -> float;

  /**
   * \brief Sets the Z position absolute to the world.
   * \param z Z position absolute to the world.
   * \sa get_z()
   */
  void set_z(float z) override;

  /**
   * \brief Gets the Theta angle absolute to the world.
   * \return Theta angle absolute to the world.
   * \sa set_theta(float theta)
   */
  [[nodiscard]] virtual auto get_theta() const -> float;

  /**
   * \brief Sets the Theta angle absolute to the world.
   * \param theta Theta angle absolute to the world.
   * \sa get_theta()
   */
  void set_theta(float theta) override;

  /**
   * \brief Gets the Phi angle absolute to the world.
   * \return Phi angle absolute to the world.
   * \sa set_phi(float phi)
   */
  [[nodiscard]] virtual auto get_phi() const -> float;

  /**
   * \brief Sets the Phi angle absolute to the world.
   * \param phi Phi angle absolute to the world.
   * \sa get_phi()
   */
  void set_phi(float phi) override;

  /**
   * \brief Gets the size scaling absolute to the world.
   * \return Size scaling absolute to the world.
   * \sa set_scale(float scale)
   */
  [[nodiscard]] virtual auto get_scale() const -> float;

  /**
   * \brief Sets the size scaling absolute to the world.
   * \param scale Size scaling absolute to the world.
   * \sa get_scale()
   */
  void set_scale(float scale) override;

  /**
   * \brief Gets the X position relative to the parent entity.
   * \return X position relative to the parent entity.
   * \sa set_x_offset(float x_offset)
   */
  [[nodiscard]] auto get_x_offset() const -> float override;

  /**
   * \brief Sets the X position relative to the parent entity.
   * \param x_offset X position relative to the parent entity.
   * \sa get_x_offset()
   */
  virtual void set_x_offset(float x_offset);

  /**
   * \brief Gets the Y position relative to the parent entity.
   * \return Y position relative to the parent entity.
   * \sa set_y_offset(float y_offset)
   */
  [[nodiscard]] auto get_y_offset() const -> float override;

  /**
   * \brief Sets the Y position relative to the parent entity.
   * \param y_offset Y position relative to the parent entity.
   * \sa get_y_offset()
   */
  virtual void set_y_offset(float y_offset);

  /**
   * \brief Gets the Z position relative to the parent entity.
   * \return Z position relative to the parent entity.
   * \sa set_z_offset(float z_offset)
   */
  [[nodiscard]] auto get_z_offset() const -> float override;

  /**
   * \brief Sets the Z position relative to the parent entity.
   * \param z_offset Z position relative to the parent entity.
   * \sa get_z_offset()
   */
  virtual void set_z_offset(float z_offset);

  /**
   * \brief Gets the Theta angle relative to the parent entity.
   * \return Theta angle relative to the parent entity.
   * \sa set_theta_offset(float theta_offset)
   */
  [[nodiscard]] auto get_theta_offset() const -> float override;

  /**
   * \brief Sets the Theta angle relative to the parent entity.
   * \param theta_offset Theta angle relative to the parent entity.
   * \sa get_theta_offset()
   */
  virtual void set_theta_offset(float theta_offset);

  /**
   * \brief Gets the Phi angle relative to the parent entity.
   * \return Phi angle relative to the parent entity.
   * \sa set_phi_offset(float phi_offset)
   */
  [[nodiscard]] auto get_phi_offset() const -> float override;

  /**
   * \brief Sets the Phi angle relative to the parent entity.
   * \param phi_offset Phi angle relative to the parent entity.
   * \sa get_phi_offset()
   */
  virtual void set_phi_offset(float phi_offset);

  /**
   * \brief Gets the size scaling relative to the parent entity.
   * \return Size scaling relative to the parent entity.
   * \sa set_scale_offset(float scale_offset)
   */
  [[nodiscard]] auto get_scale_offset() const -> float override;

  /**
   * \brief Sets the size scaling relative to the parent entity.
   * \param scale_offset Size scaling relative to the parent entity.
   * \sa get_scale_offset()
   */
  virtual void set_scale_offset(float scale_offset);

  /**
   * \brief Gets whether the X position is attached to the parent entity.
   * \return Whether the X position is attached to the parent entity.
   * \sa set_x_attached(bool x_attached)
   */
  [[nodiscard]] auto get_x_attached() const -> bool override;

  /**
   * \brief Sets whether the X position is attached to the parent entity.
   * \param x_attached Whether the X position is attached to the parent entity.
   * \sa get_x_attached()
   */
  virtual void set_x_attached(bool x_attached);

  /**
   * \brief Gets whether the X position is transformed by the parent entity.
   * \return Whether the X position is transformed by the parent entity.
   * \sa set_x_transformation_attached(bool x_transformation_attached)
   */
  [[nodiscard]] auto get_x_transformation_attached() const -> bool override;

  /**
   * \brief Sets whether the X position is transformed by the parent entity.
   * \param x_transformation_attached Whether the X position is transformed by
   * the parent entity.
   * \sa get_x_transformation_attached()
   */
  virtual void set_x_transformation_attached(bool x_transformation_attached);

  /**
   * \brief Gets whether the Y position is attached to the parent entity.
   * \return Whether the Y position is attached to the parent entity.
   * \sa set_y_attached(bool y_attached)
   */
  [[nodiscard]] auto get_y_attached() const -> bool override;

  /**
   * \brief Sets whether the Y position is attached to the parent entity.
   * \param y_attached Whether the Y position is attached to the parent entity.
   * \sa get_y_attached()
   */
  virtual void set_y_attached(bool y_attached);

  /**
   * \brief Gets whether the Y position is transformed by the parent entity.
   * \return Whether the Y position is transformed by the parent entity.
   * \sa set_y_transformation_attached(float y_transformation_attached)
   */
  [[nodiscard]] auto get_y_transformation_attached() const -> bool override;

  /**
   * \brief Sets whether the Y position is transformed by the parent entity.
   * \param y_transformation_attached Whether the Y position is transformed by
   * the parent entity.
   * \sa get_y_transformation_attached()
   */
  virtual void set_y_transformation_attached(bool y_transformation_attached);

  /**
   * \brief Gets whether the Z position is attached to the parent entity.
   * \return Whether the Z position is attached to the parent entity.
   * \sa set_z_attached(bool z_attached)
   */
  [[nodiscard]] auto get_z_attached() const -> bool override;

  /**
   * \brief Sets whether the Z position is attached to the parent entity.
   * \param z_attached Whether the Z position is attached to the parent entity.
   * \sa get_z_attached()
   */
  virtual void set_z_attached(bool z_attached);

  /**
   * \brief Gets whether the Z position is transformed by the parent entity.
   * \return Whether the Z position is transformed by the parent entity.
   * \sa set_z_transformation_attached(bool z_transformation_attached)
   */
  [[nodiscard]] auto get_z_transformation_attached() const -> bool override;

  /**
   * \brief Sets whether the Z position is transformed by the parent entity.
   * \param z_transformation_attached Whether the Z position is transformed by
   * the parent entity.
   * \sa get_z_transformation_attached()
   */
  virtual void set_z_transformation_attached(bool z_transformation_attached);

  /**
   * \brief Gets whether the Theta angle is attached to the parent entity.
   * \return Whether the Theta angle is attached to the parent entity.
   * \sa set_theta_attached(bool theta_attached)
   */
  [[nodiscard]] auto get_theta_attached() const -> bool override;

  /**
   * \brief Sets whether the Theta angle is attached to the parent entity.
   * \param theta_attached Whether the Theta angle is attached to the parent
   * entity.
   * \sa get_theta_attached()
   */
  virtual void set_theta_attached(bool theta_attached);

  /**
   * \brief Gets whether the Phi angle is attached to the parent entity.
   * \return Whether the Phi angle is attached to the parent entity.
   * \sa set_phi_attached(bool phi_attached)
   */
  [[nodiscard]] auto get_phi_attached() const -> bool override;

  /**
   * \brief Sets whether the Phi angle is attached to the parent entity.
   * \param phi_attached Whether the Phi angle is attached to the parent entity.
   * \sa get_phi_attached()
   */
  virtual void set_phi_attached(bool phi_attached);

  /**
   * \brief Gets whether the size scaling is attached to the parent entity.
   * \return Whether the size scaling is attached to the parent entity.
   * \sa set_scale_attached(bool scale_attached)
   */
  [[nodiscard]] auto get_scale_attached() const -> bool override;

  /**
   * \brief Sets whether the size scaling is attached to the parent entity.
   * \param scale_attached Whether the size scaling is attached to the parent
   * \sa get_scale_attached()
   * entity.
   */
  virtual void set_scale_attached(bool scale_attached);

  /**
   * \brief Gets the underlying 3D transformation matrix (3x3).
   * \return Underlying 3D transformation matrix (3x3).
   */
  [[nodiscard]] virtual auto get_transformation_matrix_3d() const
      -> const std::array<float, 9>&;

  /**
   * \brief Aligns the X position of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_x_transformation(component& instance)
   */
  virtual void align_component_x(component& instance) const;

  /**
   * \brief Aligns the X transformation of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_x(component& instance)
   */
  virtual void align_component_x_transformation(component& instance) const;

  /**
   * \brief Aligns the Y position of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_y_transformation(component& instance)
   */
  virtual void align_component_y(component& instance) const;

  /**
   * \brief Aligns the Y transformation of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_y_(component& instance)
   */
  virtual void align_component_y_transformation(component& instance) const;

  /**
   * \brief Aligns the Z position of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_z_transformation(component& instance)
   */
  virtual void align_component_z(component& instance) const;

  /**
   * \brief Aligns the Z transformation of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_z(component& instance)
   */
  virtual void align_component_z_transformation(component& instance) const;

  /**
   * \brief Aligns the Theta angle of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_phi(component& instance)
   */
  virtual void align_component_theta(component& instance) const;

  /**
   * \brief Aligns the Phi angle of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   * \sa align_component_theta(component& instance)
   */
  virtual void align_component_phi(component& instance) const;

  /**
   * \brief Aligns the size scaling of a component instance if attached.
   * \param instance Aligned component instance.
   * \sa align_components()
   */
  virtual void align_component_scale(component& instance) const;

  /**
   * \brief Aligns the controlled components and removes orphans.
   * \tparam property_aligners Component property aligner method pointers.
   * \sa align_component_x(component& instance)
   * \sa align_component_x_transformation(component& instance)
   * \sa align_component_y(component& instance)
   * \sa align_component_y_transformation(component& instance)
   * \sa align_component_z(component& instance)
   * \sa align_component_z_transformation(component& instance)
   * \sa align_component_theta(component& instance)
   * \sa align_component_phi(component& instance)
   * \sa align_component_scale(component& instance)
   */
  template <void (entity::*... property_aligners)(component&) const>
  void align_components() {
    auto& pointers{components()};
    const auto removed{std::ranges::remove_if(
        pointers, [&](const std::weak_ptr<component>& pointer) {
          const auto instance{pointer.lock()};
          if (instance) {
            ((this->*property_aligners)(*instance), ...);
          }
          return !instance;
        })};
    pointers.erase(removed.begin(), removed.end());
  }

 private:
  std::vector<std::weak_ptr<component>> _components;
  float _x;
  float _y;
  float _z;
  float _theta;
  float _phi;
  float _scale;
  float _x_offset;
  float _y_offset;
  float _z_offset;
  float _theta_offset;
  float _phi_offset;
  float _scale_offset;
  bool _x_attached;
  bool _x_transformation_attached;
  bool _y_attached;
  bool _y_transformation_attached;
  bool _z_attached;
  bool _z_transformation_attached;
  bool _theta_attached;
  bool _phi_attached;
  bool _scale_attached;
  std::array<float, 9> _transformation_matrix_3d;
};
}  // namespace wizard_engine::objects

#endif  // WIZARD_ENGINE_OBJECTS_ENTITY_HPP
