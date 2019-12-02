#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "tile.h"
//#include "grid.h"

//class Tile;
class Grid;

class Block {
    protected:
    std::string name;
    int orientation;
    Grid &grid;
    //vector <Tile *> tiles(4, nullptr);
    Tile *tiles[4];
    int xPos;
    int yPos;

    public:
    Tile **getTiles();
    std::string getName();
    virtual void clockWise() = 0;
    virtual void counterClockWise() = 0;
    void left();
    void right();
    void down();
    void drop();
    Block(int orientation, Grid &grid, int xPos, int yPos);
    ~Block();
};

#endif
