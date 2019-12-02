#ifndef TILE_H
#define TILE_H
#include <string>
#include "subject.h"
#include "observer.h"
#include "grid.h"
using namespace std;

class Block;

class Tile : public Subject {
    bool filled;
    Block *curBlock;
    int x;
    int y;
    Grid *grid;
    public:
    Tile(int xPos, int yPos, Grid *grid);
    bool isOccupied();
    void setFilled(bool newFilled);
    void setCurblock(Block *newCurblock);
    int getXPos();
    int getYPos();
    void swapTile();
};


#endif
