#include "zblock.h"
#include "block.h"
#include "grid.h"
#include "tile.h"
using namespace std;

void ZBlock::clockWise(){

}

void ZBlock::counterClockWise(){

}

ZBlock::ZBlock(int orientation, Grid *grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos) {
    name = "Z";
    tiles[0] = &grid.at(2).at(0);
    tiles[1] = &grid.at(2).at(1);
    tiles[2] = &grid.at(3).at(1);
    tiles[3] = &grid.at(3).at(2);
}