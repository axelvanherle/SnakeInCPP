#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <iostream>
#include <string>

#include "humanplayer.h"
#include "aiplayer.h"

using namespace std;

class PlayGame
{
public:
    PlayGame();

    // Getter and Setter.
    void setPlayerValues(void);
    void getPlayerValues(void);

private:
    HumanPlayer player1;
    AIPlayer player2;
};

#endif // PLAYGAME_H
