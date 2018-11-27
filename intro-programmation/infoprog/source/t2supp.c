// *****************************************************************************
// 1 octobre 2018
// 
// Exercices supplémentaires mélangeant des tableaux, des matrices et des
// fonctions.
//
// Ces exercices sont facultatifs. J'évaluerai formativement le code des
// étudiants  qui le souhaitent et publierai un solutionnaire vendredi.
// *****************************************************************************
#include <stdio.h>

void rotationDroite(int avant[], int apres[], int taille)
{
}

void rotationDroiteNbFois(int avant[], int apres[], int taille, int nb)
{
}

void bordure(const int R, const int C, int matrice[R][C])
{
}

void transpose(const int R, int avant[R][R], int apres[R][R])
{
}

void imprimerTableau(int tableau[], int taille)
{
  for (int i = 0; i < taille; i++)
      printf("%d ", tableau[i]);
}

void imprimerMatrice(const int R, const int C, int matrice[R][C])
{
  for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
	  printf("%d ", matrice[i][j]);
      printf("\n");
    }
}

int main()
{
    printf("Entrez la taille du tableau, puis des entiers séparés par des espaces.\n");
    printf("Entrez ensuite un nombre de rotations vers la droite.\n");
  
    int taille = 0;
    int valeur = 0;
  
    scanf("%d", &taille);
    if (taille < 0)
        return -1;

    int tableau[taille];
    int apres[taille];
    for (int i = 0; i < taille; i++)
        scanf("%d", &(tableau[i]));
  
    scanf("%d", &valeur);

    // Appels aux fonctions sur les tableaux
    printf("Avant rotation de 1 vers la droite :\n");
    imprimerTableau(tableau, taille);
    rotationDroite(tableau, apres, taille);
    printf("\nAprès rotation de 1 vers la droite :\n");
    imprimerTableau(apres, taille);

 
    printf("\n\nAvant rotation de %d vers la droite :\n", valeur);
    imprimerTableau(tableau, taille);
    rotationDroiteNbFois(tableau, apres, taille, valeur);
    printf("\nAprès rotation de %d vers la droite :\n", valeur);
    imprimerTableau(apres, taille);

    
    printf("\n\nEntrez les dimensions d'une matrice.\n");
    int r = 0;
    int c = 0;
    scanf("%d %d", &r, &c);

    // Appels aux fonctions sur les matrices
    if (r < 0 || c < 0)
      return -1;
    
    int matrice[r][c];
    
    printf("Bordure\n");
    bordure(r, c, matrice);
    imprimerMatrice(r, c, matrice);
    printf("\n");

    // La transposée est réservée aux matrices carrées
    int mAvant[r][r];
    int mApres[r][r];
    for (int i = 0; i < r; i++)
      for (int j = 0; j < r; j ++)
	mAvant[i][j] = i * r + j;

    printf("Avant transposee\n");
    imprimerMatrice(r, r, mAvant);
    transpose(r, mAvant, mApres);
    printf("\nAprès transposee\n");
    imprimerMatrice(r, r, mApres);
    printf("\n\n");
}
