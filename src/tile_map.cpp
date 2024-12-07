#include "tile_map.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const float* rotations, unsigned int width, unsigned int height) {
    // Load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // Resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // Populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            // Get the current tile number and rotation
            int tileNumber = tiles[i + j * width];
            float rotation = rotations ? rotations[i + j * width] : 0.f; // Default to 0 if no rotations are provided

            // Skip empty tiles (transparent tiles designated by -1 or a specific value)
            if (tileNumber < 0)
                continue;

            // Find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // Define the quad's corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // Define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

            // Apply rotation
            sf::Transform rotationTransform;
            rotationTransform.rotate(rotation, i * tileSize.x + tileSize.x / 2, j * tileSize.y + tileSize.y / 2);

            for (int k = 0; k < 4; ++k)
                quad[k].position = rotationTransform.transformPoint(quad[k].position);
        }
    }

    return true;
}




void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Apply the transform
    states.transform *= getTransform();

    // Apply the tileset texture
    states.texture = &m_tileset;

    // Draw the vertex array
    target.draw(m_vertices, states);
}
