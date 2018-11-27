// *****************************************************************************
// Nom : yahtzee.h
//
// Auteurs : Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// Date : 17 octobre 2018
//
// Liste de fonctions et documentation pour trouver le pointage donné pour une
// figure pour un jet - Jeu Yahtzee
//
// *****************************************************************************

#pragma once

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOMBREDES 5 //nombre de dés du jeu
#define QUANTITETOUR 13 //quantité de tours du jeu

// *****************************************************************************
// Enum 
//
// Quantité des faces de chaque possibilité de pointage du jeu.
//
//*****************************************************************************
enum {FACESCHANCE    = 1,
      FACESDOUBLE    = 2,
      FACESBRELAN    = 3,
      FACESCARRE     = 4,
      FACESYATHZEE   = 5,
      SEQPETITESUITE = 4,
      SEQGRANDESUITE = 5,
      MINFACEDES     = 1,
      MAXFACEDES     = 6}; 

// *****************************************************************************
// Enum Points
//
// Pointage des figures du jeu qui ne sont pas la somme des dés.
//
//*****************************************************************************
enum Points {POINTSMAINPLEINE  = 25,
             POINTSPETITSUITE  = 30,
             POINTSGRANDESUITE = 40,
             POINTSYATHZEE     = 50,
             POINTSBONUS       = 63,
             BONUS             = 35};

// *****************************************************************************
// Enum Rangees
//
// Qunatité de rangées pour imprimer les dés
//
//*****************************************************************************
enum Rangees {RANGEE, RANGEEUN, RANGEEDEUX, RANGEETROIS, RANGEEQUATRE};

// *****************************************************************************
// Structure Boolean
//
// Vrai ou Faux
//
//*****************************************************************************
typedef enum Boolean Boolean;
enum Boolean {FAUX,VRAI};

// *****************************************************************************
// Structure Faces
//
// Nombre de faces d'un dés
//
//*****************************************************************************
enum Faces {UN     = 1, 
            DEUX   = 2, 
            TROIS  = 3, 
            QUATRE = 4, 
            CINQ   = 5, 
            SIX    = 6};

// *****************************************************************************
// Structure Jet
//
// Nombre de dés du jeu
//
//*****************************************************************************
typedef struct Jet Jet; 
struct Jet 
{
    int des[5]; 
};

// *****************************************************************************
// Structure Pointage
//
// Liste de type de pointage du jeu. Comprend touts le possibilité de 
// ponctuation.
//
//*****************************************************************************
typedef struct Pointage Pointage; 
struct Pointage 
{
    int un; 
    int deux;
    int trois;
    int quatre;
    int cinq;
    int six;
    int brelan;
    int carre;
    int mainPleine;
    int pSuite;
    int gSuite;
    int yahtzee;
    int chance;
};

// *****************************************************************************
// lancerLesDes
//
// Lance les dés a chaque tour et a chaque choix d'utilisateur.
// Cree un nombre au hasard de 1 a 6 a chaque position du jet compte tenu la choix
// de l'utilisateur. 
//
// INPUT :
//     jet: cinq dés.
//     char: choix[6]
//
// OUTPUT : 
//     void
//        
// *****************************************************************************
void lancerLesDes(Jet* jet , char choix[6]);

// *****************************************************************************
// imprimerLesFaces
// 
// Imprime les faces des dés
//
// INPUT :
//     nombreFace: les faces des dés
//     nombreRangee: nombre de rangées
//
// OUTPUT : 
//     void
//
// *****************************************************************************
void imprimerLesFaces(int faces, int nombreRangee);

// *****************************************************************************
// imprimerLesDes
//
// Imprime les dés qui ont été lancés.
//
// INPUT :
//     jet : cinq dés
//     
// OUTPUT : 
//     void
//
// *****************************************************************************
void imprimerLesDes(Jet jet);

// *****************************************************************************
// trierLesDes
// 
// Organize les dés dans l'ordre croissant
// 
// INPUT : 
//     jet : cinq dés.
//
// OUTPUT : 
//     un structure avec les 5 dés triés par ordre croissant.
//
// *****************************************************************************
Jet trierLesDes(Jet jet);

// *****************************************************************************
// sommeFaces
//
// Valide le nombre des faces pour les figures "brelan", "carre", "yahtzee" et 
// "chance".
//
// INPUT :
//     jet : cinq dés.
//     int : nombre de faces
//
// OUTPUT : 
//     La somme de tout les faces si le nombre de faces est valide pour les figures
//     "brelan", "carre", "yahtzee" et "chance".
//
// *****************************************************************************
int sommeFaces(Jet jet, int nombreFaces); //sugestão: alterar nome da função para sommeFaces.

// *****************************************************************************
// valideSequence
//
// Valide une sequence des dés pour les figures "petite suite" et "grande suite".
//
// INPUT :
//     jet : cinq dés.
//     int : sequence
//
// OUTPUT : 
//     1 si la sequence est vrai pour les figures "petite suite" et "grande suite"
//     et zero se la sequence est faux pour les deux figures. 
//   
// *****************************************************************************
int valideSequence (Jet jet, int sequence);

// *****************************************************************************
// nbDeFace
//
// Calcule le pointage pour la figure "face"
//
// INPUT :
//     jet : cinq dés.
//     face : la face a comptabiliser.
//
// OUTPUT :
//     le pointage pour face dans jet. Le pointage est le produit de face et du
//     nombre de des dans jets qui valent face.
//
// Exemples :
//     nbDeFace({5,5,1,3,2}, 5) = 2 * 5 = 10;
//     nbDeFace({5,5,1,3,2}, 1) = 1 * 1 = 1;
//     nbDeFace({5,5,1,3,2}, 2) = 1 * 2 = 2;
//     nbDeFace({2,2,1,1,2}, 2) = 3 * 2 = 6;
// *****************************************************************************
int nbDeFace(Jet jet, int face);

// *****************************************************************************
// brelan
//
// Calcule le pointage pour la figure "brelan"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour brelan dans jet. Un brelan est trois faces
//     identiques. Il vaut la somme de dés.
//
// Exemples :
//     brelan({5,5,1,3,2}) = 0;
//     brelan({2,2,1,5,2}) = 2 + 2 + 1 + 5 + 2 = 12;
// *****************************************************************************
int brelan(Jet jet);

// *****************************************************************************
// carre
//
// Calcule le pointage pour la figure "carre"
//
// INPUT :
//      jet : cinq dés.
//
// OUTPUT :
//     le pointage pour carre dans jet. Un carre est quatres faces
//     identiques. Il vaut la somme des dés.
//
// Exemples :
//     carre({5,5,1,3,2}) = 0;
//     carre({2,2,1,2,2}) = 2 + 2 + 1 + 2 + 2 = 9;
// *****************************************************************************
int carre(Jet jet);

// *****************************************************************************
// mainPleine
//
// Calcule le pointage pour la figure "main pleine"
//
// INPUT :
//      jet : cinq dés.
//
// OUTPUT :
//     le pointage pour main pleine dans jet. Une main pleine est trois faces
//     identiques et deux faces identiques. Elle vaut 25 points.
//
// Exemples :
//     mainPleine({5,5,5,3,2}) = 0;
//     mainPleine({2,2,1,1,2}) = 25;
// *****************************************************************************
int mainPleine(Jet jet);

// *****************************************************************************
// petiteSuite
//
// Calcule le pointage pour la figure "petite suite"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour petite suite dans jet. Une petite suite vaut 30
//     points. Il y a trois petites suites possibles : 1,2,3,4 ou 2,3,4,5 ou
//     3,4,5,6. L’ordre des dés n’a pas d’importance
//
// Exemples :
//     petiteSuite{{5,3,2,3,4}) = 30;
//     petiteSuite({2,3,5,6,1}) = 0;
// *****************************************************************************
int petiteSuite(Jet jet);

// *****************************************************************************
// grandeSuite
//
// Calcule le pointage pour la figure "grande suite"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour grande suite dans jet. Une grande suite vaut 40
//     points. Il y a deux grandes suites possibles : 1,2,3,4,5 ou
//     2,3,4,5,6. L’ordre des dés n’a pas d’importance.
//
// Exemples :
//     grandeSuite{{5,3,2,6,4}) = 40;
//     grandeSuite({2,3,5,6,1}) = 0;
// *****************************************************************************
int grandeSuite(Jet jet);

// *****************************************************************************
// yahtzee
//
// Calcule le pointage pour la figure "yahtzee"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour yahtzee dans jet. Un yahtzee est cinq des identiques. Il
//     vaut 50 points.
//
// Exemples :
//     yahtzee{{2,2,2,2,2}) = 50;
//     yahtzee({2,3,2,2,2}) = 0;
// *****************************************************************************
int yahtzee(Jet jet);

// *****************************************************************************
// chance
//
// Calcule le pointage pour la figure "chance"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT : 
//     le pointage pour chance est la somme des faces.
//
// Exemples :
//     chance{{5,6,2,1,4}) = 18;
//     chance({1,1,1,1,3}) = 7;
// *****************************************************************************
int chance(Jet jet);

// *****************************************************************************
// imprimerScoresPossibles
//
// Imprime un tableau aprés la troisiéme chance de chaque tour avec le pointage 
// possible compte tenu la combinaison des dés.
//
// INPUT :
//     jet: cinq dés
//     
// OUTPUT : 
//     void   
//       
// *****************************************************************************
void imprimerScoresPossibles(Jet jet);

// *****************************************************************************
// garderPointage
//
// Enregistre le pointage choisi par l'utilisateur à chaque fin de tour dans la
// feuille de pointage. 
//
// INPUT :
//     jet: cinq dés.
//     feuilleScore: pointeur vers les possibilités de ponctuation
//     figure: une des possibilités de ponctuation
//
// OUTPUT : 
//     void
//        
// *****************************************************************************
void garderPointage(Jet jet, Pointage* feuilleScore, char figure);

// *****************************************************************************
// sommeScoreSup
//
// Somme le score de la feuille supérieur qui comprend les nombres un, deux, 
// trois, quatre, cinq et six.
//
// INPUT :
//     feuilleScore: pointeur vers les possibilités de ponctuation
//          
// OUTPUT : 
//     somme du score de la feuille supérieur
//
// *****************************************************************************
int sommeScoreSup(Pointage* feuilleScore);

// *****************************************************************************
// sommeScoreInf
//
// Somme le score de la feuille inférieur qui comprend le Brelan, le Carré, le 
// Main Pleine, le Petite Suite, le Grande Suite, le Yahtzee et la Chance
//
// INPUT :
//     feuilleScore: pointeur vers les possibilités de ponctuation 
//     
// OUTPUT : 
//     somme du score de la feuille inférieur
//
// *****************************************************************************
int sommeScoreInf(Pointage* feuilleScore);

// *****************************************************************************
// imprimerFeuilleScore
//
// Imprime la feuille de Score compte tenu les selections de pointage fait par
// l'utilisateur en chaque tour.
//
// INPUT :
//     feuilleScore: pointeur vers les possibilités de ponctuation
//     tour: nombre du tour
// 
// OUTPUT : 
//     void
//        
// *****************************************************************************
void imprimerFeuilleScore(Pointage* feuilleScore, int tour);

// *****************************************************************************
// jouerYathzee
//
// Démarre le jeu en appelant toutes les fonctions précédéntes.  
//
// *****************************************************************************
void jouerYahtzee();
