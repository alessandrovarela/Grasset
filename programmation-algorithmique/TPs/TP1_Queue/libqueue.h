// *****************************************************************************
// Nom : libqueue.h
// Auteur : Alessandro Varela
// Date : 18 Novembrer 2018
//
// Documentation de toute les fonctions pour pour le simulation Queue
//
// *****************************************************************************
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define NOMBRECYCLES 2000  // Nombre de cyclos qui définit le magasin ouvert
#define MINHASARD 1
#define MAXHASARD 2       // Nombre maximal de chances qu'un client arrive
#define NOMBREDECAISSES 4 // Nombre de cassies de magasin
#define PAUSEPARCYCLE 1000  // Pause entre les cycles (millisecondes)
#define CYCLESABANDONNER 3   // Nombre maximal de cycles d'attente pour quitter la file d'attente
#define LAMBDA 10  // Distribution exponentielle d'esperance pour la génération aléatoire du nombre d'articles

enum{ CLIENTARRIVE = 1,
      CYCLEINITIAL = 1 };

// *****************************************************************************
// Structure Client
//
// Structure Client sous forme d'une liste doublement chaînées
//
//******************************************************************************
typedef struct Client Client;
struct Client {
	Client* precedent;
    int instantArrivee;
	int nbArticles;
	Client* suivant;
};
// *****************************************************************************
// Structure Queue
//
// Structure contenant le premier de la file d'attente, le dernier de la file
// d'attente et la taille totale de la file d'attente.
//******************************************************************************
typedef struct Queue Queue;
struct Queue {
	Client* premier; 
	Client* dernier;
    int taille;
};
// *****************************************************************************
// Structure Queue
//
// Structure utilisée pour le rapport de statistiques
//******************************************************************************
typedef struct Statistiques Statistiques;
struct Statistiques {
    int nbClientsEntres;
    int nbClientsServis;
    int nbClientsAbandons;
    int nbArticlesVendu;
    int tempAttenteTotal;
    int tempAttenteMoyen;
    int tempAttenteMaximum;
    int nbArticlesTotal;
    int nbArticlesMaximum;
    int nbArticlesMinimum;
    int nbArticlesMoyen;
};
// *****************************************************************************
// Fonction : hasard
//
// retourne Vrai ou Faux sur une base aléatoire comprise entre 1 et le 
// nombre de chances spécifié par le nombre maximal de chances qu'un client 
// arrive défini dans MAXHASARD
//
// INPUT :
//     rien
//
// OUTPUT : 
//     int: Vrai si la client arrvivé, Faux sinon.
// *****************************************************************************
int hasard();

// *****************************************************************************
// Fonction : hasard 
// Retourne Le nombre d'articles dans le panier d'un client suit une 
//distribution exponentielle. 
// INPUT :
//     lambda: distribution exponentielle d'esperance 1/LAMBADA
//
// OUTPUT : 
//     int: d'articles dans le panier d'un client
// *****************************************************************************
double randExpo(double lambda);

// *****************************************************************************
// Fonction : initialiserQueues 
//  
// Initialise toutes les files avec taille zéro et 
// les premier et dernier clients avec la valeur Null. 
//
// INPUT :
//     Queue* queue: Pointeur du tableau des queues 
//
// OUTPUT : 
//     void
// *****************************************************************************
void initialiserQueues (Queue* queue);

// *****************************************************************************
// Fonction : longueurQueue 
//  
// Retourne le nombre de clients dans la queue.
//
// INPUT :
//     Queue* queue: L'adresse de la queue
//
// OUTPUT : 
//     int: nombre de clients dans la queue.
// 
// Pseudo-code:
// queue <- Pointeur sur une instance de file d'attente 
// Retourne Taille
//
// *****************************************************************************
int longueurQueue(Queue* queue);

// *****************************************************************************
// Fonction : plusCourteQueue
//  
// Retourne la queue plus courte d'un tableau de queues.
//
// INPUT :
//     Queue* queue: L'adresse tableau de queues
//
// OUTPUT : 
//     Queue*: L'adresse de la queue plus courte.
// *****************************************************************************
Queue* plusCourteQueue(Queue* queues);

// *****************************************************************************
// Fonction : creerClient
//  
// Crée un client (instance) en utilisant la structure de client.
//
// INPUT :
//     instant: Nombre du moment d'arrivée du client au magasin (cycle).
//
// OUTPUT : 
//     Client*: L'adresse du nouveau client créé.
// *****************************************************************************
Client* creerClient (int instant);

// *****************************************************************************
// Fonction : offrirClient
//  
// Ajoute le client a la fin de queue.
//
// INPUT :
//     Queue* queue: L'adressede la file d'attente où le client sera ajouté.
//     Client* client: L'adresse du client sera ajoutée.
// OUTPUT : 
//     void
//
// Pseudo-code:
// Si queue -> premier est égal NULL, alor
//      queue->premier <- client
//      queue->dernier <- client
// sinon
//      queue->dernier->suivant <- client
//      client->precedent <- queue->dernier
//      queue->dernier <- client;
//
//  queue->taille++;
//
// *****************************************************************************
void offrirClient(Queue* queue, Client* client);

// *****************************************************************************
// Fonction : coupDOeilTete
//  
// Retourne le premier client dans la queue.
// Si la queue est vide, NULL est retourne.
//
// INPUT :
//     Queue* queue: L'adressede la file.
// OUTPUT : 
//     Client* client: L'adresse du premier client de la file.
//
// *****************************************************************************
Client* coupDOeilTete(Queue* queue);

// *****************************************************************************
// Fonction : obtenirTete
//  
// Retire le premier client dans la queue si le premier est différent de NULL
//
// INPUT :
//     Queue* queue: L'adressede la file où le client sera retire.
// OUTPUT : 
//     void
//
// Pseudo-code:
//   queue <-L'adressede la file
//   Client* client <- queue->premier;
//   Si client est différent de NULL 
//        queue->premier = client->suivant
//        queue->taille--;
//        free(client);
// *****************************************************************************
void obtenirTete(Queue* queue);

// *****************************************************************************
// Fonction : clientsDansLesQueues
//  
// Rentourne Vrai s'il y a un client dans l'une des files du tableau des files.
// Cette fonction est utilisée comme condition pour que le programme principal 
// continue jusqu'à ce que tous les clients soient servis après la fermeture du magasin.
//
// INPUT :
//     Queue* queues: L'adressede du tableau de queues.
// OUTPUT : 
//     int: Vrai 'il y a un client dans l'une des files, sinon, retorune faux.
//
// *****************************************************************************
int clientsDansLesQueues(Queue* queues);

// *****************************************************************************
// Fonction : calculeTempDattente
//  
// Rentourne le temps d'attente du client qui prend la première place dans la file.
// Le temps d'attente est pris en compte jusqu'à ce qu'il occupe la première
// place dans la file d'attente. Ce n’est pas considéré comme le temps passé
// par le caissier.
//
// INPUT :
//      instant: Moment où le premier client quitte la file.    
//      Client* client: Adresse du client quittant la file.
// OUTPUT : 
//     int: Le temps d'attente du client (suivant) qui prend la première 
//          place dans la file.
//
// *****************************************************************************
int calculeTempDattente( int instant, Client* client);

// *****************************************************************************
// Fonction : abandonnerLaFile
//  
// Supprime de la file le client qui a dépassé la limite d'attente maximale.
// Le paramètre de limite de cycle d'abandon peut être modifié par la macro
// CYCLESABANDONNER.
// Le temps d'attente des clients qui ont abandonné la file d'attente est 
// également ajouté au temps d'attente total du rapport, ce qui influence
// le temps d'attente moyen.
// 
//
// INPUT :
//      Queue* queue: L'adresse de la file où le client peut être retiré 
//                    s'il dépasse la limite d'attente.
//      instant: Instant
//      Statistiques* stat: L'adresse de l'instance de statistiques
// OUTPUT : 
//     void
//
// *****************************************************************************
void abandonnerLaFile(Queue* queue , int instant, Statistiques* stat);

// *****************************************************************************
// Fonction :imprimerQueue
//  
// Imprime une file clients.
//
// INPUT :
//      Queue* queue: L'adresse de la file 
// OUTPUT : 
//     void
//
// *****************************************************************************
void imprimerQueue(Queue* queue);

// *****************************************************************************
// Fonction :imprimerQueue
//  
// Imprime toutes les files du tableau de files.
//
// INPUT :
//      Queue* queue: L'adresse du tableau de files.
// OUTPUT : 
//     void
//
// *****************************************************************************
void imprimerToutQueues(Queue* queues);

// *****************************************************************************
// Fonction :imprimerEnTete
//  
// Imprime l’en-tête indiquant si le magasin est fermé ou ouvert et compte 
// le nombre de cycles.
// INPUT :
//      instant: Instant actuele des cycles.
// OUTPUT : 
//     void
//
// *****************************************************************************
void imprimerEnTete(int instant);
// *****************************************************************************
// Fonction :imprimerStatistiques
//  
// Imprime le tableau des statistiques
// INPUT :
//      Statistiques* stat: L'adresse du tableau de statistiques
// OUTPUT : 
//     void
//
// *****************************************************************************
void imprimerStatistiques(Statistiques* stat);
