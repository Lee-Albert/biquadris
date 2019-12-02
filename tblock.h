#ifndef TBLOCK_H
#define TBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"
#include <string>
using namespace std;

class TBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    TBlock(int orientation, Grid *grid, int xPos, int yPos);
};

#endif
