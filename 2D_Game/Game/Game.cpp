#include <iostream>
#include "../../src/include/SDL2/SDL.h"

#include "../Helper.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Ground/Ground.hpp"


extern Game game;
extern Player player;

Ground ground;


Game::Game(const char* title, int xpos, int ypos, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Video initialised.\n";

        window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WindowFlags(SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE));

        if (window) {
            std::cout << "Window created.\n";
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer) {
            std::cout << "Renderer created.\n";
        }

        is_running = true;

        ground = Ground(700.0);
        std::cout << "Ground created.\n";

    } else {
        is_running = false;
    }
}

Game::~Game() {}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) {
        is_running = false;
    }
}

void Game::handleKeys() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_W]) {
        player.move_up();
    }
    if (currentKeyStates[SDL_SCANCODE_A] || currentKeyStates[SDL_SCANCODE_LEFT]) {
        player.move_left();
    }
    if (currentKeyStates[SDL_SCANCODE_S]) {
        player.move_down();
    }
    if (currentKeyStates[SDL_SCANCODE_D] || currentKeyStates[SDL_SCANCODE_RIGHT]) {
        player.move_right();
    }
    if (currentKeyStates[SDL_SCANCODE_SPACE] || currentKeyStates[SDL_SCANCODE_UP]) {
        player.jump();
    }
    if (currentKeyStates[SDL_SCANCODE_R]) {
        player.reset(50, 300);
    }
}


void Game::render() {
    SDL_SetRenderDrawColor(renderer, 141, 196, 223, 255); // light blue
    SDL_RenderClear(renderer);

    handleKeys();

    draw();

    SDL_RenderPresent(renderer);
}

void Game::draw() {
    ground.draw();
    player.draw();
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned.\n";
}

unsigned int Game::get_id() {
    return ++id;
}

window_size Game::get_window_size() {
    int w_width, w_heigth;

    SDL_GetWindowSize(game.get_window(), &w_width, &w_heigth);
    window_size w_size(w_width, w_heigth);

    return w_size;
}