#include <iostream>
#include <string>

#include "player.h"

using namespace std;

int main()
{
    Player axel;

    axel.setPlayerName("Axel");
    axel.setplayerChar('a');

    cout << axel.getplayerChar() << axel.getPlayerName() << endl;
    cout << "OXO by Axel Vanherle." << endl;
}
