#include <iostream>
#include "grid.h"

Grid::~Grid() {
	delete td;
	delete ob;
}

void Grid::setObserver(Observer *ob) {
	this->ob = ob;
}

/*
bool Grid::isFull() {

}
*/

void Grid::setLevel(int nLevel, Level *levelset); {
	curLevel = nLevel;
	level = levelset;
}



Grid::Grid(int player_, std::vector<std::vector<Tile>> theGrid_, TextDisplay *td_, Observer *ob_, int height_ = 18, int width_ = 11, Level *level_, int score = 0, bool isBlind = false, bool isHevay = false, bool isForce = false):player{player_}, theGrid{theGrid_}, td{td_}, ob{ob_}, height{height_}, width{width_}, level{level_}, score{score_}, isBlind{isBlind_}, isHeavy{isHeavy_}, isForce{isForce_}{};
