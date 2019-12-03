#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include <string>
#include "block.h"
#include "level.h"

class LevelThree : public Level {
    public:
    Block *generateBlock() override;
    Block *makeCentreBlock() override;
    LevelThree(string fileName, Grid *grid);
};

#endif