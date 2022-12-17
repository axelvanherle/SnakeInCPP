#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <iostream>
#include <string>
#include <fstream>

#include "player.h"
#include "playingfield.h"

using namespace std;

namespace AxelTTT {

class PlayGame
{
public:
    // Standard constructor
    PlayGame(string boardName);
    // Deconstructor
    ~PlayGame();

    // Make the player objects
    void makePlayerObjects(void);

    // Getter and Setter.
    void setPlayerValues(Player *newPlayer);
    void getPlayerValues(void);

    // Play the game
    void PlayTicTacToe(void);

    // Saves the field to a file.
    void saveField(void);

private:
    ofstream MyFile;
    Player *player1;
    Player *player2;
    PlayingField field;
};
}
#endif // PLAYGAME_H
