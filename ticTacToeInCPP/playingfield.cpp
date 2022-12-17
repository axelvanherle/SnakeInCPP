#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "playingfield.h"
using namespace std;

// Initliazes the array to "   ".
PlayingField::PlayingField()
{
    cout << "Playing field made." << endl;
    field[0] = "   ";
    field[1] = "   ";
    field[2] = "   ";
}

// Prints the current playing field.
void PlayingField::printField(void)
{
    for (int i = 0; i < 3; ++i)
    {
        cout << field[i][0] << " | " << field[i][1] << " | " << field[i][2] << endl;
        if (i < 2)
        {
            cout << "----------" << endl;
        }
    }
}

// Prints the current playing field.
string PlayingField::returnPrintField(void)
{
    stringstream buffer;

    for (int i = 0; i < 3; ++i)
    {
        buffer << field[i][0] << " | " << field[i][1] << " | " << field[i][2] << endl;
        if (i < 2)
        {
            buffer << "----------" << endl;
        }
    }

    return buffer.str();
}

// Allows the user to plays chars on the playing field.
// Return 0 if placed, -1 if the spot is already filled.
int PlayingField::setField(unsigned char place, int pos1, int pos2)
{
    // If the user attempts to place a char on a empty place we allow it, else we dont.
    if (field[pos1][pos2] == ' ')
    {
        field[pos1][pos2] = place;
        return 0;
    }
    else
    {
        return -1;
    }
}

// Checks if there is tic tac toe on the field.
int PlayingField::checkTicTacToe(void)
{
    // Check if horizontal tictactoe
    if (((field[0][0] == field[0][1]) && (field[0][1] == field[0][2]) && (field[0][0] == field[0][2]) && field[0][1] != ' ') || ((field[1][0] == field[1][1]) && (field[1][1] == field[1][2]) && (field[1][0] == field[1][2]) && field[1][1] != ' ') || ((field[2][0] == field[2][1]) && (field[2][1] == field[2][2]) && (field[2][0] == field[2][2]) && field[2][1] != ' '))
    {
        return 0;
    }
    // Check if vertical tictactoe
    else if (((field[0][0] == field[1][0]) && (field[1][0] == field[2][0]) && (field[0][0] == field[2][0]) && field[1][0] != ' ') || ((field[0][1] == field[1][1]) && (field[1][1] == field[2][1]) && (field[0][1] == field[2][1]) && field[1][1] != ' ') || ((field[0][2] == field[1][2]) && (field[1][2] == field[2][2]) && (field[0][2] == field[2][2]) && field[1][2] != ' '))
    {
        return 0;
    }
    // Check if cross tictactoe
    else if ((((field[0][0] == field[1][1]) && (field[1][1] == field[2][2]) && (field[0][0] == field[2][2])) && field[1][1] != ' ') || (((field[0][2] == field[1][1]) && (field[1][1] == field[2][0]) && (field[0][2] == field[2][0])) && field[1][1] != ' '))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
