#include <iostream>
#include "ConditionDeFin.h"
#pragma once

bool check_winner(const char board[BOARD_SIZE], char symbol) 
{
    for (int i = 0; i < 9; i += 3) 
    {
        if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == symbol) 
        {
            return true;
        }
    }


    for (int i = 0; i < 3; ++i) 
    {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol) 
        {
            return true;
        }
    }

    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) || 
        (board[2] == symbol && board[4] == symbol && board[6] == symbol)) 
    {
        return true;
    }

    return false;
}

bool is_board_full(const char board[BOARD_SIZE]) 
{
    for (int i = 0; i < BOARD_SIZE; ++i) 
    {
        if (board[i] >= '1' && board[i] <= '9') 
        {
            return false;
        }
    }
    return true;
}