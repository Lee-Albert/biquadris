#include "iblock.h"
#include "grid.h"

void IBlock::clockWise(){
    if (orientation == 1) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() - 3 + i, tiles[i]->getX() - i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() - 3 + i][tiles[i]->getX() - i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() - 3 + i][tiles[i]->getX() - i]);
        }
		orientation = 2;
    } else if (orientation == 2) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() + 3 - i, tiles[i]->getX() + 3 - i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() + 3 - i][tiles[i]->getX() + 3 - i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() + 3 - i][tiles[i]->getX() + 3 - i]);
        }
		orientation = 3;
    } else if (orientation == 3) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() - i, tiles[i]->getX() - 3 + i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() - i][tiles[i]->getX() - 3 + i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() - i][tiles[i]->getX() - 3 + i]);
        }
		orientation = 4;
    } else if (orientation == 4) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() + i, tiles[i]->getX() + i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() + i][tiles[i]->getX() + i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() + i][tiles[i]->getX() + i]);
        }
		orientation = 1;
    }
}

void IBlock::counterClockWise(){
    if (orientation == 1) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() - i, tiles[i]->getX() - i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() - i][tiles[i]->getX() - i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() - i][tiles[i]->getX() - i]);
        }
		orientation = 4;
    } else if (orientation == 2) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() + 3 - i, tiles[i]->getX() + i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() + 3 - i][tiles[i]->getX() + i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() + 3 - i][tiles[i]->getX() + i]);
        }
		orientation = 1;
    } else if (orientation == 3) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() - 3 + i, tiles[i]->getX() - 3 + i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() - 3 + i][tiles[i]->getX() - 3 + i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() - 3 + i][tiles[i]->getX() - 3 + i]);
        }
		orientation = 2;
    } else if (orientation == 4) {
        for (int i = 0; i < 3; i++) {
            if (!validTile(*tiles[i], tiles[i]->getY() + i, tiles[i]->getX() + 3 - i)) {
                return;
            }
        }
        for (int i = 0; i < 3; i++) {
            grid.getGrid()[tiles[i]->getY()][tiles[i]->getX()].swapTile(grid.getGrid()[tiles[i]->getY() + i][tiles[i]->getX() + 3 - i]);
            tiles[i] = &(grid.getGrid()[tiles[i]->getY() + i][tiles[i]->getX() + 3 - i]);
        }
		orientation = 3;
    }
}

IBlock::IBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "I";
}
    
void IBlock::initializeTiles(){
    tiles[0] = &(grid.getGrid().at(3).at(0));
    tiles[1] = &(grid.getGrid().at(3).at(1));
    tiles[2] = &(grid.getGrid().at(3).at(2));
    tiles[3] = &(grid.getGrid().at(3).at(3));
}