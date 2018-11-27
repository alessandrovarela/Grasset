// *****************************************************************************
// Fichier : assert.c
// Auteur : Rébecca
// Date : 15 octobre 2018
//
// Utilitaire pour les tests unitaires.
// *****************************************************************************

#include <stdio.h>
#include "assert.h"

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
void assertEgal(char* message, int attendu, int obtenu)
{
    if (obtenu == attendu)
        printf("RÉUSSI %s = %d\n", message, attendu);
    else
        printf("ÉCHEC %s = %d, mais on voulait %d\n", message, obtenu, attendu);
}
