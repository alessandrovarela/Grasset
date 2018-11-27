// *****************************************************************************
// Nom : main.c
// Date : 16 octobre 2018
// Auteur : Rébecca
//
// main pilote pour l'utilitaire de dates.
// *****************************************************************************
#include <stdio.h>
#include "date.h"
#include "dateTest.h"

// *****************************************************************************
// main : pilote pour l'utilitaire de dates.
// Exécute les tests, lit une date, l'imprime et imprime le lendemain.
// *****************************************************************************
int main()
{
    // Tests unitaires
    testDate();
    printf("\n");

    // Exécution normale
    printf("Entrez une date (jj/mm/aaaa)\n");
    Date date = {1, 1, 1970};
    int m = JANVIER;
    scanf("%d/%d/%d", &date.jour, &m, &date.annee);
    date.mois = m;
    
    if (estValide(date))
    {
        imprimerDateLongue(date);
    	printf(".\nLe lendemain est ");
    	date = demain(date);
    	imprimerDateLongue(date);	
    }
    else
        printf("La date entrée n'est pas valide. \n");

    printf(".\n");
}
