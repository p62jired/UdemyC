#include <iostream>
constexpr unsigned int LEN_X = 10;
constexpr char LEFT = 'a';
constexpr char RIGHT = 'd';
constexpr unsigned int START = 0;
constexpr unsigned int GOAL = 10;

void print_game_state(unsigned int player)
{
    char game_state[LEN_X];
    for (unsigned int i = 0; i < LEN_X; i++)
    {
        game_state[i] = '.';
    }

    game_state[START] = '|';
    game_state[GOAL] = '|';
    game_state[player] = 'P';

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        std::cout << game_state[i];
    }
}
unsigned int execute_move(unsigned int player, char move)
{

    if (move != RIGHT && move != LEFT)
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
        print_game_state(player);

        std::cin >> move;
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player);
    }
}
