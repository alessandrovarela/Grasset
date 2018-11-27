// *****************************************************************************
// Nom    : bonus.c
// Auteur : Alessandro Varela
// Date   : 12 septembre 2018
//
// Cette programa inverse l'ordre des chiffres dans un
// nombre entier strictement positif.
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>


int main()
{
	const int iBase10 = 10;

	int iNumPositif = 0;

	while ( iNumPositif <= 0 )
	{
	    printf("Entrez une nombre Positif:");
	    scanf("%d", &iNumPositif);
	}

	int iResultatDiv = iNumPositif;
    int iReste ;
    int iImprime = 1;
    

    printf("%d à l'envers est ", iNumPositif );

    // Contrôle pour ne pas imprimer les zéros a gauche pour des multiples de 10
    if ( iNumPositif%iBase10 == 0 )
		 iImprime = 0;

	while ( iResultatDiv >= iBase10 )
	{
		iReste = iResultatDiv%iBase10;
		iResultatDiv /= iBase10;
		
		if ( iImprime ) 
      		printf("%d",  iReste );

	}

	printf("%d.\n",  iResultatDiv );
}