#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

class Map {
public:
    Map(const std::string& texturePath);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
