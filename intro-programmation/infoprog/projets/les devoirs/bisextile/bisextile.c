// *****************************************************************************
// Nom    : bisextile.c
// Auteur : Alessandro Varela
// Date   : 6 septembre 2018
//
// Calcule si une année est bisexuelle
//
// *****************************************************************************


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int iAnnee;

	printf("Entrez avez une année:");
	scanf(" %d" , &iAnnee );


    if  (    ( ( iAnnee%400 == 0 ) ) //  se divise par 400
    	  ||  // ou
    	     ( ( iAnnee%4 == 0 ) && ( iAnnee%100 != 0 ) ) // se divise par 400 mais non par 100
    	)
        printf("Anné est Bisextile\n");
    else
    	printf("L'année n'est pas bisexuelle\n");


}