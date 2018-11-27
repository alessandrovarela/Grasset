// *****************************************************************************
// Fichier : assert.h
// Auteur : Rébecca
// Date : 15 octobre 2018
//
// Utilitaire pour les tests unitaires.
// *****************************************************************************
#pragma once

// *****************************************************************************
// assertEgal
//
// Vérifie que deux entiers sont identiques et imprime un message approprié
//
// INPUT :
//     message : la description du test
//     attendu : le résultat attendu de la fonction testée
//     obtenu : le résultat obtenu de la fonction testée
// *****************************************************************************
void assertEgal(char* message, int attendu, int obtenu);
