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
