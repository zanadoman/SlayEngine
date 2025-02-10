#include "../include/wizard_engine/modules/timer.hpp"

#include <cstdint>
#include <iostream>

namespace wzm = wizard_engine::modules;

auto main([[maybe_unused]] std::int32_t argc,
          [[maybe_unused]] char* argv[]) noexcept -> std::int32_t {
  wzm::timer::get().set_frame_time(10);

  for (;;) {
    std::cout << wzm::timer::get_current_time() << '\n';
    wzm::timer::get().synchronize();
  }
}
