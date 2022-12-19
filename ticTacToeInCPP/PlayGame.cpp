#include <iostream>
#include <string>
#include <cstdlib>
#include "PlayGame.h"
#include "playingfield.h"
#include "aiplayer.h"
#include "humanplayer.h"

namespace AxelTTT {

// Create two player pointers, and call the makePlayerObjects fucntion. This asks the user what kind of players they want to create.
PlayGame::PlayGame(string boardName)
{
    // Open the file
    MyFile.open(boardName);

    cout << "Game started." << endl;
    player1 = nullptr;
    player2 = nullptr;
    makePlayerObjects();
    // If player 1 or player 2 is a nullptr, the allocation in makePlayerObjects did not succeed, so we must exit.
    if (player1 == nullptr || player2 == nullptr)
    {
        cout << "Error allocating mem." << endl;
        exit(-1);
    }
}

// Deallocate both players.
PlayGame::~PlayGame()
{
    // Close the file
    MyFile.close();

    delete player1;
    delete player2;
    cout << "Game ended. Thanks for playing!" << endl;
}

void PlayGame::makePlayerObjects(void)
{
    unsigned char var = 'n';
    string temp;

    // Explination
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
    cout << "So my input would be: 1,1." << endl
         << endl
         << endl
         << endl;

    // Keep asking the user what players they want to make while "var" == 'n'.
    while (var != 'y')
    {
        cout << "Do you want the first player to be a human or AI?" << endl;
        cout << "[1] -> Human" << endl
             << "[2] -> AI" << endl;
        cin >> temp;
        if (temp[0] == '1' && temp.length() == 1)
        {
            player1 = new HumanPlayer();
            cout << "Created a human player." << endl;
            setPlayerValues(player1);
        }
        else if (temp[0] == '2' && temp.length() == 1)
        {
            player1 = new AIPlayer("AI Player");
            cout << "Created a AI player." << endl;
        }
        else
        {
            player1 = new AIPlayer("AI Player");
            cout << "Invalid value. Created a AI player." << endl;
        }

        cout << "Do you want the second player to be a human or AI?" << endl;
        cout << "[1] -> Human" << endl
             << "[2] -> AI" << endl;
        cin >> temp;
        if (temp[0] == '1' && temp.length() == 1)
        {
            player2 = new HumanPlayer();
            cout << "Created a human player." << endl;
            setPlayerValues(player2);
        }
        else if (temp[0] == '2' && temp.length() == 1)
        {
            player2 = new AIPlayer("AI Player");
            cout << "Created a AI player." << endl;
        }
        else
        {
            player2 = new AIPlayer("AI Player");
            cout << "Invalid value. Created a AI player." << endl;
        }

        try
        {
            if (player1->getPlayerChar() == player2->getPlayerChar())
            {
                throw runtime_error("Same name.");
            }
        }
        catch (runtime_error& err)
        {
            cerr << err.what() << endl;
            unsigned char Check;
            while(player1->getPlayerChar() == player2->getPlayerChar())
            {
                cout << "Impossible, player1 already uses this character!" << endl << "Please give another char:" << endl;
                cin >> Check;
                player2->setPlayerChar(Check);
            }
        }

        cout << "Players set. Continue? [y/n]: ";
        cin >> var;
        system("CLS");
    }
}

// Sets the playername and char to the Player * given.
void PlayGame::setPlayerValues(Player *newPlayer)
{
    string newName;
    unsigned char newChar;

    cout << "Player name?: ";
    //cin >> newName;
    cin.ignore();
    getline(cin,newName);
    newPlayer->setPlayerName(newName);
    cout << endl
         << "Speler char?: ";
    cin >> newChar;
    newPlayer->setPlayerChar(newChar);
}

// Prints the name and char of a player.
void PlayGame::getPlayerValues(void)
{
    cout << endl
         << "Player 1 name: " << player1->getPlayerName() << " char: " << player1->getPlayerChar() << endl;
    cout << endl
         << "Player 2 name: " << player2->getPlayerName() << " char: " << player2->getPlayerChar() << endl;
}

// This is the "game", all functionality comes together here.
void PlayGame::PlayTicTacToe(void)
{
    int counter = 0;
    cout << player1->getPlayerName() << " VS " << player2->getPlayerName() << " may the best man win!" << endl;
    MyFile << player1->getPlayerName() << " VS " << player2->getPlayerName() << " may the best man win!" << endl;
    field.printField();

    // This decides who can begin playing. If var is even player1 can begin. Else player2.
    // Rand % 2 gives 1 or 0. But we cant check if 1 or 0 is even or odd, so we do +2.
    for (int var = (rand() % 2) + 2; 1; ++var)
    {
        MyFile << "Turn " << counter << endl;
        saveField();

        if (counter == 9)
        {
            cout << "Game is a draw." << endl;
            MyFile << "Game is a draw." << endl;
            system("pause");
            break;
        }
        if (var % 2 == 0)
        {
            cout << "Player 1, " << player1->getPlayerName() << " makes his move." << endl;
            player1->placeChar(&field);
            if (field.checkTicTacToe() == true)
            {
                MyFile << "Player 1 won! Congrats " << player1->getPlayerName() << "!" << endl;
                cout << "Player 1 won! Congrats " << player1->getPlayerName() << "!" << endl;
                field.printField();
                saveField();
                system("pause");
                break;
            }
            field.printField();
        }
        else
        {
            cout << "Player 2, " << player2->getPlayerName() << " makes his move." << endl;
            player2->placeChar(&field);
            if (field.checkTicTacToe() == true)
            {
                MyFile << "Player 2 won! Congrats " << player2->getPlayerName() << "!" << endl;
                cout << "Player 2 won! Congrats " << player2->getPlayerName() << "!" << endl;
                field.printField();
                saveField();
                system("pause");
                break;
            }
            field.printField();
        }
        counter++;
    }
}

void PlayGame::saveField()
{
    if(!MyFile)
    {
        cout << "Error making a output file to save the board." << endl;
    }

    else
    {
        MyFile << field.returnPrintField();
        MyFile << endl;
    }
}
}
