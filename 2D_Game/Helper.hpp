#pragma once

/* Initialises the random generator at the beginning of the program. */
void initialise_random_number_generator();

/* Stores the window-information. */
struct window_size {
    /* The constructor.
    *
    * @param width -> Width of the window.
    * @param height -> height of the window.
    *
    * @return window_size
    */
    window_size(int width, int height);

    // Width of the window.
    int width;

    // Height of the window.
    int height;
};

/* Stores whether and where the player is standing on the ground. */
struct on_ground_check {
    /* The constructor.
    * 
    * @param on_ground -> Whether the player is standing on a block.
    * @param block_y -> Y-Position of the block the player is standing on.
    * 
    * @return on_ground_check
    */
    on_ground_check(bool on_ground, float block_y);

    // Whether the player stands on the ground.
    bool on_ground;

    /* The y-position of the block.
    * If the player is not standing on the block, but flying or falling, the value is -1.
    */
    float block_y;
};

/* Returns a random number in the range between `low` and `high`.
* 
* @param low -> Lowest possible number to return.
* @param high -> Highest possible number to return.
* 
* @return int
*/
int random(int low, int high);