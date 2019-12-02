#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"
#include "grid.h"
#include <string>
#include <fstream>
using namespace std;

class Level {
    int points;
    string filename;
    ifstream filestream;
    Grid *grid;
    bool random;
    public:
    virtual Block *generateBlock() = 0;
    Level(string filename, Grid *grid);
};

#endif
