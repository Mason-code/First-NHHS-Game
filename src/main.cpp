#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Camera.h"

    int main() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "GTA");
        window.setFramerateLimit(60);

        Player player("../src/assets/Red_Eyegore_Model.png");
        Map map("../src/assets/map.jpg");  
        Camera camera(window);

        sf::Clock clock;


        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            // Time step (delta time)
            float deltaTime = clock.restart().asSeconds();

            // Update logic
            player.update(deltaTime);
            camera.update(player.getPosition());   


            // Render
            window.clear(sf::Color::Magenta);
            camera.apply(window);  // Apply camera view
            map.draw(window);      // Draw the map
            player.draw(window);   // Draw the player
            window.display();
        }

        return 0;
    }
