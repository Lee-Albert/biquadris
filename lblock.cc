#include "lblock.h"
#include "block.h"
#include "grid.h"
#include "tile.h"
using namespace std;

void LBlock::clockWise(){

}

void LBlock::counterClockWise(){

}

LBlock::LBlock(int orientation, Grid *grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos), name{"L"}{
    tiles[0] = &grid.at(3).at(0);
    tiles[1] = &grid.at(3).at(1);
    tiles[2] = &grid.at(3).at(2);
    tiles[3] = &grid.at(2).at(2);
}