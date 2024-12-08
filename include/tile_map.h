#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    // Helper to update animations
    void updateAnimations(float deltaTime); // Match the implementation


    // Load the tile map
    bool load(
        const std::string& tileset,
        sf::Vector2u tileSize,
        const int* tiles,
        const float* rotations,
        const std::vector<int>& animations,
        unsigned int width,
        unsigned int height
    );

private:
    // Draw function override for sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // Internal representation of the vertex array and texture
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    

    // Animation-related data
    std::vector<int> m_animations; // Stores animation data
    std::vector<float> m_animationTimers; // Tracks timers for each animated tile
};