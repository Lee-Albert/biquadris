#ifndef SBLOCK_H
#define SBLOCK_H
#include "block.h"
// #include "grid.h"
// #include "tile.h"
#include <string>
using namespace std;

class SBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    void initializeTiles() override;
    SBlock(int orientation, Grid &grid, int xPos, int yPos);
};

#endif
