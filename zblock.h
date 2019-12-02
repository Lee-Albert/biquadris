#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"
#include <string>
using namespace std;

class ZBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    ZBlock(int orientation, Grid *grid, int xPos, int yPos);
}

#endif