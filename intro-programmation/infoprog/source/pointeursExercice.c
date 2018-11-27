// *****************************************************************************
//
// Nom : pointeursExercice.c
//
// Auteur : Rébecca
//
// Date : 6 octobre 2018
//
// Donnez la valeur de d, e, p, q, &d, &e, *p et *q à chaque ligne
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

int main()
{
  double d = 11.59;
  double* p = &d;
  double* q = p;
  double e;

  (*p) *= 0.15;
  
  d /= 0.1;

  q = q + 10;

  *(q - 10) = (*p) * (*p);

  e = *p;
  q = &e;

  e--;
  
  printf("À l'adresse p = %p se trouve la valeur %lf\n", p, *p);
  printf("À l'adresse q = %p se trouve la valeur %lf\n", q, *q);
  printf("La variable d = %lf se trouve à l'adresse %p\n", d, &d);
  printf("La variable e = %lf se trouve à l'adresse %p\n", e, &e);
}
