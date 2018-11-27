// ****************************************************************************
// Nom : surplus.c
// Auteur : Rébecca
// Date : 14 septembre 2018
//
// Solutionnaire aux exercices de surplus du 14 septembre 2018 minimum, mediane
// et intervale.
//
// Ma solution n'est pas la seule bonne solution.
//
// ****************************************************************************
#include <stdio.h>

// ****************************************************************************
// minimum
//
// Trouve le plus petit nombre parmi les paramètres
//
// INPUT :
//     int a : un nombre entier
//     int b : un nombre entier
//     int c : un nombre entier
//
// OUTPUT :
//     Le plus petit nombre parmi a, b et c.
//
// ****************************************************************************
int minimum(int a, int b, int c)
{ 
    if ((a <= b) && (a <= c))
    {   // a est plus petit ou égal à b et à c
	return a;
    }
    if ((b <= a) && (b <= c))
    {   // b est plus petit ou égal à a et à c
	return b;
    }
    // Si ni a, ni b sont le minimum, ça doit être c.
    return c;
}

// ****************************************************************************
// mediane
//
// Trouve la mediane parmi les paramètres.La médiane de trois nombre est le
// deuxième plus petit.
//
// INPUT :
//     int a : un nombre entier
//     int b : un nombre entier
//     int c : un nombre entier
//
// OUTPUT :
//     La mediane de a, b et c. 
//
// ****************************************************************************
int mediane(int a, int b, int c)
{
    if (((a <= b) && (b <= c)) || ((c <= b) && (b <= a)))
    {   // b est au milieu
        return b;
    }
    if (((a <= c) && (c <= b)) || ((b <= c) && (c <= a)))
    {   // c est au milieu
	return c;
    }
    // Si ni b, ni c sont au milieu, ça doit être a.
    return a;
}

// ****************************************************************************
// intervale
//
// Imprime tous les nombres entiers entre a et b inclusivement, séparés par des
// virgules.
//
// INPUT :
//     int a : le début de l'intervale
//     int b : la fin de l'intervale
//
// OUTPUT :
//     Rien. Imprime à la console.
//
// ****************************************************************************
void intervale(int a, int b)
{
    printf("%d", a);
    
    if (a > b)
    {   // Ordre décroissant
	for (int i = a - 1; i > b; i--)
	{
	    printf(", %d", i);
	}
    }
    else
    {   // Ordre croissant
	for (int i = a + 1; i < b; i++)
	{
	    printf(", %d", i);
	}
    }
    
    if (a != b)
    {   // s'il y a au moins 2 nombres, on met le mot "et" avant le dernier
        printf(" et %d", b);
    }
    printf(".\n");
}

// ****************************************************************************
// main
//
// Demande trois nombres entiers à l'usager et affiche le minimum et la médiane
// Puis il affiche tous les nombres entre les deux premiers.
//
// INPUT :
//     Rien. Lit à la console
//
// OUTPUT :
//     Rien. Imprime à la console.
//
// ****************************************************************************
int main()
{
    int a, b, c; 
    printf("Entrez 3 nombres entiers séparés par un espace\n");
    scanf("%d %d %d", &a, &b, &c);

    int min = minimum(a, b, c);
    int med = mediane(a, b, c);
    
    printf("Le plus petit nombre entre %d, %d et %d est %d\n", a, b, c, min);
    printf("La médiane entre %d, %d et %d est %d\n", a, b, c, med);
    printf("Les nombres entre %d et %d sont : ", a, b);
    intervale(a, b);
}
