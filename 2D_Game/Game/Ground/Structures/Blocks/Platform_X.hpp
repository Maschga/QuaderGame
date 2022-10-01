#pragma once

#include "Block.hpp"

class Platform_X : public Block {
public:
    /* Initializes the class.
    *
    * @param x -> X-position (the upper left corner) of the block.
    * @param x -> Y-position (the upper left corner) of the block.
    * @param width -> Width of the block / distance from the x-position to the right.
    * @param height -> Height of the block / distance from the y-position downwards.
    * @param multiplier -> Affects the length  of the way the platform flys. The higher the value of this variable the longer the way.
    * @param increment -> Affects the velocity. The higher the value of this variable the faster the block.
    *
    * @return Platform_X
    */
    Platform_X(float x, float y, float width, float height, float multiplier, float increment);

    // The destructor.
    ~Platform_X();

    // Draws the platform.
    void draw() override;
private:
    // Used to increment it per draw and get a sinus-value.
    float sin_x = 0.0;

    /* Affects the length  of the way the playtform plays. The higher the value of this variable the longer the way. */
    float multiplier;

    /* Affects the velocity. The higher the value of this variable the faster the block. */
    float increment;
};