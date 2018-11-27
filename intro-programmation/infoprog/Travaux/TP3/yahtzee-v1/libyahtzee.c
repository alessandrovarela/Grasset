

#include <time.h>
#include "libyahtzee.h"
#include <stdio.h>
#include <stdlib.h>

enum { NOMBREDES      = 5,
       FACESCHANCE    = 1,
       FACESDOUBLE    = 2,
       FACESBRELAN    = 3,
       FACESCARRE     = 4,
       FACESYATHZEE   = 5,
       SEQPETITESUITE = 4,
       SEQGRANDESUITE = 5,
       MINFACEDES     = 1,
       MAXFACEDES     = 6,
       QUANTITETOUR   =13};

enum Points { POINTSMAINPLEINE  = 25,
              POINTSPETITSUITE  = 30,
              POINTSGRANDESUITE = 40,
              POINTSYATHZEE     = 50,
              POINTSBONUS       = 35 };
/*******************************************/
int nbDeFace(Jet jet, int face)
{
    
    int iMult = 0;
    
    for(int i = 0; i < NOMBREDES; i++)
    {
        if ( jet.des[i] == face )
        {
            iMult++;
        }
    }
    
    return iMult * face;
}

/*******************************************/

Jet trierLesDes(Jet jet)
{

    int min;   
        for(int i = 0; i < NOMBREDES ; i++)
        {
            for(int j = 0; j < NOMBREDES; j++)
            {
                if ( jet.des[j] > jet.des[i] )
                {
                    min = jet.des[i];
                    jet.des[i] = jet.des[j];
                    jet.des[j] = min;
                }
            }
        }
    return jet;
}
/*******************************************/
int brelan(Jet jet)
{
    return retourneSommeFaces(jet, FACESBRELAN);
}

/*******************************************/
int carre(Jet jet)
{
     return retourneSommeFaces(jet, FACESCARRE);
}
/*******************************************/
int mainPleine(Jet jet)
{
    jet = trierLesDes(jet);
    int compte = 1;
    int estDouble = 0;
    int estBrelan = 0;

    for(int i = 0; i < NOMBREDES; i++)
    {
        if ( jet.des[i]  == jet.des[i+1] )
        {    
            compte++;
        }
        else
        {
            if ( compte == FACESBRELAN )
            {
                estBrelan = 1;
            }
            else if ( compte == FACESDOUBLE)
            {    
                estDouble = 1;
            }

            compte = 1;
        }
        
    }

    if ( estBrelan && estDouble )
        return POINTSMAINPLEINE ;
    else
        return 0;    

}
/*******************************************/
int petiteSuite(Jet jet)
{
    if ( valideSequence(jet, SEQPETITESUITE) )
        return POINTSPETITSUITE;
    else
        return 0;    
}

/*******************************************/
int grandeSuite(Jet jet)
{
    if ( valideSequence(jet, SEQGRANDESUITE) )
        return POINTSGRANDESUITE;
    else
        return 0;
}

/*******************************************/
int yahtzee(Jet jet)
{
    if ( retourneSommeFaces(jet, FACESYATHZEE) )
        return POINTSYATHZEE;
    else
        return 0;
}
/*******************************************/
int chance(Jet jet)
{
    return retourneSommeFaces(jet, FACESCHANCE);
}
/*************************************************/
int retourneSommeFaces(Jet jet, int nombreFaces)
{
    jet = trierLesDes(jet);
    int compte = 1;
    int somme  = 0;
    int estValide = 0;

    for(int i = 0; i < NOMBREDES; i++)
    {
        if ( jet.des[i]  == jet.des[i+1] )
        {    
            compte++;
            if ( compte >=nombreFaces )
                estValide = 1;

        }
        else
            compte=1;

        somme += jet.des[i];
    }
    
    // considérer le chance 
    if ( (estValide) || (nombreFaces == FACESCHANCE) )
        return somme;
    else
        return 0;    
   
}
/*******************************************/
int valideSequence ( Jet jet, int sequence )
{
    jet = trierLesDes(jet);
    int compte = 1;

    for(int i = 0; i < NOMBREDES; i++)
    {
        if ( jet.des[i+1] == ( jet.des[i]+1 )  )
        {    
            compte++;
        }
        else
        {
            if ( compte >= sequence )
            {
                return 1;
            }

            compte=1;
        }
    
    }
    
    return 0;        
}

/*******************************************/
Jet lancerLesDes(Jet jet , char choix[5] )
{
    srand(time(0));

    for( int i = 0; i < NOMBREDES; i++)
    {
        if ( choix[i] == '1' )
            jet.des[i] = rand() % MAXFACEDES + MINFACEDES;
    }   

    return jet;
   
}
/*******************************************/
void garderPointage(Jet jet, Pointage* feuilleScore,  char figure)
{        
    switch (figure)
    {
        case '1':
            feuilleScore->un = nbDeFace(jet,1);
            break;
        case '2':
            feuilleScore->deux = nbDeFace(jet,2);
            break;
        case '3':
            feuilleScore->trois = nbDeFace(jet,3);
            break;
        case '4':
            feuilleScore->quatre = nbDeFace(jet,4);
            break;
        case '5':
            feuilleScore->cinq = nbDeFace(jet,5);
            break;
        case '6':
            feuilleScore->six = nbDeFace(jet,6);             
            break;
        case 'b':
        case 'B':
            feuilleScore->brelan = brelan(jet);             
            break;
        case 'c':
        case 'C':
            feuilleScore->carre = carre(jet);             
            break;
        case 'm':
        case 'M':
            feuilleScore->mainPleine = mainPleine(jet);             
            break;
        case 'p':
        case 'P':
            feuilleScore->pSuite = petiteSuite(jet);             
            break;
        case 'g':
        case 'G':
            feuilleScore->gSuite = grandeSuite(jet);      
            break;
        case 'y':
        case 'Y':
            feuilleScore->yahtzee = yahtzee(jet);             
            break;
        case 'h':
        case 'H':
            feuilleScore->chance = chance(jet);             
            break;
    }
}
/*******************************************/
int sommeScoreSup(Pointage* feuilleScore)
{
    return  feuilleScore->un     +
            feuilleScore->deux   +
            feuilleScore->trois  +
            feuilleScore->quatre +
            feuilleScore->cinq   +
            feuilleScore->six; 
}
int sommeScoreInf(Pointage* feuilleScore)
{
    return  feuilleScore->brelan      +
            feuilleScore->carre       +
            feuilleScore->mainPleine  +
            feuilleScore->pSuite      +
            feuilleScore->gSuite      +
            feuilleScore->yahtzee     +
            feuilleScore->chance;
}

/*******************************************/
void imprimerLesDes( Jet jet )
{
    printf ( "DÉS:" );
    
    for(int i = 0; i < NOMBREDES; i++)
    {
        printf(" %d", jet.des[i]);
    }
    printf ( "\n" );

}
/*******************************************/
void imprimerScoresPossibles( Jet jet )
{
  printf("**********************************************\n");
  printf("*    QUEL POINTAGE VOULEZ-VOUS GARDER?       *\n");
  printf("**********************************************\n");
  printf("*     (1) : %2d       *       (B)relan = %2d   *\n", nbDeFace(jet,1), brelan(jet));
  printf("*     (2) : %2d       *        (C)arré = %2d   *\n", nbDeFace(jet,2), carre(jet));
  printf("*     (3) : %2d       *  (M)ain Pleine = %2d   *\n", nbDeFace(jet,3), mainPleine(jet));
  printf("*     (4) : %2d       * (P)etite suite = %2d   *\n", nbDeFace(jet,4), petiteSuite(jet));
  printf("*     (5) : %2d       * (G)rande suite = %2d   *\n", nbDeFace(jet,5), grandeSuite(jet));
  printf("*     (6) : %2d       *      (Y)ahtzee = %2d   *\n", nbDeFace(jet,6), yahtzee(jet));
  printf("*                    *       C(h)ance = %2d   *\n", chance(jet));
  printf("**********************************************\n");
}
/*******************************************/
void imprimerFeulleScore( Pointage* feuilleScore, int tour )
{
    int sommeSup = sommeScoreSup(feuilleScore);
    int sommeInf = sommeScoreInf(feuilleScore);


printf("*************************************************************************************\n");
printf("*                              FEUILLE DE SCORE TOUR  %2d/%2d                         *\n", tour, QUANTITETOUR);
printf("*************************************************************************************\n");
printf("\n");
printf("**********  Partie supérieure **********    **********  Partie inférieure ***********\n");
printf("*                                      *    *                                       *\n");
printf("*                1 :  %3d              *    *               Brelan = %3d            *\n",feuilleScore->un,feuilleScore->brelan);
printf("*                2 :  %3d              *    *                Carré = %3d            *\n",feuilleScore->deux,feuilleScore->carre);
printf("*                3 :  %3d              *    *          Main Pleine = %3d            *\n",feuilleScore->trois,feuilleScore->mainPleine);
printf("*                4 :  %3d              *    *         Petite suite = %3d            *\n",feuilleScore->quatre,feuilleScore->pSuite);
printf("*                5 :  %3d              *    *         Grande suite = %3d            *\n",feuilleScore->cinq,feuilleScore->gSuite);
printf("*                6 :  %3d              *    *              Yahtzee = %3d            *\n",feuilleScore->six,feuilleScore->yahtzee);
printf("*                                      *    *               Chance = %3d            *\n",feuilleScore->chance);
printf("*                                      *    *                                       *\n");
printf("*     Somme partie supérieure : %3d    *    *     Somme partie inferieure : %3d     *\n", sommeSup, sommeInf);
printf("****************************************    *****************************************\n");
printf("\n");
printf("*************************************************************************************\n");
printf("*                                  Score = %3d                                      *\n", sommeSup + sommeInf );
printf("*************************************************************************************\n");    
}

/*******************************************/
void jouerYahtzee()
{
    Pointage feuilleScore = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
    Pointage* pFeuilleScore = &feuilleScore;
    
    Jet jetJouer;
    char choixDes[6];
    char choixFigure;
    
    // boucle tours
    for(int tour = 1; tour <= QUANTITETOUR; tour++)
    {
        printf("Tour --> %d\n", tour);

        // Lancer premier fois
        for(int t = 0; t < NOMBREDES; t++)
        {
            choixDes[t] ='1';
        }
        jetJouer = lancerLesDes( jetJouer , choixDes  );
        imprimerLesDes( jetJouer );

        // boucle lancer les dés
        for(int jouer = 1; jouer <= 2; jouer++)
        {
            printf("Quels dés voulez-vous jeter à nouveau? (0 pour garder, 1 pour jeter)\n>");
            scanf( "%s", choixDes);

            jetJouer = lancerLesDes( jetJouer , choixDes  );
            imprimerLesDes( jetJouer );
        }
        // Imprimer les scores possibles
        imprimerScoresPossibles( jetJouer );
        printf("\n>");

        // Le choix de la figure
        scanf( " %c", &choixFigure);

        // Garder la Pointage
        garderPointage(jetJouer, pFeuilleScore, choixFigure);
        
        // imprimer Score
        imprimerFeulleScore( pFeuilleScore, tour );

    }
    

}
