#include "../../include/wizard_engine/objects/entity.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <numbers>

namespace wzo = wizard_engine::objects;

static constexpr float VALUE{std::numbers::pi_v<float>};
static constexpr float SCALE{2};
static constexpr float SCALED_VALUE{VALUE * SCALE};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wglobal-constructors"

TEST(entity, components) {
  auto component{std::make_shared<wzo::entity>()};
  wzo::entity entity{{component}};
  ASSERT_EQ(entity.components().size(), 1);
  ASSERT_NO_THROW(component.reset());
  ASSERT_NO_THROW(entity.align_components());
  ASSERT_TRUE(entity.components().empty());
}

TEST(entity, x) {
  const auto component{std::make_shared<wzo::entity>()};
  wzo::entity entity{{component}};
  ASSERT_FLOAT_EQ(entity.get_x(), 0);
  ASSERT_NO_THROW(entity.set_x(VALUE));
  ASSERT_FLOAT_EQ(entity.get_x(), VALUE);
  ASSERT_FLOAT_EQ(component->get_x(), entity.get_x());
}

TEST(entity, y) {
  const auto component{std::make_shared<wzo::entity>()};
  wzo::entity entity{{component}};
  ASSERT_FLOAT_EQ(entity.get_y(), 0);
  ASSERT_NO_THROW(entity.set_y(VALUE));
  ASSERT_FLOAT_EQ(entity.get_y(), VALUE);
  ASSERT_FLOAT_EQ(component->get_y(), entity.get_y());
}

TEST(entity, z) {
  const auto component{std::make_shared<wzo::entity>()};
  wzo::entity entity{{component}};
  ASSERT_FLOAT_EQ(entity.get_z(), 0);
  ASSERT_NO_THROW(entity.set_z(VALUE));
  ASSERT_FLOAT_EQ(entity.get_z(), VALUE);
  ASSERT_FLOAT_EQ(component->get_z(), entity.get_z());
}

TEST(entity, theta) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_theta(), 0);
  ASSERT_NO_THROW(entity.set_theta(VALUE));
  ASSERT_FLOAT_EQ(entity.get_theta(), VALUE);
}

TEST(entity, phi) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_phi(), 0);
  ASSERT_NO_THROW(entity.set_phi(VALUE));
  ASSERT_FLOAT_EQ(entity.get_phi(), VALUE);
}

TEST(entity, scale) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_scale(), 1);
  ASSERT_NO_THROW(entity.set_scale(VALUE));
  ASSERT_FLOAT_EQ(entity.get_scale(), VALUE);
}

TEST(entity, x_offset) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_x_offset(), 0);
  ASSERT_NO_THROW(entity.set_x_offset(VALUE));
  ASSERT_FLOAT_EQ(entity.get_x_offset(), VALUE);
}

TEST(entity, y_offset) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_y_offset(), 0);
  ASSERT_NO_THROW(entity.set_y_offset(VALUE));
  ASSERT_FLOAT_EQ(entity.get_y_offset(), VALUE);
}

TEST(entity, z_offset) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_z_offset(), 0);
  ASSERT_NO_THROW(entity.set_z_offset(VALUE));
  ASSERT_FLOAT_EQ(entity.get_z_offset(), VALUE);
}

TEST(entity, theta_offset) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_theta_offset(), 0);
  ASSERT_NO_THROW(entity.set_theta_offset(VALUE));
  ASSERT_FLOAT_EQ(entity.get_theta_offset(), VALUE);
}

TEST(entity, phi_offset) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_phi_offset(), 0);
  ASSERT_NO_THROW(entity.set_phi_offset(VALUE));
  ASSERT_FLOAT_EQ(entity.get_phi_offset(), VALUE);
}

TEST(entity, scale_offset) {
  wzo::entity entity{};
  ASSERT_FLOAT_EQ(entity.get_scale_offset(), 1);
  ASSERT_NO_THROW(entity.set_scale_offset(VALUE));
  ASSERT_FLOAT_EQ(entity.get_scale_offset(), VALUE);
}

TEST(entity, x_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_x_attached());
  ASSERT_NO_THROW(entity.set_x_attached(false));
  ASSERT_FALSE(entity.get_x_attached());
}

TEST(entity, x_transformation_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_x_transformation_attached());
  ASSERT_NO_THROW(entity.set_x_transformation_attached(false));
  ASSERT_FALSE(entity.get_x_transformation_attached());
}

TEST(entity, y_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_y_attached());
  ASSERT_NO_THROW(entity.set_y_attached(false));
  ASSERT_FALSE(entity.get_y_attached());
}

TEST(entity, y_transformation_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_y_transformation_attached());
  ASSERT_NO_THROW(entity.set_y_transformation_attached(false));
  ASSERT_FALSE(entity.get_y_transformation_attached());
}

TEST(entity, z_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_z_attached());
  ASSERT_NO_THROW(entity.set_z_attached(false));
  ASSERT_FALSE(entity.get_z_attached());
}

TEST(entity, z_transformation_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_z_transformation_attached());
  ASSERT_NO_THROW(entity.set_z_transformation_attached(false));
  ASSERT_FALSE(entity.get_z_transformation_attached());
}

TEST(entity, theta_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_theta_attached());
  ASSERT_NO_THROW(entity.set_theta_attached(false));
  ASSERT_FALSE(entity.get_theta_attached());
}

TEST(entity, phi_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_phi_attached());
  ASSERT_NO_THROW(entity.set_phi_attached(false));
  ASSERT_FALSE(entity.get_phi_attached());
}

TEST(entity, scale_attached) {
  wzo::entity entity{};
  ASSERT_TRUE(entity.get_scale_attached());
  ASSERT_NO_THROW(entity.set_scale_attached(false));
  ASSERT_FALSE(entity.get_scale_attached());
}

TEST(entity, align_component_x) {
  wzo::entity entity{};
  wzo::entity component{};
  ASSERT_NO_THROW(component.set_x_offset(VALUE));
  ASSERT_NO_THROW(entity.align_component_x(component));
  ASSERT_FLOAT_EQ(component.get_x(), entity.get_x());
  ASSERT_NO_THROW(component.set_x_transformation_attached(false));
  ASSERT_NO_THROW(entity.align_component_x(component));
  ASSERT_FLOAT_EQ(component.get_x(), VALUE);
  ASSERT_NO_THROW(entity.set_scale(SCALE));
  ASSERT_NO_THROW(entity.align_component_x(component));
  ASSERT_FLOAT_EQ(component.get_x(), SCALED_VALUE);
  ASSERT_NO_THROW(component.set_x_offset(0));
  ASSERT_NO_THROW(component.set_x_attached(false));
  ASSERT_NO_THROW(entity.align_component_x(component));
  ASSERT_FLOAT_EQ(component.get_x(), SCALED_VALUE);
}

TEST(entity, align_component_y) {
  wzo::entity entity{};
  wzo::entity component{};
  ASSERT_NO_THROW(component.set_y_offset(VALUE));
  ASSERT_NO_THROW(entity.align_component_y(component));
  ASSERT_FLOAT_EQ(component.get_y(), entity.get_y());
  ASSERT_NO_THROW(component.set_y_transformation_attached(false));
  ASSERT_NO_THROW(entity.align_component_y(component));
  ASSERT_FLOAT_EQ(component.get_y(), VALUE);
  ASSERT_NO_THROW(entity.set_scale(SCALE));
  ASSERT_NO_THROW(entity.align_component_y(component));
  ASSERT_FLOAT_EQ(component.get_y(), SCALED_VALUE);
  ASSERT_NO_THROW(component.set_y_offset(0));
  ASSERT_NO_THROW(component.set_y_attached(false));
  ASSERT_NO_THROW(entity.align_component_y(component));
  ASSERT_FLOAT_EQ(component.get_y(), SCALED_VALUE);
}

TEST(entity, align_component_z) {
  wzo::entity entity{};
  wzo::entity component{};
  ASSERT_NO_THROW(component.set_z_offset(VALUE));
  ASSERT_NO_THROW(entity.align_component_z(component));
  ASSERT_FLOAT_EQ(component.get_z(), entity.get_z());
  ASSERT_NO_THROW(component.set_z_transformation_attached(false));
  ASSERT_NO_THROW(entity.align_component_z(component));
  ASSERT_FLOAT_EQ(component.get_z(), VALUE);
  ASSERT_NO_THROW(entity.set_scale(SCALE));
  ASSERT_NO_THROW(entity.align_component_z(component));
  ASSERT_FLOAT_EQ(component.get_z(), SCALED_VALUE);
  ASSERT_NO_THROW(component.set_z_offset(0));
  ASSERT_NO_THROW(component.set_z_attached(false));
  ASSERT_NO_THROW(entity.align_component_z(component));
  ASSERT_FLOAT_EQ(component.get_z(), SCALED_VALUE);
}

TEST(entity, align_component_theta) {
  const wzo::entity entity{};
  wzo::entity component{};
  ASSERT_NO_THROW(component.set_theta_offset(VALUE));
  ASSERT_NO_THROW(entity.align_component_theta(component));
  ASSERT_FLOAT_EQ(component.get_theta(), VALUE);
  ASSERT_NO_THROW(component.set_theta_offset(0));
  ASSERT_NO_THROW(component.set_theta_attached(false));
  ASSERT_NO_THROW(entity.align_component_theta(component));
  ASSERT_FLOAT_EQ(component.get_theta(), VALUE);
}

TEST(entity, align_component_phi) {
  const wzo::entity entity{};
  wzo::entity component{};
  ASSERT_NO_THROW(component.set_phi_offset(VALUE));
  ASSERT_NO_THROW(entity.align_component_phi(component));
  ASSERT_FLOAT_EQ(component.get_phi(), VALUE);
  ASSERT_NO_THROW(component.set_phi_offset(0));
  ASSERT_NO_THROW(component.set_phi_attached(false));
  ASSERT_NO_THROW(entity.align_component_phi(component));
  ASSERT_FLOAT_EQ(component.get_phi(), VALUE);
}

TEST(entity, align_component_scale) {
  wzo::entity entity{};
  wzo::entity component{};
  ASSERT_NO_THROW(component.set_scale_offset(VALUE));
  ASSERT_NO_THROW(entity.align_component_scale(component));
  ASSERT_FLOAT_EQ(component.get_scale(), VALUE);
  ASSERT_NO_THROW(entity.set_scale(SCALE));
  ASSERT_NO_THROW(entity.align_component_scale(component));
  ASSERT_FLOAT_EQ(component.get_scale(), SCALED_VALUE);
  ASSERT_NO_THROW(component.set_scale_offset(0));
  ASSERT_NO_THROW(component.set_scale_attached(false));
  ASSERT_NO_THROW(entity.align_component_scale(component));
  ASSERT_FLOAT_EQ(component.get_scale(), SCALED_VALUE);
}

#pragma clang diagnostic pop
