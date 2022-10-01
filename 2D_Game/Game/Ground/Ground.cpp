#include "../../../src/include/SDL2/SDL.h"

#include "Ground.hpp"
#include "../../Helper.hpp"
#include "../Game.hpp"

#include "Structures/Structure.hpp"
#include "Structures/Spawn.hpp"
#include "Structures/Obesity1.hpp"

extern Game game;

Ground::Ground() {}

Ground::Ground(float height) {
    this->height = height;
    window_size w_size = game.get_window_size();
    float w = 0.0;
    float gap = random(150, 200); // gap between structures

    structures.push_back(new Spawn(gap));
    structures.at(0)->create_blocks(w, height);
    w += structures.at(0)->get_width();

    for (int i = 1; w_size.width - w >= 0; i++) {
        gap = random(150, 200);
        w += gap;

        structures.push_back(get_random_structure(gap));
        structures.at(i)->create_blocks(w, height);
        w += structures.at(i)->get_width();
    }
}

Ground::~Ground() {}

float Ground::get_height() {
    return height;
}

void Ground::draw() {
    handle_structures();

    for (Structure* s : structures) {
        s->draw();
    }
}

on_ground_check Ground::player_on_ground(Player* player) {
    for (Structure* s : structures) {
        on_ground_check o_g_c = s->player_on_ground(player);

        if (o_g_c.on_ground) {
            return o_g_c;
        }
    }

    return on_ground_check(false, -1);
}

void Ground::move_x(float n) {
    for (Structure* s : structures) {
        s->move_x(n);
    }
}

Structure* Ground::get_random_structure(float gap) {
    switch (random(1, 2)) {
    case 1:
        return new Obesity1(gap);
    case 2:
        return new Spawn(gap);
    default:
        return new Spawn(gap);
    }
}
#include <iostream>
void Ground::handle_structures() {
    window_size w_size = game.get_window_size();

    // delete the first structure when it is not visible anymore
    if (structures.at(0)->get_x() + structures.at(0)->get_width() < 0) {
        structures.erase(structures.begin());
    }

    // create a new one when the x-position plus the structure's width less than the screen's width is
    Structure* last_s = structures.at(structures.size() - 1);

    if (last_s->get_x() + last_s->get_width() <= w_size.width) {
        float gap = random(150, 200);

        structures.push_back(get_random_structure(gap));
        structures.at(structures.size() - 1)->create_blocks(last_s->get_x() + last_s->get_width() + gap, height);
    }
}