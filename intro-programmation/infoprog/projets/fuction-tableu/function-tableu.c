#include <stdio.h>
#include <stdlib.h>



void enleverNegatifs ( int tab[], int taille )

{

	 for (int i = 0; i < taille; ++i)
	 {
	 	if ( tab[i] < 0 )
	 		tab[i] = 0;

	 }

}



int main()
{
	const int TAILLE = 9;
	int entree[] = { 0 , 4, -5 , 2 , 3 , -5 , -65, 6, -23 };


	printf("AVANT:\n");

	for (int i = 0; i < TAILLE; ++i)
	{
		printf("%d\n", entree[i]);
	}


	enleverNegatifs ( entree , TAILLE  );

	printf("\n APRES:\n");

	for (int i = 0; i < TAILLE; ++i)
	{
		printf("%d\n", entree[i]);
	}

}