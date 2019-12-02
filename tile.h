#ifndef TILE_H
#define TILE_H
#include <string>
#include "subject.h"
#include "observer.h"
using namespace std;

class Block;

class Tile : public Subject {
    bool filled;
    Block *curBlock;
    int x;
    int y;
    public:
    Tile(int xPos, int yPos);
};


#endif
