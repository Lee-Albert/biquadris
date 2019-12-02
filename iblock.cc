#include "iblock.h"
#include "block.h"
#include "grid.h"
#include "tile.h"

void IBlock::clockWise(){

}

void IBlock::counterClockWise(){

}

IBlock::IBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos): 
Block(orientation, grid, tiles, xPos, yPos), name{"I"}{
    tiles[0] = &grid.at(3).at(0);
    tiles[1] = &grid.at(3).at(1);
    tiles[2] = &grid.at(3).at(2);
    tiles[3] = &grid.at(3).at(3);
}
    
