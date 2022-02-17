#include <iostream>
#include <stdlib.h>
#define LEN_X 10u //unsigned
#define LEFT 'a'
#define RIGHT 'd'

unsigned int player = 0;
unsigned int start = 0;
unsigned int goal = LEN_X - 1;
char move, repeatGame;

void printStatusGame()
{
    std::cout << "You are in position " << player << std::endl;
    for (unsigned int i = 0; i < LEN_X; i++)
    {
        if (i == player)
        {
            std::cout << "P";
        }

        else if (i != start && i != goal)
        {
            std::cout << ".";
        }

        else
        {
            std::cout << "|";
        }
    }
}
void getInputFromPlayer()
{
    std::cin >> move;
    if (move != RIGHT && move != LEFT)
    {
        std::cout << "Unrecognized move\n";
        return;
    }

    if (move == RIGHT && player < goal)
    {
        player++;
        std::cout << "You moved to right\n";
    }
    if (move == LEFT && player > start)
    {
        player--;
        std::cout << "You moved to left\n";
    }
}
int main()
{
    bool repeat = true;
    while (repeat)
    {
        while (player < LEN_X - 1)
        {
            if (repeatGame == 'y')
            {
                player = 0;
                repeatGame = 'n';
            }
            printStatusGame();
            getInputFromPlayer();
            system("clear");
        }
        std::cout << "You won the game!!";
        std::cout << "Play again? (y/n)";
        std::cin >> repeatGame;
        if (repeatGame == 'y')
        {
            player = start;
            repeat = true;
        }
        else
        {
            repeat = false;
        }
    }
    return 0;
}
