#include "oblock.h"
#include "grid.h"
using namespace std;

void OBlock::clockWise(){

}

void OBlock::counterClockWise(){

}

OBlock::OBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "O";
	colour = 6;
}

void OBlock::initializeTiles() {
    tiles[0] = &(grid.getGrid().at(2).at(0));
    tiles[1] = &(grid.getGrid().at(2).at(1));
    tiles[2] = &(grid.getGrid().at(3).at(0));
    tiles[3] = &(grid.getGrid().at(3).at(1));
}
