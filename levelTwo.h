#ifndef LEVELTWO_H
#define LEVELTWO_H
#include <string>
#include "block.h"
#include "level.h"

class LevelTwo : public Level {
    public:
    Block *generateBlock() override;
    Block *makeCentreBlock() override;
    LevelTwo(string fileName, Grid *grid);
    ~LevelTwo();
};

#endif
