
// *****************************************************************************
//
// Nom : boggle.h
//
// Auteurs : Carolina Spaniol
//
// Date : 12 decembre 2018
//
// Documentation des fonctions du jeu Boggle 
//
// *****************************************************************************


#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RANGEES 4 //nombre de lignes dans un matrice (grille)
#define COLONNES 4 //nombre de rangees dans un matrice (grille)
#define NB_FACES 6 //nombre de faces de chaque dés
#define MAXCOL 6 //maximum de colonnes pour faire le random de dés
#define MINCOL 0  //minimum de colonnes pour faire le random de dés
#define MAXGRILLE 4 //maximum de colonnes/lignes pour ajouter les dés dans la grille au hasard
#define MINGRILLE 0 //minimum de colonnes/lignes pour ajouter les dés dans la grille au hasard
#define FICHIERDIC "francais.txt" //dictionnaire
#define BUFF 30 //nombre de cases dans les mots
#define BUFFRANGEESDIC 500 //nombre de ligne dans le tableau dictionnaire

// *****************************************************************************
// Matrice de dés du jeu. 
// *****************************************************************************
const char DES[RANGEES * COLONNES][NB_FACES] =
{{'E', 'T', 'U', 'K', 'N', 'O'}, 
{'E', 'V', 'G', 'T', 'I', 'N'}, 
{'D', 'E', 'C', 'A', 'M', 'P'}, 
{'I', 'E', 'L', 'R', 'U', 'W'}, 
{'E', 'H', 'I', 'F', 'S', 'E'}, 
{'R', 'E', 'C', 'A', 'L', 'S'}, 
{'E', 'N', 'T', 'D', 'O', 'S'}, 
{'O', 'F', 'X', 'R', 'I', 'A'}, 
{'N', 'A', 'V', 'E', 'D', 'Z'}, 
{'E', 'I', 'O', 'A', 'T', 'A'}, 
{'G', 'L', 'E', 'N', 'Y', 'U'}, 
{'B', 'M', 'A', 'Q', 'J', 'O'}, 
{'T', 'L', 'I', 'B', 'R', 'A'}, 
{'S', 'P', 'U', 'L', 'T', 'E'}, 
{'A', 'I', 'M', 'S', 'O', 'R'}, 
{'E', 'N', 'H', 'R', 'I', 'S'}};

// *****************************************************************************
// nbCase
//
// Retourne une position au hasard du dés dans la colonne
//
// INPUT :
//     void
//
// OUTPUT :
//	   entiere: nombre da position de la colonne du dés (entre 0 et 5) 	   
// *****************************************************************************
int nbCase();

// *****************************************************************************
// nbCaseGrille
//
// Retourne une position au hasard dans la grille.
//
// INPUT :
//     void
//
// OUTPUT :
//	   entiere: une position dans la grille.  	   
// *****************************************************************************
int nbCaseGrille();

// *****************************************************************************
// lancerlesDes
//
// Lance les dés a chaque tour. Retourne un lettre qui est dans le dés au hasard.
// Un chance sur six.
//
// INPUT :
//     entiere: nombre de la ligne.
//
// OUTPUT :
//	   char: un lettre de un face du dés. 	   
// *****************************************************************************
char lancerLesDes(int nbRangee);

// *****************************************************************************
// imprimerGrille
//
// Imprime la grille du Jeu. 
//
// INPUT :
//     matrice char: grille du jeu.
//
// OUTPUT :
//	   void	   
// *****************************************************************************
void imprimerGrille(char grille[RANGEES][COLONNES]);

// *****************************************************************************
// grilleComplete
//
// Valide si la grille est complete, c'est-à-dire si toutes les cases étaient
// remplies d'un dés.  
//
// INPUT :
//     matrice char: grille du jeu.
//
// OUTPUT :
//	   entiere: vrai ou faux
// *****************************************************************************
int grilleComplete(char grille[RANGEES][COLONNES]);

// *****************************************************************************
// remplirGrille
//
// Ajoute un dés dans la matrice Grille si le case est vide.   
//
// INPUT :
//     matrice char: grille du jeu.
//
// OUTPUT :
//	   void
// *****************************************************************************
void remplirGrille(char grille[RANGEES][COLONNES]);

// *****************************************************************************
// reinitialiserVisite
//
// Réinitialise le matrice avec zero.  
//
// INPUT :
//     matrice char: grille du jeu.
//
// OUTPUT :
//	   void
// *****************************************************************************
void reinitialiserVisite(char visite[RANGEES][COLONNES]);

// *****************************************************************************
// formertMot
//
// Détermine si un mot est dans la grille à partir d'un dés.  
//
// INPUT :
//		matrice char: grille du jeu.
//		matrice char: visite (marque les positions visitées)
//      char: mot (le mot tappez par l'utilisateur)
//		entier: nombre de la ligne dans la matrice
//		entier: nombre da colonne dans la matrice
// OUTPUT :
//	   entiere: VRAI ou FAUX
// *****************************************************************************
int formerMot(char grille[RANGEES][COLONNES], char visite[RANGEES][COLONNES], char mot[], int r, int c);

// *****************************************************************************
// motDansGrille
//
// Détermine si un mot est dans la Grille du jeu.
//
// INPUT :
//		matrice char: grille du jeu.
//		matrice char: visite (marque les positions visitées)
//      char: mot (le mot tappez par l'utilisateur)

// OUTPUT :
//	   entiere: VRAI ou FAUX
// *****************************************************************************
int motDansGrille(char grille[RANGEES][COLONNES],char visite[RANGEES][COLONNES],char mot[]);

// *****************************************************************************
// imprimerMotPossible
//
// Imprime tous les mots possibles dans la Grille du jeu. La fonction imprime
// aussi le mot plus long dans la Grille. 
//
// INPUT :
//		matrice char: grille du jeu.
//		matrice char: visite (marque les positions visitées)
//      char**: dictionnaire
//		entier: taille du dictionnaire (nombre de lignes)
//
// OUTPUT :
//	   void
// *****************************************************************************
void imprimerMotPossible(char grille[RANGEES][COLONNES], char visite[RANGEES][COLONNES], char** dictionnaire, int tailleDict);

// *****************************************************************************
// libererMemoire
//
// Libère la mémoire en cas de malloc/realloc.
//
// INPUT :
//      char**: pointeur vers un pointeur
//		entiere: taille de la matrice.
//
// OUTPUT :
//	   void
// *****************************************************************************
void libererMemoire(char** matrice, int tailleMatrice);

// *****************************************************************************
// creertabStocker
//
// Tableau qui stocke les mots tappez par l'utilisateur.
//
// INPUT :
//     void
//
// OUTPUT :
//	   char**: pointeur vers un pointeur
// *****************************************************************************
char** creerTabStocker();

// *****************************************************************************
// augmenterStocker
//
// Augmente le tableau stocker si nécessaire.
//
// INPUT :
//     char**: pointeur vers un pointeur
//	   entier: taille à augmenter
//
// OUTPUT :
//	   void
// *****************************************************************************
void augmenterStocker(char** stocker, int taille);

// *****************************************************************************
// ajouterMotStocker
//
// Ajoute les mot dans Stocker.
//
// INPUT :
//     char**: pointeur vers un pointeur
//	   entier: position du mot
//	   char: mot 
//
// OUTPUT :
//	   void
// *****************************************************************************
void ajouterMotStocker(char** stocker, int indexStocker, char mot[]);

// *****************************************************************************
// calculerScore
//
// Calcule le score du jeu.
//
// INPUT :
//     char: mot 
//
// OUTPUT :
//	   entier: score total de chaque mot
// *****************************************************************************
int calculerScore(char mot[]);

// *****************************************************************************
// validerDuplicite
//
// Valide si un mot a déjà été tapé par l'utilisateur.
//
// INPUT :
//     char**: tableau où les mot tapés par l'utilisateur sont stocké
//	   entier: taille du tableau stocker
//	   char: mot 
//
// OUTPUT :
//	   entier: VRAI au FAUX
// *****************************************************************************
int validerDuplicite(char** stocker, int tailleStocker, char mot[]);

// *****************************************************************************
// imprimerStocker
//
// Imprime stocker.
//
// INPUT :
//     char**: tableau où les mot tapés par l'utilisateur sont stocké
//	   entier: taille du tableau stocker
//
// OUTPUT :
//	   void
// *****************************************************************************
void imprimerStocker(char** stocker, int tailleStocker);

// *****************************************************************************
// imprimerMeilleurMotJoeur
//
// Imprime le mot plus long tapé par l'utilisateur.
//
// INPUT :
//     char**: tableau où les mot tapés par l'utilisateur sont stocké
//	   entier: taille du tableau stocker
//
// OUTPUT :
//	   void
// *****************************************************************************
void imprimerMeilleurMotJouer(char** stocker, int tailleStocker);

// *****************************************************************************
// imprimerInstructions
//
// Imprime les instructions du jeu.
//
// INPUT :
//     void
//
// OUTPUT :
//	   void
// *****************************************************************************
void imprimerInstrutions();