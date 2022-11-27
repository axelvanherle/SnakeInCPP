#ifndef PLAYER_H
#define PLAYER_H

/*
* This is the player class. Gives inheritance to the AI and Human class.
*/


#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    Player()
    {

    }

    // Setter
    void setPlayerName(string newName)
    {
       playerName = newName;
    }

    // Getter
    string getPlayerName(void)
    {
        return playerName;
    }

    // Setter
    void setplayerChar(char newChar)
    {
        playerSymbol = newChar;
    }

    // Getter
    char getplayerChar(void)
    {
        return playerSymbol;
    }

    // Virtual function that AI and Human class can overwrite.
    virtual void placeChar(void) = 0;

private:
    string playerName;
    char playerSymbol;
};

#endif // PLAYER_H
