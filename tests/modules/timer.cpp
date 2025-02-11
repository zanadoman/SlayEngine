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

#include "../../include/wizard_engine/modules/timer.hpp"

#include <gtest/gtest.h>

#include <cstdint>

namespace wzm = wizard_engine::modules;

static constexpr std::uint8_t FRAME_TIME{1000 / 60};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wglobal-constructors"

TEST(timer, frame_time) {
  ASSERT_EQ(wzm::timer::get().get_frame_time(), 0);
  ASSERT_NO_THROW(wzm::timer::get().set_frame_time(FRAME_TIME));
  ASSERT_EQ(wzm::timer::get().get_frame_time(), FRAME_TIME);
}

TEST(timer, delta_time) {
  constexpr float DELTA_TIME{-FRAME_TIME};
  ASSERT_FLOAT_EQ(wzm::timer::get().get_delta_time(), 0);
  ASSERT_NO_THROW(wzm::timer::get().set_delta_time(DELTA_TIME));
  ASSERT_FLOAT_EQ(wzm::timer::get().get_delta_time(), DELTA_TIME);
}

TEST(timer, synchronize) {
  const auto start = wzm::timer::get_current_time();
  wzm::timer::get().synchronize();
  const auto end = wzm::timer::get_current_time();
  ASSERT_NEAR(static_cast<double>(end - start), FRAME_TIME, 2);
  ASSERT_NEAR(wzm::timer::get().get_delta_time(), FRAME_TIME, 2);
}

#pragma clang diagnostic pop
