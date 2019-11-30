#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    string cmd;
    int difficulty;
    Grid playerOne = Grid();
    Grid playerTwo = Grid();
    bool playerOneTurn = true;
    
    cout << "Player 1, choose your difficulty between 0 and 4: ";
    cin >> difficulty;
    if (difficulty = 0){
        
        playerOne.setLevel(0);
    }
    cout << endl;

    while (cin >> cmd){
        
    }
}
