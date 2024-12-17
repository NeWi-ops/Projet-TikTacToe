# Projet-TikTacToe Iwen Rapport

## Execution du programme :

La seule librairie utilisée est Iostream, le programme à été réalisé sous MacOS. Pour le lancer il faut simplement le lancer dans l'éxecuter dans le terminal de VScode par exemple et de suivre les instructions en choisissant tou d'abord le mode de jeu puis enentrant son nom et son symbole et ensuite de choisir les cases (numérotées pour mieux s'y retrouver) afin que son symbole y soit placé. 

## Organisation du code :

Le code est séparé en plusieurs fichiers, chacun ayant un role précis. on retrouve un header pour initialiser la fonction que contiendra le fichier cpp dans la plupart des cas. On retrouve un fichier contenant les conditions de fin à savoir "est ce qu'un joueur a gagné" ou "est ce que le tableau est plein".
un autre couple header/cpp permettant de tracer le tableau de jeu. Tableau qui sera modifié soit par le couple header/cpp TwoPlayer soit par celui IA en fonction du mode de jeu choisi et qui contiennent respectivement les codes permettant de jouer à 2 joueurs et à un joueur contre une IA.
Le couple header/cpp Player contient quant à lui le code permettant au joueur d'entrer son nom et son symbole grâce à une structure nommée player.
Le fichier menu permet de demander et d'enregistrer la réponse du joueur pour connaitre le mode de jeu souhaité.

Cette séparation des differentes fonction permet d'y voir clair dans le fichier main dans lequel on retrouve seulement des appels aux fonctions créées préalablement.

## Amélioration

L'amélioration effectuée concerne l'IA. Elle est assez légère mais rend la partie un petit peu plus interéssante pour un joueur seul. il s'agit simplement d'une fonction qui va opéré au début du tour de l'IA, avant qu'elle joue. Cette fonction va parcourir le plateau à la recherche de 2 symboles du joueur qui seraient alignés. Si elle trouve un tel cas de figure et qu'une case est libre (case qui pourrait permettre au joueur de gagner) l'IA placera son symbole à cet emplacement. Si un tel cas de figure n'existe pas alors elle jouera au hasard sur une case disponible.

## difficultés rencontrées

### 1 
La première difficulté que j'ai rencontrée était lors de la création du joueur 2. Le programme ne demandais pas son nom mais seulement son symbole. Il s'agissait d'une erreur dans le fichier Player.cpp, en effet j'avais utilisé un std::getline le nom du joueur 2 était donc rentré avant qu'il soit demandé ce qui pouvait donner un resultat surprenant. J'ai simplement pu le remplacer par un std::cin.

### 2
La seconde concernait la séléction des symboles. Dans le mode 2 joueurs le joueur 2 pouvait choisir le même symbole que le joueur 1 ce qui non seulement rend le jeu illisible mais surtout lorsque 3 symboles étaient alignés (par exemple 2 posés par le joueur 1 et 1 posé par le joueur 2 pour le bloquer) cela donnait automatiquement la victoire au joueur 1
Pour résoudre ce probleme il a simplement fallu ajouter une condition dans la foncton two_player_mode empechant le joueur 2 de choisir le même symbole que le joueur 1.

### 3

Un autre "soucis" non résolu car il n'empeche en rien l'execution du programme ni le jeu c'est qu'on est obligé de finir la partie en cours pour pouvoir relancer le programme et refaire une partie.

### 4

J'ai également eu des problemes concernant la taille du tableau de jeu. En effet j'avais un message d'erreur disant que ses dimensions étaient redéfinis et j'ai passé pas mal de temps à vérifier que je n'avais pas touché à sa taille (qui est une constante) quelque part dans mon code. En réalité j'avais simplement oublié les pragma once dans mes headers.