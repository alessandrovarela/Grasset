// *****************************************************************************
// Nom : fractions.c
// Auteur : Rébecca
// Date : 25 septembre 2018
//
// Squelette de programme qui va évaluer des équations fractionnelles
// à un opérateur.
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

// ****************************************************************************
// Une fraction a un numérateur et un dénominateur entier.
// ****************************************************************************
typedef struct Fraction Fraction;
struct Fraction
{
    int num;
    int den;
};

// *****************************************************************************
//
// soustraction
//
// Calcule la soustraction entre deux fractions.
//
// INPUT
//     a : La première fraction opérande
//     b : La deuxième fraction opérande
//
// OUTPUT
//     La fraction résultat de a - b en sa plus simple expression
//
// *****************************************************************************
Fraction soustraction(Fraction a, Fraction b)
{
    Fraction resultat = {1, 2};
    return resultat;
}

// *****************************************************************************
//
// multiplication
//
// Calcule le produit entre deux fractions.
//
// INPUT
//     a : La première fraction opérande
//     b : La deuxième fraction opérande
//
// OUTPUT
//     La fraction résultat de a * b en sa plus simple expression
//
// *****************************************************************************
Fraction multiplication(Fraction a, Fraction b)
{
    Fraction resultat = {1, 2};
    return resultat;
}

// *****************************************************************************
//
// division
//
// Calcule le quotient entre deux fractions.
//
// INPUT
//     a : La première fraction opérande
//     b : La deuxième fraction opérande
//
// OUTPUT
//     La fraction résultat de a / b en sa plus simple expression
//
// *****************************************************************************
Fraction division(Fraction a, Fraction b)
{
    Fraction resultat = {1, 2};
    return resultat;
}

// *****************************************************************************
//
// addition
//
// Calcule la somme entre deux fractions.
//
// INPUT
//     a : La première fraction opérande
//     b : La deuxième fraction opérande
//
// OUTPUT
//     La fraction résultat de a + b en sa plus simple expression
//
// *****************************************************************************
Fraction addition(Fraction a, Fraction b)
{
    Fraction resultat = {1, 2};
    return resultat;
}

// *****************************************************************************
//
// main
//
// Fonction pilote qui demande une fraction, un opérateur et une fraction à
// l'usager et affiche le résultat du calcul fractionnel.
//
// *****************************************************************************
int main()
{
    Fraction a = {1, 2};
    Fraction b = {1, 2};
    char op;
    
    printf("Entrez deux fractions séparées par un opérateur (+, -, * ou /).\n");
    scanf("%d/%d %c %d/%d", &a.num, &a.den, &op, &b.num, &b.den);

    // Faire le calcul
    return 0;
}
