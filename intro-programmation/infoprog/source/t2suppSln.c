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


// *****************************************************************************
//
// rotationDroite
//
// Effectuer une rotation de une position vers la droite dans un tableau.
//
// INPUT :
//     avant : Le tableau avant la rotation
//     apres : un tableau de même dimension qu'avant qui sera effacé pour
//         y mettre le résultat de la rotation
//     taille : le nombre de cases dans avant et apres
//
// OUTPUT:
//     Rien
//
// *****************************************************************************
void rotationDroite(int avant[], int apres[], int taille)
{
  for(int i = 0; i < taille; i++)
      apres[i] = avant[((i - 1) + taille) % taille];
}


// *****************************************************************************
//
// rotationDroiteNbFois
//
// Effectuer une rotation de nb positions vers la droite dans un tableau.
//
// INPUT :
//     avant : Le tableau avant la rotation
//     apres : un tableau de même dimension qu'avant qui sera effacé pour
//         y mettre le résultat de la rotation
//     taille : le nombre de cases dans avant et apres
//     nb : le nombre de positions à décaler
//
// OUTPUT:
//     Rien
//
// *****************************************************************************
void rotationDroiteNbFois(int avant[], int apres[], int taille, int nb)
{
  for(int i = 0; i < taille; i++)
      apres[i] = avant[((i - nb) + 2 * taille) % taille];
}


// *****************************************************************************
//
// bordure
//
// Remplir les cases de la matrice avec des 1 sur les bordure et des 0 au centre
//
// INPUT :
//     R : Le nombre de rangées dans la matrice
//     C : Le nombre de colonnes dans la matrice
//     matrice : la matrice à remplir
//
// OUTPUT:
//     Rien
//
// *****************************************************************************
void bordure(const int R, const int C, int matrice[R][C])
{
  for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
	  if ((i == 0) || (j == 0) || (i == R - 1) || (j == C - 1))
	      matrice[i][j] = 1;
	  else
	    matrice[i][j] = 0;
}


// *****************************************************************************
//
// transpose
//
// Effectuer la transposée d'une matrice carrée.
//
// INPUT :
//     R : Le nombre de rangées dans la matrice
//     avant : la matrice carrée à transposer
//     apres : une matrice carrée dont les cases seront effacées pour mettre
//         la transposée de avant
//
// OUTPUT:
//     Rien
//
// *****************************************************************************
void transpose(const int R, int avant[R][R], int apres[R][R])
{
  for (int i = 0; i < R; i++)
      for (int j = 0; j < R; j++)
	  apres[j][i] = avant[i][j];
}

// *****************************************************************************
//
// imprimerTableau
//
// Imprimer le tableau reçu à la console
//
// INPUT :
//     tableau : le tableau à imprimer
//     taille : le nombre de cases dans le tableau
//
// OUTPUT:
//     Rien
//
// *****************************************************************************
void imprimerTableau(int tableau[], int taille)
{
  for (int i = 0; i < taille; i++)
      printf("%d ", tableau[i]);
}

// *****************************************************************************
//
// imprimerMatrice
//
// Imprimer la matrice reçue à la console
//
// INPUT :
//     R : Le nombre de rangées dans la matrice
//     C : Le nombre de colonnes dans la matrice
//     matrice : la matrice à imprimer
//
// OUTPUT:
//     Rien
//
// *****************************************************************************
void imprimerMatrice(const int R, const int C, int matrice[R][C])
{
  for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
	  printf("%d ", matrice[i][j]);
      printf("\n");
    }
}

// *****************************************************************************
//
// Méthode pilote pour les fonctions
//
// *****************************************************************************
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
