#ifndef OBLOCK_H
#define OBLOCK_H
#include "block.h"
#include "grid.h"
#include "tile.h"
#include <string>
using namespace std;

class OBlock : public Block {
    string name;
    public:
    void clockWise() override;
    void counterClockWise() override;
    OBlock(int orientation, Grid *grid, int xPos, int yPos);
}

#endif