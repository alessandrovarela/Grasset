#pragma once
#include "boggle.h"

// *****************************************************************************
// chargerDictionnaire
//
// Transfére le dictionnaire pour un tableau.
//
// INPUT :
//     pCompteDic: variable pointeur qui compte le nombre de lignes du 
// 	   dictionnaire
//
// OUTPUT :
//	   char**: dictionnaire
// 	   
// *****************************************************************************
char** chargeDictionnaire(int* pCompteDic);

// *****************************************************************************
// trouverMotDict
//
// Trouve un mot dans le dictionnaire.
// On a utilisé le code de recherche binaire qui on a appris en Java comme base
// pour faire le code en C. 
//
// INPUT :
//     char mot[]: mot
//	   char** dictionnaire: le tableau du dictionnaire
//	   entiere tailleDict: nombre de lignes du dictionnaire
//
// OUTPUT :
//		entiere: va retourner 1 pour VRAI et 0 pour FAUX.
// 	   
// *****************************************************************************
int trouverMotDict(char mot[], char** dictionnaire, int tailleDict);