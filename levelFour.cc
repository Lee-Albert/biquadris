#include "levelFour.h"
#include <string>
#include <cstdlib>
using namespace std;

LevelFour::LevelFour(string filename, Grid *grid, int seed): Level(filename, grid, seed) {
    filestream.open(filename);
    random = true;
    points = 4;
    srand(seed);
}

Block *LevelFour::generateBlock(){
    Block *addBlock;
    if (!random) {
        string blockname;
        if (!(filestream >> blockname)){
            filestream.close();
            filestream.open(filename);
            filestream >> blockname;
        }
        if (blockname == "I"){
            addBlock = new IBlock(1, *grid, 0, 3, 4);
        } else if (blockname == "L"){
            addBlock = new LBlock(1, *grid, 0, 3, 4);
        } else if (blockname == "J"){
            addBlock = new JBlock(1, *grid, 0, 3, 4);
        } else if (blockname == "T"){
            addBlock = new TBlock(1, *grid, 0, 3, 4);
        } else if (blockname == "O"){
            addBlock = new OBlock(1, *grid, 0, 3, 4);
        } else if (blockname == "S"){
            addBlock = new SBlock(1, *grid, 0, 3, 4);
        } else {
            addBlock = new ZBlock(1, *grid, 0, 3, 4);
        }
        return addBlock;
    }
    
    int blockChoice = rand() % 9;
    if (blockChoice == 0 || blockChoice == 1){
        addBlock = new SBlock(1, *grid, 0, 3, 4);
    } else if (blockChoice == 2 || blockChoice == 3){
        addBlock = new ZBlock(1, *grid, 0, 3, 4);
    } else if (blockChoice == 4){
        addBlock = new IBlock(1, *grid, 0, 3, 4);
    } else if (blockChoice == 5){
        addBlock = new LBlock(1, *grid, 0, 3, 4);
    } else if (blockChoice == 6){
        addBlock = new JBlock(1, *grid, 0, 3, 4);
    } else if (blockChoice == 7){
        addBlock = new TBlock(1, *grid, 0, 3, 4);
    } else if (blockChoice == 8){
        addBlock = new OBlock(1, *grid, 0, 3, 4);
    }  
    return addBlock;
}

Block *LevelFour::forceBlock(string blockname){
    Block *addBlock;
    if (blockname == "I"){
        addBlock = new IBlock(1, *grid, 0, 3, 4);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, *grid, 0, 3, 4);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, *grid, 0, 3, 4);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, *grid, 0, 3, 4);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, *grid, 0, 3, 4);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, *grid, 0, 3, 4);
    } else {
        addBlock = new ZBlock(1, *grid, 0, 3, 4);
    }
    return addBlock;
}

Block *LevelFour::makeCentreBlock() {
    Block *centreBlock = new CentreBlock(1, *grid, 5, 3, 4);
    return centreBlock;
}

LevelFour::~LevelFour() {}
