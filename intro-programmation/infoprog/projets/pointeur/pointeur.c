// *****************************************************************************
// Nom : pointeur.c
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
	
    // **********************************
    // Exercice 1
    // **********************************
    printf("Exercice 1\n");

	int i = 10;
	int* p = &i;


	printf("\n\n");

	printf("Le valeur de p est:%p\n", p );
	printf("Le adresse de p est:%p\n", &p );
	printf("Le valeur dedans p est:%d\n", *p );

	printf("\n");

    //  i est un entier de valeur 10.
	printf("Le valeur de i est:%d\n", i );

	printf("Le adresse de i est:%p\n", &i );

    printf("Le valeur dedans *i n'existe pas\n");


	printf("Exercice 2\n");


    // **********************************
    // Exercice 2
    // **********************************
    printf("Exercice 2\n");

    int u = 7;
	int v = 2000;
	int* p = &u;
	int* q = &v;

	(*p)++;

	q++;

	q = p;
	(*q) = v;



}