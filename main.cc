#include "grid.h"
#include "level.h"
#include "block.h"
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
    bool playerOneTurn = true;
    bool turnOver = false;
    
    TextDisplay *display = new TextDisplay();
    Grid *playerOne = new Grid(1, display);
    Grid *playerTwo = new Grid(2, display);
    display->setGrids(playerOne, playerTwo);
    playerOne->init();
    playerTwo->init();
    string playerOneFile = "sequence1.txt";
    string playerTwoFile = "sequence2.txt";

    
    cout << "Player 1, choose your difficulty between 0 and 4: ";
    cin >> difficulty;
    if (difficulty == 0){
        Level *level = new LevelZero(playerOneFile);
        playerOne->setLevel(0, level);
    } else if (difficulty == 1){
        Level *level = new LevelOne(playerOneFile);
        playerOne->setLevel(0, level);
    }
    // add more levels
    cout << endl;

    cout << "Player 2, choose your difficulty between 0 and 4: ";
    cin >> difficulty;
    if (difficulty == 0){
        Level *level = new LevelZero(playerTwoFile);
        playerTwo->setLevel(0, level);
    } else if (difficulty == 1){
        Level *level = new LevelOne(playerTwoFile);
        playerTwo->setLevel(0, level);
    }
    // add more levels
    cout << endl;
    
    playerOne->nextBlock();
    playerOne->nextBlock();
    playerTwo->nextBlock();
    playerTwo->nextBlock();

    while (true){
        while (!turnOver){
            if (!cin >> cmd){
                return;
            }
            if (cmd == "...") {

            } else if (cmd == "..."){

            } else if (cmd == "drop"){
                ....
                turnOver = true;
            }
        }
        if (playerOneTurn){
            playerOne->nextBlock();
            playerOneTurn = false;
        } else {
            playerTwo->nextBlock();
            playerTwoTurn = false;
        }
        turnOver = false;
    }
}
