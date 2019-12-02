#ifndef LEVELONE_H
#define LEVELONE_H
#include <string>
#include "block.h"

class LevelOne : public Level {
    int points = 1;
    string playerOne;
    string playerTwo;
    bool random = true;
    public:
    Block *generateBlock() override;
    LevelOne(string playerOne, string PlayerTwo);
};

#endif
