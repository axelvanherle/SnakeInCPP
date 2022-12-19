#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

/*
 * This class is the human class. It does all its moves with userinput.
 */

#include "player.h"

namespace AxelTTT
{

    // Inherit from the player class.
    class HumanPlayer : public Player
    {
    public:
        // This funtion places the char on the playing field.
        void placeChar(PlayingField *field)
        {
            int pos1, pos2 = 0;
            bool isFilled;

            cout << "Enter the first position you want to place the char at: ";
            cin >> pos1;
            cout << "Enter the second position you want to place the char at: ";
            cin >> pos2;

            isFilled = field->setField(getPlayerChar(), pos1, pos2);
            if (isFilled == false)
            {
                while (isFilled == false)
                {
                    cout << "Enter the first position you want to place the char at: ";
                    cin >> pos1;
                    cout << "Enter the second position you want to place the char at: ";
                    cin >> pos2;
                    isFilled = field->setField(getPlayerChar(), pos1, pos2);
                }
            }
        }
    };

}

#endif // HUMANPLAYER_H
