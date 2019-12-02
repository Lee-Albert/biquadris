#include "tile.h"
#include <string>
using namespace std;
    
Tile::Tile(int xPos, int yPos): x{xPos}, y{yPos}{
    filled = false;
    curBlock = nullptr;
};

void Tile::isOccupied() {
    return filled;
}

