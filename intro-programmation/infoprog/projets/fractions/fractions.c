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
    
    Fraction resultat = {( a.num * b.den ) - ( b.num * a.den ), ( a.den * b.den)};

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
    Fraction resultat = { a.num * b.num , a.den * b.den};

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
    Fraction resultat = { a.num * b.den , a.den * b.num  };
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
    Fraction resultat = {a.num * b.den + b.num * a.den , a.den * b.den };
    return resultat;
}

int pgcd( int iNuma , int iNumb )
{
    int iInicial;

    if ( iNuma >= iNumb )
        iInicial = iNuma;
    else
        iInicial = iNumb;


    for (int i = iInicial; i >= 1 ; --i)
    {
        if ((iNuma%i == 0) && (iNumb%i == 0))            
            return i;
    }
    return 0;
}


Fraction reduire(Fraction a)
{
    int nPgcd = pgcd( a.num , a.den);

    Fraction resultat = { a.num/nPgcd , a.den/nPgcd };

    return  resultat;
}

float decimal(Fraction a)
{   
    if ( a.num == 0 )
        return 0;
    else if ( a.den == 0 ) 
        return 1;
    else 
        return (a.num * 1.0 ) / a.den;
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


    if ( op == '-' )
    {            
        // soustraction
        Fraction rSoustraction = soustraction(a,b);
        Fraction rReduire = reduire( rSoustraction );

        printf("Soustraction:%d/%d\n", rReduire.num, rReduire.den);
    }
    else if ( op == '*' )
    {            
        // multiplication
        Fraction rMultiplication = multiplication(a,b); 
        printf("Multiplication:%d/%d\n", rMultiplication.num, rMultiplication.den);

    }
    else if ( op == '/' )
    {            
        // division
        Fraction rDivision = division(a,b); 
        printf("Division:%d/%d\n", rDivision.num, rDivision.den);

    }

    else if ( op == '+' )
    {            
        // Addition
        Fraction rAddition = addition(a,b); 
        printf("Addition:%d/%d\n", rAddition.num, rAddition.den);

    }


    // Faire le calcul
    return 0;
}