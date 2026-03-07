#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "tile_map.h"
#include "mapOne_levelOne.h"

void character();

void character() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        std::cout << "it works!";
    }

}

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML Application");
    window.setFramerateLimit(60);

   

    getMap();



    sf::Clock deltaClock;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Update animations
        float deltaTime = clock.restart().asSeconds(); // Get elapsed time in seconds

        anim.updateAnimations(deltaTime);



        character();

        // Render the SFML window
        window.clear();


        window.draw(mapFloor);
        window.draw(mapBorder);
        window.draw(anim);
        

        window.display();
    }

    return 0;
}


