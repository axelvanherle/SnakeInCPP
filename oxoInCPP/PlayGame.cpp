#include <iostream>
#include <string>
#include "PlayGame.h"

PlayGame::PlayGame()
{
    cout << "Game started." << endl;
    setPlayerValues();
}

void PlayGame::setPlayerValues(void)
{
    string newName;
    char newChar;

    cout << "Player 1 name?: ";
    cin >> newName;
    player1.setPlayerName(newName);
    cout << endl << "Speler 1 char?: ";
    cin >> newChar;
    player1.setplayerChar(newChar);

    cout << endl <<  "Speler 2 naam?: ";
    cin >> newName;
    player2.setPlayerName(newName);
    cout << endl << "Speler 2 char?: ";
    cin >> newChar;
    player2.setplayerChar(newChar);

    cout << endl << endl << "Player values set." << endl;
}

void PlayGame::getPlayerValues(void)
{
    cout << endl << "Player 1 name: " << player1.getPlayerName() << " char: " << player1.getplayerChar() << endl;
    cout << endl << "Player 2 name: " << player2.getPlayerName() << " char: " << player2.getplayerChar() << endl;
}
