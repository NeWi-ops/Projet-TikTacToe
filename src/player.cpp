#include "Player.h"
#include <iostream>

Player create_player()
{
    Player player;

    std::cout<<"Player : Entrer le nom du joueur"<<std::endl;
    std::getline(std::cin, player.name);

    std::cout << player.name << " : Choisir un symbole pour le joueur (X ou O)";
    std::cin >> player.symbol;

    return player;
}