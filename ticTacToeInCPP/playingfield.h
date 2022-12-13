#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include <string>

using namespace std;

class PlayingField
{
public:
    // Initliazes the array to "   ".
    PlayingField();

    // Prints the current playing field.
    void printField(void);
    // Allows the user to plays chars on the playing field.
    int setField(unsigned char place, int pos1, int pos2);
    // Checks if there is tic tac toe on the field.
    int checkTicTacToe(void);

private:
    // Used to store the field.
    string field[3];
};

#endif // PLAYINGFIELD_H
