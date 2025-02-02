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
 * \file entity.cpp
 * \brief Entity object.
 * \sa entity.hpp
 */

#include "../../include/wizard_engine/objects/entity.hpp"
#include "../../include/wizard_engine/interfaces/component.hpp"
#include "../../include/wizard_engine/modules/math.hpp"

#include <array>
#include <memory>
#include <utility>
#include <vector>

namespace wizard_engine::objects {
entity::entity(std::vector<std::weak_ptr<component>> components,
               float x,
               float y,
               float z,
               float theta,
               float phi,
               float scale,
               float x_offset,
               float y_offset,
               float z_offset,
               float theta_offset,
               float phi_offset,
               float scale_offset,
               bool x_attached,
               bool x_transformation_attached,
               bool y_attached,
               bool y_transformation_attached,
               bool z_attached,
               bool z_transformation_attached,
               bool theta_attached,
               bool phi_attached,
               bool scale_attached)
    : _components{std::move(components)},
      _x{x},
      _y{y},
      _z{z},
      _theta{theta},
      _phi{phi},
      _scale{scale},
      _x_offset{x_offset},
      _y_offset{y_offset},
      _z_offset{z_offset},
      _theta_offset{theta_offset},
      _phi_offset{phi_offset},
      _scale_offset{scale_offset},
      _x_attached{x_attached},
      _x_transformation_attached{x_transformation_attached},
      _y_attached{y_attached},
      _y_transformation_attached{y_transformation_attached},
      _z_attached{z_attached},
      _z_transformation_attached{z_transformation_attached},
      _theta_attached{theta_attached},
      _phi_attached{phi_attached},
      _scale_attached{scale_attached},
      _transformation_matrix_3d{
          modules::math::transformation_matrix_3d({_theta, _phi}, _scale)} {}

entity::entity(const entity&) = default;

entity::entity(entity&&) noexcept = default;

entity::~entity() noexcept = default;

auto entity::operator=(const entity&) -> entity& = default;

auto entity::operator=(entity&&) noexcept -> entity& = default;

auto entity::components() const
    -> const std::vector<std::weak_ptr<component>>& {
  return _components;
}

auto entity::components() -> std::vector<std::weak_ptr<component>>& {
  return _components;
}

auto entity::get_x() const -> float {
  return _x;
}

void entity::set_x(float x) {
  _x = x;
  align_components<&entity::align_component_x>();
}

auto entity::get_y() const -> float {
  return _y;
}

void entity::set_y(float y) {
  _y = y;
  align_components<&entity::align_component_y>();
}

auto entity::get_z() const -> float {
  return _z;
}

void entity::set_z(float z) {
  _z = z;
  align_components<&entity::align_component_z>();
}

auto entity::get_theta() const -> float {
  return _theta;
}

void entity::set_theta(float theta) {
  _theta = theta;
  _transformation_matrix_3d = modules::math::transformation_matrix_3d(
      {get_theta(), get_phi()}, get_scale());
  align_components<&entity::align_component_theta,
                   &entity::align_component_x_transformation,
                   &entity::align_component_y_transformation,
                   &entity::align_component_z_transformation>();
}

auto entity::get_phi() const -> float {
  return _phi;
}

void entity::set_phi(float phi) {
  _phi = phi;
  _transformation_matrix_3d = modules::math::transformation_matrix_3d(
      {get_theta(), get_phi()}, get_scale());
  align_components<&entity::align_component_phi,
                   &entity::align_component_x_transformation,
                   &entity::align_component_y_transformation,
                   &entity::align_component_z_transformation>();
}

auto entity::get_scale() const -> float {
  return _scale;
}

void entity::set_scale(float scale) {
  _scale = scale;
  _transformation_matrix_3d = modules::math::transformation_matrix_3d(
      {get_theta(), get_phi()}, get_scale());
  align_components<
      &entity::align_component_scale, &entity::align_component_x,
      &entity::align_component_x_transformation, &entity::align_component_y,
      &entity::align_component_y_transformation, &entity::align_component_z,
      &entity::align_component_z_transformation>();
}

auto entity::get_x_offset() const -> float {
  return _x_offset * get_scale();
}

void entity::set_x_offset(float x_offset) {
  _x_offset = x_offset;
}

auto entity::get_y_offset() const -> float {
  return _y_offset * get_scale();
}

void entity::set_y_offset(float y_offset) {
  _y_offset = y_offset;
}

auto entity::get_z_offset() const -> float {
  return _z_offset * get_scale();
}

void entity::set_z_offset(float z_offset) {
  _z_offset = z_offset;
}

auto entity::get_theta_offset() const -> float {
  return _theta_offset;
}

void entity::set_theta_offset(float theta_offset) {
  _theta_offset = theta_offset;
}

auto entity::get_phi_offset() const -> float {
  return _phi_offset;
}

void entity::set_phi_offset(float phi_offset) {
  _phi_offset = phi_offset;
}

auto entity::get_scale_offset() const -> float {
  return _scale_offset;
}

void entity::set_scale_offset(float scale_offset) {
  _scale_offset = scale_offset;
}

auto entity::get_x_attached() const -> bool {
  return _x_attached;
}

void entity::set_x_attached(bool x_attached) {
  _x_attached = x_attached;
}

auto entity::get_x_transformation_attached() const -> bool {
  return _x_transformation_attached;
}

void entity::set_x_transformation_attached(bool x_transformation_attached) {
  _x_transformation_attached = x_transformation_attached;
}

auto entity::get_y_attached() const -> bool {
  return _y_attached;
}

void entity::set_y_attached(bool y_attached) {
  _y_attached = y_attached;
}

auto entity::get_y_transformation_attached() const -> bool {
  return _y_transformation_attached;
}

void entity::set_y_transformation_attached(bool y_transformation_attached) {
  _y_transformation_attached = y_transformation_attached;
}

auto entity::get_z_attached() const -> bool {
  return _z_attached;
}

void entity::set_z_attached(bool z_attached) {
  _z_attached = z_attached;
}

auto entity::get_z_transformation_attached() const -> bool {
  return _z_transformation_attached;
}

void entity::set_z_transformation_attached(bool z_transformation_attached) {
  _z_transformation_attached = z_transformation_attached;
}

auto entity::get_theta_attached() const -> bool {
  return _theta_attached;
}

void entity::set_theta_attached(bool theta_attached) {
  _theta_attached = theta_attached;
}

auto entity::get_phi_attached() const -> bool {
  return _phi_attached;
}

void entity::set_phi_attached(bool phi_attached) {
  _phi_attached = phi_attached;
}

auto entity::get_scale_attached() const -> bool {
  return _scale_attached;
}

void entity::set_scale_attached(bool scale_attached) {
  _scale_attached = scale_attached;
}

auto entity::get_transformation_matrix_3d() const
    -> const std::array<float, 9>& {
  return _transformation_matrix_3d;
}

void entity::align_component_x(component& instance) const {
  if (instance.get_x_attached() && !instance.get_x_transformation_attached()) {
    instance.set_x(get_x() + (instance.get_x_offset() * get_scale()));
  }
}

void entity::align_component_x_transformation(component& instance) const {
  if (instance.get_x_transformation_attached()) {
    instance.set_x(get_x() +
                   modules::math::transform_x_3d(
                       {instance.get_x_offset(), instance.get_y_offset(),
                        instance.get_z_offset()},
                       get_transformation_matrix_3d()));
  }
}

void entity::align_component_y(component& instance) const {
  if (instance.get_y_attached() && !instance.get_y_transformation_attached()) {
    instance.set_y(get_y() + (instance.get_y_offset() * get_scale()));
  }
}

void entity::align_component_y_transformation(component& instance) const {
  if (instance.get_y_transformation_attached()) {
    instance.set_y(get_y() +
                   modules::math::transform_y_3d(
                       {instance.get_x_offset(), instance.get_y_offset(),
                        instance.get_z_offset()},
                       get_transformation_matrix_3d()));
  }
}

void entity::align_component_z(component& instance) const {
  if (instance.get_z_attached() && !instance.get_z_transformation_attached()) {
    instance.set_z(get_z() + (instance.get_z_offset() * get_scale()));
  }
}

void entity::align_component_z_transformation(component& instance) const {
  if (instance.get_z_transformation_attached()) {
    instance.set_z(get_z() +
                   modules::math::transform_z_3d(
                       {instance.get_x_offset(), instance.get_y_offset(),
                        instance.get_z_offset()},
                       get_transformation_matrix_3d()));
  }
}

void entity::align_component_theta(component& instance) const {
  if (instance.get_theta_attached()) {
    instance.set_theta(get_theta() + instance.get_theta_offset());
  }
}

void entity::align_component_phi(component& instance) const {
  if (instance.get_phi_attached()) {
    instance.set_phi(get_phi() + instance.get_phi_offset());
  }
}

void entity::align_component_scale(component& instance) const {
  if (instance.get_scale_attached()) {
    instance.set_scale(get_scale() * instance.get_scale_offset());
  }
}
}  // namespace wizard_engine::objects
