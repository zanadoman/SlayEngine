#pragma once

#include <cstdint> // IWYU pragma: keep
#include <string> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <cstddef> // IWYU pragma: keep 
#include <algorithm> // IWYU pragma: keep
#include <memory> // IWYU pragma: keep
#include <type_traits> // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep

#ifdef __linux__
    #include <SDL2/SDL.h> // IWYU pragma: keep
    #include <SDL2/SDL_image.h> // IWYU pragma: keep
    #include <SDL2/SDL_mixer.h> // IWYU pragma: keep
    #include <SDL2/SDL_ttf.h> // IWYU pragma: keep
    #include <SDL2/SDL_net.h> // IWYU pragma: keep
#endif

#ifdef _WIN64
    #include "../SDL2/SDL.h" // IWYU pragma: keep
    #include "../SDL2/SDL_image.h" // IWYU pragma: keep
    #include "../SDL2/SDL_mixer.h" // IWYU pragma: keep
    #include "../SDL2/SDL_ttf.h" // IWYU pragma: keep
    #include "../SDL2/SDL_net.h" // IWYU pragma: keep
#endif

#define PI 3.1415927f
#define DEG_MAX 360.0f
#define RAD_MAX 6.2831855f