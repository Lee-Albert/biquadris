#include "levelOne.h"
#include <string>
#include <cstdlib>
using namespace std;

LevelOne::LevelOne(string filename, Grid *grid, int seed): Level(filename, grid, seed) {
    filestream.open(filename);
    random = true;
    points = 1;
}

Block *LevelOne::generateBlock(){
    Block *addBlock;
    srand(seed);
    int blockChoice = rand() % 12;
    if (blockChoice == 0){
        addBlock = new SBlock(1, *grid, 0, 3, 1);
    } else if (blockChoice == 1){
        addBlock = new ZBlock(1, *grid, 0, 3, 1);
    } else if (blockChoice == 2 || blockChoice == 3){
        addBlock = new IBlock(1, *grid, 0, 3, 1);
    } else if (blockChoice == 4 || blockChoice == 5){
        addBlock = new LBlock(1, *grid, 0, 3, 1);
    } else if (blockChoice == 6 || blockChoice == 7){
        addBlock = new JBlock(1, *grid, 0, 3, 1);
    } else if (blockChoice == 8 || blockChoice == 9){
        addBlock = new TBlock(1, *grid, 0, 3, 1);
    } else if (blockChoice == 10 || blockChoice == 11){
        addBlock = new OBlock(1, *grid, 0, 3, 1);
    } 
    
    return addBlock;
}

Block *LevelOne::forceBlock(string blockname){
    Block *addBlock;
    if (blockname == "I"){
        addBlock = new IBlock(1, *grid, 0, 3, 1);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, *grid, 0, 3, 1);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, *grid, 0, 3, 1);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, *grid, 0, 3, 1);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, *grid, 0, 3, 1);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, *grid, 0, 3, 1);
    } else {
        addBlock = new ZBlock(1, *grid, 0, 3, 1);
    }
    return addBlock;
}

Block *LevelOne::makeCentreBlock(){
    return nullptr;
}

LevelOne::~LevelOne() {}