// **************************************************************

//

// Nom de fichier : majeur.c

// Date de criation : 30 août 2018

// Nom : Josivan

// Valide si les personnes nees a l'anne de naissance fournis

// ***************************************************************

#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("Entrez votre annee de naissance s'il vous plait.\n");
	int anneeNaissance = 0; // initialisation
	scanf("%d", &anneeNaissance);
	int age = /* calcul de l'age */ 2018 - anneeNaissance;

	// Toute la ligne est un commentaire
	// L'age de la majorite au Canada est 18 ans

	/* Un commentaire sur plusiers lignes */ 
	if (age < 18)
	printf("Mineur\n");
	else
	printf("Majeur\n");

	printf("Merci.\n");

	printf("  @ .. @\n");
	printf(" (- - - -)\n");
	printf(" (> ____ <)\n");
	printf("  ^^ ~~ ^^\n");




}