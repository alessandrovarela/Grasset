// *****************************************************************************
// Nom : geometrie.c
// Auteur : Rébecca
// Date : 24 septembre 2018
//
// Exercice sur les structures : Le Point.
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

// ****************************************************************************
// En deux dimensions, Un point a une coordonée sur l'axe des x et une
// coordonnée sur l'axe des y.
// ****************************************************************************
typedef struct Point Point;
struct Point{
    double x;
    double y;
};

// ****************************************************************************
// Un cercle a un centre et un rayon
// ****************************************************************************
typedef struct Cercle Cercle;
struct Cercle{
    Point centre;
    double rayon;
};

// *****************************************************************************
//
// symetrieX
//
// Calcule le résultat d'une symétrie par rapport à l'axe des x sur un point
//
// INPUT
//     p : les coordonées d'un point dans le plan.
//
// OUTPUT
//     Les coordonées du point après symétrie par rapport à l'axe des x.
//
// ****************************************************************************
Point symetrieX(Point p)
{
    Point sym = {p.x, -p.y + 0.0};
    return sym;
}

// *****************************************************************************
//
// translation
//
// Calcule le résultat d'une translation sur un point.
//
// INPUT
//     p : les coordonées d'un point dans le plan.
//     translation : la description d'une translation
//
// OUTPUT
//     Les coordonées du point après translation.
//
// ****************************************************************************
Point translation(Point p, Point translation)
{
    Point t;
    t.x = p.x + translation.x;
    t.y = p.y + translation.y;
    return t;
}

// *****************************************************************************
//
// dedans
//
// Détermine si un point est dans un cercle
//
// INPUT
//     p : les coordonées d'un point dans le plan.
//     c : la description d'un cercle dans le plan
//
// OUTPUT
//     1 si p se situe dans le cercle, 0 sinon.
//
// ****************************************************************************

int dedans(Point p, Cercle c)
{
    return ((p.x - c.centre.x) * (p.x - c.centre.x) +
            (p.y - c.centre.x) * (p.x - c.centre.y) <=
            c.rayon * c.rayon);
}


// *****************************************************************************
//
// valeurOuReference
//
// Fonction qui modifie une instance de Point reçue en paramètre. Si la valeur
// de l'argument a changé avant et après l'appel alors les instances de
// structures sont passées par références, sinon, elles sont passées par valeur.
//
// INPUT
//     p : les coordonées d'un point dans le plan.
//
// OUTPUT
//     Rien
//
// ****************************************************************************
void valeurOuReference(Point p)
{
    p.x = 0;
    p.y = 0;
}

// *****************************************************************************
//
// main
//
// Pilote pour l'exercice de géométrie. Elle demande un point à l'usager, une
// translation et la description d'un cercle, puis applique la symétrie par
// rapport à la droite y=0, la translation demandée, puis dit à l'utilisateur si
// le point est dans le cercle décrit ou non.
//
// *****************************************************************************
int main()
{
    Point p;
    printf("Entrez les coordonnées d'un point. (x,y) : ");
    scanf("%lf,%lf", &p.x, &p.y);

    Point t;
    printf("Entrez une translation. (x,y) : ");
    scanf("%lf,%lf", &t.x, &t.y);

    Cercle c;
    printf("Entrez un point centre et un rayon. (x,y,r) : ");
    scanf("%lf,%lf,%lf", &c.centre.x, &c.centre.y, &c.rayon);
   
    Point sym = symetrieX(p);
    printf("\n(%.1lf, %.1lf) devient (%.1lf, %.1lf) après une "
        "symétrie par rapport à l'axe des X.\n\n",
        p.x, p.y, sym.x, sym.y);

    Point trans = translation(p, t);
    printf("(%.1lf, %.1lf) devient (%.1lf, %.1lf) après une "
        "translation de (%.1lf, %.1lf).\n\n",
        p.x, p.y, trans.x, trans.y, t.x, t.y);

    if (dedans(p, c))
        printf("Le point (%.1lf, %.1lf) est dans le cercle"
        " de centre (%.1lf, %.1lf) et de rayon %.1lf.\n\n",
        p.x, p.y, c.centre.x, c.centre.y, c.rayon);
    else
        printf("Le point (%.1lf, %.1lf) n'est pas dans le cercle"
        " de centre (%.1lf, %.1lf) et de rayon %.1lf.\n\n",
        p.x, p.y, c.centre.x, c.centre.y, c.rayon);

    // Avant l'appel à valeurOuReference
    Point test = {10,10};
    printf("Avant : test = (%.0lf,%.0lf)\n", test.x, test.y);
    valeurOuReference(test);
    
    // Après l'appel à valeurOuReference
    printf("Après : test = (%.0lf,%.0lf)\n\n", test.x, test.y);

    // Si test = (0,0) alors les instances sont passées par référence, comme les
    // tableaux.

    // Si test = (10, 10), alors elles sont passées par valeur, comme les
    // variables de type primitif (int, double, float, char).
}
