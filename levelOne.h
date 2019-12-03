#ifndef LEVELONE_H
#define LEVELONE_H
#include <string>
#include "block.h"

class LevelOne : public Level {
    public:
    Block *generateBlock() override;
    LevelOne(string fileName, Grid *grid);
};

#endif
