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
        Level *level = new LevelOne(playerOneFile, playerOne);
        playerOne->setLevel(1, level);
    } else if (difficulty == 2){
        Level *level = new LevelTwo(playerOneFile, playerOne);
        playerOne->setLevel(2, level);
    } else if (difficulty == 3){
        Level *level = new LevelThree(playerOneFile, playerOne);
        playerOne->setLevel(3, level);
    } else if (difficulty == 4){
        Level *level = new LevelFour(playerOneFile, playerOne);
        playerOne->setLevel(4, level);
    }

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
            if (playerOneTurn){
                cout << "Player One's Turn" << endl;
            } else {
                cout << "Player Two's Turn" << endl;
            }

            cout << *display;
            
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
            } else if (cmd == "down"){
                if (playerOneTurn){
                    playerOne->getCurBlock()->down();
                } else {
                    playerTwo->getCurBlock()->down();
                }
            } else if (cmd == "drop"){
                if (playerOneTurn){
                    playerOne->getCurBlock()->drop();
                } else {
                    playerTwo->getCurBlock()->drop();
                }
                turnOver = true;
            } else if (cmd == "clockwise") {
				if (playerOneTurn) {
					playerOne->getCurBlock()->clockWise();
				} else {
					playerTwo->getCurBlock()->clockWise();
				}
			} else if (cmd == "counterclockwise") {
				if (playerOneTurn) {
					playerOne->getCurBlock()->counterClockWise();
				} else {
					playerTwo->getCurBlock()->counterClockWise();
				}	
			} 
        }
        if (playerOneTurn){
            playerOne->checkFullRows();
            playerOne->generateNextBlock();
            playerOneTurn = false;
        } else {
            playerTwo->checkFullRows();
            playerTwo->generateNextBlock();
            playerOneTurn = true;
        }
        turnOver = false;
    }
}
