#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"
#include <string>
#include <fstream>
using namespace std;

class Level {
    int points;
    string filename;
    ifstream filestream;
    bool random;
    public:
    virtual Block *generateBlock() = 0;
};

#endif
