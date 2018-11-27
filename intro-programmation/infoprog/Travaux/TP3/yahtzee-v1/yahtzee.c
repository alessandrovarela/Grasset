// ************************************************************************************************
// Nom : estBienParenthesee
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette programme...
// *************************************************************************************************

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "libyahtzee.h"

int main()
{

//    jouerYahtzee();

// Para compilar
// gcc yahtzee.c libyahtzee.c -g -o yahtzee.out

// Para rodar ./yahtzee.out

// TESTES

    int x, r;
    Jet jetTest = {3,5,5,1,5};
    char choix[5]   = "00000";

    printf("Jet Anterior:");
    for(int x = 0; x < 5; x++)
    {
       printf( " %d", jetTest.des[x]);
    }
    printf( "\n"); 

    jetTest = lancerLesDes(jetTest , choix );
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


    return 0;

    
}


