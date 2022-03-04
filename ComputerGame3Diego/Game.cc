#include "Game.h"
#include <iostream>
#include <vector>

void string_game_state(unsigned int player)
{
    std::vector<char> my_vector(LEN_X);
    unsigned int tmp_row = 0;
    for (auto &val : my_vector)
    {
        val = '.';
    }
    my_vector[START] = '|';
    my_vector[GOAL] = '|';
    my_vector[player] = 'P';

    for (std::size_t i = 0; i != my_vector.size(); i++)
    {
        ++tmp_row;
        if (tmp_row == ROW_LEN)
        {
            std::cout << my_vector[i] << std::endl;
            tmp_row = 0;
        }
        else
        {
            std::cout << my_vector[i];
        }
    }
}

unsigned int execute_move(unsigned int player, char move)
{
    if (move != RIGHT && move != LEFT && move != DOWN && move != UP)
    {
        std::cout << "Unrecognized move\n";
        return player;
    }

    if (move == RIGHT && player < GOAL)
    {
        player++;
        std::cout << "You moved to right\n";
    }
    if (move == LEFT && player > START)
    {
        player--;
        std::cout << "You moved to left\n";
    }

    if (move == DOWN && player <= GOAL - ROW_LEN)
    {
        player += ROW_LEN;
        std::cout << "You moved to down\n";
    }
    if (move == UP && player >= START + ROW_LEN)
    {
        player -= ROW_LEN;
        std::cout << "You moved to up\n";
    }
    std::cout << "You are in position: " << player << std::endl;
    return player;
}

bool is_finished(unsigned int player)
{
    bool finished = false;
    if (player == GOAL)
    {
        finished = true;

        std::cout << "You won the game" << std::endl;
    }
    return finished;
}


void game()
{
    unsigned int player = 0;
    char move;
    bool finished = false;
    while (!finished)
    {
        string_game_state(player);

        std::cin >> move;
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player);
    }
}
