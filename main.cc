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
    bool gameOver = false;

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
    Grid *playerOne;
    Grid *playerTwo;
    if (!textOnly) {
	    GraphicsDisplay *window = new GraphicsDisplay();
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
			} else if (cmd == "I"){
                restartGame(0);
            } else if (cmd == "J"){
                restartGame(0);
            } else if (cmd == "L"){
                restartGame(0);
            } else if (cmd == "T"){
                restartGame(0);
            } else if (cmd == "O"){
                restartGame(0);
            } else if (cmd == "S"){
                restartGame(0);
            } else if (cmd == "Z"){
                restartGame(0);
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
				cin >> cmd;
				if (cmd == "blind") {
					playerTwo->setBlind(true);
					playerOne->getCurBlock()->getTiles()[0]->notifyObservers();	
				} else if (cmd == "heavy") {
					playerTwo->setHeavy(true);
				} else {
					playerTwo->setForce(true);
					cout << "Which block would you like to force. Defaults to Z block for invalid input." << endl;
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
				cin >> cmd;
				if (cmd == "blind") {
					playerOne->setBlind(true);
				} else if (cmd == "heavy") {
					playerOne->setHeavy(true);
				} else {
					playerOne->setForce(true);
					cout << "Which block would you like to force. Defaults to Z block for invalid input." << endl;
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
