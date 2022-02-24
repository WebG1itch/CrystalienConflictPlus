#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    // Program entry point
    Game game; // Create the game, duh!
    while(!game.getWindow()->isDone()) {
        // Game loop stuff :D
        game.handleInput();
        game.update();
        game.render();
        game.restartClock();
    }
}