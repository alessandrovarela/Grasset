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
   	if ((argc > 1) && 
   	   (((argv[1][0] = 'T') && (argv[1][1] == 'E') && (argv[1][2] == 'S') && (argv[1][3] == 'T')) || ((argv[1][0] = 't') && (argv[1][1] == 'e') &&  (argv[1][2] == 's') && (argv[1][3] == 't')))) 
   	{
   		tests ();
   	}
   	else
    jouerYahtzee();
    return 0;
}


