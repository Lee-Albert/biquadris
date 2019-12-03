#include <iostream>
#include <iomanip>
#include "textdisplay.h"
#include <vector>
#include <string>
using namespace std;

TextDisplay::TextDisplay(): grid1{nullptr}, grid2{nullptr} {
	std::vector<std::string> row(width, " ");
	for (int i = 0; i < height; ++i) {
		player1.push_back(row);
		player2.push_back(row);
	}
};

void TextDisplay::notify(Subject &whoNotified) {
	Info info = whoNotified.getInfo();
	int row = info.y;
	int col = info.x;
	//cout << row << endl;
	int player = (info.grid)->getPlayer();
	if (player == 1) {
		if (info.isOccupied && info.curBlock) {
			player1[row][col] = (info.curBlock)->getName();
			
		} else { // unoccupied tile
			player1[row][col] = " ";
		}
	} else { // player2
		if (info.isOccupied && info.curBlock) {
			player2[row][col] = (info.curBlock)->getName();
		} else { // unoccupied tile
			player2[row][col] = " ";
		}
	}
}

std::ostream &operator<<(std::ostream &out, TextDisplay &td) {
	td.getNextBlocks(td.grid1, td.grid2);
	std::string spacing = "      "; // 6 spaces
	// uncomment when getscore is fixed
	out << "Level:" << std::setw(5) << (td.grid1)->getLevel() << spacing << "Level:" << std::setw(5) << (td.grid2)->getLevel() << std::endl;
	out << "Score:" << std::setw(5) << (td.grid1)->getScore() << spacing << "Score:" << std::setw(5) << (td.grid2)->getScore() << std::endl;
	out << "-----------" << spacing << "-----------" << std::endl;
	for (int i = 0; i < td.height; ++i) {
		for (int j = 0; j < td.width; ++j) {
			out << td.player1.at(i).at(j);
		}
		out << spacing;
		for (int j = 0; j < td.width; ++j) {
			out << td.player2[i][j];
		}
		out << std::endl;
	}
	out << "-----------" << spacing << "-----------" << std::endl;
	out << "Next:      " << spacing << "Next:      " << std::endl;
	out << td.nextBlock1 << "          " << spacing << td.nextBlock2 << std::endl;
	return out;
}

void TextDisplay::setGrids(Grid *newGrid1, Grid *newGrid2){
	grid1 = newGrid1;
	grid2 = newGrid2;
}
	
void TextDisplay::getNextBlocks(Grid *grid1, Grid *grid2){
	nextBlock1 = grid1->getNextBlock()->getName();
	nextBlock2 = grid2->getNextBlock()->getName();
}
