// *****************************************************************************
// Nom : boucles.c
//
// Auteur : Rébecca
//
// Date : 7 septembre 2018
//
// Réponse aux exercices de boucles ConditionnellesEtBoucles.pdf
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>


void imprimimerCarre( int cote )
{

    int rangee = 0;
    int colonne = 0;
    
    while (rangee < cote )
    {
        colonne = 0;
        while (colonne < cote)
        {
            printf("* ");
            colonne++;
        }
        printf("\n");
        rangee++;
    }
}



int main()
{

    // *************************************************************************
    //  Appelez Imprimiez Carre
    //   De manière a imprimier 20 carrées de largeur 1 à 20
    // *************************************************************************
    

     for (int i = 0; i <= 20; ++i)
     {
         imprimimerCarre( i );
         printf("\n");
     }



    // *************************************************************************
    // Cinq étoiles
    // *************************************************************************
    
    imprimimerCarre( 5 );


    // *************************************************************************
    // 1 à 10 étoiles
    // *************************************************************************
    const int MIN = 1;
    const int MAX = 10;
    int largeur = MAX;
    int rangee = 0;
    int colonne = 0;

    printf("\n\nEntrez un nombre entre %d et %d (inclusivement)\n", MIN, MAX);
    scanf("%d", &largeur);
    
    if ((largeur < MIN) || (largeur > MAX))
        largeur = MAX;

    imprimimerCarre( largeur );

    // *************************************************************************
    // 1 à 10 étoiles, redemander à l'utilisateur en cas d'entrée invalide.
    // *************************************************************************
    largeur = 0;

    while ((largeur < MIN) || (largeur > MAX))
    {
        printf("\n\nEntrez un nombre entre %d et %d (inclusivement)\n", MIN, MAX);
        scanf("%d", &largeur);
    }

    rangee = 0;
    
    while (rangee < largeur)
    {
		colonne = 0;
		while (colonne < largeur)
		{
		    printf("* ");
		    colonne++;
		}
		printf("\n");
		rangee++;
    }
}