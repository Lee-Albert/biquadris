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
			if (td.grid1->getBlind()) {
				if ((j >= 2)&&(j <= 8)&&(i >= 5)&&(i <= 14)) {
					out << "?";
				} else {
					out << td.player1.at(i).at(j);
				}
			} else {
				out << td.player1.at(i).at(j);
			}
		}
		out << spacing;
		for (int j = 0; j < td.width; ++j) {
			 if (td.grid2->getBlind()) {
				if ((j >= 2)&&(j <= 8)&&(i >= 5)&&(i <= 14)) {
					out << "?";
				} else {
					out << td.player2.at(i).at(j);
				}
			} else {
				out << td.player2.at(i).at(j);
			}
		}
		out << std::endl;
	}
	out << "-----------" << spacing << "-----------" << std::endl;
	out << "Next:      " << spacing << "Next:      " << std::endl;
	BlockPrint bp;
	vector<string> blockPlayer1;
	vector<string> blockPlayer2;

	if (td.nextBlock1 == "I") {
		blockPlayer1 = bp.IBlock;
	} else if (td.nextBlock1 == "J") {
		blockPlayer1 = bp.JBlock;
	} else if (td.nextBlock1 == "L") {
		blockPlayer1 = bp.LBlock;
	} else if (td.nextBlock1 == "T") {
		blockPlayer1 = bp.TBlock;
	} else if (td.nextBlock1 == "O") {
		blockPlayer1 = bp.OBlock;
	} else if (td.nextBlock1 == "S") {
		blockPlayer1 = bp.SBlock;
	} else if (td.nextBlock1 == "Z") {
		blockPlayer1 = bp.ZBlock;
	}

	if (td.nextBlock2 == "I") {
		blockPlayer2 = bp.IBlock;
	} else if (td.nextBlock2 == "J") {
		blockPlayer2 = bp.JBlock;
	} else if (td.nextBlock2 == "L") {
		blockPlayer2 = bp.LBlock;
	} else if (td.nextBlock2 == "T") {
		blockPlayer2 = bp.TBlock;
	} else if (td.nextBlock2 == "O") {
		blockPlayer2 = bp.OBlock;
	} else if (td.nextBlock2 == "S") {
		blockPlayer2 = bp.SBlock;
	} else if (td.nextBlock2 == "Z") {
		blockPlayer2 = bp.ZBlock;
	}
	out << left << setw(11) << blockPlayer1[0] << spacing << left << setw(11) << blockPlayer2[0] << endl;
	out << left << setw(11) << blockPlayer1[1] << spacing << left << setw(11) << blockPlayer2[1] << endl;
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

void TextDisplay::deleteRow(int row, int player){
	if (player == 1){
		player1.erase(player1.begin() + row);
		vector<string> newRow(width, " ");
		player1.insert(player1.begin(), newRow);
	} else {
		player2.erase(player2.begin() + row);
		vector<string> newRow(width, " ");
		player2.insert(player2.begin(), newRow);
	}
}
