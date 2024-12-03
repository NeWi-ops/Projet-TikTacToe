#include<iostream>


struct Player 
{
    std::string name;  // Nom du joueur
    char symbol;       // Symbole du joueur ('X' ou 'O')
};

Player create_player();