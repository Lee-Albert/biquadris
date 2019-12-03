#include "graphicsdisplay.h"
#include <string>
using namespace std;

GraphicsDisplay::GraphicsDisplay(): grid1{nullptr}, grid2{nullptr} {
	// 350(65 - 220 - 65) - 200 - 350(65 - 220 - 65)
	// 20x20 squares
	// 290(145 - 145) - 360 - 50	

	// // draw Level strings
	// window.drawString(50, 50, "Level:");
	// window.drawString(100, 50, to_string(grid1->getLevel()));	

	// window.drawString(550 + 50, 50, "Level:");
	// window.drawString(550 + 100, 50, to_string(grid2->getLevel()));
	
	// // draw score strings
	// window.drawString(50, 150, "Score:");
	// window.drawString(100, 150, to_string(grid1->getScore()));	

	// window.drawString(550 + 50, 150, "Score:");
	// window.drawString(550 + 100, 150, to_string(grid2->getScore()));

	// // draw highscore strings
	// window.drawString(50, 250, "Highscore:");
	// // currently same as score
	// // window.drawString(100, 250, to_string(grid1->getHighscore()));	

	// window.drawString(550 + 50, 250, "Highscore:");
	// // currently same as score
	// // window.drawString(550 + 100, 250, to_string(grid2->getHighscore()));

	// for (int i = 0; i < height; ++i) {
	// 	for (int j = 0; j < width; ++j) {
	// 		window.fillRectangle(65 + j*20, 290 + i*20, 20, 20, 2); 

	// 		window.fillRectangle(65 + 550 + j*20, 290 + i*20, 20, 20, 2); 
	// 	}	
	// }


	// // draw Level strings
	// window->drawString(50, 50, "Level:");
	// window->drawString(100, 50, to_string(grid1->getLevel()));	

	// window->drawString(550 + 50, 50, "Level:");
	// window->drawString(550 + 100, 50, to_string(grid2->getLevel()));
	
	// // draw score strings
	// window->drawString(50, 150, "Score:");
	// window->drawString(100, 150, to_string(grid1->getScore()));	

	// window->drawString(550 + 50, 150, "Score:");
	// window->drawString(550 + 100, 150, to_string(grid2->getScore()));

	// // draw highscore strings
	// window->drawString(50, 250, "Highscore:");
	// // currently same as score
	// // window.drawString(100, 250, to_string(grid1->getHighscore()));	

	// window->drawString(550 + 50, 250, "Highscore:");
	// // currently same as score
	// // window.drawString(550 + 100, 250, to_string(grid2->getHighscore()));

	// for (int i = 0; i < height; ++i) {
	// 	for (int j = 0; j < width; ++j) {
	// 		window->fillRectangle(65 + j*20, 290 + i*20, 20, 20, 2); 

	// 		window->fillRectangle(65 + 550 + j*20, 290 + i*20, 20, 20, 2); 
	// 	}	
	// }	

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

	// draw borders
	window.drawLine(64, 150, 64, 510);
	window.drawLine(286, 150, 286, 510);

	window.drawLine(64, 149, 286, 149);
	window.drawLine(64, 511, 286, 511);
	
	window.drawLine(64+550, 150, 64+550, 510);
	window.drawLine(286+550, 150, 286+550, 510); 

	window.drawLine(64+550, 149, 286+550, 149);
	window.drawLine(64+550, 511, 286+550, 511);

	// draw Level strings
	window.drawString(50, 50, "Level:");
	window.drawString(100, 50, to_string(grid1->getLevel()));	

	window.drawString(550 + 50, 50, "Level:");
	window.drawString(550 + 100, 50, to_string(grid2->getLevel()));
	
	// draw score strings
	window.drawString(50, 75, "Score:");
	window.fillRectangle(100, 55, 150, 20, 0);
	window.drawString(100, 75, to_string(grid1->getScore()));	

	window.drawString(550 + 50, 75, "Score:");
	window.fillRectangle(550 + 100, 55, 150, 20, 0);
	window.drawString(550 + 100, 75, to_string(grid2->getScore()));

	// draw highscore strings
	window.drawString(50, 100, "Highscore:");
	// currently same as score
	// window.drawString(100, 250, to_string(grid1->getHighscore()));	

	window.drawString(550 + 50, 100, "Highscore:");
	// currently same as score
	// window.drawString(550 + 100, 250, to_string(grid2->getHighscore()));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int colour1 = grid1->getGrid()[i][j].getInfo().curBlock ? grid1->getGrid()[i][j].getInfo().curBlock->getColour() : 0;
			int colour2 = grid2->getGrid()[i][j].getInfo().curBlock ? grid2->getGrid()[i][j].getInfo().curBlock->getColour() : 0;

			window.fillRectangle(65 + j*20, 150 + i*20, 20, 20, colour1); 

			window.fillRectangle(65 + 550 + j*20, 150 + i*20, 20, 20, colour2); 
		}	
	}

	window.drawString(50, 550, "Next block:");
	// window.fillRectangle(50, 600, 80, 80, 0);
	if(grid1) {
		if(grid1->getNextBlock()) {
			if (grid1->getNextBlock()->getName() == "I") {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(50, 600, 80, 20, 5);
			} else if (grid1->getNextBlock()->getName() == "J") {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(50, 580, 20, 20, 4);
				window.fillRectangle(50, 600, 60, 20, 4);
			} else if (grid1->getNextBlock()->getName() == "L") {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(90, 580, 20, 20, 8);
				window.fillRectangle(50, 600, 60, 20, 8);
			} else if (grid1->getNextBlock()->getName() == "S") {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(50, 600, 40, 20, 3);
				window.fillRectangle(70, 580, 40, 20, 3);
			} else if (grid1->getNextBlock()->getName() == "Z") {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(50, 580, 40, 20, 2);
				window.fillRectangle(70, 600, 40, 20, 2);
			} else if (grid1->getNextBlock()->getName() == "T") {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(70, 580, 20, 20, 7);
				window.fillRectangle(50, 600, 60, 20, 7);
			} else {
				window.fillRectangle(50, 580, 80, 80, 0);
				window.fillRectangle(50, 580, 40, 40, 6);
			}
		}
	}
	window.drawString(50+550, 550, "Next block:");
	// window.fillRectangle(50, 600, 80, 80, 0);
	if(grid2) {
		if(grid2->getNextBlock()) {
			if (grid2->getNextBlock()->getName() == "I") {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(50+550, 600, 80, 20, 5);
			} else if (grid2->getNextBlock()->getName() == "J") {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(50+550, 580, 20, 20, 4);
				window.fillRectangle(50+550, 600, 60, 20, 4);
			} else if (grid2->getNextBlock()->getName() == "L") {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(90+550, 580, 20, 20, 8);
				window.fillRectangle(50+550, 600, 60, 20, 8);
			} else if (grid2->getNextBlock()->getName() == "S") {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(50+550, 600, 40, 20, 3);
				window.fillRectangle(70+550, 580, 40, 20, 3);
			} else if (grid2->getNextBlock()->getName() == "Z") {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(50+550, 580, 40, 20, 2);
				window.fillRectangle(70+550, 600, 40, 20, 2);
			} else if (grid2->getNextBlock()->getName() == "T") {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(70+550, 580, 20, 20, 7);
				window.fillRectangle(50+550, 600, 60, 20, 7);
			} else {
				window.fillRectangle(50+550, 580, 80, 80, 0);
				window.fillRectangle(50+550, 580, 40, 40, 6);
			}
		}
	}
}
