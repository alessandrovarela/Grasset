// *****************************************************************************
// Nom : matrix-1.c
// Auteur : 
// Date : 21 septembre 2018
//
// Exercice sur les matrix 1
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

 void imprimematrix ( const int nbRanges, const int nbColones,  int matrice[nbRanges][nbColones]  )
{

    for (int i = 0; i < nbRanges; ++i)
    {

    	for (int j = 0; j < nbColones; ++j)
    	{
    		printf(" %d,", matrice[i][j] );
    	}

   		printf("\n");
    }


}




int main()
{

    int matrice[4][3] = { { -10,  5,  4},
    					  {   5,  6,  9},
    					  {  44,  0,  4},
    					  {   1,  9,  9} } ;
	
	imprimematrix ( 4, 3 , matrice) ;
   

    int zero[10][10];

    // impime 0
    for (int i = 0; i < 10; ++i)
    	for (int j = 0; j < 10; ++j)
    	{
    		zero[i][j] = 0;
    	}

	imprimematrix ( 10, 10 , zero) ;

	printf("\n\n\n");

	// imprime col 
    for (int i = 0; i < 10; ++i)
    	for (int j = 0; j < 10; ++j)
    	{
    		zero[i][j] = i;
    	}

	imprimematrix ( 10, 10 , zero) ;

	printf("\n\n\n");


	// imprime lin
    for (int i = 0; i < 10; ++i)
    	for (int j = 0; j < 10; ++j)
    	{
    		zero[i][j] = j;
    	}

	imprimematrix ( 10, 10 , zero) ;

	printf("\n\n\n");


	// imprime diagonal

    for (int i = 0; i < 10; ++i)
    	for (int j = 0; j < 10; ++j)
    	{
    		if ( i == j ) 
    			zero[i][j] = 1;
    		else
    			zero[i][j] = 0;
    	}

	imprimematrix ( 10, 10 , zero) ;

	printf("\n\n\n");


	// imprime diagonal contraire utilize moin

    for (int i = 0; i < 10; ++i)
    	for (int j = 0; j < 10; ++j)
    	{
    		if ( ( 10 - j ) == i )
    			zero[i][j] = 1;
    		else
    			zero[i][j] = 0;
    	}

	imprimematrix ( 10, 10 , zero) ;

	printf("\n\n\n");

	// imprime diagonal contraire utilize somme

    for (int i = 0; i < 10; ++i)
    	for (int j = 0; j < 10; ++j)
    	{
    		if ( ( i + j ) == 10 )
    			zero[i][j] = 1;
    		else
    			zero[i][j] = 0;
    	}

	imprimematrix ( 10, 10 , zero) ;

	printf("\n\n\n");







	return 0;
}
