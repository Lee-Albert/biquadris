#include "iblock.h"
#include "grid.h"

void IBlock::clockWise(){
    if (orientation == 1) {
            if (validTile(*tiles[0], tiles[0]->getY()-3, tiles[0]->getX()) &&
    	    	validTile(*tiles[1], tiles[1]->getY()-2, tiles[1]->getX()-1) &&
    	    	validTile(*tiles[2], tiles[2]->getY()-1, tiles[2]->getX()-2) &&
    	    	validTile(*tiles[3], tiles[3]->getY(), tiles[3]->getX()-3)) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()-3][tiles[0]->getX()]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()-3][tiles[0]->getX()]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()-2][tiles[1]->getX()-1]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()-2][tiles[1]->getX()-1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()-1][tiles[2]->getX()-2]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()-1][tiles[2]->getX()-2]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()-3]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()-3]);
					
					orientation = 2;
                }
    } else if (orientation == 2) {
        if (validTile(*tiles[0], tiles[0]->getY()+3, tiles[0]->getX()+3) &&
    	    	validTile(*tiles[1], tiles[1]->getY()+2, tiles[1]->getX()+2) &&
    	    	validTile(*tiles[2], tiles[2]->getY()+1, tiles[2]->getX()+1) &&
    	    	validTile(*tiles[3], tiles[3]->getY(), tiles[3]->getX())) {

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()+3][tiles[0]->getX()+3]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()+3][tiles[0]->getX()+3]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()+2][tiles[1]->getX()+2]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()+2][tiles[1]->getX()+2]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()+1][tiles[2]->getX()+1]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()+1][tiles[2]->getX()+1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()]);
					
					orientation = 3;
                }
    } else if (orientation == 3) {
        if (validTile(*tiles[0], tiles[0]->getY(), tiles[0]->getX()-3) &&
    	    	validTile(*tiles[1], tiles[1]->getY()-1, tiles[1]->getX()-2) &&
    	    	validTile(*tiles[2], tiles[2]->getY()-2, tiles[2]->getX()-1) &&
    	    	validTile(*tiles[3], tiles[3]->getY()-3, tiles[3]->getX())) {

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()-3][tiles[3]->getX()]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()-3][tiles[3]->getX()]);

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()-3]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()-3]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()-1][tiles[1]->getX()-2]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()-1][tiles[1]->getX()-2]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()-2][tiles[2]->getX()-1]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()-2][tiles[2]->getX()-1]);

					
					orientation = 4;
                    }
    } else if (orientation == 4) {
        if (validTile(*tiles[0], tiles[0]->getY(), tiles[0]->getX()) &&
    	    	validTile(*tiles[1], tiles[1]->getY()+1, tiles[1]->getX()+1) &&
    	    	validTile(*tiles[2], tiles[2]->getY()+2, tiles[2]->getX()+2) &&
    	    	validTile(*tiles[3], tiles[3]->getY()+3, tiles[3]->getX()+3)) {

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()+3][tiles[3]->getX()+3]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()+3][tiles[3]->getX()+3]);

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()+1][tiles[1]->getX()+1]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()+1][tiles[1]->getX()+1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()+2][tiles[2]->getX()+2]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()+2][tiles[2]->getX()+2]);
					
					orientation = 1;
                    }
    }
}

void IBlock::counterClockWise(){
    if (orientation == 1) {
        if (validTile(*tiles[0], tiles[0]->getY(), tiles[0]->getX()) &&
    	    	validTile(*tiles[1], tiles[1]->getY()-1, tiles[1]->getX()-1) &&
    	    	validTile(*tiles[2], tiles[2]->getY()-2, tiles[2]->getX()-2) &&
    	    	validTile(*tiles[3], tiles[3]->getY()-3, tiles[3]->getX()-3)) {

                    cout << "caused by " << orientation << endl;

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()-1][tiles[1]->getX()-1]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()-1][tiles[1]->getX()-1]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()-2][tiles[2]->getX()-2]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()-2][tiles[2]->getX()-2]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()-3][tiles[3]->getX()-3]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()-3][tiles[3]->getX()-3]);
					
					orientation = 4;
                    }
    } else if (orientation == 2) {
        if (validTile(*tiles[0], tiles[0]->getY()+3, tiles[0]->getX()) &&
    	    	validTile(*tiles[1], tiles[1]->getY()+2, tiles[1]->getX()+1) &&
    	    	validTile(*tiles[2], tiles[2]->getY()+1, tiles[2]->getX()+2) &&
    	    	validTile(*tiles[3], tiles[3]->getY(), tiles[3]->getX()+3)) {

                    cout << "caused by " << orientation << endl;

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()+3]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()+3]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()+1][tiles[2]->getX()+2]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()+1][tiles[2]->getX()+2]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()+2][tiles[1]->getX()+1]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()+2][tiles[1]->getX()+1]);

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()+3][tiles[0]->getX()]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()+3][tiles[0]->getX()]);
					
					orientation = 1;
                    }
    }
    else if (orientation == 3) {
        if (validTile(*tiles[0], tiles[0]->getY()-3, tiles[0]->getX()-3) &&
    	    	validTile(*tiles[1], tiles[1]->getY()-2, tiles[1]->getX()-2) &&
    	    	validTile(*tiles[2], tiles[2]->getY()-1, tiles[2]->getX()-1) &&
    	    	validTile(*tiles[3], tiles[3]->getY(), tiles[3]->getX())) {

                    cout << "caused by " << orientation << endl;

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()-3][tiles[0]->getX()-3]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()-3][tiles[0]->getX()-3]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()-2][tiles[1]->getX()-2]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()-2][tiles[1]->getX()-2]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()-1][tiles[2]->getX()-1]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()-1][tiles[2]->getX()-1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()]);
					
					orientation = 2;
                    }
    } else if (orientation == 4) {
        if (validTile(*tiles[0], tiles[0]->getY(), tiles[0]->getX()+3) &&
    	    	validTile(*tiles[1], tiles[1]->getY()+1, tiles[1]->getX()+2) &&
    	    	validTile(*tiles[2], tiles[2]->getY()+2, tiles[2]->getX()+1) &&
    	    	validTile(*tiles[3], tiles[3]->getY()+3, tiles[3]->getX())) {

                    cout << "caused by " << orientation << endl;

                    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()+3]);
                    tiles[0] = &(grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()+3]);

                    grid.getGrid()[tiles[1]->getY()][tiles[1]->getX()].swapTile(grid.getGrid()[tiles[1]->getY()+1][tiles[1]->getX()+2]);
                    tiles[1] = &(grid.getGrid()[tiles[1]->getY()+1][tiles[1]->getX()+2]);

                    grid.getGrid()[tiles[2]->getY()][tiles[2]->getX()].swapTile(grid.getGrid()[tiles[2]->getY()+2][tiles[2]->getX()+1]);
                    tiles[2] = &(grid.getGrid()[tiles[2]->getY()+2][tiles[2]->getX()+1]);

                    grid.getGrid()[tiles[3]->getY()][tiles[3]->getX()].swapTile(grid.getGrid()[tiles[3]->getY()+3][tiles[3]->getX()]);
                    tiles[3] = &(grid.getGrid()[tiles[3]->getY()+3][tiles[3]->getX()]);
					
					orientation = 3;
                    }
    }
}

IBlock::IBlock(int orientation, Grid &grid, int xPos, int yPos): 
Block(orientation, grid, xPos, yPos){
    name = "I";
	colour = 5;
}
    
void IBlock::initializeTiles(){
    tiles[0] = &(grid.getGrid().at(3).at(0));
    tiles[1] = &(grid.getGrid().at(3).at(1));
    tiles[2] = &(grid.getGrid().at(3).at(2));
    tiles[3] = &(grid.getGrid().at(3).at(3));
}
