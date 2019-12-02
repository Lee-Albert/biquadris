#ifndef SBLOCK_H
#define SBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"

class SBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    SBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos);
}

#endif