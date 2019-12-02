#include "oblock.h"
#include "block.h"
#include "grid.h"
#include "tile.h"

void OBlock::clockWise(){

}

void OBlock::counterClockWise(){

}

OBlock::OBlock(int orientation, Grid *grid, Tile tiles, int xPos, int yPos): 
Block(orientation, grid, tiles, xPos, yPos), name{"O"}{
    tiles[0] = &grid.at(2).at(0);
    tiles[1] = &grid.at(2).at(1);
    tiles[2] = &grid.at(3).at(0);
    tiles[3] = &grid.at(3).at(1);
}
