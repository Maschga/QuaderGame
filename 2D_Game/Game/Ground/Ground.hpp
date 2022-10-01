#pragma once

#include <vector>
#include "Structures/Structure.hpp"
#include "../../Helper.hpp"
#include "../Player.hpp"

/* Creates the ground by joining individual blocks together. */
class Ground {
public:
    /* Default constructor for this class.
    *
    * @return Ground -> Object
    */
    Ground();

    /* Initializes the class.
    *
    * @param height -> Where to draw the ground.
    *
    * @return Ground -> Object
    */
    Ground(float height);

    /* The destructor. */
    ~Ground();

    /* Returns the ground height.
    * 
    * @return float
    */
    float get_height();

    /* Draws the ground by calling the draw method of each structure. */
    void draw();

    /* Checks whether the player stands on the ground.
    *
    * @param player -> Pointer to the player-object.
    *
    * @return on_ground_check
    */
    on_ground_check player_on_ground(Player* player);

    /* Moves the ground by the specified amount of pixel in x-direction.
    * To move the ground to the left side, enter a negative number.
    *
    * @param n -> Amount of pixel.
    */
    void move_x(float n);

private:
    // The ground height.
    float height = 0.0;

    // Used to get a random structure.
    Structure* get_random_structure(float gap);

    // Deletes and creates structures when one leaves the screen.
    void handle_structures();

    // Stores the blocks representing the ground.
    std::vector<Structure*> structures = {};
};