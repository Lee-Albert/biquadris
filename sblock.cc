#include "sblock.h"
#include "grid.h"

void SBlock::clockWise(){

}

void SBlock::counterClockWise(){

}

SBlock::SBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "S";
    tiles[0] = &(grid.getGrid().at(3).at(0));
    tiles[1] = &(grid.getGrid().at(3).at(1));
    tiles[2] = &(grid.getGrid().at(2).at(1));
    tiles[3] = &(grid.getGrid().at(2).at(2));
}
