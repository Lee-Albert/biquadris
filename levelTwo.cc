#include "levelTwo.h"
#include <string>
#include <cstdlib>
using namespace std;

LevelTwo::LevelTwo(string filename, Grid *grid, int seed): Level(filename, grid, seed) {
    filestream.open(filename);
    random = true;
    points = 2;
    srand(seed);
}

Block *LevelTwo::generateBlock(){
    Block *addBlock;
    int blockChoice = rand() % 7;
    if (blockChoice == 0){
        addBlock = new SBlock(1, *grid, 0, 3, 2);
    } else if (blockChoice == 1){
        addBlock = new ZBlock(1, *grid, 0, 3, 2);
    } else if (blockChoice == 2){
        addBlock = new IBlock(1, *grid, 0, 3, 2);
    } else if (blockChoice == 3){
        addBlock = new LBlock(1, *grid, 0, 3, 2);
    } else if (blockChoice == 4){
        addBlock = new JBlock(1, *grid, 0, 3, 2);
    } else if (blockChoice == 5){
        addBlock = new TBlock(1, *grid, 0, 3, 2);
    } else if (blockChoice == 6){
        addBlock = new OBlock(1, *grid, 0, 3, 2);
    }  
    return addBlock;
}

Block *LevelTwo::forceBlock(string blockname){
    Block *addBlock;
    if (blockname == "I"){
        addBlock = new IBlock(1, *grid, 0, 3, 2);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, *grid, 0, 3, 2);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, *grid, 0, 3, 2);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, *grid, 0, 3, 2);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, *grid, 0, 3, 2);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, *grid, 0, 3, 2);
    } else {
        addBlock = new ZBlock(1, *grid, 0, 3, 2);
    }
    return addBlock;
}

Block *LevelTwo::makeCentreBlock(){
    return nullptr;
}

LevelTwo::~LevelTwo() {}