#include "Game.h"
#include <iostream>
#include <random>


ConsoleInput map_user_input(char user_input)
{
    switch (user_input)
    {
    case 'a':
        return ConsoleInput::LEFT;
    case 'd':
        return ConsoleInput::RIGHT;
    case 'w':
        return ConsoleInput::UP;
    case 's':
        return ConsoleInput::DOWN;
    default:
        return ConsoleInput::INVALID;
    }
}

std::vector<Position> generate_obstacle(unsigned int num_obstacles)
{

    std::random_device seed_generator{};
    std::mt19937_64 random_generator{seed_generator()};
    std::vector<Position> obstacles(num_obstacles, Position{0, 0});

    Position temp_pos = START;
    for (std::size_t i = 0; i < obstacles.size(); i++)
    {

        std::uniform_int_distribution<unsigned int> random_distribution_x{0, LEN_X - 1};
        std::uniform_int_distribution<unsigned int> random_distribution_y{0, LEN_Y - 1};
        auto x = random_distribution_x(random_generator);
        auto y = random_distribution_y(random_generator);
        temp_pos = {x, y};
        while (temp_pos == START || temp_pos == GOAL)
        {
            x = random_distribution_x(random_generator);
            y = random_distribution_y(random_generator);
            temp_pos = {x, y};
        }
        obstacles[i] = {x, y};
    }
    return obstacles;
}


void print_game_state(Position player, std::vector<Position> &obstacles)
{
    GameState game_state(LEN_X, std::string(LEN_Y, '.'));

    for (std::size_t i = 0; i < obstacles.size(); i++)
    {
        game_state[obstacles[i].first][obstacles[i].second] = 'x';
    }

    game_state[START.first][START.second] = '|';
    game_state[GOAL.first][GOAL.second] = '|';
    game_state[player.first][player.second] = 'P';

    for (unsigned int i = 0; i < LEN_X; i++)
    {
        for (unsigned int j = 0; j < LEN_Y; j++)
        {
            std::cout << game_state[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
Position execute_move(Position player, ConsoleInput move)
{
    switch (move)
    {
    case ConsoleInput::LEFT:
    {
        if (player.second > START.second)
        {
            player.second--;
            std::cout << "You moved to left\n";
        }
        else
        {
            std::cout << "You bounced\n";
        }
        break;
    }
    case ConsoleInput::RIGHT:
    {
        if (player.second < GOAL.second)
        {
            player.second++;
            std::cout << "You moved to left\n";
        }
        else
        {
            std::cout << "You bounced\n";
        }
        break;
    }
    case ConsoleInput::UP:
    {
        if (player.first > START.first)
        {
            player.first--;
            std::cout << "You moved up\n";
        }
        else
        {
            std::cout << "You bounced\n";
        }
        break;
    }
    case ConsoleInput::DOWN:
    {
        if (player.first < GOAL.first)
        {
            player.first++;
            std::cout << "You moved down\n";
        }
        else
        {
            std::cout << "You bounced\n";
        }
        break;
    }
    case ConsoleInput::INVALID:
    {
        std::cout << "Unrecognized move!" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Unrecognized move!" << std::endl;
        break;
    }
    }
    return player;
}

bool is_finished(Position player, std::vector<Position> &obs)
{
    bool finished = false;
    for (std::size_t i = 0; i < obs.size(); i++)
    {
        if (player == obs[i])
        {
            finished = true;
            std::cout << "You died" << std::endl;
            return finished;
        }
    }


    if (player == GOAL)
    {
        finished = true;

        std::cout << "You won the game" << std::endl;
    }
    return finished;
}


void game()
{
    Position player = {0, 0};
    char user_input;
    ConsoleInput move;
    bool finished = false;
    auto obstacles = generate_obstacle(7);
    while (!finished)
    {
        print_game_state(player, obstacles);
        std::cin >> user_input;
        move = map_user_input(user_input);
        system("clear");
        player = execute_move(player, move);
        finished = is_finished(player, obstacles);
    }
}
