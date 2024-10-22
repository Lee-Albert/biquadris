#include <map>
#include <string>
#include "block.h"
#include "grid.h"
using namespace std;

Tile **Block::getTiles(){
    return tiles;
}

std::string Block::getName(){
    return name;
}

int Block::getColour() {
	return colour;
}

int Block::getLevelCreated(){
    return levelCreated;
}

bool Block::validTile(Tile curTile, int y, int x) {
    // check if space is in bounds
    if (y < 0 || x < 0 || y > 17 || x > 10) {
        return false;
    } else if (!(grid.getGrid()[y][x].isOccupied())) {
        return true;
    } else if (grid.getGrid()[y][x].getBlock() == curTile.getBlock()) {
        return true;
    } else {
        return false;
    }
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second < b.second); 
}

void Block::left() {
    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i]->getY())) {
            checkPos.insert( {tiles[i]->getY(), tiles[i]->getX()} );
        } else if ((checkPos.find(tiles[i]->getY())->second) > tiles[i]->getX()) {
            checkPos.at(tiles[i]->getY()) = tiles[i]->getX();
        }
    }

    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it->second == 0) {
            return;

        } else if (grid.getGrid()[it->first][it->second - 1].isOccupied()) {
            return;
        }
    }
    vector<pair<int,int>> vect;
    for (int i = 0; i < 4; i++) {
        vect.push_back( make_pair(tiles[i]->getY(), tiles[i]->getX()));
    }
    sort(vect.begin(), vect.end(), sortbysec);
    for (auto it = vect.begin(); it != vect.end(); it++) {
        grid.getGrid()[it->first][it->second].swapTile(grid.getGrid()[it->first][it->second - 1]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getY() == it->first && tiles[i]->getX() == it->second) {
                tiles[i] = &(grid.getGrid()[it->first][it->second - 1]);
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
        } else if (grid.getGrid()[it->first][it->second + 1].isOccupied()) {
            return;
        }
    }
    vector<pair<int,int>> vect;
    for (int i = 0; i < 4; i++) {
        vect.push_back( make_pair(tiles[i]->getY(), tiles[i]->getX()));
    }
    sort(vect.rbegin(), vect.rend(), sortbysec);
    for (auto it = vect.begin(); it != vect.end(); it++) {
        grid.getGrid()[it->first][it->second].swapTile(grid.getGrid()[it->first][it->second + 1]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getY() == it->first && tiles[i]->getX() == it->second) {
                tiles[i] = &(grid.getGrid()[it->first][it->second + 1]);
                break;
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
        } else if ((checkPos.find(tiles[i]->getX())->second) < tiles[i]->getY() ) {
            checkPos.at(tiles[i]->getX()) = tiles[i]->getY();
        }
    }
    // Check if position is available for moving
    for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
        if (it->second == 17) {
            return;
        } else if (grid.getGrid()[it->second + 1][it->first].isOccupied()) {
            return;
        }
    }
    vector<pair<int,int>> vect;
    for (int i = 0; i < 4; i++) {
        vect.push_back( make_pair(tiles[i]->getX(), tiles[i]->getY()));
    }
    sort(vect.rbegin(), vect.rend(), sortbysec);
    for (auto it = vect.begin(); it != vect.end(); it++) {
        grid.getGrid()[it->second][it->first].swapTile(grid.getGrid()[it->second + 1][it->first]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getX() == it->first && tiles[i]->getY() == it->second) {
                tiles[i] = &(grid.getGrid()[it->second + 1][it->first]);
            } 
        }
    }
    yPos--;
}

void Block::drop() {
    int downNum = 1; // Number of tiles to move down by
    bool doneCount = false;
    bool move = true;

    // create map of tiles to check
    std::map<int, int> checkPos;
    for (int i = 0; i < 4; i++) {
        if (!checkPos.count(tiles[i]->getX())) {
            checkPos.insert({ tiles[i]->getX(), tiles[i]->getY() });
        } else if ((checkPos.find(tiles[i]->getX())->second) < tiles[i]->getY() ) {
            checkPos.at(tiles[i]->getX()) = tiles[i]->getY();
        }
    }
    while (!doneCount) {
        // Check if position is available for moving
        for (auto it = checkPos.begin(); it != checkPos.end(); it++) {
            if (it->second == 17){
                doneCount = true;
                move = false;
            } else if (it->second + downNum > 17 || grid.getGrid()[it->second + downNum][it->first].isOccupied()) {
                downNum--;
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
    if (!move) {
        return;
    }
    vector<pair<int,int>> vect;
    for (int i = 0; i < 4; i++) {
        vect.push_back( make_pair(tiles[i]->getX(), tiles[i]->getY()));
    }
    sort(vect.rbegin(), vect.rend(), sortbysec);
    
    for (auto it = vect.begin(); it != vect.end(); it++) {
        grid.getGrid()[it->second][it->first].swapTile(grid.getGrid()[it->second + downNum][it->first]);
        for (int i = 0; i < 4; i++) {
            if (tiles[i]->getX() == it->first && tiles[i]->getY() == it->second) {
                tiles[i] = &(grid.getGrid()[it->second + downNum][it->first]);
            } 
        }
    }
    yPos -= downNum;
}

void Block::centreDrop() {
    int downNum = 1; // Number of tiles to move down by
    bool doneCount = false;
    bool move = true;

    while (!doneCount) {
        // Check if position is available for moving
        if (tiles[0]->getY() == 17){
            doneCount = true;
            move = false;
        } else if (tiles[0]->getY() + downNum > 17 || grid.getGrid()[tiles[0]->getY() + downNum][tiles[0]->getX()].isOccupied()) {
            downNum--;
            doneCount = true;
            break;
        }
        if (doneCount) {
            break;
        } else {
            downNum++;
        }
    }
    if (!move) {
        return;
    }
    grid.getGrid()[tiles[0]->getY()][tiles[0]->getX()].swapTile(grid.getGrid()[tiles[0]->getY() + downNum][tiles[0]->getX()]);
    tiles[0] = &(grid.getGrid()[tiles[0]->getY() + downNum][tiles[0]->getX()]);

    yPos -= downNum;
}

void Block::removeTile(Tile tile){
    for (int i = 0; i < 4; i++){
        if (tiles[i]){
            if (tiles[i]->getX() == tile.getX() && tiles[i]->getY() == tile.getY()){
                tiles[i] = nullptr;
                return;
            }
        }
    }
}

bool Block::checkCleared(){
    for (int i=0; i < 4; i++){
        if (tiles[i]){
            return false;
        }
    }
    return true;
}

Block::Block(int orientation, Grid &grid, int xPos, int yPos, int levelCreated): 
orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}, levelCreated{levelCreated}{};

Block::~Block() {}

