#pragma once

#include "Structure.hpp"

/* Represents the spawn-structure. */
class Spawn : public Structure {
public:
    using Structure::Structure;

    /* The destrucotor. */
    ~Spawn();

    /* Initialises the blocks for the structure.
    * 
    * @param x -> X-coordinate - where to begin with creating blocks.
    * @param y -> Y-coordniate - what the height of the ground is => to creat the blocks in a height the player can jump on it.
    */
    void create_blocks(float x, float y) override;
};