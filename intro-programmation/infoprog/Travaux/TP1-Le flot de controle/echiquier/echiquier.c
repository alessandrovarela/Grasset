// *****************************************************************************
// Nom    : echiquier.c
// Auteur : Alessandro Varela
// Date   : 12 septembre 2018
//
// Cette programa demande deux caractèeres ASCII à
// utilisateur et un entier, puis afiche un echiquier de la taille désirée.
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

void printlinge( char pCaract1 , char pCaract2, int pNumChar )
{

	char cDernierCaract = pCaract2 ;

	for (int iPrintLigne = 1; iPrintLigne <= pNumChar ; ++iPrintLigne)
	{

		if ( cDernierCaract == pCaract1 )
		{	
			printf("%c", pCaract2 );
		    cDernierCaract = pCaract2;
		}
		else
		{
			printf("%c", pCaract1 );
		    cDernierCaract = pCaract1;
		}
	}
	printf("\n" );

}

int main()
{
	char cCaract1;
	char cCaract2;
	int  iLigne;
	int  iValideEntrees = 1;
	int const cDecimal32 = 32;
	int const cDecimal127 = 127;
	int const cDivCol = 2;
	int const cMinEntree = 1;
	int const cMaxEntree = 16;

    // entrées et validations des symboles
 	do
	{
		iValideEntrees = 1;

    	do
    	{
	    	iValideEntrees = 1;
	    	printf("Entrez le premier caractère:");
	    	scanf(" %c" , &cCaract1);

	    	if ( ! ( cCaract1 >= cDecimal32 )  &&  ( cCaract1 <= cDecimal127 ) )
	    	{	
	    		printf("Cette caractère non est validé. Veuillez entrer uniquement les caractères imprimables.\n");
	            iValideEntrees = 0;
	        }    
	    } while ( ! iValideEntrees );

    	do 
    	{   iValideEntrees = 1;
    		printf("Entrez le deuxième caractère:");
    		scanf(" %c" , &cCaract2);

    		if ( ! ( cCaract2 >= cDecimal32 )  &&  ( cCaract2 <= cDecimal127 ) )
	    	{	
	    		printf("Cette caractère non est validé. Veuillez entrer uniquement les caractères imprimables.\n");
	            iValideEntrees = 0;
	        }    

        } while ( ! iValideEntrees );

        if ( cCaract1 == cCaract2 )
    	{
    		printf("S'il vous plaît, entrer des caractères différents!\n");
    		iValideEntrees = 0;

    	}

	} while ( ! iValideEntrees );

	// entrée et validations le entier
	do 
	{
		iValideEntrees = 1;

		printf("Entrez un entier:");
    	scanf(" %d" , &iLigne);
		
		if ( ! ( ( iLigne >= cMinEntree )  && ( iLigne <= cMaxEntree ) ) )
    	{
    		printf("S'il vous plaît, entrer une nombre entre 1 et 16\n");
    		iValideEntrees = 0;
    	}

	}   while ( ! iValideEntrees );


    // imprime uniquement des lignes de nombres pairs
    if ( iLigne%cDivCol != 0 )
    	 iLigne--;


    // imprime les symboles
	for ( int col = 1;  col <= iLigne ; col++ )
    {
    	if ( col%cDivCol == 0 )
    	{
    		printlinge( cCaract2 , cCaract1, iLigne );
    	}	
    	else
    	{  
    		printlinge( cCaract1 , cCaract2, iLigne );
    	}
	}
}