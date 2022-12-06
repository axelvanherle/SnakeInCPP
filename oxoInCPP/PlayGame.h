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
    // Standard constructor
    PlayGame();
    // Deconstructor
    ~PlayGame();

    // Make the player objects
    void makePlayerObjects(void);

    // Getter and Setter.
    void setPlayerValues(void);
    void getPlayerValues(void);

    // Play the game
    void PlayTicTacToe(void);

private:
    Player* player1;
    Player* player2;
};

#endif // PLAYGAME_H
