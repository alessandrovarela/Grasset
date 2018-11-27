// *****************************************************************************
// Nom    : carre-1-10-etoiles.c
// Auteur : Alessandro Varela
// Date   : 9 septembre 2018
//
// Dessine un carré entre 1 e 10 étoiles
// Si l’utilisateur entre un nombre invalide, redemandez-lui d’entrer 
// un nombre tant qu’il entre un nombre invalide.
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int iUserEtoile;

	int iEtoile = 1;
	int iSaute  = 1;

	while ( ! ( iUserEtoile >= 1 && iUserEtoile <= 10 ) )
	{	
		printf("Entre avec number etoile entre 1 et 10:" );
		scanf("%d" , &iUserEtoile );
    }

	while ( iSaute <= iUserEtoile )
	{

		while ( iEtoile <= iUserEtoile )
		{
			printf(" *");
			iEtoile++;
		}

			printf("\n");
            iEtoile = 1;
			iSaute++;

	}

}