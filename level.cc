#include "level.h"
#include <string>
using namespace std;

Level::Level(string filename, Grid *grid): filename{filename}, grid{grid}{}

int Level::getPoints(){
    return points;
}

Block *Level::forceBlock(string blockname){
    Block *addBlock;
    if (blockname == "I"){
        addBlock = new IBlock(1, *grid, 0, 3);
    } else if (blockname == "L"){
        addBlock = new LBlock(1, *grid, 0, 3);
    } else if (blockname == "J"){
        addBlock = new JBlock(1, *grid, 0, 3);
    } else if (blockname == "T"){
        addBlock = new TBlock(1, *grid, 0, 3);
    } else if (blockname == "O"){
        addBlock = new OBlock(1, *grid, 0, 3);
    } else if (blockname == "S"){
        addBlock = new SBlock(1, *grid, 0, 3);
    } else {
        addBlock = new ZBlock(1, *grid, 0, 3);
    }
    return addBlock;
}
