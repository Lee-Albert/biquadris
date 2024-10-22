#include "levelZero.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//ctor
LevelZero::LevelZero(string filename, Grid *grid, int seed): Level(filename, grid, seed) {
    filestream.open(filename);
    random = false;
    points = 0;
    srand(seed);
}

// (int orientation, Grid *grid, int xPos, int yPos)
Block *LevelZero::generateBlock(){
    string blockname;
    Block *addBlock;
    if (!(filestream >> blockname)){
        filestream.close();
        filestream.open(filename);
        filestream >> blockname;
    }
    if (blockname == "I"){
        addBlock = new IBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, *grid, 0, 3, 0);
    } else {
        addBlock = new ZBlock(1, *grid, 0, 3, 0);
    }
    return addBlock;
}

Block *LevelZero::makeCentreBlock(){
    return nullptr;
}

Block *LevelZero::forceBlock(string blockname){
    Block *addBlock;
    if (blockname == "I"){
        addBlock = new IBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, *grid, 0, 3, 0);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, *grid, 0, 3, 0);
    } else {
        addBlock = new ZBlock(1, *grid, 0, 3, 0);
    }
    return addBlock;
}

LevelZero::~LevelZero() {}

