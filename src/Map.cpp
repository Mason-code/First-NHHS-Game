#include "Map.h"
#include <iostream>

Map::Map(const std::string& texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading map texture from path: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(2.0f, 2.0f);  // Scale map if needed
}

void Map::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
