#ifndef AIPLAYER_H
#define AIPLAYER_H

/*
* This class is an AI class. It does all its moves without userinput.
*/

#include "player.h"
#include "playingfield.h"
#include <cstdlib>
using namespace std;

// Inherit from the player class.
class AIPlayer : public Player
{
public:
    AIPlayer()
    {
        // Providing a seed value
        srand((unsigned) time(NULL));

        setPlayerName("AI Player");

        //Set a random char.
        setPlayerChar((rand() % 94 )+ 33);
    }
    // This funtion will place the char on the playing field.
    void placeChar(PlayingField *field)
    {
        srand((unsigned) time(NULL));
        int pos1,pos2;

        pos1 = rand()%3;
        pos2 = rand()%3;

        cout << pos1 << pos2 << endl;
        field->setField(getPlayerChar(),pos1,pos2);
    }
};

#endif // AIPLAYER_H
