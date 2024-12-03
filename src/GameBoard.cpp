#include "GameBoard.h"
#include <iostream>


void draw_game_board(const char board[BOARD_SIZE])
{
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (i % 3 != 0)
        {
            std::cout << " | ";
        }
        std::cout << board[i];
        if ((i + 1) % 3 == 0) 
        {
            std::cout << "\n";
            
            if (i < BOARD_SIZE - 1) 
            {
                std::cout << "--+---+---\n";
            }
        }
    }
        std::cout << "\n";
}