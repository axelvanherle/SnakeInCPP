
#ifndef PLAYER_H
#define PLAYER_H

/*
 * This is the player class. Gives inheritance to the AI and Human class.
 */

#include <iostream>
#include <string>
#include "playingfield.h"

using namespace std;

namespace AxelTTT {

class Player
{
public:
    // Standard constructor
    Player()
    {
        cout << "Player object made" << endl;
    }

    virtual ~Player()
    {
        cout << "Player object destroyed." << endl;
    }

    // Setter
    inline void setPlayerName(string newName = "iHaveNoName!")
    {
        playerName = newName;
    }

    // Getter
    inline string getPlayerName(void)
    {
        return playerName;
    }

    // Setter
    inline void setPlayerChar(char newChar)
    {
        playerSymbol = newChar;
    }

    // Getter
    inline char getPlayerChar(void)
    {
        return playerSymbol;
    }

    // Virtual function that AI and Human class can overwrite.
    virtual void placeChar(PlayingField *field) = 0;

private:
    string playerName;
    unsigned char playerSymbol;
};
}

#endif // PLAYER_H
