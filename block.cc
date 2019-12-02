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
        if (!checkPos.count(tiles[i]->getY())) {
            checkPos.insert{ tiles[i]->getY(), tiles[i]->getX() };
        } else if ((checkPos.find(tiles[i]->getY())->second) > tiles[i]->getX()) {
            checkPos.at(tiles[i]->getY()) = tiles[i]->getX();
        }
    }

    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it->second == 0) {
            return;
        } else if (grid.theGrid[it->first][it->second - 1].isOccupied()) {
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i]->getY()) && checkPos.find(tiles[i]->getY())->second != tiles[i]->getX()) {
            checkPos.insert({ tiles[i]->getY(), tiles[i]->getX() });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it->first][it->second].swapTile(grid.theGrid[it->first][it->second - 1]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getY() == it->first && tiles[i]->getX() == it->second) {
                tiles[i] = &theGrid[it->first][it->second - 1];
            } 
        }
    }
    xPos--;
}

void Block::right() {
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i]->getY())) {
            checkPos.insert({ tiles[i]->getY(), tiles[i]->getX() });
        } else if (tiles[i]->getX() > (checkPos.find(tiles[i]->getY())->second)) {
            checkPos.at(tiles[i]->getY()) = tiles[i]->getX();
        }
    }
    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it->second == 10) {
            return;
        } else if (grid.theGrid[it->first][it->second + 1].isOccupied()) {
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i]->getY()) && checkPos.find(tiles[i]->getY())->second != tiles[i]->getX()) {
            checkPos.insert({ tiles[i]->getY(), tiles[i]->getX() });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it->first][it->second].swapTile(grid.theGrid[it->first][it->second + 1]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getY() == it->first && tiles[i]->getX() == it->second) {
                tiles[i] = &theGrid[it->first][it->second + 1];
            } 
        }
    }
    xPos++;
}

void Block::down() {
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i]->getX())) {
            checkPos.insert({ tiles[i]->getX(), tiles[i]->getY() });
        } else if ((checkPos.find(tiles[i]->getX())->second) > tiles[i]->getY() ) {
            checkPos.at(tiles[i]->getX()) = tiles[i]->getY();
        }
    }
    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it->second == 17) {
            return;
        } else if (grid.theGrid[it->second + 1][it->first].isOccupied()) {
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (checkPos.count(tiles[i]->getX()) && checkPos.find(tiles[i]->getX())->second != tiles[i]->getY()) {
            checkPos.insert({ tiles[i]->getX(), tiles[i]->getY() });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it->second][it->first].swapTile(grid.theGrid[it->second + 1][it->first]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getX() == it->first && tiles[i]->getY() == it->second) {
                tiles[i] = &theGrid[it->second + 1][it->first];
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
        if (!checkPos.count(tiles[i]->getX())) {
            checkPos.insert({ tiles[i]->getX(), tiles[i]->getY() });
        } else if ((checkPos.find(tiles[i]->getX())->second) > tiles[i]->getY() ) {
            checkPos.at(tiles[i]->getX()) = tiles[i]->getY();
        }
    }
    while (!doneCount) {
        // Check if position is available for moving
        for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
            if (it->second == 17) {
                doneCount = true;
                break;
            } else if (grid.theGrid[it->second + 1][it->first].isOccupied()) {
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
        if (checkPos.count(tiles[i]->getX()) && checkPos.find(tiles[i]->getX())->second != tiles[i]->getY()) {
            checkPos.insert({ tiles[i]->getX(), tiles[i]->getY() });
        }
    }
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        grid.theGrid[it->second][it->first].swapTile(grid.theGrid[it->second + downNum][it->first]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getX() == it->first && tiles[i]->getY() == it->second) {
                tiles[i] = &theGrid[it->second + downNum][it->first];
            } 
        }
    }
    yPos -= downNum;
}


Block::Block(int orientation, Grid &grid, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
