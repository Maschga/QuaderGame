#pragma once

#include "../../../../../src/include/SDL2/SDL.h"
#include "../../../Player.hpp"

/* Represents a block in the window.
* Used to implement other blocks by using inheritance.
*/
class Block {
public:
    /* Initializes the class.
    * 
    * @param x -> X-position (the upper left corner) of the block.
    * @param x -> Y-position (the upper left corner) of the block.
    * @param width -> Width of the block / distance from the x-position to the right.
    * @param height -> Height of the block / distance from the y-position downwards.
    * 
    * @return Block -> Object
    */
    Block(float x, float y, float width, float height);

    /* The destructor. */
    ~Block();

    /* Draws the block. */
    virtual void draw();

    /* Whether the player is currently standing on this block.
    *
    * @return bool
    */
    bool player_on_block(Player* p);

    /* Checking whether the player is on the LEFT side of this block.
    * 
    * @param p -> Pointer to the player-object.
    */
    bool player_on_left_side(Player* p);

    /* Checking whether the player is on the RIGHT side of this block.
    * 
    * @param p -> Pointer to the player-object.
    * 
    * @return bool
    */
    bool player_on_right_side(Player* p);

    /* Getter for the x-position (the upper left corner) of the block. */
    float get_x();

    /* Getter for the y-position (the upper left corner) of the block. */
    float get_y();

    /* Getter for the block width. */
    float get_width();

    /* Getter for the block height. */
    float get_height();

    /* Moves the block by the specified amount of pixel in x-direction.
    * To move the block to the left side, enter a negative number.
    * 
    * @param n -> Amount of pixel.
    */
    void move_x(float n);

    /* Moves the block by the specified amount of pixel in y-direction.
    * To move the block upwards, enter a negative number.
    * 
    * @param n -> Amount of pixel to move.
    */
    void move_y(float n);

protected:
    // Unique id.
    const unsigned int id;

    // The information of the block stored in a structure: { x, y, width, height }.
    SDL_FRect block_rect = { 0.0, 0.0, 0.0, 0.0 };

    /* Whether the block is visible in the window.
    *
    * @return bool
    */
    bool is_visible();
};