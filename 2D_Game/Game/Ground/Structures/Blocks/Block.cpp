#include "Block.hpp"
#include "../../../Game.hpp"

extern Game game;


Block::Block(float x, float y, float width, float height) : id(game.get_id()) {
    block_rect.x = x;
    block_rect.y = y;
    block_rect.w = width;
    block_rect.h = height;
}

Block::~Block() {}

void Block::draw() {
    if (is_visible()) {
        SDL_RenderFillRectF(game.get_renderer(), &block_rect);
    }
}

bool Block::player_on_block(Player* player) {
    /* The player moves multiple pixel per draw when falling so the player can glitch into a block:
    *
    *    ++++++++++++++++
    *    +              +
    *    +              +
    *    +    Player    +
    *    +              +
    *    +              +
    *    +        ######+#########
    *    ++++++++++++++++        #
    *             #              #
    *             #    Block     #
    *             #              #
    *             #              #
    *             ################
    *
    * To prevent this we need a range when checking if the player is standing on the block.
    */

    float range = player->get_fall_move_distance() != 0.0 ? player->get_fall_move_distance() : 0.1; // The range described above

    // checking whether the player is on a block height

    if (player->get_y() + player->get_height() - block_rect.y < range && block_rect.y - player->get_y() <= player->get_height()) {
        if (player->get_x() + player->get_width() < block_rect.x) { // player is on the LEFT side of the block
            if (block_rect.x <= player->get_x() - player->get_width()) { // checking whether player is standing on the block
                return true;
            }
        }
        else if (player->get_x() > block_rect.x && player->get_x() < block_rect.x + block_rect.w) { // player is standing on the block; block is wider than the player
            return true;
        }
        else { // player is on the RIGHT side of the block
            if (block_rect.x + block_rect.w >= player->get_x()) { // checking whether player is standing on the block
                return true;
            }
        }
    }

    return false;
}

bool Block::player_on_left_side(Player* player) {
    return player->get_x() + player->get_width() < block_rect.x;
}

bool Block::player_on_right_side(Player* player) {
    return block_rect.x + block_rect.w < player->get_x();
}

float Block::get_x() {
    return block_rect.x;
}

float Block::get_y() {
    return block_rect.y;
}

float Block::get_width() {
    return block_rect.w;
}

float Block::get_height() {
    return block_rect.h;
}

void Block::move_x(float n) {
    block_rect.x += n;
}

void Block::move_y(float n) {
    block_rect.y += n;
}

bool Block::is_visible() {
    window_size w_size = game.get_window_size();

    // checking if the block is visible by the ...

    // ... x-position or ...
    if (block_rect.x + block_rect.w < 0 || block_rect.x > w_size.width) {
        return false;
    }

    // ... y-position
    if (block_rect.y + block_rect.h < 0 || block_rect.y > w_size.height) {
        return false;
    }

    return true;
}