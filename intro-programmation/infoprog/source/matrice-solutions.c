// *****************************************************************************
// Nom : matrice.c
// Auteur : Rébecca
// Date : 21 septembre 2018
//
// Exercice sur les matrices. Solutionnaire
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

// *****************************************************************************
//
// imprimerMatrice
//
// Imprime à la console la matrice fournie.
//
// INPUT
//     nbRangees : nombre de rangées dans la matrice
//     nbColonnes : nombre de colonnes dans la matrice
//	   matrice : La matrice à imprimer
//
// OUTPUT
//      Rien
//
// *****************************************************************************
void imprimerMatrice(const int nbRangees, const int nbColonnes, 
					 int matrice[nbRangees][nbColonnes])
{
	for (int i = 0; i < nbRangees; i++)
	{
		for (int j = 0; j < nbColonnes; j++)
		{
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
}
// *****************************************************************************
//
// estSymetrique
//
// Détermine si une matrice est symétrique par rapport à la diagonale
// principale
//
// INPUT
//     nbRangees : nombre de rangées dans la matrice
//     nbColonnes : nombre de colonnes dans la matrice
//	   matrice : La matrice à tester
//
// OUTPUT
//     1 si matrice est symétrique, 0 sinon.
//
// *****************************************************************************
int estSymetrique(const int R, const int C, int matrice[R][C])
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (matrice[i][j] != matrice[j][i])
				return 0;
	return 1;
}

// *****************************************************************************
//
// main
//
// Fonction pilote pour les exercices, imprime 4 matrices puis répond au défi
// platine.
//
// *****************************************************************************
int main()
{
	int rangees[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			rangees[i][j] = i;
	imprimerMatrice(10, 10, rangees);

	int colonnes[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			colonnes[i][j] = j;
	imprimerMatrice(10, 10, colonnes);

	int diagonaleMajeure[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			diagonaleMajeure[i][j] = (i == j);
	imprimerMatrice(10, 10, diagonaleMajeure);

	int diagonaleMineure[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			diagonaleMineure[i][j] = (i + j == 9);
	imprimerMatrice(10, 10, diagonaleMineure);

	int matrice[4][3] = {{-10, 5, 4}, {5, 6, 9}, {44, 0, 4}, {1, 9, 9}};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", *(*(matrice + i) + j)); // ou
			printf("%d ", *(*matrice + i * 3 + j));
		}
		printf("\n");
	}
}