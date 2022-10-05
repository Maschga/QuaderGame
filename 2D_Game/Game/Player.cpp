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
    player_rect.y -= velosity_jump;
    velosity_jump -= 1;

    if (velosity_jump < 0) {
        is_jumping = false;
        velosity_jump = 25;

        is_falling = true;
    }
}

void Player::calculate_fall() {
    on_ground_check ogc = on_ground();

    if (ogc.on_ground) {
        // resetting variables
        is_falling = false;
        velosity_fall = 0;
        fall_move_distance = 0.0;

        player_rect.y = ogc.block_y - player_rect.h;
    } else {
        fall_move_distance = velosity_fall / 4;
        player_rect.y += fall_move_distance;

        if (velosity_fall < 60) { // limiting acceleration
            velosity_fall += 1;
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