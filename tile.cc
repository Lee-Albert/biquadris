#include "tile.h"
#include <string>
using namespace std;
    
Tile::Tile(int xPos, int yPos): x{xPos}, y{yPos}{
    filled = false;
    curBlock = nullptr;
};

bool Tile::isOccupied() {
    return filled;
}

