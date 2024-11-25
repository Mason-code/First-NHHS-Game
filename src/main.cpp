#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1700, 900), "SFML Application");
    window.setFramerateLimit(60);


    sf::Texture texture;
    if (!texture.loadFromFile("../src/assets/Texture/TX_props.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);


    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render the SFML window
        window.clear();


        window.draw(sprite);
        // You can add your SFML drawing code here

        window.display();
    }

    return 0;
}
