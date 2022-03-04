#include "Game.h"
#include <iostream>
#include <stdlib.h>
char repeatGame;

int main()
{
    bool repeat = true;
    while (repeat)
    {
        game();
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
