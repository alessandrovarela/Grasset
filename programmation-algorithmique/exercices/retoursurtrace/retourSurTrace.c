//*********************************************************
// retourSurTrace.c
// Rébecca
// 30 novembre 2018
//
// Exemple de retour sur trace : les dames
//*********************************************************
#include <stdio.h>
#include <stdlib.h>
#define TAILLE 4
#define TAILLELABYRINTHE 8
#define DESSIN_MUR "▇"
#define DESSIN_SOURIS "🐭"
#define DESSIN_VIDE " "
#define DESSIN_FORMAGE "🧀"

int CONTPOSSILITE;

//*********************************************************
// int libre(int echiquier[TAILLE][TAILLE], int x, int y)
// Détermine si la case (x,y) est libre dans l'échiquier
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//    x, y : les coordonnées de la case dans l'échiquier
//
// OUTPUT : 
//    1 si la case x,y est libre, 0 sinon.
//*********************************************************
int libre(int echiquier[TAILLE][TAILLE], int x, int y)
{
  for (int i = 0; i < TAILLE; i++)
  {
    if (echiquier[x][i] || echiquier[i][y])
      return 0;
    for (int j = 0; j < TAILLE; j++)
      if (echiquier[i][j] && ((i + j == x + y) || (i - j == x - y)))
	     return 0;
  }
  return 1;
}

//*********************************************************
// void printEchiquier(int echiquier[TAILLE][TAILLE])
// Imprime l'échiquier à la console.
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//*********************************************************
void printEchiquier(int echiquier[TAILLE][TAILLE])
{
  for (int i = 0; i < TAILLE; i++)
  {
      for (int j = 0; j < TAILLE; j++)
        printf("%d ", echiquier[i][j]);
      printf("\n");
  }
}

//*********************************************************

void printlab(int labyrinthe[TAILLELABYRINTHE][TAILLELABYRINTHE])
{
  for (int i = 0; i < TAILLELABYRINTHE; i++)
  {
      for (int j = 0; j < TAILLELABYRINTHE; j++)
        
        switch (labyrinthe[i][j])
        {
          case 0:
            printf("%s ", DESSIN_VIDE ) ;
            break;        
          case 1:
            printf("%s ", DESSIN_MUR ) ;
            break;        
          case 2:
            printf("%s ", DESSIN_SOURIS ) ;
            break;        
          default:
            printf("%d ", labyrinthe[i][j]);
        }
        
        
        //printf("%d ", labyrinthe[i][j]);


    printf("\n");
      
  }
  printf("\n");
}

//*********************************************************
// int dames(int echiquier[TAILLE][TAILLE], int nbDames)
// Détermine si nbDames dames peuvent être placées dans 
// l'échiquier sans qu'une puisse en manger une autre.
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//    nbDames : le nombre de dames à placer
//
// OUTPUT : 
//    1 si nbDames peuvent être placées dans l'échiquier
//    0 sinon.
//*********************************************************
int dames(int echiquier[TAILLE][TAILLE], int nbDames){
    if (nbDames == 0)
    {
//      return 1;
      printEchiquier(echiquier);
      CONTPOSSILITE++;
      printf("%d\n",CONTPOSSILITE);
    }


    int i = TAILLE - nbDames;
//  for(i = 0; i< TAILLE; i++)
//  {
    for(int j = 0; j < TAILLE; j++)
    {
      if (libre(echiquier, i, j)){
        echiquier[i][j] = 1; // met damme
        if (dames(echiquier,nbDames - 1))
            return 1;
        echiquier[i][j] = 0;
        
      }
    }
// }
  return 0;
}

 
//*********************************************************
// Chemin
//*********************************************************
int chemin ( int labyrinthe [TAILLELABYRINTHE][TAILLELABYRINTHE], int x, int y){
    
    labyrinthe [x][y] = 2;
    
    if ( y == ( TAILLELABYRINTHE - 1 )  &&  x == ( TAILLELABYRINTHE - 1 ) )
    {
        printlab(labyrinthe);
        return 1;
    };

    if (  y + 1 < TAILLELABYRINTHE )  
      if ( labyrinthe[x][y+1]  == 0 ) // droit
        if ( chemin(labyrinthe, x, y+1) == 1)
          return 1;
    if (  x + 1 < TAILLELABYRINTHE  ) //
      if ( labyrinthe[x+1][y] == 0 )
        if ( chemin ( labyrinthe, x+1 , y ) == 1 )
          return 1;
    if (y-1 >= 0 ) // gauche
      if ( labyrinthe[x][y-1] == 0 )
        if ( chemin ( labyrinthe, x , y-1 ) == 1 )
            return 1;
    if (x-1 >= 0 )
      if ( labyrinthe[x-1][y] == 0 ) // acima
        if ( chemin ( labyrinthe, x-1 , y ) == 1 )
            return 1;

    labyrinthe[x][y] = 0;
    return 0;

}


//*********************************************************
// Pilote pour le problème des dames.
//*********************************************************
int main()
{
/*  
  int echiquier[TAILLE][TAILLE];
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE; j++)
      echiquier[i][j] = 0;
  dames(echiquier, TAILLE);  
//  printEchiquier(echiquier);  
*/
// RETOUR SOUSTRACE

//int lab[TAILLELABYRINTHE][TAILLELABYRINTHE] = { {0,1,0,0,0},
//                  {0,0,0,1,0},
//                  {0,1,0,1,0},
//                  {0,1,0,0,0},
//                  {0,0,0,1,0}};

// int c = libre(lab, 0, 0);
// printf("C:%d", c);

int lab[TAILLELABYRINTHE][TAILLELABYRINTHE] = 
                { {0,0,1,0,0,0,0,0},
                  {0,1,1,0,1,1,1,0},
                  {0,0,0,0,1,0,0,0},
                  {0,1,1,0,1,0,1,0},
                  {1,1,1,0,1,0,1,1},
                  {0,0,0,0,1,0,1,0},
                  {1,1,1,0,1,0,1,0},
                  {1,0,0,0,1,0,0,0} };


chemin( lab, 0, 0 );

}


