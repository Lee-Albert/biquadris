#include <iostream>
#include <algorithm>
#include "grid.h"
using namespace std;

Grid::~Grid() {
	delete td;
    delete gd;
	// delete ob;
}

void Grid::init() {
    std::vector<std::vector<Tile>> grid; // Intialize grid
    for (int i=0; i < height; i++){ // populates grid with cells
        std::vector<Tile> row;
        for (int j=0; j < width; j++){
            row.emplace_back(Tile(j, i, this)); 
        }
        grid.emplace_back(row);
    }
    theGrid = grid;
    for (int row=0; row < height; row++){
        for (int col=0; col < width; col++){
            Tile &t = theGrid.at(row).at(col);
            t.attach(td); // Attach textDisplay to each cell
            if (gd) {
			    t.attach(gd);
            }   
        }
    }
}

void Grid::reset(){
    if (score > highScore){
        highScore = score;
    }
    score = 0;
    isBlind = false;
    isHeavy = false;
    isForce = false;
    curBlock = nullptr;
    nextBlock = nullptr;
    deleteBlocks();
    for (int row=0; row < height; row++){
        for (int col=0; col < width; col++){
            theGrid.at(row).at(col).updateTile(false, nullptr);
        }
    }
}

void Grid::deleteBlocks(){
    for (auto block : blocks){
        delete block;
    }
    blocks.clear();
}

void Grid::setObserver(Observer *ob) {
	// this->ob = ob;
}


void Grid::setLevel(int nLevel, Level *levelset) {
	curLevel = nLevel;
	level = levelset;
}

Block *Grid::getNextBlock(){
    return nextBlock;
}

Block *Grid::getCurBlock(){
    return curBlock;
}

int Grid::getLevel() {
	return curLevel;
}

int Grid::getPlayer() {
    return player;
}

bool Grid::generateNextBlock() {
    Block *newBlock = level->generateBlock();
    //cout << "hello1" << endl;
    blocks.emplace_back(newBlock);
    //cout << "hello2" << endl;
    curBlock = nextBlock;
    nextBlock = newBlock;
    //cout << "hello3" << endl;
    if (curBlock){
        curBlock->initializeTiles();
        Tile **tiles = curBlock->getTiles();
        for (int i=0; i < 4; i++){
            if (tiles[i]->isOccupied()){
                return true;
            }
            tiles[i]->updateTile(true, curBlock);
        }
    }
    return false;
}

bool Grid::replaceCurBlock(string blockname){
    Tile **oldTiles = curBlock->getTiles();
    for (int i=0; i < 4; i++){
        oldTiles[i]->updateTile(false, nullptr);
    }
    blocks.erase(remove(blocks.begin(), blocks.end(), curBlock), blocks.end());
    delete curBlock;

    Block *newBlock = level->forceBlock(blockname);
    blocks.emplace_back(newBlock);
    curBlock = newBlock;
    curBlock->initializeTiles();
    Tile **tiles = curBlock->getTiles();
    for (int i=0; i < 4; i++){
        if (tiles[i]->isOccupied()){
            return true;
        }
        tiles[i]->updateTile(true, curBlock);
    }
    return false;
}

bool Grid::generateCentreBlock() {
    curBlock = level->makeCentreBlock();
    blocks.emplace_back(curBlock);
    curBlock->initializeTiles();
    Tile **tiles = curBlock->getTiles();
    if (tiles[0]->isOccupied()){
        return true;
    }
    tiles[0]->updateTile(true, curBlock);
    return false;
}

int Grid::getScore() {
	return score;
}

vector<vector<Tile>> &Grid::getGrid(){
    return theGrid;
};

Grid::Grid(int player, TextDisplay *td, GraphicsDisplay *gd): player{player}, td{td}, gd{gd}, height{18}, width{11}, score{0}, isBlind{false}, isHeavy{false}, isForce{false}{}
// Grid::Grid(int player, TextDisplay *td): player{player}, td{td}, height{18}, width{11}, score{0}, isBlind{false}, isHeavy{false}, isForce{false}{}

std::ostream &operator<<(std::ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}

int Grid::checkFullRows(){
    int counter = 0;
    bool full;
    vector <int> fullRows;
    for (int row = 0; row < height; row++){
        full = true;
        for (int col = 0; col < width; col++){
            if (!theGrid[row][col].isOccupied()){
                full = false;
                break;
            }
        }
        if (full){
            counter++;
            fullRows.emplace_back(row);
        }
    }
    deleteRows(fullRows);
    if (counter > 0){
        int newPoints = counter + level->getPoints();
        score += newPoints * newPoints;
    }
    return counter;
}

void Grid::deleteRows(vector <int> rows){
    for (auto row : rows){
        vector <Tile> rowToDelete = theGrid.at(row);
        for (auto tile : rowToDelete){
            tile.getBlock()->removeTile(&tile);
        }
        theGrid.erase(theGrid.begin() + row);
        td->deleteRow(row, player);
        // increase all y position of affected rows by 1
        for (int i=0; i < row; i++){
            for (int j=0; j < width; j++){
                theGrid.at(i).at(j).incrementY();
            }
        }
        // add new row at top
        vector<Tile> newRow;
        for (int i=0; i < width; i++){
            newRow.emplace_back(Tile(i, 0, this)); 
        }
        theGrid.insert(theGrid.begin(), newRow);
    }
}

void Grid::setBlind(bool toSet) {
	isBlind = toSet;	
}

void Grid::setHeavy(bool toSet) {
	isHeavy = toSet;
}

void Grid::setForce(bool toSet) {
	isForce = toSet;
}

bool Grid::getBlind() {
	return isBlind;
}

bool Grid::getHeavy() {
	return isHeavy;
}

bool Grid::getForce() {
	return isForce;
}
