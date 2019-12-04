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
#include <queue>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {

    string cmd;
    int difficulty = 0;
    bool playerOneTurn = true;
    bool turnOver = false;
    bool gameOver = false;

    string playerOneFile = "sequence1.txt";
    string playerTwoFile = "sequence2.txt";
	
	queue<string> playerOneSequence;
	queue<string> playerTwoSequence;

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

    Level *levelP1;
    Level *levelP2;
    // cout << "Player 1, choose your difficulty between 0 and 4: ";
    // cin >> difficulty;
    if (difficulty == 0){
        levelP1 = new LevelZero(playerOneFile, playerOne, seed);
        playerOne->setLevel(0, levelP1);
    } else if (difficulty == 1){
        levelP1 = new LevelOne(playerOneFile, playerOne, seed);
        playerOne->setLevel(1, levelP1);
    } else if (difficulty == 2){
        levelP1 = new LevelTwo(playerOneFile, playerOne, seed);
        playerOne->setLevel(2, levelP1);
    } else if (difficulty == 3){
        levelP1 = new LevelThree(playerOneFile, playerOne, seed);
        playerOne->setLevel(3, levelP1);
    } else if (difficulty == 4){
        levelP1 = new LevelFour(playerOneFile, playerOne, seed);
        playerOne->setLevel(4, levelP1);
    }
    int pOneDropCount = 0;

    // cout << "Player 2, choose your difficulty between 0 and 4: ";
    // cin >> difficulty;
    if (difficulty == 0){
        levelP2 = new LevelZero(playerTwoFile, playerTwo, seed);
        playerTwo->setLevel(0, levelP2);
    } else if (difficulty == 1){
        levelP2 = new LevelOne(playerTwoFile, playerTwo, seed);
        playerTwo->setLevel(1, levelP2);
    } else if (difficulty == 2){
        levelP2 = new LevelTwo(playerTwoFile, playerTwo, seed);
        playerTwo->setLevel(2, levelP2);
    } else if (difficulty == 3){
        levelP2 = new LevelThree(playerTwoFile, playerTwo, seed);
        playerTwo->setLevel(3, levelP2);
    } else if (difficulty == 4){
        levelP2 = new LevelFour(playerTwoFile, playerTwo, seed);
        playerTwo->setLevel(4, levelP2);
    }
    int pTwoDropCount = 0;

    cout << endl;
  
    playerOne->generateNextBlock();
    playerOne->generateNextBlock();
    playerTwo->generateNextBlock();
    playerTwo->generateNextBlock();

    auto restartGame = [&](int winner){
        if (winner == 1){
            cout << "Player 1 wins!" << endl;
        } else if (winner == 2){
            cout << "Player 2 wins!" << endl;
        }
        playerOne->reset();
        playerTwo->reset();
        gameOver = false;
        playerOneTurn = true;
        pOneDropCount = 0;
        pTwoDropCount = 0;
        bool x;
        x = playerOne->generateNextBlock();
        cout << x << endl;
        x = playerOne->generateNextBlock();
        cout << x << endl;
        x = playerTwo->generateNextBlock();
        cout << x << endl;
        x = playerTwo->generateNextBlock();
        cout << x << endl;
    };

    while (true){
        while (!turnOver){
            if (playerOneTurn){
				if(window) {
					window->printPlayer(1);
				}
                cout << "Player One's Turn" << endl;
            } else {
				if(window) {
					window->printPlayer(2);
				}
                cout << "Player Two's Turn" << endl;
            }

            cout << *display;
            
			if (playerOneTurn) {
				if (playerOneSequence.empty()) {
					if (!(cin >> cmd)){
                		return 0;
            		}
				} else {
					cmd = playerOneSequence.front();
					playerOneSequence.pop();	
				}
			} else {
				if (playerTwoSequence.empty()) {
					if (!(cin >> cmd)){
                		return 0;
            		}
				} else {
					cmd = playerTwoSequence.front();
					playerTwoSequence.pop();
				}
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
			} else if (cmd == "restart"){
                restartGame(0);
            } else if (cmd == "I" || cmd == "J" || cmd == "L" || cmd == "T" || 
                        cmd == "O" || cmd == "S" || cmd == "Z"){
                if (playerOneTurn){
                    gameOver = playerOne->replaceCurBlock(cmd);
                    if (gameOver){
                        restartGame(2);
                    }
                } else {
                    gameOver = playerTwo->replaceCurBlock(cmd);
                    if (gameOver){
                        restartGame(1);
                    }
                }
			} else if (cmd == "levelup") {
                if (playerOneTurn) {
                    if (playerOne->getLevel() < 4) {
                        delete levelP1;
                        playerOne->levelUp(playerOneFile, seed);
                    }
                } else {
                    if (playerTwo->getLevel() < 4) {
                        delete levelP2;
                        playerTwo->levelUp(playerTwoFile, seed);
                    }
                }
                continue;
            } else if (cmd == "leveldown") {
                if (playerOneTurn) {
                    if (playerOne->getLevel() > 0) {
                        delete levelP1;
                        playerOne->levelDown(playerOneFile, seed);
                    }
                } else {
                    if (playerTwo->getLevel() > 0) {
                        delete levelP2;
                        playerTwo->levelDown(playerTwoFile, seed);
                    }
                }
                continue;	
			} else if (cmd == "sequence") {
                string file;
                cin >> file;
                ifstream seq(file);
                string queuecmd;
                if (playerOneTurn) {
                    while (seq >> queuecmd) {	
                        playerOneSequence.push(queuecmd);	
                    }			
                } else {
                    while (seq >>queuecmd) {
                        playerTwoSequence.push(queuecmd);
                    }
                }   
            }
        }
        int rowsCleared;
        if (playerOneTurn){
            rowsCleared = playerOne->checkFullRows();
            if (playerOne->getLevel() == 4){
                if (rowsCleared > 0) {
                    pOneDropCount = 0;
                } else {
                    pOneDropCount++;
                }
                if (pOneDropCount == 5) {
                    gameOver = playerOne->generateCentreBlock();
                    if (gameOver){
                        restartGame(2);
                    }
                    playerOne->getCurBlock()->centreDrop();
                    playerOne->checkFullRows();
                    pOneDropCount = 0;
                }
            }
            gameOver = playerOne->generateNextBlock();
            if (gameOver){
                restartGame(2);
            }
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
                    gameOver = playerTwo->replaceCurBlock(cmd);
                    if (gameOver){
                        restartGame(1);
                    }
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
                    gameOver = playerTwo->generateCentreBlock();
                    if (gameOver){
                        restartGame(1);
                    }
                    playerTwo->getCurBlock()->centreDrop();
                    playerTwo->checkFullRows();
                    pTwoDropCount = 0;
                }
            }
            gameOver = playerTwo->generateNextBlock();
            if (gameOver){
                restartGame(1);
            }
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
                    gameOver = playerOne->replaceCurBlock(cmd);
                    if (gameOver){
                        restartGame(2);
                    }
				}
			}
            playerOneTurn = true;
        }
        turnOver = false;
    }
}
