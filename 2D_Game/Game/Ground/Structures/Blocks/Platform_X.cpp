#include <cmath>
#include "../../../../../src/include/SDL2/SDL.h"
#include "Platform_X.hpp"
#include "../../../Game.hpp"
#include "../../../Player.hpp"

extern Game game;
extern Player player;

Platform_X::Platform_X(float x, float y, float width, float height, float multiplier, float increment) : Block(x, y, width, height) {
    this->multiplier = multiplier;
    this->increment = increment;
}

Platform_X::~Platform_X() {}

void Platform_X::draw() {
    float move = multiplier * sin(sin_x);
    sin_x += increment;

    SDL_FRect platform_rect = {
        block_rect.x,
        block_rect.y,
        block_rect.w,
        block_rect.h
    };

    if (is_visible()) {
        // draw the block
        SDL_SetRenderDrawColor(game.get_renderer(), 0, 110, 255, 0);
        SDL_RenderFillRectF(game.get_renderer(), &platform_rect);

        if (player_on_block(&player)) {
            player.move_x(move); // Move the player when standing on it.
        }

    }

    move_x(move); // Move the block.
}