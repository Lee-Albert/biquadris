#include "block.h"
#include "tile.h"
#include <map>
#include <string>

Tile **Block::getTiles(){
    return tiles;
}

string Block::getName(){
    return name;
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
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (checkPos.count(it.y) && checkPos.find(it.y)->second != it.x) {
            checkPos.insert({ it.y, it.x });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it.first][it.second].swapTile(grid.theGrid[it.first][it.second - 1]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->y == it.first && tiles[i]->x == it.second) {
                tiles[i] = &theGrid[it.first][it.second - 1];
            } 
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
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (checkPos.count(it.y) && checkPos.find(it.y)->second != it.x) {
            checkPos.insert({ it.y, it.x });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it.first][it.second].swapTile(grid.theGrid[it.first][it.second + 1]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->y == it.first && tiles[i]->x == it.second) {
                tiles[i] = &theGrid[it.first][it.second + 1];
            } 
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
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (checkPos.count(it.x) && checkPos.find(it.x)->second != it.y) {
            checkPos.insert({ it.x, it.y });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it.second][it.first].swapTile(grid.theGrid[it.second + 1][it.first]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->x == it.first && tiles[i]->y == it.second) {
                tiles[i] = &theGrid[it.second + 1][it.first];
            } 
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
    for (auto it = tiles.begin(); it != tiles.end(); it++) {
        if (checkPos.count(it.x) && checkPos.find(it.x)->second != it.y) {
            checkPos.insert({ it.x, it.y });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it.second][it.first].swapTile(grid.theGrid[it.second + downNum][it.first]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->x == it.first && tiles[i]->y == it.second) {
                tiles[i] = &theGrid[it.second + downNum][it.first];
            } 
        }
    }
}


Block::Block(int orientation, Grid &grid, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
