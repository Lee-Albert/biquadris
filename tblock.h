#ifndef TBLOCK_H
#define TBLOCK_H
#include "block.h"
// #include "grid.h"
// #include "tile.h"
#include <string>
using namespace std;

class TBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    void initializeTiles() override;
    TBlock(int orientation, Grid &grid, int xPos, int yPos, int levelCreated);
    ~TBlock();
};

#endif

