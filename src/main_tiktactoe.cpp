#include <iostream>

#include "TwoPlayer.h"

int main() {
   
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    
    
    

    
    std::cout << "Plateau de jeu initial :\n";
    draw_game_board(game_board);

   std::cout << "Bienvenue au jeu du Tic-Tac-Toe !\n";
   std::cout << "Mode de jeu : Deux joueurs\n";

    // Lancer le mode deux joueurs
    two_player_mode();

    return 0;

    

    return 0;
}