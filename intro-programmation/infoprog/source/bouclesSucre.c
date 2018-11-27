// ****************************************************************************
//
// Nom : boucles.c
//
// Date : 10 septembre 2018
//
// Auteur : Rébecca
//
// Solution aux exercices de traduction de boucles avant/sans sucre syntaxique
//
// ****************************************************************************


#include <stdlib.h>
#include <stdio.h>

int main()
{
	// ************************************************************************
	// Exercice 1
	// ************************************************************************
	for (int i = 10; i >=0; i --)
	{
		printf("%d ", i);
	}
	printf("\n");

	// Imprime les nombre de 10 à 0 inclusivement
	// Est équivalent à
	int i = 0;
	while (i >=0)
	{
		printf("%d ", i);
		i--;
	}
	printf("\n");


	// ************************************************************************
	// Exercice 2
	// ************************************************************************
	for (int n = 384; !(n % 2); n /= 2)
	{
		printf("%d ", n);
	}

	// Retire tous les facteurs 2 de 384. 
	// Est équivalent à
	int n = 384;
	while(!(n % 2))
	{
		printf("%d ", n);
		n /= 2;
	}
	printf("\n");


	// ************************************************************************
	// Exercice 3
	// ************************************************************************
	for (int i = 2; i > 0; i *= i)
	{
		printf("%d ", i);
	}

	// Multiplie i par lui-même jusqu'à débordement
	i = 0;
	while(i > 0)
	{
		printf("%d ", i);
		i *= i;
	}
	printf("\n");


	// ************************************************************************
	// while vs do while
	// ************************************************************************
	int entree = 0;
	int somme = 0;

	printf("Entrez des nombres entiers. Pour quitter, entrez 0\n");
	scanf("%d", &entree);

	while (entree != 0)
	{
		somme += entree;
		scanf("%d", &entree);
	}
	printf("La somme vaut %d\n", somme);

	// Effectue le même travail que

	entree = 0;
	somme = 0;
	printf("Entrez des nombres entiers. Pour quitter, entrez 0\n");
	do
	{
		scanf("%d", &entree);
		somme += entree;
	} while (entree != 0);
	printf("La somme vaut %d\n", somme);
}