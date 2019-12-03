#include "sblock.h"
#include "grid.h"

void TBlock::clockWise(){
    if (orientation == 1) {		
    	    if (validTile(*tiles[0], tiles[0]->getY()-2, tiles[0]->getX()) &&
    	    	validTile(*tiles[1], tiles[1]->getY()-1, tiles[1]->getX()-1) &&
    	    	validTile(*tiles[2], tiles[2]->getY(), tiles[2]->getX()) &&
    	    	validTile(*tiles[3], tiles[3]->getY()+1, tiles[3]->getX()-1)) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()-2][tiles[0]->getX()])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()-2][tiles[0]->getX()]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()-1][tiles[1]->getX()-1])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()-1][tiles[1]->getX()-1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()+1][tiles[3]->getX()-1])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()+1][tiles[3]->getX()-1]);

                }
    	} else if (orientation == 2) {		
    	    if (validTile(*tiles[0], tiles[0]->getY()+1, tiles[0]->getX()+2) &&
    	    	validTile(*tiles[1], tiles[1]->getY(), tiles[1]->getX()+1) &&
    	    	validTile(*tiles[2], tiles[2]->getY()+1, tiles[2]->getX()) &&
    	    	validTile(*tiles[3], tiles[3]->getY(), tiles[3]->getX()-1)) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()+1][tiles[0]->getX()+2])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()+1][tiles[0]->getX()+2]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()+1])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()+1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()+1][tiles[2]->getX()])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()+1][tiles[2]->getX()]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()][tiles[3]->getX()-1])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()][tiles[3]->getX()-1]);

                }
    	} else if (orientation == 3) {		
    	    if (validTile(*tiles[0], tiles[0]->getY()+1, tiles[0]->getX()-1) &&
    	    	validTile(*tiles[1], tiles[1]->getY(), tiles[1]->getX()) &&
    	    	validTile(*tiles[2], tiles[2]->getY()-1, tiles[2]->getX()-1) &&
    	    	validTile(*tiles[3], tiles[3]->getY()-2, tiles[3]->getX())) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()+1][tiles[0]->getX()-1])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()+1][tiles[0]->getX()-1]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()-1][tiles[2]->getX()-1])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()-1][tiles[2]->getX()-1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()-2][tiles[3]->getX()])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()-2][tiles[3]->getX()]);

                }
    	} else if (orientation == 4) {		
    	    if (validTile(*tiles[0], tiles[0]->getY(), tiles[0]->getX()-1) &&
    	    	validTile(*tiles[1], tiles[1]->getY()+1, tiles[1]->getX()) &&
    	    	validTile(*tiles[2], tiles[2]->getY(), tiles[2]->getX()+1) &&
    	    	validTile(*tiles[3], tiles[3]->getY()+1, tiles[3]->getX()+2)) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()][tiles[0]->getX()-1])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()][tiles[0]->getX()-1]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()+1][tiles[1]->getX()])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()+1][tiles[1]->getX()]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()+1])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()+1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()+1][tiles[3]->getX()+2])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()+1][tiles[3]->getX()+2]);

                }
    	}
}

void TBlock::counterClockWise(){
    if (orientation == 1) {		
    	    if (validTile(*tiles[0], tiles[0]->getY(), tiles[0]->getX()+1) &&
    	    	validTile(*tiles[1], tiles[1]->getY()-1, tiles[1]->getX()) &&
    	    	validTile(*tiles[2], tiles[2]->getY(), tiles[2]->getX()-1) &&
    	    	validTile(*tiles[3], tiles[3]->getY()-1, tiles[3]->getX()-2)) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()][tiles[0]->getX()+1])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()][tiles[0]->getX()+1]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()-1][tiles[1]->getX()])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()-1][tiles[1]->getX()]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()-1])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()-1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()-1][tiles[3]->getX()-2])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()-1][tiles[3]->getX()-2]);
                }
    	} else if (orientation == 2) {		
    	    if (validTile(*tiles[0], tiles[0]->getY()+2, tiles[0]->getX()) &&
    	    	validTile(*tiles[1], tiles[1]->getY()+1, tiles[1]->getX()+1) &&
    	    	validTile(*tiles[2], tiles[2]->getY(), tiles[2]->getX()) &&
    	    	validTile(*tiles[3], tiles[3]->getY()-1, tiles[3]->getX()+1)) {
                    
                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()+2][tiles[0]->getX()])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()+2][tiles[0]->getX()]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()+1][tiles[1]->getX()+1])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()+1][tiles[1]->getX()+1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()][tiles[2]->getX()]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()-1][tiles[3]->getX()+1])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()-1][tiles[3]->getX()+1]);
                    
                }
    	} else if (orientation == 3) {		
    	    if (validTile(*tiles[0], tiles[0]->getY()-1, tiles[0]->getX()-2) &&
    	    	validTile(*tiles[1], tiles[1]->getY(), tiles[1]->getX()-1) &&
    	    	validTile(*tiles[2], tiles[2]->getY()-1, tiles[2]->getX()) &&
    	    	validTile(*tiles[3], tiles[3]->getY(), tiles[3]->getX()+1)) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()-1][tiles[0]->getX()-2])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()-1][tiles[0]->getX()-2]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()-1])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()-1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()-1][tiles[2]->getX()])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()-1][tiles[2]->getX()]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()][tiles[3]->getX()+1])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()][tiles[3]->getX()+1]);
                    
                }
    	} else if (orientation == 4) {		
    	    if (validTile(*tiles[0], tiles[0]->getY()-1, tiles[0]->getX()+1) &&
    	    	validTile(*tiles[1], tiles[1]->getY(), tiles[1]->getX()) &&
    	    	validTile(*tiles[2], tiles[2]->getY()+1, tiles[2]->getX()+1) &&
    	    	validTile(*tiles[3], tiles[3]->getY()+2, tiles[3]->getX())) {
                    
                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()()[tiles[0]->getY()+1][tiles[0]->getX()-1])
                    tiles[0] = &(grid.getGrid()()[tiles[0]->getY()+1][tiles[0]->getX()-1]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()])
                    tiles[1] = &(grid.getGrid()()[tiles[1]->getY()][tiles[1]->getX()]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()()[tiles[2]->getY()+1][tiles[2]->getX()+1])
                    tiles[2] = &(grid.getGrid()()[tiles[2]->getY()+1][tiles[2]->getX()+1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()()[tiles[3]->getY()]+2[tiles[3]->getX()])
                    tiles[4] = &(grid.getGrid()()[tiles[3]->getY()+2][tiles[3]->getX()]);

                }
    	}
}
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
