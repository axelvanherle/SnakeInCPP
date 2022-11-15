#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
public:
    Player()
    {

    }

    void setPlayerName(string newName)
    {
       playerName = newName;
    }

    string getPlayerName(void)
    {
        return playerName;
    }

    void setplayerChar(char newChar)
    {
        playerSymbol = newChar;
    }

    char getplayerChar(void)
    {
        return playerSymbol;
    }

    virtual void placeChar(void) = 0;

private:
    string playerName;
    char playerSymbol;
};

#endif // PLAYER_H
