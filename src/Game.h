//
// Created by Jake on 2/5/2022.
//
#include "Window.h"

#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

class Game {

public:
    Game();
    ~Game();

    Window* getWindow() { return &m_window; }

    void handleInput();
    void update();
    void render();

    sf::Time getElapsed() { return m_elapsed; }
    void restartClock() { m_elapsed += m_clock.restart(); }
private:
    void moveSprite();
    Window m_window;

    sf::Texture m_spriteTexture;
    sf::Sprite m_sprite;
    sf::Vector2i m_increment;

    sf::Clock m_clock;
    sf::Time m_elapsed;

    float frameTime = 1.0f / 60.0f; // Change the last number to adjust the framerate of the game.
};


#endif //MAIN_CPP_GAME_H
