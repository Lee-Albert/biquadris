#include "grid.h"
#include "tile.h"
#include "level.h"
#include "block.h"
#include "info.h"
#include "textdisplay.h"
#include "graphicdisplay.h"
// include all the blocks
// include all the levels
#include "levelZero.h"
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
        Level *level = new LevelZero(playerOneFile, playerOne);
        playerOne->setLevel(0, level);
    } else if (difficulty == 1){
        //Level *level = new LevelOne(playerOneFile);
        //playerOne->setLevel(0, level);
    }
    // add more levels
    cout << endl;

    cout << "Player 2, choose your difficulty between 0 and 4: ";
    cin >> difficulty;
    if (difficulty == 0){
        Level *level = new LevelZero(playerTwoFile, playerTwo);
        playerTwo->setLevel(0, level);
    } else if (difficulty == 1){
        //Level *level = new LevelOne(playerTwoFile);
        //playerTwo->setLevel(0, level);
    }
    // add more levels
    cout << endl;
    
    playerOne->generateNextBlock();
    playerOne->generateNextBlock();
    playerTwo->generateNextBlock();
    playerTwo->generateNextBlock();

    
    while (true){
        while (!turnOver){
            // Tile **tiles;
            // if (playerOneTurn){
            //     tiles = playerOne->getCurBlock()->getTiles();
            // } else {
            //     tiles = playerTwo->getCurBlock()->getTiles();
            // }
            // for (int i=0; i < 4; i++){
            //     cout << tiles[i]->getX() << " ," << tiles[i]->getY() << endl;
            // }
            std::cout << *display;
			if (!(cin >> cmd)){
                return 0;
            }
            if (cmd == "left") {
                if (playerOneTurn){
                    playerOne->getCurBlock()->left();
                } else {
                    playerTwo->getCurBlock()->left();
                }
            } else if (cmd == "right"){
                if (playerOneTurn){
                    playerOne->getCurBlock()->right();
                } else {
                    playerTwo->getCurBlock()->right();
                }
            } else if (cmd == "drop"){
                if (playerOneTurn){
                    playerOne->getCurBlock()->drop();
                } else {
                    playerTwo->getCurBlock()->drop();
                }
                turnOver = true;
            }
        }
        if (playerOneTurn){
            playerOne->getNextBlock();
            playerOneTurn = false;
        } else {
            playerTwo->getNextBlock();
            playerOneTurn = true;
        }
        turnOver = false;
    }
}
