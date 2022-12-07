#include <iostream>
#include <string>
#include <cstring>
#include "playingfield.h"
using namespace std;

PlayingField::PlayingField()
{
    cout << "Playing field made." << endl;
    field[0] = "   ";
    field[1] = "   ";
    field[2] = "   ";
}

void PlayingField::printField (void)
{
    for (int i = 0; i < 3; ++i) {
        cout << field[i][0] << " | " << field[i][1] << " | " << field[i][2] << endl;
        if(i < 2)
        {
            cout << "----------" << endl;
        }
    }
}

void PlayingField::setField (unsigned char place, int pos1, int pos2)
{
    field[pos1][pos2] = place;
}

void PlayingField::checkTicTacToe (void)
{
}
