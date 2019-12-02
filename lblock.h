#ifndef LBLOCK_H
#define LBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"

class LBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    LBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos);
}

#endif