#ifndef AIPLAYER_H
#define AIPLAYER_H

/*
 * This class is an AI class. It does all its moves without userinput.
 */

#include "player.h"
#include "playingfield.h"
#include <cstdlib>

namespace AxelTTT {

using namespace std;

// Inherit from the player class.
class AIPlayer : public Player
{
public:
    AIPlayer(string name)
    {
        setPlayerName(name);
        // Set a random char.
        setPlayerChar((rand() % 94) + 33);
    }
    // This funtion places the char on the playing field.
    void placeChar(PlayingField *field)
    {
        int pos1, pos2;
        bool isFilled;

        pos1 = rand() % 3;
        pos2 = rand() % 3;

        isFilled = field->setField(getPlayerChar(), pos1, pos2);
        if (isFilled == false)
        {
            while (isFilled == false)
            {
                pos1 = rand() % 3;
                pos2 = rand() % 3;
                isFilled = field->setField(getPlayerChar(), pos1, pos2);
            }
        }
    }
};
}
#endif // AIPLAYER_H

