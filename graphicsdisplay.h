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
	// Xwindow window(900,700);
	int height = 18;
	int width = 11;
  public:
	// GraphicsDisplay();
	~GraphicsDisplay();
	void notify(Subject &whoFrom) override;

};

#endif
