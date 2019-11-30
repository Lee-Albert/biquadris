#include "levelZero.h"
#include <string>
#include <fstream>
using namespace std;

//ctor
levelZero::levelZero(string filename): filename{filename}{
    filestream{filename};
}

Block *levelZero::generateBlock(){
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