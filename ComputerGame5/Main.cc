#include "Game.h"
#include <iostream>
#include <stdlib.h>
char repeatGame;

int main()
{
    bool repeat = true;
    Game game;
    while (repeat)
    {
        game.start_game();
        std::cout << "You won the game!!";
        std::cout << "Play again? (y/n)";
        std::cin >> repeatGame;
        if (repeatGame == 'y')
        {
            repeat = true;
        }
        else
        {
            repeat = false;
        }
    }
    return 0;
}
