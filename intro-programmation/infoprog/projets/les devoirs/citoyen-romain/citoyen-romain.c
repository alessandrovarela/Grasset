// *****************************************************************************
// Nom    : citoyen-romain.c
// Auteur : Alessandro Varela
// Date   : 6 septembre 2018
//
// valide la citoyenneté d’une personne si est romain
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{

    char cPere, cAge, cEnfant;

	printf("Son père est citoyen romain (o/n)?");
	scanf(" %c", &cPere);

	if ( ( cPere != 'o' ) && ( cPere != 'O' ) ) // Si vous n'avez pas de père romain
	{	
		printf("Vous n'êtes pas citoyen romain.\n");
	}
	else
	{
		printf("Vous avez au moins 30 ans (o/n)?"); 
        scanf(" %c", &cAge);
		
		if ( ( cAge == 'o' ) || ( cAge == 'O' ) ) // avez au moins 30 ans
		{	
			printf("Vous êtes un citoyen romain!\n");
        }
        else 
        {	
			printf("Vous avez au moins un enfan légitime (o/n)?");
        	scanf(" %c", &cEnfant);
        	
        	if ( ( cEnfant == 'o' ) || ( cAge == 'O' ) ) // aves au moins un enfan
			{	
				printf("Vous êtes un citoyen romain!\n");
        	}
        	else
        	{	
				printf("Vous n'êtes pas citoyen romain.\n\n");
        	}	

        }	
    }


}