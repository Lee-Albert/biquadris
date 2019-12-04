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
	int colour;
    Grid &grid;
    //vector <Tile *> tiles(4, nullptr);
    Tile *tiles[4];
    int xPos;
    int yPos;
    int levelCreated;

    public:
    Tile **getTiles();
    void removeTile(Tile tile);
    std::string getName();
	int getColour();
    bool validTile(Tile curTile, int y, int x);
    virtual void clockWise() = 0;
    virtual void counterClockWise() = 0;
    virtual void initializeTiles() = 0;
    void left();
    void right();
    void down();
    void drop();
    void centreDrop();
    bool checkCleared();
    int getLevelCreated();
    Block(int orientation, Grid &grid, int xPos, int yPos, int levelCreated);
    virtual ~Block();
};

#endif
