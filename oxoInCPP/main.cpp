#include <iostream>
#include <string>

#include "PlayGame.h"

using namespace std;

int main()
{   
    // Make the game object.
    PlayGame game;

    cout << "OXO by Axel Vanherle." << endl;

    // Set the names of the players.
    game.setPlayerValues();
    game.getPlayerValues();
}
