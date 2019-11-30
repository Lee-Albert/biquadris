#ifndef LEVELZERO_H
#define LEVELZERO_H
#include "level.h"
#include <fstream>
#include <string>

class levelZero : public Level {
    int points = 0;
    string filename;
    ifstream filestream;
    public:
    Block *generateBlock() override;
    levelZero(string filename);
}

#endif