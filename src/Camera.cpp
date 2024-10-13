#include "Camera.h"

Camera::Camera(sf::RenderWindow& window) {
    view = window.getDefaultView();
}

void Camera::update(const sf::Vector2f& playerPosition) {
    view.setCenter(playerPosition);  // Center the view on the player's position
}

void Camera::apply(sf::RenderWindow& window) {
    window.setView(view);
}
