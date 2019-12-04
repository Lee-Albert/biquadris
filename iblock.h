#ifndef IBLOCK_H
#define IBLOCK_H
#include "block.h"
// #include "grid.h"
// #include "tile.h"
#include <string>
using namespace std;

class IBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    void initializeTiles() override;
    IBlock(int orientation, Grid &grid, int xPos, int yPos, int levelCreated);
    ~IBlock();
};

#endif
