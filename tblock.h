#ifndef TBLOCK_H
#define TBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"

class TBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    TBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos);
}

#endif