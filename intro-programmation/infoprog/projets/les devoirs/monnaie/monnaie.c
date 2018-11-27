//*****************************************************************************
// Nom    : monnaie.c
// Auteur : Alessandro Varela
// Date   : 6 septembre 2018
//
// divide montant à l’aide de pièces de monnaie
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int iMont;

    int iMonn25;
    int iMonn10;
    int iMonn05;
    int iMonn01;
    float fRestTemp;


    printf("Entrez avec montant:");
    scanf("%d", &iMont);

    iMonn25   = iMont / 25.0;
	fRestTemp = iMont%25;

    iMonn10   = fRestTemp / 10;
    fRestTemp = iMont%10;

    if ( ( fRestTemp / 5 ) < 5 )
        iMonn05 = 0;    	
    else
       iMonn05   = fRestTemp / 5;

    
    iMonn01   = fRestTemp / 1;      	

    
    fRestTemp = iMont%5;

    printf("%d * de 25C\n" , iMonn25);
    printf("%d * de 10C\n" , iMonn10);
    printf("%d * de 5C\n"  , iMonn05);
    printf("%d * de 1C\n"  , iMonn01);


    







}