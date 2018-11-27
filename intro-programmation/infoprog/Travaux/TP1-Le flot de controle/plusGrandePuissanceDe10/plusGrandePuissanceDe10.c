// *****************************************************************************
// Nom    : plusGrandePuissanceDe10.c
// Auteur : Alessandro Varela
// Date   : 11 septembre 2018
//
// Cette programme trouve la plus grande puissance de
// 10 qui entre dans un nombre strictement positif.  
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int iNumPositif = 0;
          
    int iMaxExposant;
    int iPuissanceMaxPre = 0;
    int iExposantMaxPre;
    
    int const iBase10 = 10;
    int iPuissance = 0;
	
    while ( iNumPositif <= 0 )
    {
    		printf("Entrez une nombre Positif:");
    		scanf("%d", &iNumPositif);
    }
      
    // Incrémente l'exposant jusqu'à ce que la puissance soit supérieure au nombre indiqué
    for (iMaxExposant = 1; iPuissance <= iNumPositif ; ++iMaxExposant)
    {
     	iPuissance = 1;
     	
     	// calcule la puissance
     	for ( int i = 1;  i <= iMaxExposant ; ++i )
		{		 
			iPuissance *= iBase10;
		}

		// Enregistre la puissance et l'exposant précédent
		if ( iPuissance <= iNumPositif )
		{	iPuissanceMaxPre = iPuissance;
			iExposantMaxPre  = iMaxExposant;
		}
	}
    
    // Traite des nombres inférieurs à 10 que la puissance doit être 1
    if ( iNumPositif < iBase10 )
    	iPuissanceMaxPre = 1;


	printf("La plus grande puissance de 10 qui entre dans %d est %d^%d = %d\n" , iNumPositif ,iBase10, iExposantMaxPre , iPuissanceMaxPre   );	 

}