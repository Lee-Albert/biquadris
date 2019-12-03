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

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
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
    cout << "first step checkpos is " << endl;
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
            } else if (it->second + downNum == 17 && !(grid.getGrid()[it->second + downNum][it->first].isOccupied())) {
                doneCount = true;
                break;
            } else if (grid.getGrid()[it->second + downNum][it->first].isOccupied()) {
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

void Block::removeTile(Tile *tile){
    for (int i = 0; i < 4; i++){
        if (tiles[i]){
            if (tiles[i] == tile){
                tiles[i] = nullptr;
            }
        }
    }
}


Block::Block(int orientation, Grid &grid, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
