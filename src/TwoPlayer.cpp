#include "TwoPlayer.h"
#include "GameBoard.h"
#include "ConditionDeFin.h"
#include <iostream>



void two_player_mode() 
{
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::cout << "Création du joueur 1 :\n";
    Player player1 = create_player();

    std::cout << "Création du joueur 2 :\n";
    Player player2 = create_player();
    if (player2.symbol == player1.symbol)
    {
        std::cout<<"Vous ne pouvez pas choisir le même symbole que " <<player1.name<< ", veuillez en choisir un autre."<<std::endl;
        std::cout<<"Entrez un symbole different de "<<player1.symbol<<std::endl;
        std::cin>>player2.symbol;
    }

    Player current_player = player1;
    bool game_running = true;

    while (game_running) 
    {
        draw_game_board(game_board);

        std::cout << "C'est au tour de " << current_player.name << " (" << current_player.symbol << ").\n";
        std::cout << "Choisissez une case (1-9) : ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail() || choice < 1 || choice > 9 || game_board[choice - 1] == 'X' || game_board[choice - 1] == 'O') 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Choix invalide. Veuillez réessayer.\n";
            continue;
        }

        game_board[choice - 1] = current_player.symbol;

        if (check_winner(game_board, current_player.symbol)) 
        {
            draw_game_board(game_board);
            std::cout << "Félicitations, " << current_player.name << "! Vous avez gagné !\n";
            game_running = false;
        }
        else if (is_board_full(game_board)) 
        {
            draw_game_board(game_board);
            std::cout << "Match nul !\n";
            game_running = false;
        }
        else 
        {
            current_player = (current_player.name == player1.name) ? player2 : player1;
        }
    }
}