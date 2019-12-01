#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include "tile.h"

class Block {
    int orientation;
    Grid *grid;
    Tile *tiles[4];
    int xPos;
    int yPos;
    public:
    virtual void clockWise() = 0;
    virtual void counterClockWise() = 0;
    void left();
    void right();
    void down();
    void drop();
    Block(int orientation, Grid grid, Tile tiles, int xPos, int yPos);
    ~Block();
}

#endif
