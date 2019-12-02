#include "lblock.h"
#include "grid.h"
using namespace std;

void LBlock::clockWise(){

}

void LBlock::counterClockWise(){

}

LBlock::LBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "L";
    tiles[0] = &(grid.getGrid().at(3).at(0));
    tiles[1] = &(grid.getGrid().at(3).at(1));
    tiles[2] = &(grid.getGrid().at(3).at(2));
    tiles[3] = &(grid.getGrid().at(2).at(2));
}
