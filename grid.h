#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "tile.h"
// #include "subject.h"
// #include "observer.h"
// #include "block.h"
// other #includes
#include "textdisplay.h"
// #include "graphicdisplay.h"
#include "level.h"

// class Level;
class Block;
class Observer;
class TextDisplay;
// class GraphicDisplay;

class Grid {
	int player;
	std::vector<std::vector<Tile>> theGrid;
	TextDisplay *td;
	//Observer *ob;
	int height;
	int width;
	Level *level;
	Block *curBlock;
	int score;
	int curLevel;
	bool isBlind;
	bool isHeavy;
	bool isForce;
  public:
	~Grid();
	void init();
	void setObserver(Observer *ob);
	void nextBlock();
	bool isFull();
	bool heightReached();
	int rowsFull();
	void addRow();
	int getScore();
	void setLevel(int nLevel, Level *levelset);
	int getLevel();
	int getPlayer();
	Grid(int player, TextDisplay *td);
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
