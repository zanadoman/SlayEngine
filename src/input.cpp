#include "WZE/input.hpp"
#include "WZE/engine.hpp"
#include "WZE/window.hpp"

std::array<bool, wze::KEY_COUNT> wze::input::_keys = {};
int16_t wze::input::_cursor_x = 0;
int16_t wze::input::_cursor_y = 0;
float_t wze::input::_cursor_dx = 0.0f;
float_t wze::input::_cursor_dy = 0.0f;
float_t wze::input::_mouse_sens = 1.0f;
wze::cursor wze::input::_cursor = nullptr;

void wze::input::_update_keys() {
    static_assert((size_t)KEY_COUNT <= (size_t)SDL_NUM_SCANCODES);

    uint8_t const* keys;
    uint32_t mouse;

    keys = SDL_GetKeyboardState(nullptr);
    for (size_t i = 0; i < KEY_COUNT; i++) {
        _keys.at(i) = keys[i];
    }

    mouse = SDL_GetMouseState(nullptr, nullptr);
    _keys.at(KEY_MOUSE_LMB) = mouse & SDL_BUTTON_LEFT;
    _keys.at(KEY_MOUSE_MMB) = mouse & SDL_BUTTON_MIDDLE;
    _keys.at(KEY_MOUSE_RMB) = mouse & SDL_BUTTON_RIGHT;
    _keys.at(KEY_MOUSE_MWU) = false;
    _keys.at(KEY_MOUSE_MWD) = false;

    for (SDL_Event const& event : engine::__events()) {
        if (event.type == SDL_MOUSEWHEEL) {
            if (0 < event.wheel.y) {
                _keys.at(KEY_MOUSE_MWU) = true;
            } else if (event.wheel.y < 0) {
                _keys.at(KEY_MOUSE_MWD) = true;
            }
            break;
        }
    }
}

void wze::input::_update_cursor() {
    int32_t x;
    int32_t y;

    for (SDL_Event const& event : engine::__events()) {
        if (event.type == SDL_MOUSEMOTION) {
            _cursor_x = std::clamp(event.motion.x, 0, window::width() - 1);
            _cursor_y = std::clamp(event.motion.y, 0, window::height() - 1);
            break;
        }
    }

    SDL_GetRelativeMouseState(&x, &y);
    _cursor_dx = x * _mouse_sens;
    _cursor_dy = -y * _mouse_sens;
}

bool wze::input::keys(key key) {
    return _keys.at(key);
}

int16_t wze::input::cursor_x() {
    return _cursor_x;
}

int16_t wze::input::cursor_y() {
    return _cursor_y;
}

float_t wze::input::cursor_dx() {
    return _cursor_dx;
}

float_t wze::input::cursor_dy() {
    return _cursor_dy;
}

float_t wze::input::mouse_sens() {
    return _mouse_sens;
}

void wze::input::set_mouse_sens(float_t sens) {
    _mouse_sens = sens;
}

bool wze::input::cursor_visible() {
    return !SDL_GetRelativeMouseMode();
}

void wze::input::hide_cursor() {
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void wze::input::show_cursor() {
    SDL_SetRelativeMouseMode(SDL_FALSE);
}

wze::cursor const& wze::input::cursor() {
    return _cursor;
}

void wze::input::set_cursor(wze::cursor const& cursor) {
    SDL_SetCursor(cursor.get());
    _cursor = cursor;
}

void wze::input::__update() {
    _update_keys();
    _update_cursor();
}