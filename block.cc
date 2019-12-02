#include "block.h"
#include <map>
#include <string>
#include "block.h"

Tile **Block::getTiles(){
    return tiles;
}

std::string Block::getName(){
    return name;
}

void Block::left() {
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i].y)) {
            checkPos.insert{ tiles[i].y, tiles[i].x };
        } else if ((checkPos.find(tiles[i].y)->second) > tiles[i].x) {
            checkPos.at(tiles[i].y) = tiles[i].x;
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
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i].y) && checkPos.find(tiles[i].y)->second != tiles[i].x) {
            checkPos.insert({ tiles[i].y, tiles[i].x });
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
    xPos--;
}

void Block::right() {
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i].y)) {
            checkPos.insert({ tiles[i].y, tiles[i].x });
        } else if (tiles[i].x > (checkPos.find(tiles[i].y)->second)) {
            checkPos.at(tiles[i].y) = tiles[i].x;
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
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i].y) && checkPos.find(tiles[i].y)->second != tiles[i].x) {
            checkPos.insert({ tiles[i].y, tiles[i].x });
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
    xPos++;
}

void Block::down() {
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i].x)) {
            checkPos.insert({ tiles[i].x, tiles[i].y });
        } else if ((checkPos.find(tiles[i].x)->second) > tiles[i].y ) {
            checkPos.at(tiles[i].x) = tiles[i].y;
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
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i].x) && checkPos.find(tiles[i].x)->second != tiles[i].y) {
            checkPos.insert({ tiles[i].x, tiles[i].y });
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
    yPos--;
}

void Block::drop() {
    int downNum = 0; // Number of tiles to move down by
    bool doneCount = false;

    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i].x)) {
            checkPos.insert({ tiles[i].x, tiles[i].y });
        } else if ((checkPos.find(tiles[i].x)->second) > tiles[i].y ) {
            checkPos.at(tiles[i].x) = tiles[i].y;
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
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i].x) && checkPos.find(tiles[i].x)->second != tiles[i].y) {
            checkPos.insert({ tiles[i].x, tiles[i].y });
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
    yPos -= downNum;
}


Block::Block(int orientation, Grid &grid, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
