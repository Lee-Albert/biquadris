#ifndef INFO_H
#define INFO_H

#include "grid.h"
#include "block.h"

struct Info {
	int x;
	int y;
	Grid *grid;
	bool isOccupied;
	Block *curBlock;
};

#endif
