#include "Player.h"
#include <iostream>

Player create_player()
{
    Player player;

    std::cout<<"Player : Entrer le nom du joueur"<<std::endl;
    std::cin >> player.name;

    std::cout << player.name << " : Choisir un symbole pour le joueur ";
    std::cin >> player.symbol;

    return player;
}