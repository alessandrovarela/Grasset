
// ************************************************************************************************
// Nom: yahtzeeTests.c
// 
// Auteurs: Alessandro Varela, Josivan Almeida, Carolina Spaniol
// 
// Date: 17 octobre 2018
// 
// Tester les fonctions du jeux YAHTZEE. Il y a au moins 2 tests unitaires pour chaque fonction.
//
// *************************************************************************************************

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "yahtzeeTests.h"

// ************************************************************************************************
// Test Unitaire: nbDeFace
// 
// Cas de test 1 (testUn): Jet = {3,5,4,4,4}; face = 4; résultat = 12
// 
// Cas de test 2 (testDeux): 
// 
// *************************************************************************************************
void testernbDeFace()//Jet jet, int face
{
	Jet testUn = {3,5,4,4,4}; 
	int face = 4;
	int resultatTestUn = nbDeFace (testUn, face);

	if (resultatTestUn == 12)
		printf ("RÉUSSI! :) Le resultat du Test UN (nbDeFace) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (nbDeFace) est %d et aurait dû être 12\n", resultatTestUn);	
}

// ************************************************************************************************
// Test Unitaire: brelan
//
// Cas de test 1 (testUn): Jet = {3,3,3,2,5}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testerbrelan()//Jet jet
{
	Jet testUn = {3,3,3,2,5};
	int resultatTestUn = brelan(testUn);
	
	if (resultatTestUn == 16)
		printf ("RÉUSSI! :) Le resultat du Test UN (Brelan) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (Brelan) est %d et aurait dû être 16\n", resultatTestUn);	

}

// ************************************************************************************************
// Test Unitaire: carre
//
// Cas de test 1 (testUn): Jet = {3,3,3,3,5}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testercarre()//Jet jet
{
	Jet testUn = {3,3,3,3,5};
	int resultatTestUn = carre(testUn);
	
	if (resultatTestUn == 17)
		printf ("RÉUSSI! :) Le resultat du Test UN (carre) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (carre) est %d et aurait dû être 17\n", resultatTestUn);	
}

// ************************************************************************************************
// Test Unitaire: mainPleine
//
// Cas de test 1 (testUn): Jet = {3,3,3,5,5}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testermainPleine()//Jet jet
{
	Jet testUn = {3,3,3,5,5};
	int resultatTestUn = mainPleine(testUn);
	
	if (resultatTestUn == 25)
		printf ("RÉUSSI! :) Le resultat du Test UN (mainPleine) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (mainPleine) est %d et aurait dû être 25\n", resultatTestUn);	
}

// ************************************************************************************************
// Test Unitaire: petiteSuite
//
// Cas de test 1 (testUn): Jet = {1,2,3,4,6}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testerpetiteSuite()//Jet jet
{
	Jet testUn = {1,2,3,4,6};
	int resultatTestUn = petiteSuite(testUn);
	
	if (resultatTestUn == 30)
		printf ("RÉUSSI! :) Le resultat du Test UN (petiteSuite) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (petiteSuite) est %d et aurait dû être 30\n", resultatTestUn);	
}

// ************************************************************************************************
// Test Unitaire: grandSuite
//
// Cas de test 1 (testUn): Jet = {1,2,3,4,5}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testergrandeSuite()//Jet jet
{
	Jet testUn = {1,2,3,4,5};
	int resultatTestUn = grandeSuite(testUn);
	
	if (resultatTestUn == 40)
		printf ("RÉUSSI! :) Le resultat du Test UN (grandSuite) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (grandSuite) est %d et aurait dû être 40\n", resultatTestUn);
}

// ************************************************************************************************
// Test Unitaire: yahtzee
// 
// Cas de test 1 (testUn): Jet = {6,6,6,6,6}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testeryahtzee()//Jet jet
{
	Jet testUn = {6,6,6,6,6};
	int resultatTestUn = yahtzee(testUn);
	
	if (resultatTestUn == 50)
		printf ("RÉUSSI! :) Le resultat du Test UN (yahtzee) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (yahtzee) est %d et aurait dû être 50\n", resultatTestUn);
}

// ************************************************************************************************
// Test Unitaire: chance
// 
// Cas de test 1 (testUn): Jet = {6,6,6,6,6}
// 
// Cas de test 2 (testDeux):
// 
// *************************************************************************************************
void testerchance()//Jet jet
{
	Jet testUn = {6,6,6,6,6};
	int resultatTestUn = chance(testUn);
	
	if (resultatTestUn == 30)
		printf ("RÉUSSI! :) Le resultat du Test UN (chance) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test UN (chance) est %d et aurait dû être 30\n", resultatTestUn);
}

// ************************************************************************************************
// Test qui apelle tout le cas des tests 
// *************************************************************************************************
void tests() {
	testernbDeFace();
	testerbrelan();
	testercarre();
	testermainPleine();
	testerpetiteSuite();
	testergrandeSuite();
	testeryahtzee();
	testerchance();
}






