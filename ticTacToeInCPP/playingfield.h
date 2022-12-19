#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include <string>

using namespace std;

namespace AxelTTT
{

    class PlayingField
    {
    public:
        // Initliazes the array to "   ".
        PlayingField(void);
        // Prints the current playing field.
        void printField(void);
        // Returns the playing field as a string.
        string returnPrintField(void);
        // Allows the user to plays chars on the playing field.
        bool setField(unsigned char place, int pos1, int pos2);
        // Checks if there is tic tac toe on the field.
        bool checkTicTacToe(void);

    private:
        // Used to store the field.
        string field[3];
    };
}
#endif // PLAYINGFIELD_H
