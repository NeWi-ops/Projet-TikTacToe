#include "Menu.h"
#include <iostream>


int show_main_menu() {
    int choice = 0;
    while (true) {
        // Affichage du menu
        std::cout << "Bienvenue dans le jeu du TicTacToe\n";
        std::cout << "Veuillez choisir un mode de jeu :\n";
        std::cout << "1. Deux joueurs\n";
        std::cout << "2. Un joueur contre l'IA\n";
        std::cout << "Votre choix : ";

        std::cin >> choice;

        // Validation de l'entrée
        if (std::cin.fail() || choice < 1 || choice > 2) {
            std::cin.clear(); // Efface l'état d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le buffer d'entrée
            std::cout << "Choix invalide. Veuillez entrer 1 ou 2.\n";
        } else {
            return choice; // Retourne le choix valide
        }
    }
}