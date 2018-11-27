// *****************************************************************************
// Fichier : dateTest.c
// Auteur : Rébecca
// Date : 15 octobre 2018
//
// Tests unitaires pour l'utilitaire de date.
// *****************************************************************************
#include <stdio.h>
#include "dateTest.h"


// *****************************************************************************
// assertDateEgal
//
// Vérifie que deux dates sont identiques et imprime un message approprié
//
// INPUT :
//     message : la description du test
//     attendu : le résultat attendu de la fonction testée
//     obtenu : le résultat obtenu de la fonction testée
// *****************************************************************************
void assertDateEgal(char* message, Date attendu, Date obtenu)
{
    if ((obtenu.jour == attendu.jour) &&
	    (obtenu.mois == attendu.mois) &&
	    (obtenu.annee == attendu.annee))
    {
        printf("RÉUSSI %s = ", message);
	    imprimerDateCourte(obtenu);
    }
    else
    {
        printf("ÉCHEC %s = ", message);
        imprimerDateCourte(obtenu);
	    printf(", mais on voulait ");
	    imprimerDateCourte(attendu);
    }
    printf(".\n");
}

// *****************************************************************************
// testerBissextile : tests unitaires pour la fonction bissextile
// *****************************************************************************
void testerBissextile()
{
    printf("\nTests bissextile : \n");
    assertEgal("bissextile(2000)", 1, bissextile(2000));
    assertEgal("bissextile(1980)", 1, bissextile(1980));
    assertEgal("bissextile(1900)", 0, bissextile(1900));
    assertEgal("bissextile(2001)", 0, bissextile(2001));
    assertEgal("bissextile(2018)", 0, bissextile(2018));
}

// *****************************************************************************
// testerEstValide : tests unitaires pour la fonction estValide
// *****************************************************************************
void testerEstValide()
{
    printf("\nTests estValide : \n");
    Date d = {0,0,0};
    assertEgal("estValide({0,0,0})", 0, estValide(d));
    
    Date e = {1,1,0};
    assertEgal("estValide({1,1,0})", 1, estValide(e));
    
    Date f = {8,13,0};
    assertEgal("estValide({8,13,0})", 0, estValide(f));
    
    Date g = {31,12,2000};
    assertEgal("estValide({31,12,2000})", 1, estValide(g));
    
    Date h = {5,5,-450};
    assertEgal("estValide({5,5,-450})", 1, estValide(h));
}

// *****************************************************************************
// testerNbJoursDansMois: tests unitaires pour la fonction nbJoursDansMois
// *****************************************************************************
void testerNbJoursDansMois()
{
    printf("\nTests nbJoursDansMois : \n");
    Date d = {0,0,0};
    assertEgal("nbJoursDansMois({0,0,0})", 0, nbJoursDansMois(d));
    
    Date e = {1,1,2000};
    assertEgal("nbJoursDansMois({1,1,2000})", 31, nbJoursDansMois(e));

    Date f = {1,2,2000};
    assertEgal("nbJoursDansMois({1,2,2000})", 29, nbJoursDansMois(f));

    Date g = {1,2,2001};
    assertEgal("nbJoursDansMois({1,2,2001})", 28, nbJoursDansMois(g));
    
    Date h = {1,4,2020};
    assertEgal("nbJoursDansMois({1,4,2020})", 30, nbJoursDansMois(h));
}


// *****************************************************************************
// testerJourSemaine: tests unitaires pour la fonction jourSemaine
// *****************************************************************************
void testerJourSemaine()
{
    printf("\nTests jourSemaine : \n");
    
    Date h = {35,1,1999};
    assertEgal("jourSemaine({35,1,1999})", 0, jourSemaine(h));
    
    Date i = {9,11,1970};
    assertEgal("jourSemaine({9,11,1970})", 1, jourSemaine(i));
    
    Date j = {1,2,1900};
    assertEgal("jourSemaine({1,2,1900})", 4, jourSemaine(j));

    Date k = {3,3,1900};
    assertEgal("jourSemaine({3,3,1900})", 6, jourSemaine(k));

    Date l = {25,1,1970};
    assertEgal("jourSemaine({25,1,1970})", 0, jourSemaine(l));
}

// *****************************************************************************
// testerDemain: tests unitaires pour la fonction demain
// *****************************************************************************
void testerDemain()
{
    printf("\nTests demain : \n");
    
    Date h = {19,1,1999};
    Date d = {20,1,1999};
    assertDateEgal("demain({19,1,1999})", d, demain(h));
    
    Date i = {31,12,2000};
    Date e = {1,1,2001};
    assertDateEgal("demain({31,12,2000})", e, demain(i));
    
    Date j = {30,9,2000};
    Date f = {1,10,2000};
    assertDateEgal("demain({31,12,2000})", f, demain(j));

    Date k = {28,2,2018};
    Date g = {1,3,2018};
    assertDateEgal("demain({28,2,2018})", g, demain(k));

    Date l = {15,15,2000};
    assertDateEgal("demain({15,15,2000})", l, demain(l));
}

// *****************************************************************************
// test : pilote pour les tests
// *****************************************************************************
void testDate()
{
    testerBissextile();
    testerEstValide();
    testerNbJoursDansMois();
    testerDemain();
    testerJourSemaine();
}
