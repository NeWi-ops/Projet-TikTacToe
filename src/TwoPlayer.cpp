#include "TwoPlayer.h"
#include "GameBoard.h"
#include "ConditionDeFin.h"
#include <iostream>



void two_player_mode() {
    // Initialisation du plateau
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    // Création des joueurs
    std::cout << "Création du joueur 1 :\n";
    Player player1 = create_player();

    std::cout << "Création du joueur 2 :\n";
    Player player2 = create_player();

    // Boucle principale du jeu
    Player current_player = player1;
    bool game_running = true;

    while (game_running) {
        // Afficher le plateau
        draw_game_board(game_board);

        // Tour du joueur actuel
        std::cout << "C'est au tour de " << current_player.name << " (" << current_player.symbol << ").\n";
        std::cout << "Choisissez une case (1-9) : ";
        int choice;
        std::cin >> choice;

        // Validation de l'entrée
        if (std::cin.fail() || choice < 1 || choice > 9 || game_board[choice - 1] == 'X' || game_board[choice - 1] == 'O') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Choix invalide. Veuillez réessayer.\n";
            continue;
        }

        // Mettre à jour le plateau
        game_board[choice - 1] = current_player.symbol;

        // Vérifier si le joueur a gagné
        if (check_winner(game_board, current_player.symbol)) {
            draw_game_board(game_board);
            std::cout << "Félicitations, " << current_player.name << "! Vous avez gagné !\n";
            game_running = false;
        }
        // Vérifier si le plateau est plein
        else if (is_board_full(game_board)) {
            draw_game_board(game_board);
            std::cout << "Match nul !\n";
            game_running = false;
        }
        // Changer de joueur
        else {
            current_player = (current_player.name == player1.name) ? player2 : player1;
        }
    }
}