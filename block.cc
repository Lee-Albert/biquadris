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


Block::Block(int orientation, Grid *grid, Cell *cells, int xPos, int yPos): this->orientation{orientation}, this->gird{grid}, this->xPos{xPos}, this->yPos{yPos}{};

Block::~Block() {
}
