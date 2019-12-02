#ifndef LBLOCK_H
#define LBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"
#include <string>
using namespace std;

class LBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    LBlock(int orientation, Grid *grid, int xPos, int yPos);
}

#endif