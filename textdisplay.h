#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include <string>
#include "observer.h"
#include "subject.h"
#include "grid.h"
#include "tile.h"
// other #includes

// class Tile;
// class Grid;
class TextDisplay: public Observer {
	std::vector<std::vector<std::string>> player1; // grid of chars
	std::vector<std::vector<std::string>> player2; // grid of chars
	Grid *grid1;
	Grid *grid2;
	const int height = 18;
	const int width = 11;
  public:
	TextDisplay();
	
	void notify(Subject &whoNotified) override;
	
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
