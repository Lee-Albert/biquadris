#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"
#include "iblock.h"
#include "lblock.h"
#include "jblock.h"
#include "tblock.h"
#include "oblock.h"
#include "sblock.h"
#include "zblock.h"
#include "centreblock.h"
#include <string>
#include <fstream>
using namespace std;

class Grid;

class Level {
    protected:
    int seed;
    string filename;
    Grid *grid;
    ifstream filestream;
    bool random;
    int points;
    public:
    int getPoints();
    void setRandom(bool isRandom);
    void setFile(string newFile);
    Block *forceBlock(string blockname);
    virtual Block *generateBlock() = 0;
    virtual Block *makeCentreBlock() = 0;
    Level(string filename, Grid *grid, int seed);
    virtual ~Level() = 0;
};

#endif
