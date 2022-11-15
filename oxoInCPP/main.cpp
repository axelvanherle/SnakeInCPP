#include <iostream>
#include <string>

#include "PlayGame.h"

using namespace std;

int main()
{
    PlayGame game;

    cout << "OXO by Axel Vanherle." << endl;

    game.setPlayerValues();
    game.getPlayerValues();
}
