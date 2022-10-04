#include "../../src/include/SDL2/SDL.h"

#include "Player.hpp"
#include "Game.hpp"
#include "../Helper.hpp"
#include "Ground/Ground.hpp"

extern Game game;
extern Ground ground;

Player::Player(float width, float height, float move_distance) : id(game.get_id()) {
    window_size w_size = game.get_window_size();

    player_rect.x = w_size.width / 15.0;
    player_rect.y = w_size.height / 5.0;
    player_rect.w = width;
    player_rect.h = height;

    this->move_distance = move_distance;
}

Player::~Player() {}

void Player::draw() {
    if (is_jumping) {
        calculate_jump();
    } else if (is_falling) {
        calculate_fall();
    }

    SDL_SetRenderDrawColor(game.get_renderer(), 220, 5, 45, 0);
    SDL_RenderFillRectF(game.get_renderer(), &player_rect);
}

float Player::get_x() {
    return player_rect.x;
}

float Player::get_y() {
    return player_rect.y;
}

float Player::get_width() {
    return player_rect.w;
}

float Player::get_height() {
    return player_rect.h;
}

float Player::get_move_distance() {
    return move_distance;
}

float Player::get_fall_move_distance() {
    return fall_move_distance;
}

bool Player::jumps() {
    return is_jumping;
}

bool Player::falls() {
    return is_falling;
}

void Player::set_move_distance(float md) {
    move_distance = md;
}

void Player::jump() {
    if (!is_falling) {
        is_jumping = true;
    }
}

void Player::move_up() {
    /*
    if (is_falling) {
        return;
    }

    if (player_rect.y - move_distance >= 0) {
        player_rect.y -= move_distance;
    } else {
        player_rect.y = 0.0;
    }
    */
}

void Player::move_down() {
    /*
    window_size w_size = game.get_window_size();

    if (on_ground() || is_falling) {
        return;
    }

    if (player_rect.y + move_distance <= w_size.height - player_rect.h) {
        player_rect.y += move_distance;
    } else {
        player_rect.y = w_size.height - player_rect.h;
    }
    */
}

void Player::move_left() {
    if (player_rect.x - move_distance >= 0) {
        player_rect.x -= move_distance;
    } else {
        player_rect.x = 0.0;
    }

    if (!on_ground().on_ground && !is_jumping) {
        is_falling = true;
    }
}

void Player::move_right() {
    window_size w_size = game.get_window_size();

    if (player_rect.x + move_distance <= w_size.width - player_rect.w) {
        // checking if the player is approximately in the middle of the window and the structures must be moved instead of the player
        if ((double)player_rect.x + player_rect.w > w_size.width * 0.5) {
            ground.move_x(move_distance * -1); // -1 because the ground must move to the left
        } else {
            player_rect.x += move_distance;
        }
    } else {
        player_rect.x = w_size.width - player_rect.w;
    }

    if (!on_ground().on_ground && !is_jumping) {
        is_falling = true;
    }
}

on_ground_check Player::on_ground() {
    return ground.player_on_ground(this);
}

void Player::calculate_jump() {
    // using the formula x-0.5*g*t**2 to calculate jump-velocity

    if (jump_started == 0) { // first method call after pressing falling began
        jump_started = SDL_GetTicks();
        jump_start = player_rect.y + player_rect.h;

        player_rect.y -= 5;
    } else {
        Uint32 passed_seconds = SDL_GetTicks() - jump_started;
        float distance_traveled = player_rect.y + player_rect.h - jump_start;

        float move_y = (distance_traveled - 0.5  * 9.81 * passed_seconds * passed_seconds) / 10000;
        
        // without this the player would at first jump very slowly and than get faster and faster over time.
        // by this calculation the behavior of the acceleration turns around.
        move_y = 20.0 + move_y;

        if (move_y < 0.0) {
            // resetting variables
            is_jumping = false;
            jump_start = 0;
            jump_started = 0;

            is_falling = true;
        } else {
            player_rect.y -= move_y;
        }
    }
}

void Player::calculate_fall() {
    // using the formula 0.5*g*t**2 to calculate fall-velocity

    if (fall_started == 0) { // first method call after falling began
        fall_started = SDL_GetTicks();

        fall_move_distance = 2;
        player_rect.y += fall_move_distance;
    } else {
        on_ground_check ogc = on_ground();

        if (ogc.on_ground) {
            // resetting variables
            is_falling = false;
            fall_started = 0;
            fall_move_distance = 0.0;

            player_rect.y = ogc.block_y - player_rect.h;
        } else {
            Uint32 passed_seconds = SDL_GetTicks() - fall_started;
            fall_move_distance = (0.5 * 9.81 * passed_seconds * passed_seconds) / 100000;
            player_rect.y += fall_move_distance;
        }
    }
}

void Player::move_x(float n) {
    window_size w_size = game.get_window_size();

    if (n > 0) { // player should move to the right
        if ((double)player_rect.x + player_rect.w + n > w_size.width * 0.5) {
            ground.move_x(n * -1); // -1 because the ground must move to the left
        }
        else {
            player_rect.x += n;
        }
    } else {
        if (player_rect.x + n < 0) { // checking if player is next to the barrier
            player_rect.x = 0.0;

            if (!on_ground().on_ground) {
                is_falling = true;
            }
        }

        player_rect.x += n;
    }
}

void Player::move_y(float n) {
    player_rect.y += n;
}