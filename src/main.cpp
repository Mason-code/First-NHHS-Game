#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "tile_map.h"
#include "mapOne_levelOne.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1700, 900), "SFML Application");
    window.setFramerateLimit(60);

   

    getMap();



    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render the SFML window
        window.clear();



        

        window.draw(map);
        
        
        window.display();
    }

    return 0;
}
