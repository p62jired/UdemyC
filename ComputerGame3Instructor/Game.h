#pragma once
#include <string>
#include <utility>
#include <vector>

using Position = std::pair<unsigned int, unsigned int>;
using GameState = std::vector<std::string>;


constexpr unsigned int LEN_X = 5;
constexpr unsigned int LEN_Y = 5;
constexpr Position START = {0, 0};
constexpr Position GOAL = {LEN_X - 1, LEN_Y - 1};


enum class ConsoleInput : int
{
    LEFT,
    RIGHT,
    UP,
    DOWN,
    INVALID
};

ConsoleInput map_user_input(char user_input);

void print_game_state(ConsoleInput player);

Position execute_move(ConsoleInput player, ConsoleInput move);

bool is_finished(Position player);

void game();
