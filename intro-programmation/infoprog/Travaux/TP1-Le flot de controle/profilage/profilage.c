// *****************************************************************************
// Nom    : profilage.c
// Auteur : Alessandro Varela
// Date   : 10 septembre 2018
//
// Ce programme demande à l'utilisateur son année da naissance.  
// Toute entree de l'usager doit fournir une reaction du programme.
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // bibliothèque de date et heure

int main()
{

    int    iAnneeNaissance;
    int    iAge;

    time_t tDateActuelle;      // type pour les dates et les heures
    struct tm *sInfoDate;      // structure pour enregistrer la date actuelle
    char   cDateStr[5];        // caractère à 5 positions pour sauvegarder l'horodatage
    int    iAnneeActuele;

    const  int i00Age = 0;
    const  int i03Age = 3;
    const  int i14Age = 14;
    const  int i17Age = 17;
    const  int i65Age = 65;
    const  int i99Age = 99;


    time( &tDateActuelle );
    sInfoDate = localtime( &tDateActuelle );
    strftime(cDateStr, 5, "%Y", sInfoDate);
    iAnneeActuele = atoi( cDateStr  ); // convertir en entier

	
	printf("Quelle est votre annee de naissance?");
	scanf(" %d", &iAnneeNaissance );

	iAge = iAnneeActuele - iAnneeNaissance;

     
	if ( iAge < i00Age )
	{
		printf("Désolé, vous n'êtes pas encore né.\n" );
	}
	else if ( iAge <= i03Age )
	{
		printf("Vous êtes un bébé génial qui sait lire et écrire.\n" );
	}
	else if ( iAge <= i14Age )
	{
		printf("Vous êtes un enfant très curieux.\n" );
	}
	else if ( iAge <= i17Age )
	{
		printf("Vous êtes un adolescent intéressé par l'apprentissage.\n" );
	}    	
	else if ( iAge <= i65Age )
	{
		printf("Vous êtes un adulte.\n" );
	}
	else if ( iAge <= i99Age )
	{
		printf("Vous avez beaucoup d'expérience de vie.\n" );
	}   
	else 
	{
		printf("Il semble que vous ne disiez pas la vérité.\n" );
	}   

}