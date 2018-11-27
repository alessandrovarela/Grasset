// *****************************************************************************
//
// Nom : yahtzee.h
//
// Auteurs : Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// Date : 17 octobre 2018
//
// Liste de fonctions et documentation pour trouver le pointage donné pour une
// figure pour un jet.
//
// *****************************************************************************

#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define NOMBREDES 5
#define QUANTITETOUR 13

enum {FACESCHANCE    = 1,
      FACESDOUBLE    = 2,
      FACESBRELAN    = 3,
      FACESCARRE     = 4,
      FACESYATHZEE   = 5,
      SEQPETITESUITE = 4,
      SEQGRANDESUITE = 5,
      MINFACEDES     = 1,
      MAXFACEDES     = 6,}; 

enum Points {POINTSMAINPLEINE  = 25,
             POINTSPETITSUITE  = 30,
             POINTSGRANDESUITE = 40,
             POINTSYATHZEE     = 50,
             POINTSBONUS       = 63,
             BONUS             = 35};

typedef enum Boolean Boolean;
enum Boolean { FAUX , VRAI };

typedef enum Faces Faces; 
enum Faces {UN     = 1, 
            DEUX   = 2, 
            TROIS  = 3, 
            QUATRE = 4, 
            CINQ   = 5, 
            SIX    = 6 };

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
// Structure pour le pointage du jeu. Comprend touts le possibilité de 
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
// trierLesDes
// 
// Organize les dés dans l'ordre croissant
// 
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT : 
//     jet : cinq dés.
//
// OUTPUT : 
//     un structure avec les 5 dés triés par ordre croissant.
//
// Exemple :
//      trierLesDes({1,4,5,3,1}) = {1,1,3,4,5};
//      trierLesDes({5,4,3,2,1}) = {1,2,3,4,5};
// *****************************************************************************
Jet trierLesDes(Jet jet);

// *****************************************************************************
// retourneSommeFaces
//
// Valide le nombre des faces pour les figures "brelan", "carre", "yahtzee" et 
// "chance".
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     jet : cinq dés.
//     int : nombre de faces
//
// OUTPUT : 
//     La somme de tout les faces si le nombre de faces est valide pour les figures
//     "brelan", "carre", "yahtzee" et "chance".
//
// Exemples :
//     retourneSommeFaces({1,1,1,3,4}) = 1 + 1 + 1 + 3 + 4 = 10; (brelan)
//     retourneSommeFaces({5,5,5,5,2}) = 5 + 5 + 5 + 5 + 2 = 22; (carre)   
// *****************************************************************************
int retourneSommeFaces(Jet jet, int nombreFaces); //sugestão: alterar nome da função para sommeFaces. 

// *****************************************************************************
// valideSequence
//
// Valide une sequence des dés pour les figures "petite suite" et "grande suite".
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     jet : cinq dés.
//     int : sequence
//
// OUTPUT : 
//     1 si la sequence est vrai pour les figures "petite suite" et "grande suite"
//     et zero se la sequence est faux pour les deux figures. 
//
// Exemples :
//     valideSequence({1,5,2,4,3}, 5) = 1 (grande suite)
//     valideSequence({2,4,3,6,6}), 4) = 0 (FAUX pour le petite suite)   
// *****************************************************************************
int valideSequence (Jet jet, int sequence);

// *****************************************************************************
// lancerLesDes
//
// 
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     jet : cinq dés.
//     char : choix[6]
//
// OUTPUT : 
//     
//
// Exemples :
//     
//        
// *****************************************************************************
// Jet lancerLesDes(Jet jet , char choix[6]);
void lancerLesDes(Jet* jet , char choix[6]);

// *****************************************************************************
// garderPointage
//
// 
//
// AUTEURS: Alessandro Varela 
//
// INPUT :
//     jet : cinq dés.
//     pointeur : Pointage* feuilleScore 
//     char : figure
//
// OUTPUT : 
//     
//
// Exemples :
//     
//        
// *****************************************************************************
void garderPointage(Jet jet, Pointage* feuilleScore,  char figure);

// *****************************************************************************
// sommeScoreSup
//
// 
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     pointeur : Pointage* feuilleScore 
//     
//
// OUTPUT : 
//     
//
// Exemples :
//     
//        
// *****************************************************************************
int sommeScoreSup(Pointage* feuilleScore);

// *****************************************************************************
// sommeScoreInf
//
// 
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     pointeur : Pointage* feuilleScore 
//     
//
// OUTPUT : 
//     
//
// Exemples :
//     
//        
// *****************************************************************************
int sommeScoreInf(Pointage* feuilleScore);


// *****************************************************************************
void imprimerLesFaces(Faces nombreFace, int nombreRangee);
// *****************************************************************************
// imprimerLesDes
//
// Imprime les dés qui ont été lancés.
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     jet : cinq dés
//     
// OUTPUT : 
//     la sequence des dés qui ont été lancés a chaque tour.
//
// Exemples :
//     ?????????????
//        
// *****************************************************************************
void imprimerLesDes(Jet jet);

// *****************************************************************************
// imprimerScoresPossibles
//
// Imprime un tableau aprés la troisiéme chance de chaque tour avec le pointage 
// possible pour chaque option compte tenu le resultat donné par les dés.
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     jet : cinq dés
//     
// OUTPUT : 
//  ????????????????????????   
//
// Exemples :
//     ???????????????????
//        
// *****************************************************************************
void imprimerScoresPossibles(Jet jet);

// *****************************************************************************
// imprimerFeuilleScore
//
// Imprime la feuille de Score avant chaque tour compte tenu les selection fait
// par le jouer en chaque tour.
//
// AUTEURS: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// INPUT :
//     jet : cinq dés
//
// OUTPUT : 
//     ???????????????????????
//
// Exemples :
//     ??????????????????????
//        
// *****************************************************************************
void imprimerFeuilleScore(Pointage* feuilleScore, int tour); //alterei para Feuille

// *****************************************************************************
// jouerYathzee
//
// 
//
// AUTEURS: Alessandro Varela
//
// INPUT :
//     pointuer
//     tour     
//
// OUTPUT : 
//     ??????
//
// Exemples :
//     ??????
//        
// *****************************************************************************
void jouerYahtzee(); //precisamos manter as informações no arquivo yahtzee.c se vamos documentar ela aqui?
