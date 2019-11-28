#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"
#include <string>

class Level {
    int points;
    string playerOne;
    string playerTwo;
    bool random;
    public:
    virtual Block generateBlock() = 0;
}

#endif