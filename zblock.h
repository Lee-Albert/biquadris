#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"

class ZBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    ZBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos);
}

#endif