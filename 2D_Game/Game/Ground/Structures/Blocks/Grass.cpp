#include "../../../../../src/include/SDL2/SDL.h"
#include "../../../Game.hpp"
#include "Grass.hpp"

extern Game game;

void Grass::draw() {
    if (is_visible()) {
        SDL_FRect grass_rect = {
            block_rect.x,
            block_rect.y,
            block_rect.w,
            block_rect.h / 3
        };

        SDL_FRect earth_rect = {
            block_rect.x,
            block_rect.y + block_rect.h / 3,
            block_rect.w,
            block_rect.h - block_rect.h / 3,
        };

        SDL_SetRenderDrawColor(game.get_renderer(), 55, 128, 0, 0);
        SDL_RenderFillRectF(game.get_renderer(), &grass_rect);

        SDL_SetRenderDrawColor(game.get_renderer(), 105, 67, 24, 0);
        SDL_RenderFillRectF(game.get_renderer(), &earth_rect);
    }
}