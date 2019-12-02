#include "block.h"
#include "tile.h"
#include <map>

Tile **Block::getTiles(){
    return tiles;
}

void Block::left() {
    // create map of tiles to check
    map<int, int> checkPos;
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (!checkPos.count(it.y)) {
            checkPos.insert({ it.y, it.x });
        } else if ((checkPos.find(it.y)->second) > it.x) {
            checkPos.at(it.y) = it.x;
        }
    }
    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it.second == 0) {
            return;
        } else if (grid.theGrid[it.first][it.second - 1].isOccupied()) {
            return;
        }
    }
}

void Block::right() {
    // create map of tiles to check
    map<int, int> checkPos;
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (!checkPos.count(it.y)) {
            checkPos.insert({ it.y, it.x });
        } else if (it.x > (checkPos.find(it.y)->second)) {
            checkPos.at(it.y) = it.x;
        }
    }
    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it.second == 10) {
            return;
        } else if (grid.theGrid[it.first][it.second + 1].isOccupied()) {
            return;
        }
    }
}

void Block::down() {
    //use observer pattern to check if theres a block underneath
}

void Block::drop() {
    //use observer pattern to check if theres a block underneath
}


Block::Block(int orientation, Grid &grid, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
