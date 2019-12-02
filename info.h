#ifndef INFO_H
#define INFO_H

class Grid;
class Block;

struct Info {
	int x;
	int y;
	Grid *grid;
	bool isOccupied;
	Block *curBlock;
};

#endif
