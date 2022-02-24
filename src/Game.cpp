//
// Created by Jake on 2/5/2022.
//

#include "Game.h"

Game::Game(): m_window("Testing Chamber Constructed", sf::Vector2u(800,600)) {
    // Set up members
    m_spriteTexture.loadFromFile("../graphics/terrain/bait_1.png");
    m_sprite.setTexture(m_spriteTexture);
    m_increment = sf::Vector2i(60,60); // Moves at 60px / second
}

Game::~Game() {}

void Game::update() {
    m_window.update(); // Update the window
    moveSprite();
}

void Game::moveSprite() {
    sf::Vector2u l_windowSize = m_window.getWindowSize();
    sf::Vector2u l_textureSize = m_spriteTexture.getSize();

    if((m_sprite.getPosition().x > l_windowSize.x - l_textureSize.x && m_increment.x > 0) || (m_sprite.getPosition().x < 0 && m_increment.x < 0)) {
        m_increment.x = -m_increment.x;
    }

    if((m_sprite.getPosition().y > l_windowSize.y - l_textureSize.y && m_increment.y > 0) || (m_sprite.getPosition().y < 0 && m_increment.y < 0)) {
        m_increment.y = -m_increment.y;
    }

    float deltaTime = m_elapsed.asSeconds();
    m_sprite.setPosition(m_sprite.getPosition().x + (m_increment.x * deltaTime), m_sprite.getPosition().y + (m_increment.y * deltaTime));
}

void Game::render() {
    m_window.beginDraw(); // To clear the screen
    m_window.Draw(m_sprite);
    m_window.endDraw(); // Send to display
}

void Game::handleInput() {

}
