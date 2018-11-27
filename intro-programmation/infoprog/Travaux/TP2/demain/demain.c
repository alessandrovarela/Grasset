// *****************************************************************************
// Nom : demain.c
// Auteur : Alessandro Varela
// Date : 03 Octobre 2018
// 
// Cette programme est un paquet de fonctions. La fonction principale est demain,
// qui reçoit une date et retourne la date du lendemain.
// Les autres fonctions sont appelées directement ou indirectement par demain.
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>

typedef enum Mois Mois;
enum Mois { JANVIER = 1,
			FEVRIER,
			MARS,
			AVRIL,
			MAI,
			JUIN,
			JUILLET,
			AOUT,
		    SEPTEMBRE,
		    OCTUBRE,
		    NOVEMBRE,
		    DECEMBRE};

typedef struct Date Date;
struct Date{
	int jour;
	Mois mois;
	int annee;
};

// ************************************************************************************************
// Fonction : bisextile
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction reçoit une annee et retourne
// vrai si l'année est bisexuelle et faux sinon.
// INPUT :
//     int annee : anne
//
// OUTPUT :
//     int: Vrai si l'année est bisexuelle, Faux sinon.
//
// *************************************************************************************************
int bisextile(int annee)
{ 

    if  (    ( ( annee%400 == 0 ) ) 
    	  || 
    	     ( ( annee%4  == 0 ) && ( annee%100 != 0 ) )
    	)
        return 1;
    else
		return 0; 
}

// ************************************************************************************************
// Fonction : nbJoursDansMois
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction reçoit une moins et une annee et retourne le nombre de jours dans le mois.
// Si le mois est invalide ou l'année est inférieure à zéro retourne faux.
// INPUT :
//     int mois : Le moin
//	   int annee: Le annee
//
// OUTPUT :
//     int: Le nombre de jours dans le mois. Si le mois ou l'année est invalide, il retourne faux.
//
// *************************************************************************************************
int nbJoursDansMois(int mois, int annee)
{   
	if ( (mois > DECEMBRE) || (mois < JANVIER) || (annee <= 0))
    	return 0;

	switch (mois)
	{
		case AVRIL:
		case JUIN:
		case SEPTEMBRE:
		case NOVEMBRE:
			return 30;
			break;
	    case FEVRIER:
			if ( bisextile(annee) )
           		return 29;
        	else
           		return 28;
			break;
		default:
			return 31;
			break;
	} 
}

// ************************************************************************************************
// Fonction : estValide
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction reçoit une date et retourne
// vrai si la date est valide et faux sinon.
// INPUT :
//     Date date: Une Data avec structure par jour, mois et année.
//
// OUTPUT :
//     int: Vrai si la date est valide, Faux sinon.
//
// *************************************************************************************************
int estValide(Date date)
{ 	
	int dernierJour = nbJoursDansMois(date.mois, date.annee);
	
	if (     ( (date.jour <= 0 ) || (date.jour > 31) )
		  || ( ! dernierJour ) 
	   )
	    return 0;
	
	else if (     ( ( date.jour >= 29 ) && ( date.jour <= 31 ) )
			  &&  ( date.jour > dernierJour )
	        )
		return 0;
	else
		return 1;
}

// ************************************************************************************************
// Fonction : demain
// Auteur   : Alessandro Varela
// Date     : 03 octobre 2018
//
// Cette fonction reçoit une date et retourne la date du lendemain. Si la date est invalide,
// il retoune 0/0/0.
// INPUT :
//     Date aujourdhui: Une Data avec structure par jour, mois et année.
//
// OUTPUT :
//     Date: la date du lendemain. Si la date est invalide, retourne 0/0/0.
//
// Exemple de tests: 
//
//    // toute l'année
//    Date date1 = { 31 , 12, 1980 };
//    Date lendemain = demain(date1);    
//    printf("Lendemain : %d/%d/%d\n", lendemain.jour,lendemain.mois, lendemain.annee);
//
//     // année bisexuelle
//    Date date2 = { 29 , 02, 2016 };
//    lendemain = demain(date2);    
//    printf("Lendemain : %d/%d/%d\n", lendemain.jour,lendemain.mois, lendemain.annee);
//
//    // jour normale
//    Date date3 = { 01 , 02, 2018 };
//   lendemain = demain(date3);    
//    printf("Lendemain : %d/%d/%d\n", lendemain.jour,lendemain.mois, lendemain.annee);
// *************************************************************************************************
Date demain(Date aujourdhui)
{ 
	if ( ! estValide ( aujourdhui ) )
    {
	 	aujourdhui.jour = 0;
		aujourdhui.mois = 0;
		aujourdhui.annee = 0;
		return (aujourdhui);		
	}
	
	if ( aujourdhui.jour == nbJoursDansMois(aujourdhui.mois,aujourdhui.annee) )
	{   
		aujourdhui.jour = 1;
	    
		if ( aujourdhui.mois < 12 )
		{
			++aujourdhui.mois;
		}
		else
		{
		    aujourdhui.mois  = 1;
			aujourdhui.annee = ++aujourdhui.annee;
		}
	}
    else
	{
		++aujourdhui.jour;
	}
	   	
	return aujourdhui;

}

// *****************************************************************************
// main
//
// Exemples d'utilisation de la fonction demain
//
// *****************************************************************************
int main()
{
 
  	Date date;
	printf("Entrez une date (jj/mm/aaaa)\n");
	scanf("%d/%d/%d", &date.jour, &date.mois, &date.annee);

	Date lendemain = demain(date);
	if ( lendemain.jour == 0 )
		printf("La Date %d/%d/%d est invalide.\n", date.jour, date.mois, date.annee );
	else		
		printf("Lendemain : %d/%d/%d\n", lendemain.jour,lendemain.mois, lendemain.annee);	
}