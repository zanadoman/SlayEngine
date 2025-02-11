#include "../../include/wizard_engine/modules/timer.hpp"

#include <gtest/gtest.h>

#include <cstdint>

namespace wzm = wizard_engine::modules;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wglobal-constructors"

constexpr std::uint8_t FRAME_TIME{1000 / 60};

TEST(timer, frame_time) {
  EXPECT_EQ(wzm::timer::get().get_frame_time(), 0);
  EXPECT_NO_THROW(wzm::timer::get().set_frame_time(FRAME_TIME));
  EXPECT_EQ(wzm::timer::get().get_frame_time(), FRAME_TIME);
}

TEST(timer, delta_time) {
  constexpr float DELTA_TIME{-FRAME_TIME};
  EXPECT_EQ(wzm::timer::get().get_delta_time(), 0);
  EXPECT_NO_THROW(wzm::timer::get().set_delta_time(DELTA_TIME));
  EXPECT_EQ(wzm::timer::get().get_delta_time(), DELTA_TIME);
}

TEST(timer, synchronize) {
  const auto start = wzm::timer::get_current_time();
  wzm::timer::get().synchronize();
  const auto end = wzm::timer::get_current_time();
  EXPECT_NEAR(static_cast<double>(end - start), FRAME_TIME, 2);
  EXPECT_NEAR(wzm::timer::get().get_delta_time(), FRAME_TIME, 2);
}

#pragma clang diagnostic pop
