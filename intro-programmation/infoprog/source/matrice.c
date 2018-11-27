#include <stdio.h>
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
int main()
{
	matrice[4][3] = {{-10, 5, 4}, {5, 6, 9}, {44, 0, 4}, {1, 9, 9}};
	imprimerMatrice(4,3,matrice);
}