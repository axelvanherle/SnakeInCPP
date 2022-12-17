#include "PlayGame.h"

int main()
{
    srand((unsigned)time(NULL));

    AxelTTT::PlayGame game("board.txt");

    game.PlayTicTacToe();

    return EXIT_SUCCESS;
}
