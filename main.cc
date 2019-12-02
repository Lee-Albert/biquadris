#include "grid.h"
#include "tile.h"
#include "level.h"
#include "block.h"
#include "info.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
// include all the blocks
// include all the levels
// #include "levelZero.h"
// #include "levelOne.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    string cmd;
    int difficulty;
    TextDisplay *display = new TextDisplay();
    Grid *playerOne = new Grid(1, display);
    playerOne->init();
    Grid *playerTwo = new Grid(2, display);
    playerTwo->init();
    string playerOneFile = "sequence1.txt";
    string playerTwoFile = "sequence2.txt";
    bool playerOneTurn = true;
    
    cout << "Player 1, choose your difficulty between 0 and 4: ";
    cin >> difficulty;
    if (difficulty == 0){
        // Level *level = new LevelZero(playerOneFile);
        // playerOne->setLevel(0, level);
    } else if (difficulty == 1){
        // Level *level = new LevelOne(playerOneFile);
        // playerOne->setLevel(0, level);
    }
    // add more levels
    cout << endl;

    cout << "Player 2, choose your difficulty between 0 and 4: ";
    cin >> difficulty;
    if (difficulty == 0){
        // Level *level = new LevelZero(playerTwoFile);
        // playerTwo->setLevel(0, level);
    } else if (difficulty == 1){
        // Level *level = new LevelOne(playerTwoFile);
        // playerTwo->setLevel(0, level);
    }
    // add more levels
    cout << endl;

    while (cin >> cmd){
        
    }
}
