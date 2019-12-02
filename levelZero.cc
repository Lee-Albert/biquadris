#include "level.h"
#include "levelZero.h"
#include <string>
#include <fstream>
using namespace std;

//ctor
string filename, Grid *grid
LevelZero::LevelZero(string filename, Grid *grid): Level(filename, grid) {
    filestream{filename};
    random = false;
    points = 0;
}

// (int orientation, Grid *grid, int xPos, int yPos)
Block *LevelZero::generateBlock(){
    string blockname;
    Block *addBlock;
    if (!(filestream >> blockname)){
        filestream.clear()
        filestream{filename};
        filestream >> blockname;
    }
    if (blockname == "I"){
        addBlock = new IBlock(1, grid, 0, 3);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, grid, 0, 3);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, grid, 0, 3);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, grid, 0, 3);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, grid, 0, 3);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, grid, 0, 3);
    } else {
        addBlock = new ZBlock(1, grid, 0, 3);
    }
    return addBlock;
}
