#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    // Load the tile map
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const float* rotations, unsigned int width, unsigned int height);

private:
    // Draw function override for sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray m_vertices; // Vertex array for tiles
    sf::Texture m_tileset;     // Texture for the tileset
};
