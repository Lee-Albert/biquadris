#include "jblock.h"
#include "grid.h"
#include <string>
#include "grid.h"
using namespace std;

void JBlock::clockWise(){

}

void JBlock::counterClockWise(){

}

JBlock::JBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "J";
}

void JBlock::initializeTiles() {
    tiles[0] = &(grid.getGrid().at(2).at(0));
    tiles[1] = &(grid.getGrid().at(3).at(0));
    tiles[2] = &(grid.getGrid().at(3).at(1));
    tiles[3] = &(grid.getGrid().at(3).at(2));
};