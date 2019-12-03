#ifndef LEVELZERO_H
#define LEVELZERO_H
#include "level.h"
#include <fstream>
#include <string>

class LevelZero : public Level {
    public:
    Block *generateBlock() override;
    Block *makeCentreBlock() override;
    LevelZero(string filename, Grid *grid, int seed);
    ~LevelZero();
};

#endif
