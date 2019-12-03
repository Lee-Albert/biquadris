#ifndef LEVELONE_H
#define LEVELONE_H
#include <string>
#include "block.h"
#include "level.h"

class LevelOne : public Level {
    public:
    Block *generateBlock() override;
    Block *makeCentreBlock() override;
    LevelOne(string fileName, Grid *grid, int seed);
    ~LevelOne();
};

#endif
