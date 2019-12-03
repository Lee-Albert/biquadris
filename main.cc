#include "grid.h"
#include "tile.h"
#include "level.h"
#include "block.h"
#include "info.h"
#include "textdisplay.h"
#include "graphicsdisplay.h"
// include all the blocks
// include all the levels
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {

    string cmd;
    int difficulty = 0;
    bool playerOneTurn = true;
    bool turnOver = false;

    string playerOneFile = "sequence1.txt";
    string playerTwoFile = "sequence2.txt";

    bool textOnly = false;

    // NOT IMPLEMENTED
    int seed;
    // int startLevel;

    string cmdLineArg;
    for (int i = 1; i < argc; ++i) {
        cmdLineArg = argv[i];
        if (cmdLineArg == "-text") {
            textOnly = true;
        } else if (cmdLineArg == "-seed") {
            // IMPLEMENT
            stringstream ss(argv[i+1]);
            ss >> seed;
        } else if (cmdLineArg == "-scriptfile1") {
            playerOneFile = argv[i+1];
        } else if (cmdLineArg == "-scriptfile2") {
            playerTwoFile = argv[i+1];
        } else if (cmdLineArg == "-startlevel") {
            // IMPLEMENT
            stringstream ss(argv[i+1]);
            ss >> difficulty;
        }
    }

    TextDisplay *display = new TextDisplay();
	GraphicsDisplay *window = nullptr;
    Grid *playerOne;
    Grid *playerTwo;
    if (!textOnly) {
	    window = new GraphicsDisplay();
        playerOne = new Grid(1, display, window);
        playerTwo = new Grid(2, display, window);
        window->setGrids(playerOne, playerTwo);
    } else {
        playerOne = new Grid(1, display, nullptr);
        playerTwo = new Grid(2, display, nullptr);
    }
    
    display->setGrids(playerOne, playerTwo);
    playerOne->init();
    playerTwo->init();

    // cout << "Player 1, choose your difficulty between 0 and 4: ";
    // cin >> difficulty;
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
    int pOneDropCount = 0;

    // cout << "Player 2, choose your difficulty between 0 and 4: ";
    // cin >> difficulty;
    if (difficulty == 0){
        Level *level = new LevelZero(playerTwoFile, playerTwo);
        playerTwo->setLevel(0, level);
    } else if (difficulty == 1){
        Level *level = new LevelOne(playerTwoFile, playerTwo);
        playerTwo->setLevel(1, level);
    } else if (difficulty == 2){
        Level *level = new LevelTwo(playerTwoFile, playerTwo);
        playerTwo->setLevel(2, level);
    } else if (difficulty == 3){
        Level *level = new LevelThree(playerTwoFile, playerTwo);
        playerTwo->setLevel(3, level);
    } else if (difficulty == 4){
        Level *level = new LevelFour(playerTwoFile, playerTwo);
        playerTwo->setLevel(4, level);
    }
    cout << endl;
    int pTwoDropCount = 0;
    playerOne->generateNextBlock();
    playerOne->generateNextBlock();
    playerTwo->generateNextBlock();
    playerTwo->generateNextBlock();

    
    while (true){
        while (!turnOver){
            if (playerOneTurn){
				if(window) {
					// window->printSpecial();
					window->printPlayer(1);
				}
                cout << "Player One's Turn" << endl;
            } else {
				if(window) {
					// window->printSpecial();
					window->printPlayer(2);
				}
                cout << "Player Two's Turn" << endl;
            }

            cout << *display;
            
			if (!(cin >> cmd)){
                return 0;
            }
            if (cmd == "left") {
                if (playerOneTurn){
                    playerOne->getCurBlock()->left();
                    if (playerOne->getLevel() >= 3){
                        playerOne->getCurBlock()->down();
                    }
                    if (playerOne->getHeavy()){
                        playerOne->getCurBlock()->down();
                    }
                } else {
                    playerTwo->getCurBlock()->left();
                    if (playerTwo->getLevel() >= 3){
                        playerTwo->getCurBlock()->down();
                    }
                    if (playerTwo->getHeavy()){
                        playerTwo->getCurBlock()->down();
                    }
                }
            } else if (cmd == "right"){
                if (playerOneTurn){
                    playerOne->getCurBlock()->right();
                    if (playerOne->getLevel() >= 3){
                        playerOne->getCurBlock()->down();
                    } 
                    if (playerOne->getHeavy()){
                        playerOne->getCurBlock()->down();
                    }
                } else {
                    playerTwo->getCurBlock()->right();
                    if (playerTwo->getLevel() >= 3){
                        playerTwo->getCurBlock()->down();
                    }
                    if (playerTwo->getHeavy()){
                        playerTwo->getCurBlock()->down();
                    }
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
					playerOne->setBlind(false);
                    playerOne->setHeavy(false);
                    playerOne->setForce(false);
                } else {
                    playerTwo->getCurBlock()->drop();
					playerTwo->setBlind(false);
                    playerTwo->setHeavy(false);
                    playerTwo->setForce(false);
                }
                turnOver = true;
            } else if (cmd == "clockwise") {
				if (playerOneTurn) {
					playerOne->getCurBlock()->clockWise();
                    if (playerOne->getLevel() >= 3){
                        playerOne->getCurBlock()->down();
                    }
                    if (playerOne->getHeavy()){
                        playerOne->getCurBlock()->down();
                    }
				} else {
					playerTwo->getCurBlock()->clockWise();
                    if (playerTwo->getLevel() >= 3){
                        playerTwo->getCurBlock()->down();
                    }
                    if (playerTwo->getHeavy()){
                        playerTwo->getCurBlock()->down();
                    }
				}
			} else if (cmd == "counterclockwise") {
				if (playerOneTurn) {
					playerOne->getCurBlock()->counterClockWise();
                    if (playerOne->getLevel() >= 3){
                        playerOne->getCurBlock()->down();
                    }
                    if (playerOne->getHeavy()){
                        playerOne->getCurBlock()->down();
                    }
				} else {
					playerTwo->getCurBlock()->counterClockWise();
                    if (playerTwo->getLevel() >= 3){
                        playerTwo->getCurBlock()->down();
                    }
                    if (playerTwo->getHeavy()){
                        playerTwo->getCurBlock()->down();
                    }
				}	
			}
        }
        int rowsCleared;
        if (playerOneTurn){
            rowsCleared = playerOne->checkFullRows();
			// testing
			// rowsCleared = 4;
            if (playerOne->getLevel() == 4){
                if (rowsCleared > 0) {
                    pOneDropCount = 0;
                } else {
                    pOneDropCount++;
                }
                if (pOneDropCount == 5) {
                    playerOne->generateCentreBlock();
                    playerOne->getCurBlock()->centreDrop();
                    playerOne->checkFullRows();
                    pOneDropCount = 0;
                }
            }
            playerOne->generateNextBlock();
			if (rowsCleared >= 2) {
				string specialcmd;
				cout << "Choose a special action: blind, heavy, or force" << endl;
				if (window) {
					window->printSpecial();
				}	
				cin >> cmd;
				if (cmd == "blind") {
					playerTwo->setBlind(true);
					// to update graphics display
					playerOne->getCurBlock()->getTiles()[0]->notifyObservers();	
				} else if (cmd == "heavy") {
					playerTwo->setHeavy(true);
				} else {
					playerTwo->setForce(true);
					cout << "Which block would you like to force. Defaults to Z block for invalid input." << endl;
					if (window) {
						window->printSpecialPrompt();
					}
                    cin >> cmd;
                    playerTwo->replaceCurBlock(cmd);
				}
			}
            playerOneTurn = false;
        } else {
            rowsCleared = playerTwo->checkFullRows();
            if (playerTwo->getLevel() == 4){
                if (rowsCleared > 0) {
                    pTwoDropCount = 0;
                } else {
                    pTwoDropCount++;
                }
                if (pTwoDropCount == 5) {
                    playerTwo->generateCentreBlock();
                    playerTwo->getCurBlock()->centreDrop();
                    playerTwo->checkFullRows();
                    pTwoDropCount = 0;
                }
            }
            playerTwo->generateNextBlock();
			if (rowsCleared >= 2) {
				string specialcmd;
				cout << "Choose a special action: blind, heavy, or force" << endl;
				if (window) {
					window->printSpecial();
				}
				cin >> cmd;
				if (cmd == "blind") {
					playerOne->setBlind(true);
				} else if (cmd == "heavy") {
					playerOne->setHeavy(true);
				} else {
					playerOne->setForce(true);
					cout << "Which block would you like to force? Defaults to Z block for invalid input." << endl;
					if (window) {
						window->printSpecialPrompt();
					}
                    cin >> cmd;
                    playerOne->replaceCurBlock(cmd);
				}
			}
            playerOneTurn = true;
        }
        turnOver = false;
    }
}
