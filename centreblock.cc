#include "centreblock.h"
#include "grid.h"

void CentreBlock::clockWise(){}

void CentreBlock::counterClockWise(){}

CentreBlock::CentreBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "*";
	colour = 9;
}

void CentreBlock::initializeTiles(){
    tiles[0] = &(grid.getGrid().at(3).at(5));
    tiles[1] = nullptr;
    tiles[2] = nullptr;
    tiles[3] = nullptr;
}
