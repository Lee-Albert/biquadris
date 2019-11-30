#include "textdisplay.h"
#include "subject.h"
#include <vector>

TextDisplay::TextDisplay(): {
	std::vector<std::string> row(width, " ");
	for (int i = 0; i < height; ++i) {
		player1.push_back(row);
		player2.push_back(row);
	}
};

void TextDisplay::notify(Subject &whoNotified) {
	// change the colours/strings/chars of the board
	// consider which player is being acted on
	// how to acess grids from here????
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
	
}
