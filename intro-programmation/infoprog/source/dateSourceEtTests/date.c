// *****************************************************************************
// Fichier : date.c
// Auteur : Rébecca
// Date : 16 octobre 2018
//
// Utilitaire de dates grégoriennes.
// *****************************************************************************
#include <stdio.h>
#include "date.h"

#define PREMIER 1
#define SIECLE 100

// Nombre de jours dans les mois
enum NbJours {NB_JOURS_FEV_BIS = 29, NB_JOURS_FEV = 28, NB_JOURS_JANV = 31,
	      NB_JOURS_AVR = 30};

// Règle pour les années bissextile sur la planète Terre
enum RegleBisTerre {R = 4, E = 100};

// *****************************************************************************
// bissextile
//
// Détermine si une année est bissextile ou non
//
// INPUT :
//     annee : l'année
//
// OUTPUT :
//     1 si annee est bissextile, 0 sinon.
// *****************************************************************************
int bissextile(int annee)
{
    return ((!(annee % R) && (annee % E)) || !(annee % (R * E)));
}

// *****************************************************************************
// nbJoursDansMois
//
// Détermine le nombre de jours dans un mois
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Le nombre de jours dans le mois de d. Les choix possibles sont
//     28, 29, 30 ou 31
// *****************************************************************************
int nbJoursDansMois(Date date)
{
    switch (date.mois)
    {
        case FEVRIER:
            return (bissextile(date.annee) ? NB_JOURS_FEV_BIS : NB_JOURS_FEV);
        case AVRIL:
        case JUIN:
        case SEPTEMBRE:
        case NOVEMBRE:
            return NB_JOURS_AVR;
        case JANVIER:
        case MARS:
        case MAI:
        case JUILLET:
        case AOUT:
        case OCTOBRE:
        case DECEMBRE:
            return NB_JOURS_JANV;
        default :
            return 0;
    }
}

// *****************************************************************************
// estValide
//
// Détermine si une date est valide
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     1 si d est valide, 0 sinon
// *****************************************************************************
int estValide(Date date)
{
    return ((date.mois >= JANVIER) && (date.mois <= DECEMBRE) &&
            (date.jour >= PREMIER) && (date.jour <= nbJoursDansMois(date)));
}

// *****************************************************************************
// demain
//
// Calcule la date du lendemain d'une date donnée
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     La date du lendemain de d
// *****************************************************************************
Date demain(Date hui)
{
    if (!estValide(hui))
        return hui;
    
    hui.jour++;
    if (estValide(hui))
        return hui;
   
    hui.jour = PREMIER;
    hui.mois++;
    if (estValide(hui))
        return hui;
    
    hui.mois = JANVIER;
    hui.annee++;
    return hui;
}

// *****************************************************************************
// jourSemaine
//
// Détermine le jour de la semaine pour une date
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Le jour de la semaine sur lequel tombe d. (dimanche, lundi, mardi,
//     mercredi, jeudi, vendredi ou samedi)
// *****************************************************************************
int jourSemaine(Date date)
{
    if (!estValide(date))
        return DIMANCHE;
  
    int y = date.annee;
    int m = date.mois;
    if (m == JANVIER || m == FEVRIER)
    {
        y--;
        m += (DECEMBRE - FEVRIER);
    }
    else
        m -= FEVRIER;
    int c = y/SIECLE;
    y %= SIECLE;
    return ((((date.jour + (26 * m - 2) / 10 - 2 * c + y + y / 4 + c / 4)
	      % NB_JOURS_SEMAINE) + NB_JOURS_SEMAINE) % NB_JOURS_SEMAINE);
}

// *****************************************************************************
// imprimerDateLongue
//
// Imprime une date en format long. Par exemple : Lundi le 15 octobre 2018
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerDateLongue(Date date)
{
    if (estValide(date))
    {
    	imprimerJourSemaine(jourSemaine(date));
    	printf(", le %d%s", date.jour, (date.jour == PREMIER) ? "e " : " ");
    	imprimerMois(date.mois);
    	printf(" %d", date.annee);
    }
}

// *****************************************************************************
// imprimerMois
//
// Imprime le nom d'un mois.
//
// INPUT :
//     mois : un mois
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerMois(Mois mois)
{
    switch (mois)
    {
        case JANVIER   : printf("janvier");   break;
        case FEVRIER   : printf("février");   break;
        case MARS      : printf("mars");      break;
        case AVRIL     : printf("avril");     break;
        case MAI       : printf("mai");       break;
        case JUIN      : printf("juin");      break;
        case JUILLET   : printf("juillet");   break;
        case AOUT      : printf("aout");      break;
        case SEPTEMBRE : printf("septembre"); break;
        case OCTOBRE   : printf("octobre");   break;
        case NOVEMBRE  : printf("novembre");  break;
        case DECEMBRE  : printf("décembre");  break;
    }
}

// *****************************************************************************
// imprimerJourSemaine
//
// Imprime le nom d'un jour de la semaine
//
// INPUT :
//     jour : un jour
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerJourSemaine(Jour jour)
{
    switch (jour)
    {
        case DIMANCHE : printf("Dimanche"); break;
        case LUNDI    : printf("Lundi");    break;
        case MARDI    : printf("Mardi");    break;
        case MERCREDI : printf("Mercredi"); break;
        case JEUDI    : printf("Jeudi");    break;
        case VENDREDI : printf("Vendredi"); break;
        case SAMEDI   : printf("Samedi");   break;
    }
}

// *****************************************************************************
// imprimerDateCourte
//
// Imprime une date dans le format jj/mm/aaaa
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerDateCourte(Date date)
{
    printf("%d/%d/%d", date.jour, date.mois, date.annee);
}

// *****************************************************************************
// egales
//
// Détermine si deux dates sont égales
//
// INPUT :
//     d : une première date
//     e : une deuxième date
//
// OUTPUT :
//     1 si d et e sont identiques, 0 sinon.
// *****************************************************************************
int egales(Date d, Date e)
{
    return ((d.jour == e.jour) && (d.mois == e.mois) && (d.annee == e.annee));
}
