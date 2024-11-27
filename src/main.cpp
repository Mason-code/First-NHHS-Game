#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include <tile_map.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(1700, 900), "SFML Application");
    window.setFramerateLimit(60);

    // Define a rectangle, located at (0, 0) with a size of 20x5
   



    // sf::Texture texture;
    // if (!texture.loadFromFile("../src/assets/Texture/TX_props.png", sf::IntRect(32, 0, 32, 32))) {
    //    return EXIT_FAILURE;
    // }
    // sf::Sprite sprite(texture);
    // sprite.setPosition(sf::Vector2f(700.f, 60.f));

    // sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale





    std::vector<int> level;

      // Append value 10 times
    for (int i = 0; i < 144; ++i) {
        level.push_back(156);
    }

    TileMap map;
    if (!map.load("../src/assets/Texture/TX_props.png", { 32, 32 }, level.data(), 12, 12))
        return -1;


    std::vector<int> level_dos;

    // Append value 10 times
    for (int i = 0; i < 752; ++i) {
        level_dos.push_back(72);
    }


    TileMap MapLayer;
    if (!MapLayer.load("../src/assets/Texture/TX_props.png", { 32, 32 }, level_dos.data(), 6, 6))
        return -1;


    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Render the SFML window
        window.clear();



        
        // window.draw(sprite);


        window.draw(map);
        window.draw(MapLayer);
        window.display();
    }

    return 0;
}
