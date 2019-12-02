#ifndef IBLOCK_H
#define IBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"


class IBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    IBlock(int orientation, Grid *grid, int xPos, int yPos);
};

#endif
