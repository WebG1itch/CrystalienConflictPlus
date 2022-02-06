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

    void handleInput();
    void update();
    void render();
    Window* getWindow() { return &m_window; }

private:
    void moveSprite();
    Window m_window;
    sf::Texture m_spriteTexture;
    sf::Sprite m_sprite;
    sf::Vector2i m_increment;
};


#endif //MAIN_CPP_GAME_H
