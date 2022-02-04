#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "First window!");

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Close window button clocked.
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        // Draw here.
        sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(320,240);
        window.draw(rectangle); // Render the shape
        window.display();
    }
}