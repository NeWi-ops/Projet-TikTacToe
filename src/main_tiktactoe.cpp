#include <iostream>
#include "GameBoard.h"

int main() {
   
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    
    std::cout << "Plateau de jeu initial :\n";
    draw_game_board(game_board);

   

    

    return 0;
}