// *****************************************************************************
// Fichier : date.h
// Auteur : Rébecca
// Date : 15 octobre 2018
//
// Utilitaire de dates grégoriennes.
// *****************************************************************************
#pragma once

#define NB_JOURS_SEMAINE 7

// Liste des mois
typedef enum Mois Mois;
enum Mois {JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
	   SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};

// Liste des jours de la semaine. La semaine commence le dimanche
typedef enum Jour Jour;
enum Jour {DIMANCHE, LUNDI, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI};

// Structure pour encapsuler une date
typedef struct Date Date;
struct Date
{
    int jour;
    Mois mois;
    int annee;
};

// *****************************************************************************
// demain
//
// Calcule la date du lendemain d'une date donnée. Si la date est invalide
// elle est retournée inchangée.
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     La date du lendemain de d
// *****************************************************************************
Date demain(Date d);

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
int bissextile(int annee);

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
int estValide(Date d);

// *****************************************************************************
// nbJoursDansMois
//
// Détermine le nombre de jours dans un mois. Si le mois est invalide, 0 est
// retourné.
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Le nombre de jours dans le mois de d. Les choix possibles sont
//     28, 29, 30 ou 31
// *****************************************************************************
int nbJoursDansMois(Date d);

// *****************************************************************************
// jourSemaine
//
// Détermine le jour de la semaine pour une date.  Si la date est invalide,
// dimanche est retourné.
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Le jour de la semaine sur lequel tombe d. (dimanche, lundi, mardi,
//     mercredi, jeudi, vendredi ou samedi)
// *****************************************************************************
int jourSemaine(Date d);

// *****************************************************************************
// imprimerDateCourte
//
// Imprime une date dans le format jj/mm/aaaa.
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerDateCourte(Date date);


// *****************************************************************************
// imprimerDateLongue
//
// Imprime une date en format long. Par exemple : Lundi le 15 octobre 2018. Si
// la date est invalide, rien n'est imprimé.
//
// INPUT :
//     d : Une date
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerDateLongue(Date date);


// *****************************************************************************
// imprimerMois
//
// Imprime le nom d'un mois. Si le mois est invalide, rien n'est imprimé.
//
// INPUT :
//     mois : un mois
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerMois(Mois mois);


// *****************************************************************************
// imprimerJourSemaine
//
// Imprime le nom d'un jour de la semaine. Si le jour est invalide, rien n'est
// imprimé.
//
// INPUT :
//     jour : un jour
//
// OUTPUT :
//     Rien
// *****************************************************************************
void imprimerJourSemaine(Jour jour);

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
int egales(Date d, Date e);
