// *****************************************************************************
// Nom : fonctions.c
//
// Auteur : Rébecca
//
// Date : 7 septembre 2018
//
// Réponse aux exercices de boucles ConditionnellesEtBoucles.pdf
// à l'aide de fonctions.
//
// *****************************************************************************

// ***************************************************************************** 
// Function nom      : imprimerRectangle
// Parameters        : int largeur, int longueur, char symbole
// Type de retour    : rien
// où est-elle apeelê: imprimerCarre()

// ***************************************************************************** 
// Function nom      : imprimerCarre
// Parameters        : int largeur, char symbole
// Type de retour    : rien
// où est-elle apeelê: 




#include <stdio.h>
#include <stdlib.h>
void imprimerRectangle(int largeur, int longueur, char symbole)
{
    for(int i = 0; i < largeur; i ++)
    {
        for (int j = 0; j < longueur; j++)
    	{
    	    printf("%c ", symbole);
    	}
        printf("\n");
    }
}


// *****************************************************************************
// imprimerCarre
//
// Imprime un carré ayant les dimensions voulues en utilisant le symbole
// demandé à la console.
//
// INPUT :
//     int largeur : La largeur du carré à dessiner
//     char symbole : le symbole à utiliser pour dessiner le carré
//
// OUTPUT :
//     Rien
//
// *****************************************************************************
void imprimerCarre(int largeur, char symbole)
{
    imprimerRectangle(largeur, largeur, symbole);
}


// *****************************************************************************
// validerNombre
//
// Valide qu'un nombre est entre min et max inclusivement.
//
// INPUT :
//     int min : la valeur minimale que le nombre peut avoir pour être valide
//     int max : la valeur maximale que le nombre peut avoir pour être valide
//
// OUTPUT :
//     int : Vrai si min <= nombre <= max, Faux sinon.
//
// *****************************************************************************
int validerNombre(int min, int max, int nombre)
{
    return ((nombre >= min) && (nombre <= max));
}


// *****************************************************************************
// demanderNombre
//
// Affiche une jolie phrase à la console qui indique à l'utilisateur
// d'entrer un nombre entre min et max..
//
// INPUT :
//     int min : la valeur minimale demandée
//     int max : la valeur maximale demandée
//
// OUTPUT :
//     rien
//
// *****************************************************************************
void demanderNombre(int min, int max)
{
    printf("\n\nEntrez un nombre entre %d et %d (inclusivement)\n", min, max);
}


// *****************************************************************************
// main
//
// Affiche des carrés à l'aide du symbole étoile à la console
//
// INPUT :
//     rien
//
// OUTPUT :
//     rien
//
// *****************************************************************************
int main()
{
    // *************************************************************************
    // Cinq étoiles
    // *************************************************************************
    const int COTE = 5;
    const char SYMBOLE = '*';
    imprimerCarre(COTE, SYMBOLE);
    
    // *************************************************************************
    // 1 à 10 étoiles
    // *************************************************************************
    const int MIN = 1;
    const int MAX = 10;
    int largeur = 0;

    demanderNombre(MIN, MAX);
    scanf("%d", &largeur);
    if (!validerNombre(MIN, MAX, largeur))
        largeur = MAX;

    imprimerCarre(largeur, SYMBOLE);
    
    // *************************************************************************
    // 1 à 10 étoiles, redemander à l'utilisateur en cas d'entrée invalide.
    // *************************************************************************
    demanderNombre(MIN, MAX);
    scanf("%d", &largeur);
    while (!validerNombre(MIN, MAX, largeur))
    {
        demanderNombre(MIN, MAX);
        scanf("%d", &largeur);
    }
    imprimerCarre(largeur, SYMBOLE);
}
