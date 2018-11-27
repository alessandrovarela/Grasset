// *****************************************************************************
// Nom : mois.c
// Auteur : Rébecca
// Date : 5 septembre 2018
//
// Imprime le nombre de jours dans un mois donné
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int JANVIER = 1;
    const int FEVRIER = 2;
    const int AVRIL = 4;
    const int JUIN = 6;
    const int SEPTEMBRE = 9;
    const int NOVEMBRE = 11;
    const int DECEMBRE = 12;

    printf("Entrez un mois (entre 1 et 12)\n");
    int mois = 0;
    scanf("%d", &mois);
    
    // DÉBUT DIAGRAMME
    if ((mois > DECEMBRE) || (mois < JANVIER))
    {
    	printf("Le mois doit etre entre 1 et 12.\n");
    }
    else if ((mois == AVRIL) || (mois == JUIN) || (mois == SEPTEMBRE) || (mois == NOVEMBRE))
    {
    	printf("Le mois #%d a 30 jours.\n", mois);
    }
    else if (mois == FEVRIER)
    {
    	printf("Le mois #%d a 28 ou 29 jours.\n", mois);
    }
    else
    {
    	printf("Le mois #%d a 31 jours.\n", mois);
    }
    // FIN DIAGRAMME
}
