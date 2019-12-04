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
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"

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
	vector<Block *> blocks;
	TextDisplay *td;
	GraphicsDisplay *gd;
	// Observer *ob;
	int height;
	int width;
	Level *level = nullptr;
	Block *curBlock = nullptr;
	Block *nextBlock = nullptr;
	int score;
	int highScore;
	int curLevel;
	bool isBlind;
	bool isHeavy;
	bool isForce;
	void deleteBlocks();
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
	int checkFullRows();
	void deleteRows(vector <int> rows);
	void noRand(string file);
	void random();
	int getScore();
	void setLevel(int nLevel, Level *levelset);
	void levelUp(string filename, int seed);
	void levelDown(string filename, int seed);
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
