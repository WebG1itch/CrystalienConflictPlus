#include <string>
#include "SFML/Graphics.hpp"
#ifndef CRYSTALIENCONFLICTPLUS_CPP_WINDOW_H
#define CRYSTALIENCONFLICTPLUS_CPP_WINDOW_H


class Window {
public:
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();

    void beginDraw() { m_window.clear(sf::Color::Black); } // Clear the window
    void endDraw()  { m_window.display(); } // Display the changes

    bool isDone() const { return m_isDone; }

    bool isFullscreen() const { return m_isFullscreen; }
    sf::Vector2u getWindowSize() {return m_windowSize; }

    void update();
    void toggleFullscreen();

    void Draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }

private:
    void setup(const std::string& l_title, const sf::Vector2u& l_size);
    void destroy() { m_window.close(); } // close the window
    void create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone{};
    bool m_isFullscreen{};

};


#endif //CRYSTALIENCONFLICTPLUS_CPP_WINDOW_H
