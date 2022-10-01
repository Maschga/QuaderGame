#include "Spawn.hpp"
#include "Blocks/Grass.hpp"
#include "../../../Helper.hpp"

Spawn::~Spawn() {}

void Spawn::create_blocks(float x, float y) {

	blocks.push_back(new Grass(x, y, random(200, 500), 50));

	this->x = x;
	this->y = y;

	width = blocks.at(0)->get_width();
}