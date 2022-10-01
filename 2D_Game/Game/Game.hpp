#pragma once

#include "../../src/include/SDL2/SDL.h"
#include "../Helper.hpp"

class Game {
public:
    /* Initializes the class.
    * 
    * @param title -> Title of the window.
    * @param xpos -> X-position of the window.
    * @param ypos -> Y-position of the window.
    * @param width -> Width of the window.
    * @param height -> Height of the window.
    * 
    * @return Game -> Object
    */
    Game(const char* title, int xpos, int ypos, int width, int height);

    /* The destructor. */
    ~Game();

    /* Gets events coming from the window like SDL_QUIT. */
    void handleEvents();

    /* Gets key events from the window and moves the player. */
    void handleKeys();

    /* Renders the whole window and updates the screen of the window. */
    void render();

    /* Draws the objects of the game (player, structures, ...). */
    void draw();

    /* Called when the user wants to quit the window. */
    void clean();

    /* Returns a unique id used to identfy game objects like blocks. Starts at 1.
    * 
    * @return unsigned int -> The id.
    */
    unsigned int get_id();

    /* Whether the game is currently running.
    * 
    * @return bool
    */
    bool running() { return is_running; }

    /* Returns the width and height of the current window.
    * 
    * @return window_size
    */
    window_size get_window_size();

    /* Getter for the window-object.
    * 
    * @return SDL_Window -> Pointer to the object.
    */
    SDL_Window* get_window() { return window; }

    /* Getter for the renderer-object.
    *
    * @return SDL_Renderer -> Pointer to the object.
    */
    SDL_Renderer* get_renderer() { return renderer; }

private:
    // Wether the game is currently running.
    bool is_running = false;

    /* Variable to hand over unique ids to game - objects like blocks.
    * Gets incremented every time an id is requested.
    */
    unsigned int id = 0;

    // The window-object.
    SDL_Window* window = nullptr;

    // The renderer-object.
    SDL_Renderer* renderer = nullptr;
};