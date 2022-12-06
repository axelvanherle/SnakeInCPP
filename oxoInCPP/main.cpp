#include <iostream>
#include <string>

#include "PlayGame.h"

using namespace std;

int main()
{   
    // Make the game object.
    PlayGame game;

    cout << "TicTacToe by Axel Vanherle." << endl;

    // Get the names of the players.
    game.setPlayerValues();
    game.getPlayerValues();
}
