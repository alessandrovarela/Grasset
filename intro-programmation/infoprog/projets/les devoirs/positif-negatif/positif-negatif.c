//*****************************************************************************
// Nom    : positif-negatif.c
// Auteur : Alessandro Varela
// Date   : 6 septembre 2018
//
// Si le nombre est strictement positif, écrivez “+”.
// Si le nombre est strictement négatif, écrivez “-”.
// Si le nombre est nul, écrivez “0”.
//
//*****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int x;
	
    printf("Entrez une nombre:");
	scanf("%d", &x );

	if ( x > 0 )
		printf("+\n");
	else
	   if ( x < 0 ) 
          printf("-\n");
       else
       	  printf("0\n\n" );



}