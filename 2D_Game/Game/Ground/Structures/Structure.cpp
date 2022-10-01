#include "Structure.hpp"
#include "Blocks/Block.hpp"
#include "../../../Helper.hpp"
#include "../../Player.hpp"
#include "../../Game.hpp"

extern Game game;
extern Player player;

Structure::Structure(float gap) : id(game.get_id()) {
    this->gap = gap;
}

Structure::~Structure() {}

void Structure::create_blocks(float x, float y) {}

void Structure::draw() {
    for (Block* b : blocks) {
        b->draw();
    }
}

float Structure::get_x() {
    return x;
}
float Structure::get_y() {
    return y;
}

float Structure::get_width() {
    return width;
}

float Structure::get_gap() {
    return gap;
}

on_ground_check Structure::player_on_ground(Player* player) {
    on_ground_check ogc = { false, -1 };

    for (Block* b : blocks) {
        if (b->player_on_block(player)) {
            ogc.on_ground = true;
            ogc.block_y = b->get_y();
        }
    }

    return ogc;
}

void Structure::move_x(float n) {
    for (Block* b : blocks) {
        b->move_x(n);
    }

    x += n;
}