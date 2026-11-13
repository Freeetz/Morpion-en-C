#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include "function.h"

int main() {
    bool wantToPlay = false;
    char choice[4];
    char joueur[20];

    printf("Souhaitez-vous jouer à \033[36mTic-Tac-Toe\033[0m ? (oui/non) ");
    scanf("%3s", choice);

    if (strcmp(choice, "oui") == 0) {
        system("clear");
        printf("Bienvenue sur notre jeu \033[33mTic-Tac-Toe\033[0m !\n\n");
        printf("Contre qui voulez-vous jouez ? (\033[36mlocal\033[0m/\033[36mordinateur\033[0m)\n");
        scanf("%19s", joueur);
        wantToPlay = true;
    } else if (strcmp(choice, "non") == 0) {
        printf("D'accord, \033[33mmerci\033[0m d'avoir utiliser notre outil !\n");
        wantToPlay = false;
        exit(0);
    } else {
        printf("\033[31mCommande invalide.\033[0m\n");
    }

    while (wantToPlay) {
        system("clear"); // Rendre le terminal propre
        TicTacToe(joueur);
        break;
    }
}

// wantToPlay = true;