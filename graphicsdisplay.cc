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

	// draw over the special prompt
	window.fillRectangle(310, 200, 300, 600, 0);
	// draw borders
	window.drawLine(64, 150, 64, 510);
	window.drawLine(285, 150, 285, 510);

	window.drawLine(64, 149, 285, 149);
	window.drawLine(64, 510, 285, 510);
	
	window.drawLine(64+550, 150, 64+550, 510);
	window.drawLine(285+550, 150, 285+550, 510); 

	window.drawLine(64+550, 149, 285+550, 149);
	window.drawLine(64+550, 510, 285+550, 510);

	// draw player name plates
	window.drawBigString(65+75, 135, "Player One");
	window.drawBigString(550+65+75, 135, "Player Two"); 

	// draw Level strings
	window.drawString(65, 50, "Level:");
	window.drawString(200, 50, to_string(grid1->getLevel()));	

	window.drawString(550 + 65, 50, "Level:");
	window.drawString(550 + 200, 50, to_string(grid2->getLevel()));
	
	// draw score strings
	window.drawString(65, 75, "Score:");
	window.fillRectangle(200, 60, 150, 20, 0);
	window.drawString(200, 75, to_string(grid1->getScore()));	

	window.drawString(550 + 65, 75, "Score:");
	window.fillRectangle(550 + 200, 60, 150, 20, 0);
	window.drawString(550 + 200, 75, to_string(grid2->getScore()));

	// draw highscore strings
	window.drawString(65, 100, "Highscore:");
	window.fillRectangle(200, 85, 150, 20, 0);
	window.drawString(200, 100, to_string(grid1->getHighscore()));	

	window.drawString(550 + 65, 100, "Highscore:");
	window.fillRectangle(550 + 200, 85, 150, 20, 0);
	window.drawString(550 + 200, 100, to_string(grid2->getHighscore()));

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int colour1 = grid1->getGrid()[i][j].getInfo().curBlock ? grid1->getGrid()[i][j].getInfo().curBlock->getColour() : 0;
			int colour2 = grid2->getGrid()[i][j].getInfo().curBlock ? grid2->getGrid()[i][j].getInfo().curBlock->getColour() : 0;
			if (grid1->getBlind()) {
				if ((j>=2)&&(j<=8)&&(i>=5)&&(i<=14)) {
					window.fillRectangle(65 + j*20, 150 + i*20, 20, 20, 1);
				} else {
					window.fillRectangle(65 + j*20, 150 + i*20, 20, 20, colour1); 
				}
			} else {	
				window.fillRectangle(65 + j*20, 150 + i*20, 20, 20, colour1); 
			}

			if (grid2->getBlind()) {
				if ((j>=2)&&(j<=8)&&(i>=5)&&(i<=14)) {
					window.fillRectangle(65+550+j*20, 150+i*20, 20, 20, 1);
				} else {
					window.fillRectangle(65 + 550 + j*20, 150 + i*20, 20, 20, colour2); 
				}
			} else {
				window.fillRectangle(65 + 550 + j*20, 150 + i*20, 20, 20, colour2); 
			}
		}	
	}

	window.drawString(65, 550, "Next block:");
	if(grid1) {
		if(grid1->getNextBlock()) {
			if (grid1->getNextBlock()->getName() == "I") {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(50+15, 600, 80, 20, 5);
			} else if (grid1->getNextBlock()->getName() == "J") {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(50+15, 580, 20, 20, 4);
				window.fillRectangle(50+15, 600, 60, 20, 4);
			} else if (grid1->getNextBlock()->getName() == "L") {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(90+15, 580, 20, 20, 8);
				window.fillRectangle(50+15, 600, 60, 20, 8);
			} else if (grid1->getNextBlock()->getName() == "S") {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(50+15, 600, 40, 20, 3);
				window.fillRectangle(70+15, 580, 40, 20, 3);
			} else if (grid1->getNextBlock()->getName() == "Z") {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(50+15, 580, 40, 20, 2);
				window.fillRectangle(70+15, 600, 40, 20, 2);
			} else if (grid1->getNextBlock()->getName() == "T") {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(70+15, 580, 20, 20, 7);
				window.fillRectangle(50+15, 600, 60, 20, 7);
			} else {
				window.fillRectangle(50+15, 580, 80, 80, 0);
				window.fillRectangle(50+15, 580, 40, 40, 6);
			}
		}
	}
	window.drawString(65+550, 550, "Next block:");
	if(grid2) {
		if(grid2->getNextBlock()) {
			if (grid2->getNextBlock()->getName() == "I") {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(50+15+550, 600, 80, 20, 5);
			} else if (grid2->getNextBlock()->getName() == "J") {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(50+15+550, 580, 20, 20, 4);
				window.fillRectangle(50+15+550, 600, 60, 20, 4);
			} else if (grid2->getNextBlock()->getName() == "L") {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(90+15+550, 580, 20, 20, 8);
				window.fillRectangle(50+15+550, 600, 60, 20, 8);
			} else if (grid2->getNextBlock()->getName() == "S") {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(50+15+550, 600, 40, 20, 3);
				window.fillRectangle(70+15+550, 580, 40, 20, 3);
			} else if (grid2->getNextBlock()->getName() == "Z") {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(50+15+550, 580, 40, 20, 2);
				window.fillRectangle(70+15+550, 600, 40, 20, 2);
			} else if (grid2->getNextBlock()->getName() == "T") {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(70+15+550, 580, 20, 20, 7);
				window.fillRectangle(50+15+550, 600, 60, 20, 7);
			} else {
				window.fillRectangle(50+15+550, 580, 80, 80, 0);
				window.fillRectangle(50+15+550, 580, 40, 40, 6);
			}
		}
	}
}

void GraphicsDisplay::printSpecial() {
	window.drawString(310, 300, "Choose a special action: blind, heavy, or force");
}

void GraphicsDisplay::printSpecialPrompt() {
	
	window.drawString(310, 315, "force");
	window.drawString(310, 345, "Which block would you like to force?");
	window.drawString(310, 360, "Defaults to Z block for invalid input");
}

void GraphicsDisplay::printPlayer(int player) {
	window.fillRectangle(290, 130, 320, 60, 0);
	if (player == 1) {
		window.drawBigString(400, 150, "Player One's Turn"); 
		window.fillCircle(300, 180, 20, 10);
		
	} else {
		window.drawBigString(400, 150, "Player Two's Turn");
		window.fillCircle(600, 180, 20, 10);
	}
}

void GraphicsDisplay::printWinner(int player) {
	if (player == 1) {
		window.drawBigString(410,100, "Player One wins!");
	} else {
		window.drawBigString(410,100,"Player Two wins!");
	}
}

void GraphicsDisplay::coverWinner() {
	window.fillRectangle(400,90,110,100, 0);
}


