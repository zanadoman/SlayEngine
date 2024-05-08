#include "../inc/timer.hpp" // IWYU pragma: keep

uint8_t  wze::timer::frametime = 0;
uint64_t wze::timer::lasttime  = 0;
uint8_t  wze::timer::deltatime = 0;

uint8_t wze::timer::get_frametime() {
    return timer::frametime;
}

void wze::timer::set_frametime(uint8_t frametime) {
    timer::frametime = frametime;
}

uint8_t wze::timer::get_deltatime() {
    return timer::deltatime;
}

void wze::timer::set_deltatime(uint8_t deltatime) {
    timer::deltatime = deltatime;
}

uint64_t wze::timer::get_time() {
    return SDL_GetTicks64();
}

void wze::timer::update() {
    uint32_t deadline;

    deadline = timer::lasttime + timer::frametime;

    if (SDL_GetTicks64() < deadline) {
        SDL_Delay(deadline - SDL_GetTicks64());
    }

    timer::deltatime = SDL_GetTicks64() - timer::lasttime;
    timer::lasttime = SDL_GetTicks64();
}