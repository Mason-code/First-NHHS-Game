#include "Player.h"
#include <iostream>

Player::Player(const std::string& texturePath) : speed(200.0f) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from path: " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(500, 400);
}

void Player::handleInput(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y += speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += speed * deltaTime;

    sprite.move(movement);
}

void Player::update(float deltaTime) {
    handleInput(deltaTime);

    // not sure if it goes here but whatever
    Player::setScale(0.05f, 0.05f);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

// The const keyword indicates that this function does not modify the object's state (i.e., it won't change any member variables of the Player class).
sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

// Mason (because we access a private variable "sprite" we need to add the class, like change ->{'void setScale(float x, float y)' to 'void Player::setScale(float x, float y)'}
void Player::setScale(float x, float y) {
    sprite.setScale(x, y);
}