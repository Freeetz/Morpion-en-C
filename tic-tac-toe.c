#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <time.h> 
#include <unistd.h>
#include "function.h"

char *valeurMorpion[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

int NotAlreadyPick(char *valeurMor) {
    if (strcmp(valeurMorpion[*valeurMor], " ") != 0) {
        printf("Il es interdit de \033[1;31mtricher\033[0m ! Cet case es déjà prise.\n\n");
        sleep(3);
        return 1;
    }

    return 0;
}

void ModifValue(int player, int valeurMorp, char verif) {
    if (NotAlreadyPick(&verif) == 0) {
        if (player == 1) {
            valeurMorpion[valeurMorp] = "\033[1;31mX\033[0m";
        } else if (player == 2) {
            valeurMorpion[valeurMorp] = "\033[1;36mO\033[0m";
        }
    }
}

int winner = 0;
void CheckNoWinner() {
    // Check joueur 1
    if (strcmp(valeurMorpion[0], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[1], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[2], "\033[1;31mX\033[0m") == 0) { // Ligne du haut
        winner = 1;
    } else if (strcmp(valeurMorpion[3], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[5], "\033[1;31mX\033[0m") == 0) { // Ligne du milieu
        winner = 1;
    } else if (strcmp(valeurMorpion[6], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[7], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[8], "\033[1;31mX\033[0m") == 0) { // Ligne du bas
        winner = 1;
    } else if (strcmp(valeurMorpion[0], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[8], "\033[1;31mX\033[0m") == 0) { // Ligne de en haut a gauche jusqu'en en bas a droite
        winner = 1;
    } else if (strcmp(valeurMorpion[2], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[6], "\033[1;31mX\033[0m") == 0) { // Ligne de en haut a droite jusqu'en en bas a gauche
        winner = 1;
    } else if (strcmp(valeurMorpion[0], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[3], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[6], "\033[1;31mX\033[0m") == 0) { // Ligne toute à gauche
        winner = 1;
    } else if (strcmp(valeurMorpion[1], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[7], "\033[1;31mX\033[0m") == 0) { // Ligne droite au milieu
        winner = 1;
    } else if (strcmp(valeurMorpion[2], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[5], "\033[1;31mX\033[0m") == 0 && strcmp(valeurMorpion[8], "\033[1;31mX\033[0m") == 0) { // Ligne toute à droite
        winner = 1;
    }

    // Check joueur 2
    if (strcmp(valeurMorpion[0], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[1], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[2], "\033[1;36mO\033[0m") == 0) { // Ligne du haut
        winner = 2;
    } else if (strcmp(valeurMorpion[3], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[5], "\033[1;36mO\033[0m") == 0) { // Ligne du milieu
        winner = 2;
    } else if (strcmp(valeurMorpion[6], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[7], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[8], "\033[1;36mO\033[0m") == 0) { // Ligne du bas
        winner = 2;
    } else if (strcmp(valeurMorpion[0], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[8], "\033[1;36mO\033[0m") == 0) { // Ligne de en haut a gauche jusqu'en en bas a droite
        winner = 2;
    } else if (strcmp(valeurMorpion[2], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[6], "\033[1;36mO\033[0m") == 0) { // Ligne de en haut a droite jusqu'en en bas a gauche
        winner = 2;
    } else if (strcmp(valeurMorpion[0], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[3], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[6], "\033[1;36mO\033[0m") == 0) { // Ligne toute à gauche
        winner = 2;
    } else if (strcmp(valeurMorpion[1], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[4], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[7], "\033[1;36mO\033[0m") == 0) { // Ligne droite au milieu
        winner = 2;
    } else if (strcmp(valeurMorpion[2], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[5], "\033[1;36mO\033[0m") == 0 && strcmp(valeurMorpion[8], "\033[1;36mO\033[0m") == 0) { // Ligne toute à droite
        winner = 2;
    }

    // Partie nul
    if (strcmp(valeurMorpion[0], " ") != 0 && strcmp(valeurMorpion[1], " ") != 0 && strcmp(valeurMorpion[2], " ") != 0 && strcmp(valeurMorpion[3], " ") != 0 && strcmp(valeurMorpion[4], " ") != 0 && strcmp(valeurMorpion[5], " ") != 0 && strcmp(valeurMorpion[6], " ") != 0 && strcmp(valeurMorpion[7], " ") != 0 && strcmp(valeurMorpion[8], " ") != 0) {
        printf("\033[31mMATCH NUL\033[0m - \033[31mAUCUN\033[0m GAGNANT !");
        exit(0);
    }
}

void TicTacToe(char joueur[]) {
    bool play = false;
    int choice;
    char prenom1[50], prenom2[50];
    int tour = 1;
    srand(time(NULL));

    if (strcmp(joueur, "local") == 0) {
        // Prise d'info JOUEUR 1 : 
        printf("Prénom du \033[1;31mJoueur 1\033[0m : ");
        scanf("%49s", prenom1);
        printf("%s vous jouer les \033[1;31mCROIX\033[0m ( \033[1;31mX\033[0m )\n", prenom1);

        // Prise d'info JOUEUR 2 : 
        printf("Prénom du \033[1;36mJoueur 2\033[0m : ");
        scanf("%49s", prenom2);
        printf("%s vous jouer les \033[1;36mCERCLE\033[0m ( \033[1;36mO\033[0m )\n", prenom2);
    }

    system("clear");
    play = true;

    while (play) {
        // Affichage tableau de jeu
        printf("        | %s | %s | %s \n", valeurMorpion[0], valeurMorpion[1], valeurMorpion[2]);
        printf("        |---|---|---\n");
        printf("        | %s | %s | %s \n", valeurMorpion[3], valeurMorpion[4], valeurMorpion[5]);
        printf("        |---|---|---\n");
        printf("        | %s | %s | %s \n", valeurMorpion[6], valeurMorpion[7], valeurMorpion[8]);
        // Fin affichage tableau de jeu

        if (strcmp(joueur, "local") == 0) {
            if (winner == 1) {
                printf("\033[1;35m%s\033[0m à \033[32mGAGNER\033[0m la partie !\n", prenom1);
                exit(0);
            } else if (winner == 2) {
                printf("\033[1;35m%s\033[0m à \033[32mGAGNER\033[0m la partie !\n", prenom2);
                exit(0);
            }
        } 

        if (strcmp(joueur, "ordinateur") == 0) {
            if (winner == 1) {
                printf("Vous avez \033[32mGAGNER\033[0m la partie !\n");
                exit(0);
            } else if (winner == 2) {
                printf("L'ordinateur a \033[32mGAGNER\033[0m la partie !\n");
                printf("\033[31mRetentez votre chance la prochaine fois..\033[0m");
                exit(0);
            }
        }

        if (tour == 1) {
            if (strcmp(joueur, "local") == 0) {
                printf("\033[35m%s\033[0m | Choisissez une case : ", prenom1);
                if (scanf("%d", &choice)) {
                    ModifValue(1, choice, choice);
                    system("clear");
                    CheckNoWinner();
                    tour = 2;
                } else {
                    printf("\033[31mERREUR : Veuillez indiquez un chiffre.\n\033[0m");
                    exit(0);
                }   
            } else {
                printf("Choisissez une case : ");
                if (scanf("%d", &choice)) {
                    if (choice >= 0 && choice < 9) {
                        ModifValue(1, choice, choice);
                        system("clear");
                        CheckNoWinner();
                        tour = 2;
                    } else {
                        printf("Choisissez un chiffre entre 0 et 8.");
                    }
                } else {
                    printf("\033[31mERREUR : Veuillez indiquez un chiffre.\n\033[0m");
                    exit(0);
                }   
            }
        } else if (tour == 2) {
            if (strcmp(joueur, "local") == 0) {
                printf("\033[35m%s\033[0m | Choisissez une case : ", prenom2);
                if (scanf("%d", &choice)) {
                    if (choice >= 0 && choice < 9) {
                        ModifValue(2, choice, choice);
                        system("clear");
                        CheckNoWinner();
                        tour = 1;
                    } else {
                        system("clear");
                        printf("Choisissez un chiffre entre 0 et 8.\n\n");
                    }
                } else {
                    printf("\033[31mERREUR : Veuillez indiquez un chiffre.\n\033[0m");
                    exit(0);
                }
            } else {
                // Ordi au pif
                int nombre = rand() % 9;
                printf("💡 L'ordinateur \033[33mréfléchis\033[0m..\n\n");
                sleep(3);
                while(strcmp(valeurMorpion[nombre], " ") != 0) nombre = rand() % 9; // Faire en sorte que l'ordi ne tombe pas sur une valeur déjà utiliser.
                ModifValue(2, nombre, nombre);
                system("clear");
                CheckNoWinner();
                tour = 1;
            }
        } else {
            printf("Erreur");
        }
        
    }

}