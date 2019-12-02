#include <iostream>
#include "grid.h"
#include "tile.h"

Grid::~Grid() {
	delete td;
	// delete ob;
}

// not finished
void Grid::init() {
    std::vector<std::vector<Tile>> grid; // Intialize grid
    for (int i=0; i < height; i++){ // populates grid with cells
        std::vector<Tile> row;
        for (int j=0; j < width; j++){
            row.emplace_back(Tile(j, i)); 
        }
        grid.emplace_back(row);
    }
    theGrid = grid;
    for (int row=0; row < height; row++){
        for (int col=0; col < width; col++){
            Tile &t = theGrid.at(row).at(col);
            t.attach(td); // Attach textDisplay to each cell
            /*
            if (row > 0){
                t.attach(&theGrid.at(row-1).at(col));
            }
            if (row > 0 && col + 1 < n){
                t.attach(&theGrid.at(row-1).at(col+1));
            }
            if (col + 1 < n){
                t.attach(&theGrid.at(row).at(col+1));
            }
            if (row + 1 < n && col + 1 < n){
                t.attach(&theGrid.at(row+1).at(col+1));
            }
            if (row + 1 < n){
                t.attach(&theGrid.at(row+1).at(col));
            }
            if (row + 1 < n && col > 0){
                t.attach(&theGrid.at(row+1).at(col-1));
            }
            if (col > 0){
                t.attach(&theGrid.at(row).at(col-1));
            }
            if (row > 0 && col > 0){
                t.attach(&theGrid.at(row-1).at(col-1));
            }*/
        }
    }
}

void Grid::setObserver(Observer *ob) {
	//this->ob = ob;
}

/*
bool Grid::isFull() {

}
*/

void Grid::setLevel(int nLevel, Level *levelset) {
	curLevel = nLevel;
	level = levelset;
}

int Grid::getLevel() {
	return curLevel;
}

int Grid::getPlayer() {
    return player;
}

void Grid::nextBlock() {
    Block *curBlock= level->generateBlock();
    Tile **tiles = curBlock->getTiles();
    for (int i=0; i < 4; i++){
        tiles[i]->setFilled(true);
        tiles[i]->setCurblock(curBlock);
    }
}

Grid::Grid(int player, TextDisplay *td): player{player}, td{td}, height{18}, width{11}, score{0}, isBlind{false}, isHeavy{false}, isForce{false}{}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}
