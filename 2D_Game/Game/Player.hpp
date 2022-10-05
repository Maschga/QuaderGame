#pragma once

#include "../../src/include/SDL2/SDL.h"
#include "../Helper.hpp"

class Player {
public:
    // Resets the player to a specifed position. Used when the player fell down. NOTE: Will be removed in future.
    void reset(float x, float y) { player_rect.x = x; player_rect.y = y; is_falling = true; velosity_fall = 0;}

    /* Initializes the class.
    *
    * @param width -> Width of the player.
    * @param height -> Height of the player.
    * @param move_distance -> How fast the player moves per window-draw.
    *
    * @return Block -> Object
    */
    Player(float width, float height, float move_distance);

    /* The destructor. */
    ~Player();

    /* Draws the player. */
    void draw();

    /* Getter for the x-position of the player. 
    * 
    * @return float
    */
    float get_x();

    /* Getter for the y-position of the player.
    *
    * @return float
    */
    float get_y();

    /* Getter for the width of the player.
    *
    * @return float
    */
    float get_width();

    /* Getter for the height of the player.
    *
    * @return float
    */
    float get_height();

    /* Returns how fast the player moves per window-draw.
    *
    * @return float
    */
    float get_move_distance();

    /* Returns how far the player was moved in the last fall-calculation.
    *
    * @return float
    */
    float get_fall_move_distance();

    /* Whether the player is currently jumping.
    *
    * @return bool
    */
    bool jumps();

    /* Whether the player is currently falling.
    *
    * @return bool
    */
    bool falls();

    /* Sets the move_distance (=> how fast the player moves per draw).
    * 
    * @param md -> The new move_distance-value.
    */
    void set_move_distance(float md);

    /* Prepares the object for a jump. */
    void jump();

    /* NOTICE: Currently not implemented. */
    void move_up();

    /* NOTICE: Currently not implemented. */
    void move_down();

    /* Moves the player to the left by move_distance. */
    void move_left();

    /* Moves the player to the left by move_distance. */
    void move_right();

    /* Whether the player is currently standing on the ground.
    * 
    * @return on_ground_check
    */
    on_ground_check on_ground();

    /* Moves the player in x-direction by the specified Amount.
    * 
    * @param n -> Amount by which the player is moved.
    */
    void move_x(float n);

    /* Moves the player in y-direction by the specified Amount.
    *
    * @param n -> Amount by which the player is moved.
    */
    void move_y(float n);

private:
    // Unique id.
    const unsigned int id;

    // How far the player moves per draw.
    float move_distance = 0.0;

    // Whether the player is currently jumping.
    bool is_jumping = false;

    // Whether the player is currently falling.
    bool is_falling = true;

    // Handles the jump acceleration; when jumping variable is decreases to 0, then falling begins.
    int velosity_jump = 25;

    // Handles the fall acceleration; when falling variable is increased to 60 after that the player falls constant.
    int velosity_fall = 0;

    /* How far the player was moved in the last fall-calculation.
    * Defaults to 0.0 when the player is not falling.
    */
    float fall_move_distance = 0.0;

    // Calculates the player's jump and physics.
    void calculate_jump();

    // Calculates the player's fall and physics.
    void calculate_fall();

    // The information of the player stored in a structure: { x, y, width, height }.
    SDL_FRect player_rect = { 0.0, 0.0, 0.0, 0.0 }; // x, y, width, height
};