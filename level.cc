#include "level.h"
#include <string>
using namespace std;

Level::Level(string filename, Grid *grid): filename{filename}, grid{grid}{}

int Level::getPoints(){
    return points;
}
