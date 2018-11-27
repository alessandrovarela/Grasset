// *****************************************************************************
// Nom : structures.c
// Auteur : 
// Date : 21 septembre 2018
//
// Exercice sur les matrix 1
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>


typedef struct Appartement Appartement;
		struct Appartement{
							int nbChambres;
							double nbSdB;
							int animaux;
							int prixParMois;
						  };

int repondBesoinsJules(Appartement apt)
{
	return (apt.nbChambres == 1 &&
			apt.animaux &&
			apt.prixParMois < 800);
}


int repondBesoinsFontecilla(Appartement apt)
{
	return (apt.nbChambres >= 3 &&
			apt.nbSdB >= 1.5);
}						  


void imprimerDescriptionAppartement(Appartement apt)
{



//	const char ANIMAUXOUI = 'OUI';
//	char ANIMAUXNON = 'NON';
//	char cPrintAnimux;


/*
	if ( apt.animaux == 1 )
		cPrintAnimux = ANIMAUXOUI ;
	else 
		cPrintAnimux = ANIMAUXNON;
*/		

	printf("Chambres:%d, Sales de Bain:%f, Animaux:%c, Prix par Moin:%d  \n", apt.nbChambres , apt.nbSdB , apt.animaux, apt.prixParMois );

}


int main()
{

	
    const int APTS_MANON = 5;

	Appartement apt;

	apt.nbChambres = 1;
	apt.nbSdB = 1;
	apt.animaux = 0;
	apt.prixParMois = 750;

	if (repondBesoinsJules(apt))
		printf("L'appartement repond aux besoin de Jules\n");
	else 
		printf("L'appartement ne repond pas aux besoin de Jules\n");

	// Appartamants Manon

	printf("\n\n\n");

	Appartement apts[5] = {	{2, 1, 0, 900}, 
							{2, 1.5, 0, 1100},
							{3, 2, 0, 1600},
							{2, 1, 0, 850},
							{1, 1, 0, 745} }; 


	for (int i = 0; i < APTS_MANON; ++i)
	{

		repondBesoinsFontecilla(apts[i]);


		if (repondBesoinsFontecilla(apt))
			printf("L'appartement repond aux besoin de Fontecilla\n");
		else 
			printf("L'appartement ne repond pas aux besoin de Fontecilla\n");


		imprimerDescriptionAppartement (apts[i]);

	}





}