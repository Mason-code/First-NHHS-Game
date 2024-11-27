#include "mapOne_levelOne.h"
#include <iostream>
#include <vector>
#include "tile_map.h" 
#include <SFML/Graphics.hpp>


// dont forget to define declared variables as extern in the header

/*
std::vector<int> level = {
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3,
    3, 3, 3, 3, 3
};

TileMap map;



std::vector<int> level_dos(752, 72); // Initializes with 752 elements, each set to 72
TileMap MapLayer;

*/



void getMap() {
    if (!map.load("../src/assets/Texture/TX_props.png", { 32, 32 }, level.data(), 5, 5)) {
        std::cout << "Failed to load map!" << std::endl;
    }

    }
}
