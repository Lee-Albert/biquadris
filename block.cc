#include "block.h"
#include "tile.h"
#include <map>

Tile **Block::getTiles(){
    return tiles;
}

void Block::left() {
    // create map of tiles to check
    std::map<int, int> checkPos;
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
    std::map<int, int> checkPos;
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
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (!checkPos.count(it.x)) {
            checkPos.insert({ it.x, it.y });
        } else if ((checkPos.find(it.x)->second) > it.y ) {
            checkPos.at(it.x) = it.y;
        }
    }
    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it.second == 17) {
            return;
        } else if (grid.theGrid[it.second + 1][it.first].isOccupied()) {
            return;
        }
    }
}

void Block::drop() {
    int downNum = 0; // Number of tiles to move down by
    bool doneCount = false;

    // create map of tiles to check
    std::map<int, int> checkPos;
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (!checkPos.count(it.x)) {
            checkPos.insert({ it.x, it.y });
        } else if ((checkPos.find(it.x)->second) > it.y ) {
            checkPos.at(it.x) = it.y;
        }
    }
    while (!doneCount) {
        // Check if position is available for moving
        for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
            if (it.second == 17) {
                doneCount = true;
                break;
            } else if (grid.theGrid[it.second + 1][it.first].isOccupied()) {
                doneCount = true;
                break;
            }
        }
        if (doneCount) {
            break;
        } else {
            downNum++;
        }
    }
}


Block::Block(int orientation, Grid &grid, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
