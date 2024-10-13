#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(const std::string& texturePath);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;

    // Mason (even though we used the 'Player::yadayada' in the definition I am guessing we dont need it here in the declaration because we are aleardy inside of the class
    void setScale(float x, float y);

private: // you need the 'Player::stuff' to access this elsewhere
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    void handleInput(float deltaTime);
};

#endif
