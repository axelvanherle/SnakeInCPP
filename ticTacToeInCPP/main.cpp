#include "PlayGame.h"

int main()
{
    srand((unsigned)time(NULL));

    PlayGame game;

    game.PlayTicTacToe();

    return EXIT_SUCCESS;
}
