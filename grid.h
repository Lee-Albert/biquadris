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
	std::vector<std::vector<Tile>> theGrid;
	TextDisplay *td = nullptr;
	Observer *ob = nullptr;
	int height = 18;
	int width = 11;
	Level level = nullptr;
	int score = 0;
	bool isBlind = false;
	bool isHeavy = false;
	bool isForce = false;
  public:
	~Grid();

	void init();
	void setObserver(Observer *ob);
	bool isFull();
	bool heightReached();
	int rowsFull();
	void addRow();
	int getScore();
	Level getLevel();

	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
