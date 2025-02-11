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

#include "../../include/wizard_engine/modules/math.hpp"

#include <gtest/gtest.h>

#include <array>
#include <numbers>

namespace wzm = wizard_engine::modules;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wglobal-constructors"

TEST(math, epsilon) {
  constexpr auto EPSILON{wzm::math::epsilon()};
  ASSERT_FLOAT_EQ(EPSILON, .01F);
}

TEST(math, to_radians) {
  constexpr auto RADIANS{wzm::math::to_radians(0)};
  ASSERT_FLOAT_EQ(RADIANS, 0);
  ASSERT_FLOAT_EQ(wzm::math::to_radians(45), std::numbers::pi_v<float> / 4);
  ASSERT_FLOAT_EQ(wzm::math::to_radians(90), std::numbers::pi_v<float> / 2);
  ASSERT_FLOAT_EQ(wzm::math::to_radians(180), std::numbers::pi_v<float>);
  ASSERT_FLOAT_EQ(wzm::math::to_radians(360), std::numbers::pi_v<float> * 2);
}

TEST(math, to_degrees) {
  constexpr auto DEGREES{wzm::math::to_degrees(0)};
  ASSERT_FLOAT_EQ(DEGREES, 0);
  ASSERT_FLOAT_EQ(wzm::math::to_degrees(std::numbers::pi_v<float> / 4), 45);
  ASSERT_FLOAT_EQ(wzm::math::to_degrees(std::numbers::pi_v<float> / 2), 90);
  ASSERT_FLOAT_EQ(wzm::math::to_degrees(std::numbers::pi_v<float>), 180);
  ASSERT_FLOAT_EQ(wzm::math::to_degrees(std::numbers::pi_v<float> * 2), 360);
}

TEST(math, magnitude_2d) {
  ASSERT_FLOAT_EQ(wzm::math::magnitude_2d({3, 4}), 5);
}

TEST(math, magnitude_3d) {
  ASSERT_FLOAT_EQ(wzm::math::magnitude_3d({2, 3, 6}), 7);
}

TEST(math, angle_2d) {
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({-1, -1}), wzm::math::to_radians(-135));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({-1, 0}), wzm::math::to_radians(180));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({-1, 1}), wzm::math::to_radians(135));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({0, -1}), wzm::math::to_radians(-90));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({0, 0}), wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({0, 1}), wzm::math::to_radians(90));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({1, -1}), wzm::math::to_radians(-45));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({1, 0}), wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(wzm::math::angle_2d({1, 1}), wzm::math::to_radians(45));
}

TEST(math, angle_3d) {
  auto theta_phi = wzm::math::angle_3d({-1, -1, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-135));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(125.26439F));
  theta_phi = wzm::math::angle_3d({-1, -1, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-135));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({-1, -1, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-135));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(54.73561F));
  theta_phi = wzm::math::angle_3d({-1, 0, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(180));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(135));
  theta_phi = wzm::math::angle_3d({-1, 0, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(180));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({-1, 0, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(180));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(45));
  theta_phi = wzm::math::angle_3d({-1, 1, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(135));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(125.26439F));
  theta_phi = wzm::math::angle_3d({-1, 1, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(135));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({-1, 1, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(135));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(54.73561F));
  theta_phi = wzm::math::angle_3d({0, -1, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-90));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(135));
  theta_phi = wzm::math::angle_3d({0, -1, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-90));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({0, -1, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-90));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(45));
  theta_phi = wzm::math::angle_3d({0, 0, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(180));
  theta_phi = wzm::math::angle_3d({0, 0, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(0));
  theta_phi = wzm::math::angle_3d({0, 0, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(0));
  theta_phi = wzm::math::angle_3d({0, 1, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(90));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(135));
  theta_phi = wzm::math::angle_3d({0, 1, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(90));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({0, 1, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(90));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(45));
  theta_phi = wzm::math::angle_3d({1, -1, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-45));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(125.26439F));
  theta_phi = wzm::math::angle_3d({1, -1, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-45));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({1, -1, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(-45));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(54.73561F));
  theta_phi = wzm::math::angle_3d({1, 0, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(135));
  theta_phi = wzm::math::angle_3d({1, 0, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({1, 0, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(0));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(45));
  theta_phi = wzm::math::angle_3d({1, 1, -1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(45));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(125.26439F));
  theta_phi = wzm::math::angle_3d({1, 1, 0});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(45));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(90));
  theta_phi = wzm::math::angle_3d({1, 1, 1});
  ASSERT_FLOAT_EQ(theta_phi[0], wzm::math::to_radians(45));
  ASSERT_FLOAT_EQ(theta_phi[1], wzm::math::to_radians(54.73561F));
}

TEST(math, normalize_2d) {
  const std::array<float, 2> vector{3, 4};
  const auto normalized{wzm::math::normalize_2d(vector)};
  ASSERT_FLOAT_EQ(wzm::math::magnitude_2d(normalized), 1);
  const auto vector_theta{wzm::math::angle_2d(vector)};
  const auto normalized_theta{wzm::math::angle_2d(normalized)};
  ASSERT_FLOAT_EQ(normalized_theta, vector_theta);
}

TEST(math, normalize_3d) {
  const std::array<float, 3> vector{3, 4, 5};
  const auto normalized{wzm::math::normalize_3d(vector)};
  ASSERT_FLOAT_EQ(wzm::math::magnitude_3d(normalized), 1);
  const auto vector_theta_phi{wzm::math::angle_3d(vector)};
  const auto normalized_theta_phi{wzm::math::angle_3d(normalized)};
  ASSERT_FLOAT_EQ(normalized_theta_phi[0], vector_theta_phi[0]);
  ASSERT_FLOAT_EQ(normalized_theta_phi[1], vector_theta_phi[1]);
}

TEST(math, resolve_x_2d) {
  ASSERT_FLOAT_EQ(wzm::math::resolve_x_2d(1, wzm::math::to_radians(0)), 1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_x_2d(1, wzm::math::to_radians(180)), -1);
}

TEST(math, resolve_y_2d) {
  ASSERT_FLOAT_EQ(wzm::math::resolve_y_2d(1, wzm::math::to_radians(90)), 1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_y_2d(1, wzm::math::to_radians(-90)), -1);
}

TEST(math, resolve_x_3d) {
  ASSERT_FLOAT_EQ(wzm::math::resolve_x_3d(
                      1, {wzm::math::to_radians(0), wzm::math::to_radians(90)}),
                  1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_x_3d(1, {wzm::math::to_radians(180),
                                              wzm::math::to_radians(90)}),
                  -1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_x_3d(1, {wzm::math::to_radians(180),
                                              wzm::math::to_radians(-90)}),
                  1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_x_3d(1, {wzm::math::to_radians(0),
                                              wzm::math::to_radians(-90)}),
                  -1);
}

TEST(math, resolve_y_3d) {
  ASSERT_FLOAT_EQ(wzm::math::resolve_y_3d(1, {wzm::math::to_radians(90),
                                              wzm::math::to_radians(90)}),
                  1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_y_3d(1, {wzm::math::to_radians(-90),
                                              wzm::math::to_radians(90)}),
                  -1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_y_3d(1, {wzm::math::to_radians(-90),
                                              wzm::math::to_radians(-90)}),
                  1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_y_3d(1, {wzm::math::to_radians(90),
                                              wzm::math::to_radians(-90)}),
                  -1);
}

TEST(math, resolve_z_3d) {
  ASSERT_FLOAT_EQ(wzm::math::resolve_z_3d(
                      1, {wzm::math::to_radians(0), wzm::math::to_radians(0)}),
                  1);
  ASSERT_FLOAT_EQ(wzm::math::resolve_z_3d(1, {wzm::math::to_radians(0),
                                              wzm::math::to_radians(180)}),
                  -1);
}

#pragma clang diagnostic pop
