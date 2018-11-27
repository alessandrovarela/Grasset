// *****************************************************************************
// Nom : structures.c
// Auteur : Rébecca
// Date : 24 septembre 2018
//
// Exercice sur les structures : Appartement.
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

// ****************************************************************************
// Un appartement a 
//   Un nombre de chambre,
//   Un nombre de salles de bain (0.5 pour une salle d'eau),
//   Droit ou non aux animaux de compagnie,
//   Un loyer par mois.
// ****************************************************************************
typedef struct Appartement Appartement;
struct Appartement{
     int nbChambres;
     double nbSdB;
     int animaux;
     int prixParMois;
};

// *****************************************************************************
//
// repondBesoinsJules
//
// Détermine si un appartement répond aux besoins de Jules. Jules cherche un
// studio à moins de 800$ par mois et qui permet les animaux de compagnie.
//
// INPUT
//     apt : un appartement
//
// OUTPUT
//     1 si l'appartement répond aux besoins de Jules et 0 sinon.
//
// *****************************************************************************
int repondBesoinsJules(Appartement apt)
{
    const int STUDIO = 1;
    const int LIMITE_PRIX_JULES = 800;

    return (apt.nbChambres == STUDIO &&
            apt.animaux &&
            apt.prixParMois < LIMITE_PRIX_JULES);
}

// *****************************************************************************
//
// repondBesoinsFontecilla
//
// Détermine si un appartement répond aux besoins de la famille Fontecilla. 
// La famille Fontecilla cherche un appartement ayant au moins 3 chambres
// à coucher et 1.5 salles de bain.
//
// INPUT
//     apt : un appartement
//
// OUTPUT
//     1 si l'appartement répond aux besoins des Fontecilla et 0 sinon.
//
// *****************************************************************************
int repondBesoinsFontecilla(Appartement apt)
{
    const int NB_CHAMBRES_MIN_FONTECILLA = 3;
    const double NB_SDB_MIN_FONTECILLA = 1.5;

    return (apt.nbChambres >= NB_CHAMBRES_MIN_FONTECILLA &&
            apt.nbSdB >= NB_SDB_MIN_FONTECILLA);
}

// *****************************************************************************
//
// imprimerDescriptionAppartement
//
// Imprime à la console une descrption d'un appartement
//
// INPUT
//     apt : l'appartement à afficher
//
// OUTPUT
//     rien
//
// *****************************************************************************
void imprimerDescriptionAppartement(Appartement apt)
{
    printf("%d chambre(s) à coucher, %.1lf salle(s) de bain, %d$/mois.\n",
	   apt.nbChambres, apt.nbSdB, apt.prixParMois);
    printf("Les animaux de compagnie sont ");
    if (apt.animaux)
        printf("acceptés");
    else
        printf("interdits");
    printf(".\n");
}

// *****************************************************************************
//
// main
//
// Pilote pour l'exercice des appartements. Crée un tableau de 5 appartements
// représentant l'immeuble à logement de Manon. Imprime la description de chaque
// appartement et affiche, pour chaque logement, s'il répond aux besoins de
// Jules et/ou à ceux de la famille Fontecilla.
//
// *****************************************************************************
int main()
{
    const int APTS_MANON = 5;
    Appartement apts[] = {{2, 1, 0, 900}, {2, 1.5, 0, 1100},
			  {3, 2, 0, 1600}, {2, 1, 0, 850}, {1, 1, 0, 745}};

    printf("\nLES APPARTEMENTS DE MANON\n\n");	
    for (int i = 0; i < APTS_MANON; i++)
    {
    	printf("Appartement %d : ", i);
    	imprimerDescriptionAppartement(apts[i]);
	
	if (repondBesoinsJules(apts[i]))
	    printf("Répond aux besoins de Jules.\n");
	else
	    printf("Ne répond pas aux besoins de Jules.\n");
	
	if (repondBesoinsFontecilla(apts[i]))
	    printf("Répond aux besoins des Fontecilla.\n");
	else
	    printf("Ne répond pas aux besoins des Fontecilla.\n");
    	printf("\n");
    }
}
