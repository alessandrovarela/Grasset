// ************************************************************************************************
// Nom: jouerYahtzee
//
// Auteurs: Alessandro Varela, Josivan Almeida, Carolina Spaniol
//
// Date: 13 octobre 2018
//
// But du programme: démarrez le jeu
//
// *************************************************************************************************

#include "libyahtzee.h"
#include "yahtzeeTests.h"

int main(int argc, char** argv)
{
/*
	int x, r;
    Jet jetTest = {1,2,3,4,6};
    char choix[6]   = "00000";

 //   int v = valideChoixDes(choix);
 //   printf("Última posição Choix:%c\n", choix[NOMBREDES] );

    printf("Jet Anterior:");
    for(int x = 0; x < 5; x++)
    {
       printf( " %d", jetTest.des[x]);
    }
    printf( "\n"); 

    lancerLesDes(&jetTest , choix );
    printf("Jet Lançado :");
    for(int x = 0; x < 5; x++)
    {
       printf( " %d", jetTest.des[x]);
    }
    printf( "\n"); 
 
  
    Jet RetornaTrie = trierLesDes(jetTest);
    printf("Jet Ordenado:");
    for(int x = 0; x < 5; x++)
    {
       printf( " %d", RetornaTrie.des[x]);
    }
    printf( "\n"); 
   
    
    for(int p = 1; p <= 6; p++)
    {
      x = nbDeFace(jetTest,p);
      printf("(%d) : %d\n", p, x);
    }
     
    x = brelan(jetTest);
    printf("Brelan     : %d\n", x);

    x = carre(jetTest);
    printf("Carre      : %d\n", x);

    x = mainPleine(jetTest);
    printf("Main Pleine: %d\n", x);

    x = petiteSuite(jetTest);
    printf("Petite Suite: %d\n", x);

    x = grandeSuite(jetTest);
    printf("Grande Suite: %d\n", x);

 
    x = yahtzee(jetTest);
    printf("Yahtzee    : %d\n", x);

   x = chance(jetTest);
    printf("Chance     : %d\n", x);

*/
	
	if ((argc > 1) && 
   	   (((argv[1][0] = 'T') && (argv[1][1] == 'E') && (argv[1][2] == 'S') && (argv[1][3] == 'T')) || ((argv[1][0] = 't') && (argv[1][1] == 'e') &&  (argv[1][2] == 's') && (argv[1][3] == 't')))) 
   	{
   		tests ();
   	}
   	else
    {	
		jouerYahtzee();
	}
	
    return 0;
}
// gcc *.c -g -o yahtzee.out

