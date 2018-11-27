// *****************************************************************************
// Nom    : carre-5etoiles.c
// Auteur : Alessandro Varela
// Date   : 9 septembre 2018
//
// Dessine un carré de 5 étoiles
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int iEtoile = 1;
	int iSaute  = 1;

	while ( iSaute <= 5 )
	{

		while ( iEtoile <= 5)
		{
			printf(" *");
			iEtoile++;
		}

			printf("\n");
            iEtoile = 1;
			iSaute++;

	}

}