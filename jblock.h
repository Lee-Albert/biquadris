#ifndef JBLOCK_H
#define JBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"

class JBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    JBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos);
}

#endif
