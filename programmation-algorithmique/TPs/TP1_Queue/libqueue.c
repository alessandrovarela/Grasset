// *****************************************************************************
// Nom : libqueue.c
// Auteur : Alessandro Varela
// Date : 18 Novembrer 2018
//
// Fonctions du programme queue 
//
// *****************************************************************************
#include "libqueue.h"

/***********************************************/
int hasard() {
    return ((rand()%MAXHASARD) == CLIENTARRIVE);
}

/***********************************************/
double randExpo(double lambda){   
    double u = rand() / (RAND_MAX + 1.0);
    return -log(1 - u) / lambda;
}

/***********************************************/
void initialiserQueues (Queue* queue){

    for(int i = 0; i < NOMBREDECAISSES; i++)
    {   queue[i].taille=0;
        queue[i].premier=NULL;
        queue[i].dernier=NULL;       
    }
}

/***********************************************/
int longueurQueue(Queue* queue){
    return queue->taille;
}

/***********************************************/
Queue* plusCourteQueue(Queue* queues){
     
    Queue* plusCourt; 
    int petitTaille = longueurQueue(&queues[NOMBREDECAISSES-1]); 
    plusCourt = &queues[NOMBREDECAISSES-1];
    
    for(int i = (NOMBREDECAISSES-2); i >= 0; i--)
    {
        if ( longueurQueue(&queues[i]) <= petitTaille ){
            petitTaille = longueurQueue(&queues[i]);
            plusCourt = &queues[i];
        }

    }
    return plusCourt;
}

/***********************************************/
Client* creerClient (int instant)
{    
    Client* nouveau = (Client*)malloc(sizeof(Client));
	nouveau->precedent = NULL;
    nouveau->instantArrivee = instant;
	nouveau->nbArticles = (int)randExpo(1.0/LAMBDA)+1;
	nouveau->suivant = NULL;
	return nouveau;
}    

/***********************************************/
void offrirClient(Queue* queue, Client* client){

    if ( queue->premier == NULL){
        queue->premier = client;
        queue->dernier = client;
    }
    else {
        // ajouter nouveau client sur le dernier
        (queue->dernier)->suivant = client;

        // ajouter novoveu client sur le precedan
        client->precedent = queue->dernier;
        
        // met à jour le dernier dans la queue
        queue->dernier = client;
    }
    // met à jour le taille
    queue->taille++;
}
/***********************************************/
Client* coupDOeilTete(Queue* queue){
    return queue->premier;
}

/***********************************************/
void obtenirTete(Queue* queue){
    
    Client* client = queue->premier;

    if ( client != NULL ){
        queue->premier = client->suivant;
        
        queue->taille--;
        free(client);
    }
}
/***********************************************/
int clientsDansLesQueues(Queue* queues){   
    for(int i = 0; i < NOMBREDECAISSES; i++){
        if (queues[i].taille > 0 )
            return 1;
    }
    return 0;
}
/***********************************************/
int calculeTempDattente( int instant, Client* client){
    
    if (client->suivant != NULL )
       return (instant - client->suivant->instantArrivee);
    return 0;
}

/***********************************************/
void abandonnerLaFile(Queue* queue , int instant, Statistiques* stat)
{
    if ( queue->taille > 1 )
    {
        for(Client* client = queue->premier->suivant; client != NULL; client=client->suivant)
        {
            if ( (instant - client->instantArrivee) >= CYCLESABANDONNER )
            {
                if (client->suivant != NULL)
                    client->suivant->precedent = client->precedent;
                else
                    queue->dernier = queue->premier;

                if (client->precedent != NULL)
                    client->precedent->suivant = client->suivant;
                
                queue->taille--;
                stat->nbClientsAbandons++;
                // Inclut le temps d'attente d'abandon dans la statistique d'attente totale
                stat->tempAttenteTotal += ( instant - client->instantArrivee );
                if (stat->tempAttenteMaximum < ( instant - client->instantArrivee ))
                    stat->tempAttenteMaximum = ( instant - client->instantArrivee );
                free(client);
            }
        }
    }
 	
}

/***********************************************/
void imprimerQueue(Queue* queue){
    if ( queue->premier != NULL ) {
        for(Client* c = queue->premier; c!= NULL; c=c->suivant)
        {
            printf("{%d,%d}",c->instantArrivee, c->nbArticles);
        }
   }
}

/***********************************************/
void imprimerToutQueues(Queue* queues){
    
    for(int i = 0; i < NOMBREDECAISSES; i++)
    {
        printf("Caisse %d <%d>:",i+1, queues[i].taille );
        imprimerQueue(&queues[i]);
        printf("\n");
    }
}

/***********************************************/
void imprimerEnTete(instant){
    printf("==========================================================\n");
    if (instant <= NOMBRECYCLES)
        printf("|                      MAGASIN [ OUVERT ]                |\n");
    else
        printf("|                      MAGASIN [ FERMÉ  ]                |\n");
    printf("==========================================================\n");
    printf("|                       CYCLE %4d /%4d                 |\n",instant,NOMBRECYCLES);
    printf("==========================================================\n");
}

/***********************************************/
void imprimerStatistiques(Statistiques* stat){

    int percClientServis = 0;
    int percClientAbandons = 0;
    int tempAttenteMoyen = 0;
    int moyenArticles  = 0;

    if ( stat->nbClientsEntres > 0 )
    {
        percClientServis = (stat->nbClientsServis*100/stat->nbClientsEntres);
        percClientAbandons = (stat->nbClientsAbandons*100/stat->nbClientsEntres);
        moyenArticles = (stat->nbArticlesTotal / stat->nbClientsEntres);
    }
    if ( stat->nbClientsServis > 0)
    {
        tempAttenteMoyen = stat->tempAttenteTotal / stat->nbClientsServis;
    }
         
    printf("+----------------------------------------------------------+\n");
    printf("| STATISTIQUES - Modèle à files multiples                  |\n");
    printf("+----------------------------------------------------------+\n");
    printf("| Nombre de clients entrés                | %7d |      |\n",stat->nbClientsEntres);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Nombre de clientes servis               | %7d | %3d%% |\n",stat->nbClientsServis, percClientServis);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Nombre d'abandons [d'attente maximal:%d]| %7d | %3d%% |\n",CYCLESABANDONNER,stat->nbClientsAbandons,percClientAbandons);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Nombre d'articles vendus                | %7d |      |\n", stat->nbArticlesVendu);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Temps d'attente total [avec abandons]   | %7d |Cycles|\n", stat->tempAttenteTotal);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Temps  d'attente moyen                  | %7d |Cycles|\n", tempAttenteMoyen );
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Temps  d'attente maximum                | %7d |Cycles|\n", stat->tempAttenteMaximum);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Nombre d'articles maximum               | %7d |      |\n", stat->nbArticlesMaximum);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Nombre d'articles minimum               | %7d |      |\n", stat->nbArticlesMinimum);
    printf("+-----------------------------------------+---------+------+\n");
    printf("| Nombre d'articles moyen                 | %7d |      |\n", moyenArticles);
    printf("+-----------------------------------------+---------+------+\n");    
}
