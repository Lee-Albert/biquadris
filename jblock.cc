#include "block.h"
#include "grid.h"
#include "tile.h"
#include <string>
using namespace std;

void JBlock::clockWise(){

}

void JBlock::counterClockWise(){

}

JBlock::JBlock(int orientation, Grid *grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos), name{"J"}{
    tiles[0] = &grid.at(2).at(0);
    tiles[1] = &grid.at(3).at(0);
    tiles[2] = &grid.at(3).at(1);
    tiles[3] = &grid.at(3).at(2);
}