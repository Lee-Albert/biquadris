#include "levelZero.h"
#include <string>
#include <fstream>
using namespace std;

//ctor
string filename;
Grid *grid;
LevelZero::LevelZero(string filename, Grid *grid): Level(filename, grid) {
    filestream{filename};
    random = false;
    points = 0;
}

// (int orientation, Grid *grid, Tile tiles, int xPos, int yPos)
Block *LevelZero::generateBlock(){
    string blockname;
    Block *addBlock;
    if (!(filestream >> blockname)){
        filestream.clear()
        filestream{filename};
        filestream >> blockname;
    }
    if (blockname == "I"){
        addBlock = new IBlock(1, );
    } else if (blockname == "L"){
        addBlock = new LBlock();
    } else if (blockname == "J"){
        addBlock = new JBlock();
    } else if (blockname == "T"){
        addBlock = new TBlock();
    } else if (blockname == "O"){
        addBlock = new OBlock();
    } else if (blockname == "S"){
        addBlock = new SBlock();
    } else {
        addBlock = new ZBlock();
    }
    return addBlock;
}
