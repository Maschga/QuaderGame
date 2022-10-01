#pragma once

#include <vector>
#include "Blocks/Block.hpp"
#include "../../../Helper.hpp"
#include "../../Player.hpp"

/* Represents a structure in the game. */
class Structure {
public:
    /* Initializes the class.
    * 
    * @param gap -> The distance between the structure before this one and this one.
    * 
    * @return Structure
    */
    Structure(float gap);

    /* The destructor. */
    ~Structure();

    /* Initialises the blocks for the structure.
    *
    * @param x -> X-coordinate - where to begin with creating blocks.
    * @param y -> Y-coordniate - what the height of the ground is => to creat the blocks in a height the player can jump on it.
    */
    virtual void create_blocks(float x, float y);

    /* Draws the structure by drawing each block. */
    void draw();

    /* Getter for the x-coordinate (uper left corner) of the structure. */
    float get_x();

    /* Getter for the y-coordinate (uper left corner) of the structure. */
    float get_y();

    /* Getter for the width of the structure. */
    float get_width();

    /* Getter for gap (distance) between the structur before this one and this one. */
    float get_gap();

    /* Checks whether the player stands on the ground.
    *
    * @param player -> Pointer to the player-object.
    *
    * @return on_ground_check
    */
    on_ground_check player_on_ground(Player* player);

    /* Moves the structure by the specified amount of pixel in x-direction.
    * To move the structure to the left side, enter a negative number.
    *
    * @param n -> Amount of pixel.
    */
    void move_x(float n);

protected:
    // Unique id.
    const unsigned int id;

    // X-coordniate of the structure.
    float x = 0.0;

    // Y-coordniate of the structure.
    float y = 0.0;

    // Width of the structure.
    float width = 0.0;

    // Gap (distance) between the structur before this one and this one.
    float gap = 0.0;

    // Contains all the blocks representing this structure.
    std::vector<Block*> blocks;
};