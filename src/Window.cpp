//
// Created by Jake on 2/4/2022.
//

#include "Window.h"

Window::Window() {
    setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {
    setup(l_title, l_size);
}

Window::~Window() {
    destroy();
}

void Window::setup(const std::string &l_title, const sf::Vector2u &l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    create();
}

void Window::create() {
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}

void Window::update() {
    sf::Event event{};
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            m_isDone = true;
        } else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
            toggleFullscreen();
        }
    }
}

void Window::toggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    destroy();
    create();
}
