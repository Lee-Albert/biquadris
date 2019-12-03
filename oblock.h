#ifndef OBLOCK_H
#define OBLOCK_H
#include "block.h"
// #include "grid.h"
// #include "tile.h"
#include <string>
using namespace std;

class OBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    void initializeTiles() override;
    OBlock(int orientation, Grid &grid, int xPos, int yPos);
};

#endif
