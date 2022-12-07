#include <iostream>
#include <string>
#include "PlayGame.h"
#include "playingfield.h"

PlayGame::PlayGame()
{
    cout << "Game started." << endl;
    player1 = nullptr;
    player2 = nullptr;
    makePlayerObjects();
    if(player1 == nullptr || player2 == nullptr)
    {
        exit (-1);
    }
    setPlayerValues();
}

PlayGame::~PlayGame()
{
    delete player1;
    delete player2;
    cout << "Game ended. Thanks for playing!" << endl;
}

void PlayGame::makePlayerObjects(void)
{
    unsigned char var = 'n';
    int temp = 0;
    while(var != 'y')
    {
        cout << "Do you want the first player to be a human or AI?" << endl;
        cout << "[1] -> Human" << endl << "[2] -> AI" << endl;
        cin >> temp;
        if(temp == 1)
        {
            player1 = new HumanPlayer();
            cout << "Created a human player." << endl;
        }
        else if (temp == 2)
        {
            player1 = new AIPlayer();
            cout << "Created a AI player." << endl;
        }
        else
        {
            player1 = new AIPlayer();
            cout << "Invalid value. Created a AI player." << endl;
        }

        cout << "Do you want the second player to be a human or AI?" << endl;
        cout << "[1] -> Human" << endl << "[2] -> AI" << endl;
        cin >> temp;
        if(temp == 1)
        {
            player2 = new HumanPlayer();
            cout << "Created a human player." << endl;
        }
        else if (temp == 2)
        {
            player2 = new AIPlayer();
            cout << "Created a AI player." << endl;
        }
        else
        {
            player2 = new AIPlayer();
            cout << "Invalid value. Created a AI player." << endl;
        }

        cout << "Players set. Continue? [y/n]: ";
        cin >> var;

    }
}

void PlayGame::setPlayerValues(void)
{
    string newName;
    char newChar;

    cout << "Player 1 name?: ";
    cin >> newName;
    player1->setPlayerName(newName);
    cout << endl << "Speler 1 char?: ";
    cin >> newChar;
    player1->setPlayerChar(newChar);

    cout << endl <<  "Speler 2 naam?: ";
    cin >> newName;
    player2->setPlayerName(newName);
    cout << endl << "Speler 2 char?: ";
    cin >> newChar;
    player2->setPlayerChar(newChar);

    cout << endl << endl << "Player values set." << endl;
}

void PlayGame::getPlayerValues(void)
{
    cout << endl << "Player 1 name: " << player1->getPlayerName() << " char: " << player1->getPlayerChar() << endl;
    cout << endl << "Player 2 name: " << player2->getPlayerName() << " char: " << player2->getPlayerChar() << endl;
}

void PlayGame::PlayTicTacToe(void)
{

}
