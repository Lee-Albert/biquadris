#include "block.h"

void Block::left() {
    if (this->xPos > 0) {
        this->xPos--;
    }
}

void Block::right() {
    if (this->xPos < 10) {
        this->xPos++;
    }
}

void Block::down() {
    //use observer pattern to check if theres a block underneath
}

void Block::drop() {
    //use observer pattern to check if theres a block underneath
}


