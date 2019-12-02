#ifndef TILE_H
#define TILE_H
#include <string>
#include "subject.h"
#include "observer.h"
#include "grid.h"
#include "info.h"
using namespace std;

class Block;
class Grid;

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
	Info getInfo() const override;
};


#endif
