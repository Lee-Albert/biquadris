#include "graphicsdisplay.h"
#include <string>
using namespace std;

GraphicsDisplay::GraphicsDisplay(): grid1{nullptr}, grid2{nullptr} {
	
};

GraphicsDisplay::~GraphicsDisplay() {
}

void GraphicsDisplay::setGrids(Grid *newGrid1, Grid *newGrid2) {
	grid1 = newGrid1;
	grid2 = newGrid2;
}

void GraphicsDisplay::getNextBlocks(Grid *newGrid1, Grid *newGrid2) {
	nextBlock1 = grid1->getNextBlock()->getName();
	nextBlock2 = grid2->getNextBlock()->getName();
}

void GraphicsDisplay::notify(Subject &whoFrom) {
	// 350(65 - 220 - 65) - 200 - 350(65 - 220 - 65)
	// 20x20 squares
	// 290(145 - 145) - 360 - 50	

	// draw Level strings
	window.drawString(50, 50, "Level:");
	window.drawString(100, 50, to_string(grid1->getLevel()));	

	window.drawString(550 + 50, 50, "Level:");
	window.drawString(550 + 100, 50, to_string(grid2->getLevel()));
	
	// draw score strings
	window.drawString(50, 150, "Score:");
	window.drawString(100, 150, to_string(grid1->getScore()));	

	window.drawString(550 + 50, 150, "Score:");
	window.drawString(550 + 100, 150, to_string(grid2->getScore()));

	// draw highscore strings
	window.drawString(50, 250, "Highscore:");
	// currently same as score
	// window.drawString(100, 250, to_string(grid1->getHighscore()));	

	window.drawString(550 + 50, 250, "Highscore:");
	// currently same as score
	// window.drawString(550 + 100, 250, to_string(grid2->getHighscore()));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			window.fillRectangle(65 + j*20, 290 + i*20, 20, 20, 2); 

			window.fillRectangle(65 + 550 + j*20, 290 + i*20, 20, 20, 2); 
		}	
	}	

}
