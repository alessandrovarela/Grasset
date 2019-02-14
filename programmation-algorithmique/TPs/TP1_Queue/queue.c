// ************************************************************************************************
// Nom: queue.c
// Auteur: Alessandro Varela
// Date: 18 novembre 2018
//
// Ce programme simule l'arrivée et le départ de clients dans lesquels ils achètent des produits et 
// qui sont// servis par les caisses disponibles dans le magasin.
// Le magasin peut recevoir des clients lorsqu'il est ouvert. Le nombre maximal de cycles définit
// la période d'ouverture du magasin.
// Lorsque le magasin est fermé (il dépasse la limite des cycles établis), le programme continue 
// jusqu'à ce que tous les clients à l'intérieur du magasin soient satisfaits.
// À la fin, vous pouvez consulter le rapport avec les statistiques de fréquentation du magasin.
//
// Vous pouvez modifier les paramètres de simulation dans le fichier libqueue.h
// *************************************************************************************************

#include "libqueue.h"

int main()
{
    int instant = CYCLEINITIAL;
    srand(time(0));
    Queue queues[NOMBREDECAISSES];
    Statistiques statistiques = {0,0,0,0,0,0,0,0,0,0,0};
    initialiserQueues(queues);

    // Tant qu'il y a des clients dans le magasin ou que le magasin est ouvert
    while ( clientsDansLesQueues(queues) || instant <= NOMBRECYCLES )
    {
        if ( hasard() && instant <= NOMBRECYCLES)
        {  
            // Créer le client
            Client* clientNouveau  = creerClient( instant );
            // Vérifier la file  plus courte
            Queue* queuePlusCourte = plusCourteQueue(queues);
            // Ajoute dans la file plus courte
            offrirClient(queuePlusCourte, clientNouveau);

            // Met à jour les statistiques
            statistiques.nbClientsEntres++;
            statistiques.nbArticlesTotal += clientNouveau->nbArticles;
            
            if (clientNouveau->nbArticles > statistiques.nbArticlesMaximum)
                statistiques.nbArticlesMaximum = clientNouveau->nbArticles;
            
            if ( statistiques.nbClientsEntres == 1 )
                statistiques.nbArticlesMinimum = clientNouveau->nbArticles;
            else 
            {
                if (clientNouveau->nbArticles < statistiques.nbArticlesMinimum)
                    statistiques.nbArticlesMinimum = clientNouveau->nbArticles;
            }
        };
        // Imprime l'en-tête, les files et le rapport
        system("clear");
        imprimerEnTete(instant);
        imprimerToutQueues(queues);
        imprimerStatistiques(&statistiques);
        // Parcour le tableau des files
        for(int i = 0; i < NOMBREDECAISSES; i++)
        {
            // Retourne le premier de la ligne
            Client* clientPremier = coupDOeilTete(&queues[i]);

            if ( clientPremier != NULL ){
                // S'il y a des articles, retirer un
                if (clientPremier->nbArticles > 0)
                {
                    clientPremier->nbArticles--;
                    statistiques.nbArticlesVendu++;
                }
                else
                // S'il n'y a pas d'articles, retirer de la file
                {
                    statistiques.tempAttenteTotal += calculeTempDattente( instant , clientPremier );
                    if (calculeTempDattente(instant,clientPremier) > statistiques.tempAttenteMaximum)
                    {
                        statistiques.tempAttenteMaximum = calculeTempDattente(instant,clientPremier);
                    }
                    obtenirTete(&queues[i]);
                    statistiques.nbClientsServis++;
                }
            }
            // Vérifier et retirer les clients ayant dépassé la limite d'attente.
            abandonnerLaFile(&queues[i],instant,&statistiques);
        }
        
        // Imprime l'en-tête, les files et le rapport
        system("clear");
        imprimerEnTete(instant);
        imprimerToutQueues(queues);
        imprimerStatistiques(&statistiques);
        usleep(PAUSEPARCYCLE);
        instant++;
    }
    return 0;
}
