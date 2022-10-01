#include "Obesity1.hpp"
#include "Blocks/Grass.hpp"
#include "../../../Helper.hpp"
#include "Blocks/Platform_X.hpp"

Obesity1::~Obesity1() {}

void Obesity1::create_blocks(float x, float y) {
    blocks.push_back(new Platform_X(x, y, 150.0, 30.0, 3.0, 0.01));
    width += blocks.at(0)->get_width() /* <-- block's width */ + 500 /* gap for next block */;

    blocks.push_back(new Grass(x + width, y - 250, 30, 40));
    width += blocks.at(1)->get_width() /* <-- block's width */ + 300 /* gap for next block */ ;

    blocks.push_back(new Grass(x + width, y + 200, 200, 60));
    width += blocks.at(2)->get_width() /* <-- block's width */ + 200 /* gap for next block */;

    blocks.push_back(new Grass(x + width, y + 50, 80, 40));
    width += blocks.at(3)->get_width() /* <-- block's width */;

    this->x = x;
    this->y = y;

    blocks.push_back(new Grass(x + 120, y - 100, 30, 40)); // block's width not important
    blocks.push_back(new Grass(x + 550, y + 150, 60, 40)); // block's width not important
}