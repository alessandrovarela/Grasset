
// ************************************************************************************************
// Nom: yahtzeeTests.c
// 
// Auteurs: Alessandro Varela, Josivan Almeida, Carolina Spaniol
// 
// Date: 19 octobre 2018
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
// Cas de test 2 (testDeux): Jet = {2,3,3,3,1}; face = 3; résultat = 9
// 
// *************************************************************************************************
void testernbDeFace()
{
	Jet testUn = {3,5,4,4,4}; 
	int faceUn = 4;
	int resultatTestUn = nbDeFace (testUn, faceUn);

	if (resultatTestUn == 12)
		printf ("RÉUSSI! :) Le resultat du Test 1 (nbDeFace) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (nbDeFace) est %d et aurait dû être 12\n", resultatTestUn);

	Jet testDeux = {2,3,3,3,1}; 
	int faceDeux = 3;
	int resultatTestDeux = nbDeFace (testDeux, faceDeux);

	if (resultatTestDeux == 9)
		printf ("RÉUSSI! :) Le resultat du Test 2 (nbDeFace) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (nbDeFace) est %d et aurait dû être 9\n", resultatTestDeux);
}

// ************************************************************************************************
// Test Unitaire: brelan
//
// Cas de test 1 (testUn): Jet = {3,3,3,2,5}
// 
// Cas de test 2 (testDeux): Jet = {1,2,3,4,5};
// 
// *************************************************************************************************
void testerbrelan()
{
	Jet testUn = {3,3,3,2,5};
	int resultatTestUn = brelan(testUn);
	
	if (resultatTestUn == 16)
		printf ("RÉUSSI! :) Le resultat du Test 1 (Brelan) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (Brelan) est %d et aurait dû être 16\n", resultatTestUn);	

	Jet testDeux = {1,2,3,4,5};
	int resultatTestDeux = brelan(testDeux);
	
	if (resultatTestDeux == 0)
		printf ("RÉUSSI! :) Le resultat du Test 2 (Brelan) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (Brelan) est %d et aurait dû être 0\n", resultatTestDeux);
}

// ************************************************************************************************
// Test Unitaire: carre
//
// Cas de test 1 (testUn): Jet = {3,3,3,3,5}
// 
// Cas de test 2 (testDeux): Jet = {2,2,2,2,2}
// 
// *************************************************************************************************
void testercarre()
{
	Jet testUn = {3,3,3,3,5};
	int resultatTestUn = carre(testUn);
	
	if (resultatTestUn == 17)
		printf ("RÉUSSI! :) Le resultat du Test 1 (carre) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (carre) est %d et aurait dû être 17\n", resultatTestUn);

	Jet testDeux = {2,2,2,2,2};
	int resultatTestDeux = carre(testDeux);
	
	if (resultatTestDeux == 10)
		printf ("RÉUSSI! :) Le resultat du Test 2 (carre) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (carre) est %d et aurait dû être 10\n", resultatTestDeux);	
}

// ************************************************************************************************
// Test Unitaire: mainPleine
//
// Cas de test 1 (testUn): Jet = {1,1,1,5,5}
// 
// Cas de test 2 (testDeux): Jet = {2,6,4,6,2}
// 
// *************************************************************************************************
void testermainPleine()
{
	Jet testUn = {1,5,1,5,1};
	int resultatTestUn = mainPleine(testUn);
	
	if (resultatTestUn == 25)
		printf ("RÉUSSI! :) Le resultat du Test 1 (mainPleine) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (mainPleine) est %d et aurait dû être 13\n", resultatTestUn);

	Jet testDeux = {2,6,4,6,2};
	int resultatTestDeux = mainPleine(testDeux);
	
	if (resultatTestDeux == 0)
		printf ("RÉUSSI! :) Le resultat du Test 2 (mainPleine) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (mainPleine) est %d et aurait dû être 0\n", resultatTestDeux);	
}

// ************************************************************************************************
// Test Unitaire: petiteSuite
//
// Cas de test 1 (testUn): Jet = {1,2,3,4,6}
// 
// Cas de test 2 (testDeux): Jet = {6,5,2,3,4} 
// 
// *************************************************************************************************
void testerpetiteSuite()
{
	Jet testUn = {1,2,3,4,6};
	int resultatTestUn = petiteSuite(testUn);
	
	if (resultatTestUn == 30)
		printf ("RÉUSSI! :) Le resultat du Test 1 (petiteSuite) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (petiteSuite) est %d et aurait dû être 30\n", resultatTestUn);	

	Jet testDeux = {6,5,2,3,4};
	int resultatTestDeux = petiteSuite(testDeux);
	
	if (resultatTestDeux == 30)
		printf ("RÉUSSI! :) Le resultat du Test 2 (petiteSuite) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (petiteSuite) est %d et aurait dû être 30\n", resultatTestDeux);	
}

// ************************************************************************************************
// Test Unitaire: grandSuite
//
// Cas de test 1 (testUn): Jet = {1,5,3,4,2}
// 
// Cas de test 2 (testDeux): Jet = {3,5,2,5,5}
// 
// *************************************************************************************************
void testergrandeSuite()
{
	Jet testUn = {1,5,3,4,2};
	int resultatTestUn = grandeSuite(testUn);
	
	if (resultatTestUn == 40)
		printf ("RÉUSSI! :) Le resultat du Test 1 (grandSuite) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (grandSuite) est %d et aurait dû être 40\n", resultatTestUn);

	Jet testDeux = {3,5,2,5,5};
	int resultatTestDeux = grandeSuite(testDeux);
	
	if (resultatTestDeux == 0)
		printf ("RÉUSSI! :) Le resultat du Test 2 (grandSuite) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (grandSuite) est %d et aurait dû être 0\n", resultatTestDeux);
}

// ************************************************************************************************
// Test Unitaire: yahtzee
// 
// Cas de test 1 (testUn): Jet = {6,6,6,6,6}
// 
// Cas de test 2 (testDeux): Jet = {5,5,4,5,5}
// 
// *************************************************************************************************
void testeryahtzee()
{
	Jet testUn = {6,6,6,6,6};
	int resultatTestUn = yahtzee(testUn);
	
	if (resultatTestUn == 50)
		printf ("RÉUSSI! :) Le resultat du Test 1 (yahtzee) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (yahtzee) est %d et aurait dû être 50\n", resultatTestUn);

	Jet testDeux = {5,5,4,5,5};
	int resultatTestDeux = yahtzee(testDeux);
	
	if (resultatTestDeux == 0)
		printf ("RÉUSSI! :) Le resultat du Test 2 (yahtzee) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (yahtzee) est %d et aurait dû être 0\n", resultatTestDeux);
}

// ************************************************************************************************
// Test Unitaire: chance
// 
// Cas de test 1 (testUn): Jet = {6,6,6,6,6}
// 
// Cas de test 2 (testDeux): Jet = {2,1,4,4,6}
// 
// *************************************************************************************************
void testerchance()
{
	Jet testUn = {6,6,6,6,6};
	int resultatTestUn = chance(testUn);
	
	if (resultatTestUn == 30)
		printf ("RÉUSSI! :) Le resultat du Test 1 (chance) est %d\n", resultatTestUn);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 1 (chance) est %d et aurait dû être 30\n", resultatTestUn);

	Jet testDeux = {2,1,4,4,6};
	int resultatTestDeux = chance(testDeux);
	
	if (resultatTestDeux == 17)
		printf ("RÉUSSI! :) Le resultat du Test 2 (chance) est %d\n", resultatTestDeux);
	else 
		printf ("ÉCHEC! :( Le resultat du Test 2 (chance) est %d et aurait dû être 17\n", resultatTestDeux);	
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






