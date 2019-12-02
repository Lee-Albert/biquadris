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
//class Level;
// class GraphicDisplay;
using namespace std;

class Grid {
	int player;
	vector<vector<Tile>> theGrid;
	TextDisplay *td;
	//Observer *ob;
	int height;
	int width;
	Level *level;
	Block *curBlock;
	Block *nextBlock;
	int score;
	int curLevel;
	bool isBlind;
	bool isHeavy;
	bool isForce;
  public:
	~Grid();
	void init();
	void setObserver(Observer *ob);
	void getNextBlock();
	bool isFull();
	bool heightReached();
	int rowsFull();
	void addRow();
	int getScore();
	void setLevel(int nLevel, Level *levelset);
	int getLevel();
	int getPlayer();
	vector<vector<Tile>> &getGrid();
	Grid(int player, TextDisplay *td);
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
