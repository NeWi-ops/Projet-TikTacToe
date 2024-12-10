#include <iostream>
#include "Menu.h"
#include "TwoPlayer.h"
#include "GameBoard.h"
#include "ConditionDeFin.h"
#include "IA.h"

int main() {
   
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };



    // Afficher le menu principal et obtenir le choix de l'utilisateur
    int choice = show_main_menu();

    // Lancer le mode de jeu correspondant
    if (choice == 1) {
        std::cout << "Mode de jeu : Deux joueurs\n";
        std::cout << "Plateau de jeu initial :\n";
        draw_game_board(game_board);
        two_player_mode();
    } else if (choice == 2) {
        std::cout << "Mode de jeu : Un joueur\n";
        std::cout << "Plateau de jeu initial :\n";
        draw_game_board(game_board);
        single_player_mode();
        // Ajouter l'appel à la fonction correspondante une fois le mode IA implémenté
    }

    return 0;
    
}