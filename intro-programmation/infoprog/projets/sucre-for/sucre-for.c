// *****************************************************************************
// Nom    : sucre-for.c
// Auteur : Alessandro Varela
// Date   : 10 septembre 2018
//
// Utilisation  de for
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>


int main()
{

    // while 01

    int i = 10;

    while ( i >= 0 )
    {
   
    	printf("i = %d\n", i );
    	i--;
    }

    
    //while 02
    
    int n = 384;
    while ( ! ( n % 2) )
    {

        // n % 2 vaut 0 si n est pair
        //            FAUX si n est pair
        // ! ( n % 2 ) vaut 1 si n est pair
        //            VRAI si n est pair
        // Quando o resto da divisao for 0 é considerado FAUX

    	printf("n = %d\n", n );
    	n/=2;
    }	

    //while 03

    i = 2;
    while ( i > 0 )
    {
    	printf("i = %d\n", i );
    	i*=i;

    	// Multiple i par lui-même jusq'au
    	// débordement
    }

    
    








}