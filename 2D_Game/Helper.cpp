#include <random>
#include "Helper.hpp"

std::random_device rd; // obtain a random number from hardware
std::mt19937 gen(rd()); // seed the generator

window_size::window_size(int width, int height) {
    this->width = width;
    this->height = height;
}

on_ground_check::on_ground_check(bool on_ground, float block_y) {
    this->on_ground = on_ground;
    this->block_y = block_y;
}

int random(int min, int max) {
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}