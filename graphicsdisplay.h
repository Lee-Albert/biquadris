#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "window.h"
#include <iostream>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "grid.h"
#include "tile.h"
#include "block.h"
#include "blockPrint.h"

using namespace std;

class GraphicsDisplay: public Observer {
	Xwindow window{900,700};
	Grid* grid1;
	Grid* grid2;
	string nextBlock1;
	string nextBlock2;
	int height = 18;
	int width = 11;
  public:
	GraphicsDisplay();
	~GraphicsDisplay();
	void setGrids(Grid *newGrid1, Grid *newGrid2);
	void getNextBlocks(Grid *grid1, Grid *grid2);
	void notify(Subject &whoFrom) override;

};

#endif
