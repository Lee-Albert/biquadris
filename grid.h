#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "tile.h"
#include "observer.h"
// other #includes
#include "textdisplay.h"
#include "graphicdisplay.h"


class Grid {
	int player;
	std::vector<std::vector<Tile>> theGrid;
	TextDisplay *td;
	//Observer *ob;
	int height;
	int width;
	Level *level;
	int score;
	int curLevel;
	bool isBlind = false;
	bool isHeavy = false;
	bool isForce = false;
  public:
	~Grid();
	void reset();
	void setObserver(Observer *ob);
	bool isFull();
	bool heightReached();
	int rowsFull();
	void addRow();
	int getScore();
	void setLevel(int nLevel, Level *levelset);
	Level *getLevel();
	Grid(int player, TextDisplay *td, int height = 18, int width = 11, int score = 0, bool isBlind = false, bool isHevay = false, bool isForce = false);
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif