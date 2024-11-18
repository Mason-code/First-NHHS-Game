#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");
    window.setFramerateLimit(60);












    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render the SFML window
        window.clear();
        // You can add your SFML drawing code here
        window.display();
    }

    return 0;
}
