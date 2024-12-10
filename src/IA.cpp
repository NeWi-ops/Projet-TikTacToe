#include <iostream>
#include "IA.h"
#include "ConditionDeFin.h"
#include "GameBoard.h"


int get_random_move(const char board[BOARD_SIZE]) {
    int move;
    do {
        move = std::rand() % BOARD_SIZE; // Génère un indice entre 0 et 8
    } while (board[move] == 'X' || board[move] == 'O');
    return move;
}

void single_player_mode() {
    // Initialisation du plateau
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    // Création du joueur
    std::cout << "Création du joueur :\n";
    Player player = create_player();

    // Création de l'IA
    Player ai;
    ai.name = "IA";
    ai.symbol = (player.symbol == 'X') ? 'O' : 'X';

     // Initialiser le générateur de nombres aléatoires
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Boucle principale du jeu
    Player current_player = player;
    bool game_running = true;

    while (game_running) {
        // Afficher le plateau       
        
        draw_game_board(game_board);

        if (current_player.name == "IA") {
            // Tour de l'IA
            std::cout << "C'est au tour de l'IA (" << current_player.symbol << ").\n";
            int move = get_random_move(game_board);
            std::cout << "L'IA joue sur la case " << (move + 1) << ".\n";
            game_board[move] = current_player.symbol;
        } else {
            // Tour du joueur
            std::cout << "C'est à votre tour, " << current_player.name << " (" << current_player.symbol << ").\n";
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
        }

        // Vérifier si le joueur courant a gagné
        if (check_winner(game_board, current_player.symbol)) {
            draw_game_board(game_board);
            std::cout << "Félicitations, " << current_player.name << "! Vous avez gagné !\n";
            game_running = false;
        }
        // Vérifier si le plateau est plein (match nul)
        else if (is_board_full(game_board)) {
            draw_game_board(game_board);
            std::cout << "Match nul !\n";
            game_running = false;
        }
        // Changer de joueur
        else {
            current_player = (current_player.name == player.name) ? ai : player;
        }
    }
}