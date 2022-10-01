#pragma once

#include "Block.hpp"

/* Represents a grass-block in the game. */
class Grass : public Block {
    using Block::Block;

    // Draws the grassblock.
    void draw() override;
};