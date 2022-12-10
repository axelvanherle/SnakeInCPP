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

int PlayingField::setField (unsigned char place, int pos1, int pos2)
{
    if(field[pos1][pos2] == ' ')
    {
        field[pos1][pos2] = place;
        return 0;
    }
    else
    {
        return -1;
    }
}

int PlayingField::checkTicTacToe (void)
{
    // Check if horizontal tictactoe
    if(((field[0][0] == field[0][1]) && (field[0][1] == field[0][2]) && (field[0][0] == field[0][2]) && field[0][1] != ' ')
    || ((field[1][0] == field[1][1]) && (field[1][1] == field[1][2]) && (field[1][0] == field[1][2]) && field[1][1] != ' ')
    || ((field[2][0] == field[2][1]) && (field[2][1] == field[2][2]) && (field[2][0] == field[2][2]) && field[2][1] != ' '))
    {
        return 0;
        cout << "SUCCES HORIZONTAL" << endl;
    }
    // Check if vertical tictactoe
    else if(((field[0][0] == field[1][0]) && (field[1][0] == field[2][0]) && (field[0][0] == field[2][0]) && field[1][0] != ' ')
    || ((field[0][1] == field[1][1]) && (field[1][1] == field[2][1]) && (field[0][1] == field[2][1]) && field[1][1] != ' ')
    || ((field[0][2] == field[1][2]) && (field[1][2] == field[2][2]) && (field[0][2] == field[2][2]) && field[1][2] != ' '))
    {
        return 0;
        cout << "SUCCES VERTICAL" << endl;
    }
    // Check if cross tictactoe
    else if((((field[0][0] == field[1][1]) && (field[1][1] == field[2][2]) && (field[0][0] == field[2][2])) && field[1][1] != ' ')
    || (((field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && (field[0][2] == field[2][0])) && field[1][1] != ' '))
    {
        return 0;
        cout << "SUCCES CROSS" << endl;
    }
    else
    {
        return 1;
    }
}
