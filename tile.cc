#include "tile.h"
#include <string>
using namespace std;
    
Tile::Tile(int xPos, int yPos, Grid *grid): x{xPos}, y{yPos}, grid{grid}{
    filled = false;
    curBlock = nullptr;
};

bool Tile::isOccupied() {
    return filled;
}

void Tile::setFilled(bool newFilled){
    filled = newFilled;
    this->notifyObservers();
}

void Tile::setCurblock(Block *newCurblock){
    curBlock = newCurblock;
    this->notifyObservers();
}

void Tile::swapTile(Tile &other) {
    std::swap(filled, other.filled);
    std::swap(curBlock, other.curBlock);
    this->notifyObservers();
    other.notifyObservers();
}