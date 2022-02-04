#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Testing");
    sf::Texture baseGroundTexture;
    if(!baseGroundTexture.loadFromFile("../graphics/terrain/terrain.png")) {
        // Manage errors here :)
    }
    sf::Sprite sprite(baseGroundTexture);
    sf::Vector2u size = baseGroundTexture.getSize();
    sprite.setOrigin(size.x / 2, size.y / 2);
    sf::Vector2f increment(0.4f, 0.4f);

    sprite.setColor(sf::Color::White);

    while(window.isOpen()) { // this bit here is kinda important because that's how you close the window.
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Close window button clocked.
                window.close();
            }
        }

        if((sprite.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || (sprite.getPosition().x - (size.x / 2) < 0 && increment.x < 0)) {
            // Reverse the direction on X axis
            increment.x = -increment.x;
        }

        if((sprite.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (sprite.getPosition().y - (size.y / 2) < 0 && increment.y < 0)) {
            // Reverse the direction on the Y axis
            increment.y = -increment.y;
        }

        sprite.setPosition(sprite.getPosition() + increment);

        window.clear(sf::Color::Black); // clear last frame to new color
        window.draw(sprite);
        window.display();
    }
}