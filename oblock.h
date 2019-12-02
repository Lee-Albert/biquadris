#ifndef OBLOCK_H
#define OBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"

class OBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    OBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos);
}

#endif