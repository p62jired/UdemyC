#pragma once
#include <vector>
constexpr unsigned int LEN_X = 25;
constexpr unsigned int START = 0;
constexpr unsigned int GOAL = LEN_X - 1;
constexpr unsigned int ROW_LEN = 5;

constexpr char LEFT = 'a';
constexpr char RIGHT = 'd';
constexpr char UP = 'w';
constexpr char DOWN = 's';

void print_game_state(unsigned int player);

unsigned int execute_move(unsigned int player, char move);

bool is_finished(unsigned int player);
void string_game_state();
void game();
