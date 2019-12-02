#include <iostream>
#include <iomanip>
#include "textdisplay.h"
#include <vector>

TextDisplay::TextDisplay(): grid1{nullptr}, grid2{nullptr} {
	std::vector<std::string> row(width, " ");
	for (int i = 0; i < height; ++i) {
		player1.push_back(row);
		player2.push_back(row);
	}
};

void TextDisplay::notify(Subject &whoNotified) {
	int row = whoNotified.getInfo().y;
	int col = whoNotified.getInfo().x;
	int player = (whoNotified.getInfo().grid)->getPlayer();
	if (player == 1) {
		if (whoNotified.getInfo().isOccupied) {
			// uncomment when block is fixed
			// player1[row][col] = (whoNotified.getInfo().curBlock)->getName();
		} else { // unoccupied tile
			player1[row][col] = " ";
		}
	} else { // player2
		if (whoNotified.getInfo().isOccupied) {
			// uncomment when block is fixed
			// player2[row][col] = (whoNotified.getInfo().curBlock)->getName();
		} else { // unoccupied tile
			player2[row][col] = " ";
		}
	}
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	std::string spacing = "      "; // 6 spaces
	// uncomment when getscore is fixed
	out << "Level:" << std::setw(5) << (td.grid1)->getLevel() << spacing << "Level:" << std::setw(5) << (td.grid2)->getLevel() << std::endl;
	out << "Score:" << std::setw(5) << (td.grid1)->getScore() << spacing << "Score:" << std::setw(5) << (td.grid2)->getScore() << std::endl;
	out << "-----------" << spacing << "-----------" << std::endl;
	for (int i = 0; i < td.height; ++i) {
		for (int j = 0; i < td.width; ++j) {
			out << td.player1[i][j];
		}
		out << spacing;
		for (int j = 0; j < td.width; ++j) {
			out << td.player2[i][j];
		}
		out << std::endl;
	}
	out << "-----------" << spacing << "-----------" << std::endl;
	out << "Next:      " << spacing << "Next:      " << std::endl;
	// how to output the next block?
	return out;
}

void TextDisplay::setGrids(Grid *grid1, Grid *grid2){
	grid1 = grid1;
	grid2 = grid2;
}
	
