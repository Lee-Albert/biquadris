#include "levelThree.h"
#include <string>
#include <cstdlib>
using namespace std;

LevelThree::LevelThree(string filename, Grid *grid): Level(filename, grid) {
    filestream.open(filename);
    random = true;
    points = 3;
}

Block *LevelThree::generateBlock(){
    Block *addBlock;
    srand(time(NULL));
    int blockChoice = rand() % 9;
    if (blockChoice == 0 || blockChoice == 1){
        addBlock = new SBlock(1, *grid, 0, 3);
    } else if (blockChoice == 2 || blockChoice == 3){
        addBlock = new ZBlock(1, *grid, 0, 3);
    } else if (blockChoice == 4){
        addBlock = new IBlock(1, *grid, 0, 3);
    } else if (blockChoice == 5){
        addBlock = new LBlock(1, *grid, 0, 3);
    } else if (blockChoice == 6){
        addBlock = new JBlock(1, *grid, 0, 3);
    } else if (blockChoice == 7){
        addBlock = new TBlock(1, *grid, 0, 3);
    } else if (blockChoice == 8){
        addBlock = new OBlock(1, *grid, 0, 3);
    }  
    return addBlock;
}

Block *LevelThree::makeCentreBlock(){
    return nullptr;
}

LevelThree::~LevelThree() {}