#include "levelZero.h"
#include <string>
#include <fstream>
using namespace std;

//ctor
LevelZero::LevelZero(string filename): filename{filename}{
    filestream{filename};
}

Block *LevelZero::generateBlock(){
    string blockname;
    Block *addBlock;
    if (!(filestream >> blockname)){
        filestream.clear()
        filestream{filename};
        filestream >> blockname;
    }
    if (blockname == "I"){
        addBlock = new IBlock();
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
