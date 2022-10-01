#include "../src/include/SDL2/SDL.h"

#include "Game/Game.hpp"
#include "Game/Player.hpp"

Game game = Game("2D_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);
Player player = Player(50.0, 50.0, 4.0);

int main(int argc, char* args[]) {
    const int FPS = 120;
    const float frameDelay = 1000 / FPS;

    Uint32 frameStart;
    float frameTime;

    // Game loop
    while (game.running()) {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.render();

        frameTime = SDL_GetTicks() - (float)frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game.clean();

    return 0;
}

int WinMain(int argc, char* args[]) { // this methods is called on windows instead of "main()"
    return main(argc, args);
}