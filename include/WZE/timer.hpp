#pragma once

#include "common.hpp" // IWYU pragma: keep

namespace wze {
    class timer final {
        private:
        static uint8_t _delay;
        static uint64_t _last;
        static uint8_t _delta;

        public:
        static uint8_t delay();
        static void set_delay(uint8_t ms);
        static uint8_t delta();
        static void set_delta(uint8_t ms);
        static uint64_t now();
        static void __update();
    };
} // namespace wze