#ifndef LEVELFOUR_H
#define LEVELFOUR_H
#include <string>
#include "block.h"
#include "level.h"

class LevelFour : public Level {
    public:
    Block *generateBlock() override;
    LevelFour(string fileName, Grid *grid);
};

#endif