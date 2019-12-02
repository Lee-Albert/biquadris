#include "iblock.h"
#include "grid.h"

void IBlock::clockWise(){
    
}

void IBlock::counterClockWise(){

}

IBlock::IBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "I";
    tiles[0] = &(grid.getGrid().at(3).at(0));
    tiles[1] = &(grid.getGrid().at(3).at(1));
    tiles[2] = &(grid.getGrid().at(3).at(2));
    tiles[3] = &(grid.getGrid().at(3).at(3));
}
    
