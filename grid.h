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
	Observer *ob;
	int height = 18;
	int width = 11;
	Level *level;
	int score = 0;
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
	Grid(int player_, std::vector<std::vector<Tile>> theGrid_, TextDisplay *td_, Observer *ob_, int height_ = 18, int width_ = 11, Level *level_, int score = 0, bool isBlind = false, bool isHevay = false, bool isForce = false);
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif