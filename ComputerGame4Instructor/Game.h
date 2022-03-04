#pragma once
#include <string>
#include <utility>
#include <vector>

using Position = std::pair<unsigned int, unsigned int>;
using GameState = std::vector<std::string>;
using Obstacles = std::vector<Position>;


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

GameState update_game_state(const Position &player, const Obstacles &obtacles);

void print_game_state(const GameState &game_state);

Position execute_move(ConsoleInput player, ConsoleInput move);


bool is_dead(const Position &player, const Obstacles &obstacles);
bool is_finished(Position player);

unsigned int random_uint(const unsigned int lower, const unsigned int upper);

Position random_position(const unsigned int lower_x,
                         const unsigned int upper_x,
                         const unsigned int lower_y,
                         const unsigned int upper_y);
void game();
