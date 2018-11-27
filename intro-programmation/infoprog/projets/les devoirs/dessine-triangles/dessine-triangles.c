// *****************************************************************************
// Nom    : dessine-triangles.c
// Auteur : Alessandro Varela
// Date   : 9 septembre 2018
//
// dessine des triangles de différentes formes
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{

	const int iMaxLignes = 10;
	
	int iLignes       = 0;
	int iEtoiles      = 1;
	int iEtoilesPrec  = 0;


    // Triagle 01
    printf("Triagle 01");
	while ( iLignes <= iMaxLignes )
	{

		while ( iEtoiles < iEtoilesPrec )
		{
			printf(" *");
			iEtoiles++;
		}


		printf("\n");

        iEtoiles = 0;
        iEtoilesPrec++;        
        iLignes++;

	}

 // Triagle 02

    printf("\n");
    printf("Triagle 02");

	iLignes       = 0;
	iEtoiles      = iMaxLignes;
	iEtoilesPrec  = iMaxLignes;


	while ( iLignes <= iMaxLignes )
	{

		while ( iEtoiles < iEtoilesPrec )
		{
			printf(" *");
			iEtoiles++;
		}


		printf("\n");

        iEtoiles = 0;
        iEtoilesPrec--;        
        iLignes++;

	}	


 // Triagle 03

    printf("\n");
    printf("Triagle 03\n");

	int iEspace       = 0;

	iLignes       = 1;
	iEtoiles      = 0;
	


	while ( iLignes <= iMaxLignes )
	{

		// imprime les espaces
		while ( iEspace < ( iMaxLignes - iLignes ) )
		{
			printf(" ");
			iEspace++;
		}

         
		// imprime les etoiles
		while ( iEtoiles < iLignes  )
		{
			printf(" *");
			iEtoiles++;
		}


		printf("\n");

        iEspace  = 0;
        iEtoiles = 0;
        iLignes++;

	}	

// Triagle 04

    printf("\n");
    printf("Triagle 04\n");

	iEspace       = 0;
	iLignes       = 1;
	iEtoiles      = 0;
	


	while ( iLignes <= iMaxLignes )
	{

		// imprime les espaces
		while ( iEspace < ( iMaxLignes - iLignes ) )
		{
			printf("  ");
			iEspace++;
		}

         
		// imprime les etoiles
		while ( iEtoiles < iLignes  )
		{
			printf(" *");
			iEtoiles++;
		}


		printf("\n");

        iEspace  = 0;
        iEtoiles = 0;
        iLignes++;

	}	

// Triagle 05

    printf("\n");
    printf("Triagle 05\n");

	iEspace       = 0;
	iLignes       = 1;
	iEtoiles      = 0;
	


	while ( iLignes <= iMaxLignes )
	{

		// imprime les espaces
		while ( iEspace < (  iLignes - 1  ) )
		{
			printf("  ");
			iEspace++;
		}

         
		// imprime les etoiles
		while ( iEtoiles < ( iMaxLignes - ( iLignes - 1 )  ) )
		{
			printf(" *");
			iEtoiles++;
		}


		printf("\n");

        iEspace  = 0;
        iEtoiles = 0;
        iLignes++;

	}	


}