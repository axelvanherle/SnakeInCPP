#ifndef PLAYINGFIELD_H
#define PLAYINGFIELD_H

#include <string>

using namespace std;

class PlayingField
{
public:
    PlayingField();

    void printField (void);
    int setField (unsigned char place, int pos1, int pos2);
    int checkTicTacToe (void);

private:
    string field[3];
};

#endif // PLAYINGFIELD_H
