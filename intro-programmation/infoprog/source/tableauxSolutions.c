// *****************************************************************************
// Nom : tableaux.c
// Auteur : 
// Date : 17 septembre 2018
//
// Exercice sur les tableaux. Exercice supplémentaire sur les
// tableaux. Solutionnaire
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

// *****************************************************************************
//
// etendue
//
// Trouve la différence entre le plus grand et le plus petit élément d'un
// tableau.
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//      L'étendue de tab.
//
// *****************************************************************************
int etendue(int tab[], int taille)
{
  if (taille == 0)
    return -1;
  
  int min = tab[0];
  int max = tab[0];
  for (int i = 0; i < taille; i++)
  {
    if (tab[i] > max) max = tab[i];
    if (tab[i] < min) min = tab[i];
  }
  return max - min;
}

// *****************************************************************************
//
// mode
//
// Trouve l'élément le plus courant dans un tableau d'entiers.
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//      Le mode de tab.
//
// *****************************************************************************
int mode(int tab[], int taille)
{
  if (taille == 0)
    return 0;

  int mode = tab[0];
  int pop = 1;
  for (int i = 1; i < taille; i++)
  {
    int popProvisoire = 1;
    for (int j = i + 1; j < taille; j++)
    {
      if (tab[i] == tab[j])
      {
        popProvisoire++;
        if (popProvisoire > pop)
        {
          pop = popProvisoire;
          mode = tab[i];
        }
      }
    }
  }
  return mode;
}

// *****************************************************************************
//
// moyenne
//
// Trouve la moyenne des éléments d'un tableau d'entiers
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//      La moyenne de tab
//
// *****************************************************************************
double moyenne(int tab[], int taille)
{
  if (taille == 0)
    return -1.0;
  
  double somme = 0.0;
  for (int i = 0; i < taille; i++)
    somme += tab[i];

  return somme/taille;  
}

// *****************************************************************************
//
// comboMax
//
// Trouve la longueur de la plus longue série de cases identiques dans un
// tableau.
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//      La longueur du plus long combo dans tab.
//
// *****************************************************************************
int comboMax(int tab[], int taille)
{
  if (taille == 0)
    return 0;

  int pop = 1;
  int popProvisoire  = 1;
  int comboProvisoire = tab[0];

  for (int i = 1; i < taille; i++)
  {
    if (tab[i] == comboProvisoire)
    {
      popProvisoire++;
      if (popProvisoire > pop)
        pop = popProvisoire;
    }
    else
    {
      popProvisoire = 1;
      comboProvisoire = tab[i];
    }
  }
  return pop;
}

// *****************************************************************************
//
// estPalindrome
//
// Détermine si un tableau est symétrique par rapport au centre. I.e. il se lit
// de la même manière, qu'on commence du début ou de la fin.
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//      1 si tab est palindromique, 0 sinon.
//
// *****************************************************************************
int estPalindrome(int tab[], int taille)
{
  for (int i = 0; i < taille/2; i++)
  {
    if (tab[i] != tab[taille - i - 1])
      return 0;
  }
  return 1;
}

// *****************************************************************************
//
// fouille
//
// Détermine si un tableau contient une valeur.
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//     valeur : la valeur a chercher dans tab
//
// OUTPUT
//     1 si tab contient valeur, 0 sinon.
//
// *****************************************************************************
int fouille(int tab[], int taille, int valeur)
{
  for (int i = 0; i < taille; i++)
    if (tab[i] == valeur)
      return 1;
  return 0;
}

// *****************************************************************************
//
// deuxPlusPetits
//
// Imprime les deux plus petits éléments d'un tableau
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//     Rien
//
// *****************************************************************************
void deuxPlusPetits(int tab[], int taille)
{
  if (taille <= 0)
    return;

  int min = tab[0];
  int avantMin = tab[0];
  
  for (int i = 0; i < taille; i++)
  {
    if (min == avantMin)
	  { // Initialisation
      if (tab[i] < min)
        min = tab[i];
      else
        avantMin = tab[i];
    }
    if (tab[i] < min)
    {
      avantMin = min;
      min = tab[i];
    }
    else if((tab[i] > min) && (tab[i] < avantMin))
      avantMin = tab[i];
  }
  printf("%d et %d\n", min, avantMin);
}

// *****************************************************************************
//
// troisPlusGrands
//
// Imprime les trois plus grands éléments d'un tableau
//
// INPUT
//     tab : un tableau d'entiers
//     taille : le nombre de cases dans tab
//
// OUTPUT
//     Rien
//
// *****************************************************************************
void troisPlusGrands(int tab[], int taille)
{
  if (taille <= 0)
    return;

  int max = tab[0];
  int min = tab[0];
  for (int i = 0; i < taille; i++)
  {
    if (max < tab[i])
      max = tab[i];
    if (min > tab[i])
      min = tab[i];
  }

  int avantMax = min;
  for (int i = 0; i < taille; i++)
    if ((avantMax < tab[i]) && (tab[i] != max))
      avantMax = tab[i];

  int avantAvantMax = min;
  for (int i = 0; i < taille; i++)
    if ((avantAvantMax < tab[i]) && (tab[i] != max) && (tab[i] != avantMax))
      avantAvantMax = tab[i];

  printf("%d, %d et %d\n", max, avantMax, avantAvantMax);
}

// *****************************************************************************
//
// egalite
//
// Détermine si deux tableaux sont égaux. Deux tableaux sont égaux s'ils ont la
// même taille et contiennent les mêmes éléments dans le même ordre.
//
// INPUT
//     tabSource : un tableau d'entiers
//     tailleSource : le nombre de cases dans tabSource
//     tabCompare : un deuxième tableau d'entiers
//     tailleCompare : le nombre de cases dans tabCompare
//
// OUTPUT
//     1 si les deux tableaux sont égaux, 0 sinon.
//
// *****************************************************************************
int egalite(int tabSource[], int tailleSource, int tabCompare[], int tailleCompare)
{
  if (tailleSource != tailleCompare)
    return 0;

  for (int i = 0; i < tailleSource; i++)
    if (tabSource[i] != tabCompare[i])
      return 0;

  return 1;
}

// *****************************************************************************
//
// imprimerConsonne
//
// Imprime les caractères qui ne sont pas des voyelles dans une chaîne de
// caractères. Les voyelles sont A, a, E, e, I, i, O, o, U, u.
//
// INPUT
//     char phrase[] : la chaîne de caractères
//
// OUTPUT
//     Rien
//
// *****************************************************************************
void imprimerConsonne(char phrase[])
{
  for (int i = 0; phrase[i] != '\0'; i++)
  {
    if ((phrase[i] != 'A') && (phrase[i] != 'a') &&
        (phrase[i] != 'E') && (phrase[i] != 'e') &&
        (phrase[i] != 'I') && (phrase[i] != 'i') &&
        (phrase[i] != 'O') && (phrase[i] != 'o') &&
        (phrase[i] != 'U') && (phrase[i] != 'u'))
      printf("%c", phrase[i]);
  }
}

// *****************************************************************************
//
// renverserEtImprimer
//
// Renverse et imprime un tableau.
//
// INPUT
//     int tab[] : Le tableau à renverser et imprimer
//     int taille : le nombre de cases dans tab.
//
// OUTPUT
//     Rien
//
// *****************************************************************************
void renverserEtImprimer(int tab[], int taille)
{
  for (int i = 0; i < taille/2; i++)
  {
    int temp = tab[i];
    tab[i] = tab[taille - i - 1];
    tab[taille - i - 1] = temp;
  }
  for (int i = 0; i < taille; i++)
    printf("tab[%d] = %d\n", i, tab[i]);
}

// *****************************************************************************
//
// main
//
// Fonction pilote pour les exercices, elle demande à l'utilisateur d'entrer la
// taille d'un tableau, les cases d'un tableau puis un nombre, et exécute les
// fonctions définies plus haut sur ces entrées.
//
// *****************************************************************************
int main()
{
  printf("Entrez la taille du tableau, puis des entiers séparés par des espaces.\n");
  printf("Entrez ensuite un entier.\n");
  
  int taille = 0;
  int valeur = 0;
  
  scanf("%d", &taille);
  if (taille < 0)
    return -1;

  int tableau[taille];
  for (int i = 0; i < taille; i++)
    scanf("%d", &(tableau[i]));
  
  scanf("%d", &valeur);

  printf("\n\nVous avez choisi d'entrer %d entiers : ", taille);
  for (int i = 0; i < taille; i++)
    printf("%d ", tableau[i]);

  printf("\nVous avez choisi d'entrer le nombre : %d\n\n\n", valeur);

  printf("L'étendue est : %d\n", etendue(tableau, taille));
  printf("La moyenne est : %lf\n", moyenne(tableau, taille));
  printf("Le mode est : %d\n", mode(tableau, taille));
  printf("Le plus long combo est de longueur : %d\n", comboMax(tableau, taille));

  if (estPalindrome(tableau, taille))
    printf("Le tableau est un palindrome.\n");
  else
    printf("Le tableau n'est pas un palindrome.\n");

  if (fouille(tableau, taille, valeur))
    printf("Le tableau contient %d.\n", valeur);
  else
    printf("Le tableau ne contient pas %d.\n", valeur);

  deuxPlusPetits(tableau, taille);
  troisPlusGrands(tableau, taille);
  renverserEtImprimer(tableau, taille);
  imprimerConsonne("Le lapin mange des carottes\n");
}
