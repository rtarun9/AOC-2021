#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <array>
#include <algorithm>
#include <numeric>

constexpr int BOARD_DIM = 5;

int main()
{
    #include "bingo_board.txt"
    
    int current_index = 0;
    int player_won_index = -1;

    int current_num = 0;
    while (player_won_index < 0)
    {
        current_num = guess[current_index];

        // check out the nums and also check if player is won by row
        for (std::size_t player = 0; player < board.size(); player++)
        {
            for (std::size_t row = 0; row < board[player].size(); row++)
            {
                std::replace(board[player][row].begin(), board[player][row].end(), current_num, -1);
                int i = std::count(board[player][row].begin(), board[player][row].end(), -1);
                if (i == BOARD_DIM)
                {
                    player_won_index = player;
                    break;
                }
            }

            // check for columns
            for (std::size_t column = 0; column < board[player].size(); column++)
            {
                int row_checked_nums = 0;
                for (std::size_t row = 0; row < board[player].size(); row++)
                {
                    if (board[player][row][column] == -1)
                    {
                        row_checked_nums++;
                    }                  
                }

                if (row_checked_nums == BOARD_DIM)
                {
                    player_won_index = player;
                    break;
                }

                row_checked_nums = 0;
            }
        }
        current_index++;
    }

    int uncheck_nums = 0;
    for (std::size_t row = 0; row < BOARD_DIM; row++)
    {
        for (std::size_t column = 0; column < BOARD_DIM; column++)
        {
            uncheck_nums += board[player_won_index][row][column] == -1 ? 0 : board[player_won_index][row][column]; 
        }
    }

    std::cout << uncheck_nums * guess[--current_index];
}