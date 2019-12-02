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
	// change the colours/strings/chars of the board
	// consider which player is being acted on
	// how to acess grids from here
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	std::string spacing = "      "; // 6 spaces
	// out << "Level:" << std::setw(5) << (td.grid1)->getLevel() << spacing << "Level:" << std::setw(5) << (td.grid2)->getLevel() << std::endl;
	// out << "Score:" << setw(5) << (td.grid1)->getScore() << spacing << "Score:" << setw(5) << (td.grid2)->getScore() << std::endl;
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
	
