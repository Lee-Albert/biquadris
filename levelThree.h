#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include <string>
#include "block.h"

class LevelThree : public Level {
    public:
    Block *generateBlock() override;
    LevelThree(string fileName, Grid *grid);
};

#endif