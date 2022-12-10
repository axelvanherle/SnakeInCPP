#include <iostream>
#include <string>
#include <cstdlib>
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

    cout << "How do i play?" << endl;
    cout << "If its your turn, enter the position you want to place a char in." << endl;
    cout << "For example, lets say i want to place a char on X." << endl;
    cout << "     0   1   2" << endl;
    cout << " 0     | X |   " << endl;
    cout << "    -----------" << endl;
    cout << " 1     |   |   " << endl;
    cout << "    -----------" << endl;
    cout << " 2     |   |   " << endl;
    cout << "You have 3 horizontal rows, and 3 vertical rows." << endl;
    cout << "Character X is on the 0th horizontal row, and on position 1." << endl;
    cout << "So my input would be: 0,1." << endl;
    cout << "Another example? Sure." << endl;
    cout << "     0   1   2" << endl;
    cout << " 0     |   |   " << endl;
    cout << "    -----------" << endl;
    cout << " 1     | X |   " << endl;
    cout << "    -----------" << endl;
    cout << " 2     |   |   " << endl;
    cout << "Lets say i again want to place a char on position X." << endl;
    cout << "Its on the 1st horizontal row, and the 1st positon vertically." << endl;
    cout << "So my input would be: 1,1." << endl << endl << endl << endl;


    while(var != 'y')
    {
        cout << "Do you want the first player to be a human or AI?" << endl;
        cout << "[1] -> Human" << endl << "[2] -> AI" << endl;
        cin >> temp;
        if(temp == 1)
        {
            player1 = new HumanPlayer();
            cout << "Created a human player." << endl;
            setPlayerValues(player1);
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
            setPlayerValues(player2);
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
        system("CLS");
    }
}

void PlayGame::setPlayerValues(Player* newPlayer)
{
    string newName;
    unsigned char newChar;

    cout << "Player name?: ";
    cin >> newName;
    newPlayer->setPlayerName(newName);
    cout << endl << "Speler char?: ";
    cin >> newChar;
    newPlayer->setPlayerChar(newChar);
}

void PlayGame::getPlayerValues(void)
{
    cout << endl << "Player 1 name: " << player1->getPlayerName() << " char: " << player1->getPlayerChar() << endl;
    cout << endl << "Player 2 name: " << player2->getPlayerName() << " char: " << player2->getPlayerChar() << endl;
}

void PlayGame::PlayTicTacToe(void)
{
    int counter = 0;
    srand((unsigned) time(NULL));

    field.printField();

    for (int var = (rand()%2)+2; 1; ++var)
    {
        if(counter == 9)
        {
            cout << "Game is a draw." << endl;
            system("pause");
            exit(1);
        }
        if(var % 2 == 0)
        {
            cout << "Player 1, " << player1->getPlayerName() << " makes his move." << endl;
            player1->placeChar(&field);
            if (field.checkTicTacToe() == 0)
            {
                cout << "Player 1 won! Congrats " << player1->getPlayerName() << "!" << endl;
                field.printField();
                system("pause");
                exit(1);
            }
            field.printField();
        }
        else
        {
            cout << "Player 2, " << player2->getPlayerName() << " makes his move." << endl;
            player2->placeChar(&field);
            if (field.checkTicTacToe() == 0)
            {
                cout << "Player 2 won! Congrats " << player2->getPlayerName() << "!" << endl;
                field.printField();
                system("pause");
                exit(1);
            }
            field.printField();
        }
        counter++;
    }
}
