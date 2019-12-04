#ifndef CENTREBLOCK_H
#define CENTREBLOCK_H
#include "block.h"

class CentreBlock : public Block {
    public:
    void clockWise() override;
    void counterClockWise() override;
    CentreBlock(int orientation, Grid &grid, int xPos, int yPos, int levelCreated);
    void initializeTiles();
};


#endif
