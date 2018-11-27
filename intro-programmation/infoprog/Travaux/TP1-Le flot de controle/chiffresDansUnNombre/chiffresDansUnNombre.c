// *****************************************************************************
// Nom    : chiffresDansUnNombre.c
// Auteur : Alessandro Varela
// Date   : 12 septembre 2018
//
// Cette programa fait la liste des chiffres qui forment
// un nombre entier strictement positif. 
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>


int plusGrandePuissanceDe10( int iNumPositif  ) 

{
    
          
    int iMaxExposant;
    int iPuissanceMaxPre = 0;
    int iExposantMaxPre;
    
    int const iBase10 = 10;
    int iPuissance = 0;
	      
    // Incrémente l'exposant jusqu'à ce que la puissance soit supérieure au nombre indiqué
    for (iMaxExposant = 1; iPuissance <= iNumPositif ; ++iMaxExposant)
    {
       	iPuissance = 1;
       	
       	// calcule la puissance
       	for ( int i = 1;  i <= iMaxExposant ; ++i )
  		{		 
  			iPuissance = iPuissance * iBase10;
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

	return iExposantMaxPre;

}

int main()
{

    int iNumPositif =0;
    const int iBase10 = 10;

    while ( iNumPositif <= 0 )
    {
        printf("Entrez une nombre Positif:");
        scanf("%d", &iNumPositif);
    }
  
    // enregistre le plus grand exposant de la base 10 du nombre entré
    const int iMaxExposant = plusGrandePuissanceDe10(iNumPositif);
   
    int iDiviseur = 1;
    int iResultatDiv = iNumPositif;
    int iReste ;
   
    // Soulève la base 10 avec la puissance trouvée
    for ( int x = 1; x <= iMaxExposant ; x++ )
    { 
     	 iDiviseur *= iBase10;
    }

    // Imprime la première partie des informations de sortie
    printf("Les chiffres qui forment %d son " , iNumPositif );
   
    // Divise le nombre entré par le majeur divisor tandis 
    // que le diviseur é plus grand ou égal à 1
    while ( iDiviseur >= 1 ) 
    {
      
      iReste = iResultatDiv%iDiviseur; 
      iResultatDiv /= iDiviseur;

      // imprimer le chiffre
      printf("%d",  iResultatDiv );

      // contrôle de la virgule et du mot "et"
      if ( iDiviseur == iBase10 )
          printf(" et ");
      else if ( iDiviseur > iBase10 )
          printf(", ");       

      iDiviseur /= iBase10;
      iResultatDiv = iReste;
    }

    printf(".\n");
   
}