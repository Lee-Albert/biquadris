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
#include "graphicsdisplay.h"
#include "level.h"

// class Level;
class Block;
class Observer;
class TextDisplay;
//class Level;
class GraphicsDisplay;
using namespace std;

class Grid {
	int player;
	vector<vector<Tile>> theGrid;
	TextDisplay *td;
	GraphicsDisplay *gd;
	// Observer *ob;
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
	void reset();
	void setObserver(Observer *ob);
	bool generateNextBlock();
	bool generateCentreBlock();
	bool replaceCurBlock(string blockname);
	Block *getNextBlock();
	Block *getCurBlock();
	bool isFull();
	bool heightReached();
	int checkFullRows();
	void deleteRows(vector <int> rows);
	int getScore();
	void setLevel(int nLevel, Level *levelset);
	int getLevel();
	int getPlayer();
	vector<vector<Tile>> &getGrid();
	Grid(int player, TextDisplay *td, GraphicsDisplay *gd);
	void setBlind(bool toSet);
	bool getBlind();
	void setHeavy(bool toSet);
	bool getHeavy();
	void setForce(bool toSet);
	bool getForce();
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
