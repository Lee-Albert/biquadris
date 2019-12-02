#include "tile.h"
#include "grid.h"
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

Info Tile::getInfo() const {
	Info tileInfo;
	tileInfo.x = x;
	tileInfo.y = y;
	tileInfo.grid = grid;
	tileinfo.isOccupied = isOccupied();
	tileInfo.curBlock = curBlock;
	return tileInfo;
}
