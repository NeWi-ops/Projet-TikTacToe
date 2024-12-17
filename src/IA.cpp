#include <iostream>
#include "IA.h"
#include "ConditionDeFin.h"
#include "GameBoard.h"

int find_blocking_move(const char board[BOARD_SIZE], char player_symbol) 
{
    
    const int win_patterns[8][3] = 
    {
        {0, 1, 2}, 
        {3, 4, 5}, 
        {6, 7, 8}, 
        {0, 3, 6}, 
        {1, 4, 7}, 
        {2, 5, 8}, 
        {0, 4, 8}, 
        {2, 4, 6}  
    };

    for (int i = 0; i < 8; ++i) 
    {
        int count_player = 0; 
        int empty_index = -1; 

        for (int j = 0; j < 3; ++j) 
        {
            int index = win_patterns[i][j];
            if (board[index] == player_symbol) 
            {
                count_player++;
            } 
            else if (board[index] != 'X' && board[index] != 'O') 
            {
                empty_index = index; 
            }
        }

        if (count_player == 2 && empty_index != -1) 
        {
            return empty_index;
        }
    }

    return -1; 
}

int get_random_move(const char board[BOARD_SIZE]) 
{
    int move;
    do 
    {
        move = std::rand() % BOARD_SIZE; 
    } 
    while (board[move] == 'X' || board[move] == 'O');
    return move;
}

void single_player_mode() 
{
    char game_board[BOARD_SIZE] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    std::cout << "Création du joueur :\n";
    Player player = create_player();

    Player ai;
    ai.name = "IA";
    ai.symbol = (player.symbol == 'X') ? 'O' : 'X';

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Player current_player = player;
    bool game_running = true;

    while (game_running) 
    {
        
        draw_game_board(game_board);

        if (current_player.name == "IA") 
        {
            std::cout << "C'est au tour de l'IA (" << current_player.symbol << ").\n";
            int blocking_move = find_blocking_move(game_board, player.symbol);
            int move;

        if (blocking_move != -1) 
        {
        move = blocking_move;
        std::cout << "L'IA bloque votre coup sur la case " << (move + 1) << ".\n";
        }
        else
        {
            move = get_random_move(game_board);
            std::cout << "L'IA joue sur la case " << (move + 1) << ".\n";
        }
            game_board[move] = current_player.symbol;
        } 
        else 
        {
            std::cout << "C'est à votre tour, " << current_player.name << " (" << current_player.symbol << ").\n";
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
        }

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
            current_player = (current_player.name == player.name) ? ai : player;
        }
    }
}