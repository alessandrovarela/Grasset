// *****************************************************************************
// Nom : types.c
// Auteur : Rébecca
// Date : 4 septembre 2018
//
// Réponse aux exercices de VariablesTypesOperateurs.pdf, page 19
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // ***************************************************************************
  // Exercice de déclaration
  // ***************************************************************************
  int chiffrePrefere = 0;
  char prenom = 'R';
  double e = 2.71828182846;

  printf("Mon chiffre chanceux est le %d.\n", chiffrePrefere);
  printf("La premiere lettre de mon prenom est %c\n", prenom);
  printf("e = %.10lf.\n", e);

  // ***************************************************************************
  // Somme de trois entiers
  // ***************************************************************************
  printf("\n\nEntrez trois entiers séparés par des espaces\n");

  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  int somme = a + b + c;
  int difference = a - b - c;
  int produit = a * b * c;

  printf("%d + %d + %d = %d\n", a, b, c, somme);
  printf("%d - %d - %d = %d\n", a, b, c, difference);
  printf("%d * %d * %d = %d\n", a, b, c, produit);

  // ***************************************************************************
  // Age dans 5 ans
  // ***************************************************************************
  printf("\n\nEntrez votre age\n");

  int age;
  scanf("%d", &age);

  printf("Dans 5 ans, vous aurez %d ans.\n", age + 5);
  printf("Vous avez été majeur pendant entre %d et %d années.\n",
	 age - 17, age - 18);

  // ***************************************************************************
  // Les secondes
  // ***************************************************************************
  printf("\n\nEntrez un nombre de secondes\n");

  int s;
  scanf("%d", &s);
  
  int m = s / 60;
  s = s % 60;
  
  int h = m / 60;
  m = m % 60;

  printf("Ceci équivaut à %d heures, %d minutes et %d secondes.\n\n", h, m, s);
}
