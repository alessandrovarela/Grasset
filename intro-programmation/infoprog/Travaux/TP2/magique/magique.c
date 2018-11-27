// ************************************************************************************************
// Fonction : vraimentMagique
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction considère recevoir un carré presque magique et tester uniquement les 
// fonctionnalités supplémentaires pour qu'un carré soit considéré comme vraiment magique.
// Un carré est vraiment magique quand chaque nombre de 1 a n2 (puissance 2) doit apparaître une 
// et une seule fois dans la matrice.
// Si des fonctionnalités supplémentaires sont trouvées retourne vrai, Faux sinon.
//
// INPUT :
//     const int nbRanges              : Nombre de rangées dans le carré.
//     const int nbColones             : Nombre de colonnes dans le carré.
//     int matrice[nbRanges][nbColones]: Matrice du carré [lignes] [colonnes]
//
// OUTPUT :
//     int: Si des fonctionnalités supplémentaires sont trouvées retourne vrai, Faux sinon.
//
// *************************************************************************************************

#include <stdio.h>
#include <stdlib.h>
int vraimentMagique ( const int nbRanges, const int nbColones,  int matrice[nbRanges][nbColones] )
{
    
    int const MAXIMUM = ( nbRanges * nbRanges ) ;
    int iSequence;

    for ( int x = 1; x <= MAXIMUM; ++x )
    {
        iSequence = 0;
        for ( int i = 0; i < nbRanges; ++i)
        {
            for ( int j = 0; j < nbColones; ++j)
            {
                if ( (matrice[i][j] == 0) || (matrice[i][j] > MAXIMUM) )
                {
                    return 0;                    
                }
                else if (matrice[i][j] == x )
                    iSequence = 1;
            }
        }
        if (iSequence == 0)
            return 0;
    }

    return 1;
}
// ************************************************************************************************
// Fonction : estPresqueMagique
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction recevoir la matrice d'un carré et valide si ce n'est pas de magique,
// si c'est presque magique ou si c'est vraiment magique.
//
// INPUT :
//     const int nbRanges              : Nombre de rangées dans le carré.
//     const int nbColones             : Nombre de colonnes dans le carré.
//     int matrice[nbRanges][nbColones]: Matrice du carré [lignes] [colonnes]
//
// OUTPUT :
//     int: Faux sinon magique, 1 si c'est presque magique et 2 si c'est vraiment magique.
//
// *************************************************************************************************
int estPresqueMagique(const int R, const int C, int matrice[R][C])
{ 
    int iMagique             = 0;
    int iSommeCollone        = 0;
    int iSommeLigne          = 0;
    int iSommeDiag1          = 0;
    int iSommeDiag2          = 0;

    enum ResMagique { PAS_MAGIQUE, PRESQUE_MAGIQUE, VRAIMENT_MAGIQUE};
    
    for (int i = 0; i < R; ++i)
    {
        iSommeLigne   = 0;
        iSommeCollone = 0;
        for (int j = 0; j < C; ++j)
        {
            iSommeLigne   += matrice[i][j];
            iSommeCollone += matrice[j][i];
            
            if ( i == j )
            {
                iSommeDiag1 += matrice[i][j];
            }

            if ( ( i + j ) == (R - 1) )
            {
                iSommeDiag2 += matrice[i][j];
            }

        }
        
        if ( i == 0 )         
           // Définit le nombre magique 
           iMagique = iSommeLigne;

        if ( (iSommeLigne != iMagique) || (iSommeCollone != iMagique))
        {
           return PAS_MAGIQUE;
        }
    }

    if ( (iSommeDiag1 != iMagique ) || (iSommeDiag2 != iMagique) )
    {
        return PAS_MAGIQUE;     
    }
    
    if ( vraimentMagique(R, C,matrice) )
       return VRAIMENT_MAGIQUE;
    else 
       return PRESQUE_MAGIQUE;
}

// ************************************************************************************************
// Fonction : estPresqueMagique
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction recevoir la matrice e imprime.
//
// INPUT :
//     const int nbRanges              : Nombre de rangées 
//     const int nbColones             : Nombre de colonnes 
//     int matrice[nbRanges][nbColones]: Matrice [lignes] [colonnes]
//
// OUTPUT :
//     rien
//
// *************************************************************************************************
 void imprimematrix ( const int nbRanges, const int nbColones,  int matrice[nbRanges][nbColones]  )
{
    for (int i = 0; i < nbRanges; ++i)
    {
    	for (int j = 0; j < nbColones; ++j)
    	{
    		printf(" %d", matrice[i][j] );
    	}
   		printf("\n");
    }
}
// *****************************************************************************
// main
//
// Exemples d'utilisation de la fonction estPresqueMagique
//
// *****************************************************************************
int main()
{

    //  Vraiment Magique
    int carreVraimentMagique[3][3] = {{2,7,6},{9,5,1},{4,3,8}};

    //  Presque Magique        
    int carrePresqueMagique[3][3] = {{9,17,10},{13,12,11},{14,7,15}};
    
    //  Ne Pas Magique        
    int carrePasMagique[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
    imprimematrix (3,3,carreVraimentMagique );

    switch ( estPresqueMagique(3, 3, carreVraimentMagique))
    {
        case 0:
            printf("La matrice n'est pas Magique.\n");
            break;
        case 1:
            printf("La matrice est Presque Magique.\n");
            break;
        default:
            printf("La matrice est Vraiment Magique.\n");
            break;
    } 

    imprimematrix (3,3,carrePresqueMagique );

    switch ( estPresqueMagique(3, 3, carrePresqueMagique))
    {
        case 0:
            printf("La matrice n'est pas Magique.\n");
            break;
        case 1:
            printf("La matrice est Presque Magique.\n");
            break;
        default:
            printf("La matrice est Vraiment Magique.\n");
            break;
    } 

    imprimematrix (3,3,carrePasMagique );

    switch ( estPresqueMagique(3, 3, carrePasMagique))
    {
        case 0:
            printf("La matrice n'est pas Magique.\n");
            break;
        case 1:
            printf("La matrice est Presque Magique.\n");
            break;
        default:
            printf("La matrice est Vraiment Magique.\n");
            break;
    } 
    
}
