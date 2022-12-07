#include <iostream>
#include <string>
#include <cstring>
#include "playingfield.h"
using namespace std;

PlayingField::PlayingField()
{

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

void PlayingField::checkTicTacToe (void)
{

}
