#ifndef JBLOCK_H
#define JBLOCK_H
#include "block.h"
// #include "grid.h"
// #include "tile.h"
using namespace std;

class JBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    JBlock(int orientation, Grid *grid, int xPos, int yPos);
};

#endif
