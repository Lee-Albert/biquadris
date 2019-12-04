#include "level.h"
#include <string>
using namespace std;

Level::Level(string filename, Grid *grid, int seed): filename{filename}, grid{grid}, seed{seed}{}

int Level::getPoints(){
    return points;
}

void Level::setRandom(bool isRandom){
    random = isRandom;
}

void Level::setFile(string newFile){
    filename = newFile;
    filestream.open(filename);
}

Level::~Level(){}