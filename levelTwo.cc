#include "levelTwo.h"
#include <string>
#include <cstdlib>
using namespace std;

LevelTwo::LevelTwo(string filename, Grid *grid): Level(filename, grid) {
    filestream.open(filename);
    random = true;
    points = 2;
}

Block *LevelTwo::generateBlock(){
    Block *addBlock;
    srand(time(NULL));
    int blockChoice = rand() % 7;
    if (blockChoice == 0){
        addBlock = new SBlock(1, *grid, 0, 3);
    } else if (blockChoice == 1){
        addBlock = new ZBlock(1, *grid, 0, 3);
    } else if (blockChoice == 2){
        addBlock = new IBlock(1, *grid, 0, 3);
    } else if (blockChoice == 3){
        addBlock = new LBlock(1, *grid, 0, 3);
    } else if (blockChoice == 4){
        addBlock = new JBlock(1, *grid, 0, 3);
    } else if (blockChoice == 5){
        addBlock = new TBlock(1, *grid, 0, 3);
    } else if (blockChoice == 6){
        addBlock = new OBlock(1, *grid, 0, 3);
    }  
    return addBlock;
}

Block *LevelTwo::makeCentreBlock(){
    return nullptr;
}