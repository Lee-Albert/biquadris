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

void Tile::updateTile(bool newFilled, Block *newCurblock){
    filled = newFilled;
    curBlock = newCurblock;
    this->notifyObservers();
}

Info Tile::getInfo() {
	Info tileInfo;
	tileInfo.x = x;
	tileInfo.y = y;
	tileInfo.grid = grid;
	tileInfo.isOccupied = this->isOccupied();
	tileInfo.curBlock = curBlock;
	return tileInfo;
}

void Tile::swapTile(Tile &other) {
    std::swap(filled, other.filled);
    std::swap(curBlock, other.curBlock);
    this->notifyObservers();
    other.notifyObservers();
}

int Tile::getX() {
    return x;
}

int Tile::getY() {
    return y;
}

Block* Tile::getBlock(){
    return curBlock;
}

void Tile::incrementY(){
    y++;
}

