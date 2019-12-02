#include "block.h"

void Block::left() {
    if (this->xPos > 0) {
        this->xPos--;
    }
}

void Block::right() {
    if (this->xPos < 10) {
        this->xPos++;
    }// Fix this shit
}

void Block::down() {
    //use observer pattern to check if theres a block underneath
}

void Block::drop() {
    //use observer pattern to check if theres a block underneath
}


Block::Block(int orientation, Grid *grid, Tile *tiles, int xPos, int yPos): orientation{orientation}, grid{grid}, xPos{xPos}, yPos{yPos}{};

Block::~Block() {
}
