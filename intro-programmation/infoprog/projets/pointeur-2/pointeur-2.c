// *****************************************************************************
// Nom : pointeur-2.c
// Auteur : Alessandro
// Date : 05 Oct 2018
//
// Exercices Pointeurs
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>


int main()
{
	
    int u = 7;
	int v = 2000;
	int* p = &u;
	int* q = &v;

	
	// u est une variable de type entier valeur 7
	// v est une variable de type entier valeur 200
	// p est une pointeur de type entier avec adresse u
	// q est une pointeur de type entier avec adn
 


	(*p)++;

	printf("apres (*p)++\n");

	printf("Le valeur u est %d\n", u);
	printf("Le valeur u est %d\n", v);
	printf("Le valeur p est %p\n", p);
	printf("Le valeur q est %p\n", q);


	q++;

	printf("apres q++\n");

	printf("Le valeur u est %d\n", u);
	printf("Le valeur u est %d\n", v);
	printf("Le valeur p est %p\n", p);
	printf("Le valeur q est %p\n", q);


	q = p;

	printf("apres q=p\n");
	
	printf("Le valeur u est %d\n", u);
	printf("Le valeur u est %d\n", v);
	printf("Le valeur p est %p\n", p);
	printf("Le valeur q est %p\n", q);

	(*q) = v;

	printf("apres (*q) = v\n");

	printf("Le valeur u est %d\n", u);
	printf("Le valeur u est %d\n", v);
	printf("Le valeur p est %p\n", p);
	printf("Le valeur q est %p\n", q);

	u++;

	printf("apres u++\n");

	printf("Le valeur u est %d\n", u);
	printf("Le valeur u est %d\n", v);
	printf("Le valeur p est %p\n", p);
	printf("Le valeur q est %p\n", q);

	u = v;
	printf("apres u=v\n");

	printf("Le valeur u est %d\n", u);
	printf("Le valeur u est %d\n", v);
	printf("Le valeur p est %p\n", p);
	printf("Le valeur q est %p\n", q);


}