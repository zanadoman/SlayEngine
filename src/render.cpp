/*
  Wizard Engine
  Copyright (C) 2023-2024 Zana Domán

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

#define WZE_INTERNAL

#include <WZE/camera.hpp>
#include <WZE/math.hpp>
#include <WZE/render.hpp>
#include <WZE/window.hpp>

SDL_Renderer* wze::render::_base = nullptr;
float_t wze::render::_origo_x = 0.f;
float_t wze::render::_origo_y = 0.f;
std::vector<std::weak_ptr<wze::renderable>> wze::render::_instances = {};
std::vector<std::shared_ptr<wze::renderable const>> wze::render::_space = {};
std::vector<std::shared_ptr<wze::renderable const>> wze::render::_plane = {};

void wze::render::open_frame() {
    if (SDL_SetRenderDrawColor(_base, 0, 0, 0, 255)) {
        throw std::runtime_error(SDL_GetError());
    }
    if (SDL_RenderClear(_base)) {
        throw std::runtime_error(SDL_GetError());
    }
}

bool wze::render::invisible(renderable const& instance) {
    return !instance.visible() ||
           (instance.spatial() && instance.z() <= camera::z()) ||
           instance.color_a() == 0 || !instance.texture() ||
           instance.width() == 0.f || instance.height() == 0.f;
}

void wze::render::transform(renderable& instance) {
    instance.set_screen_area(
        {_origo_x + instance.screen_area().x - instance.screen_area().w / 2.f,
         _origo_y + instance.screen_area().y - instance.screen_area().h / 2.f,
         instance.screen_area().w, instance.screen_area().h});
}

bool wze::render::offscreen(renderable const& instance) {
    return instance.screen_area().x + instance.screen_area().w < 0.f ||
           window::width() <= instance.screen_area().x ||
           instance.screen_area().y + instance.screen_area().h < 0.f ||
           window::height() <= instance.screen_area().y;
}

void wze::render::draw(renderable const& instance) {
    if (SDL_SetTextureColorMod(instance.texture().get(), instance.color_r(),
                               instance.color_g(), instance.color_b())) {
        throw std::runtime_error(SDL_GetError());
    }
    if (SDL_SetTextureAlphaMod(instance.texture().get(), instance.color_a())) {
        throw std::runtime_error(SDL_GetError());
    }
    if (SDL_RenderCopyExF(_base, instance.texture().get(), nullptr,
                          &instance.screen_area(),
                          (double_t)math::to_degrees(instance.screen_angle()),
                          nullptr, (SDL_RendererFlip)instance.flip())) {
        throw std::runtime_error(SDL_GetError());
    }
}

void wze::render::close_frame() {
    SDL_RenderPresent(_base);
}

SDL_Renderer* wze::render::base() {
    return _base;
}

std::vector<std::weak_ptr<wze::renderable>>& wze::render::instances() {
    return _instances;
}

float_t wze::render::origo_x() {
    return _origo_x;
}

void wze::render::set_origo_x(float_t origo_x) {
    _origo_x = origo_x;
}

float_t wze::render::origo_y() {
    return _origo_y;
}

void wze::render::set_origo_y(float_t origo_y) {
    _origo_y = origo_y;
}

void wze::render::init() {
    _base = SDL_CreateRenderer(window::base(), -1,
                               SDL_RENDERER_ACCELERATED |
                                   SDL_RENDERER_TARGETTEXTURE);
    if (!_base) {
        throw std::runtime_error(SDL_GetError());
    }
    if (SDL_RenderSetLogicalSize(_base, window::width(), window::height())) {
        throw std::runtime_error(SDL_GetError());
    }
    if (SDL_SetRenderDrawBlendMode(_base, SDL_BLENDMODE_BLEND)) {
        throw std::runtime_error(SDL_GetError());
    }

    _origo_x = window::width() / 2.f;
    _origo_y = window::height() / 2.f;
}

void wze::render::update() {
    std::vector<std::weak_ptr<renderable>>::iterator iterator;
    std::shared_ptr<renderable> instance;

    _space.clear();
    _plane.clear();

    for (iterator = _instances.begin(); iterator != _instances.end();) {
        if ((instance = iterator->lock())) {
            ++iterator;
            if (invisible(*instance)) {
                continue;
            }
            camera::project(*instance);
            transform(*instance);
            if (offscreen(*instance)) {
                continue;
            }
            if (instance->spatial()) {
                _space.push_back(instance);
            } else {
                _plane.push_back(instance);
            }
        } else {
            _instances.erase(iterator);
        }
    }

    std::ranges::sort(
        _space,
        [](std::shared_ptr<renderable const> const& instance1,
           std::shared_ptr<renderable const> const& instance2) -> bool {
            return instance1->z() != instance2->z()
                       ? instance2->z() < instance1->z()
                       : instance1->priority() < instance2->priority();
        });

    std::ranges::sort(
        _plane,
        [](std::shared_ptr<renderable const> const& instance1,
           std::shared_ptr<renderable const> const& instance2) -> bool {
            return instance1->priority() < instance2->priority();
        });

    open_frame();

    std::ranges::for_each(
        _space, [](std::shared_ptr<renderable const> const& instance) -> void {
            draw(*instance);
        });

    std::ranges::for_each(
        _plane, [](std::shared_ptr<renderable const> const& instance) -> void {
            draw(*instance);
        });

    close_frame();
}

std::pair<float_t, float_t> wze::render::detransform(float_t x, float_t y) {
    return {x - _origo_x, y - _origo_y};
}
