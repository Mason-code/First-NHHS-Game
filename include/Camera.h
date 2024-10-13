#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera(sf::RenderWindow& window);
    void update(const sf::Vector2f& playerPosition);
    void apply(sf::RenderWindow& window);

private:
    sf::View view;
    sf::Vector2f center;
};

#endif
