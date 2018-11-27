// *****************************************************************************
// Nom : fractions.c
// Auteur : Rébecca
// Date : 25 septembre 2018
//
// Exercice sur les structures : Fractions.
//
// *****************************************************************************
#include <stdio.h>

// Les quatre opérateurs permis sont +, -, * et /
typedef enum Operateur Operateur;
enum Operateur {PLUS = '+', MOINS = '-', FOIS = '*', DIV = '/'};

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
// fractionToDecimal
//
// Calcule la valeur en décimale d'une fraction. Le dénominateur ne doit pas
// être nul.
//
// INPUT
//     f : une fraction
//
// OUTPUT
//     La valeur en décimale de la fraction. Erreur si le dénominateur est nul.
//
// *****************************************************************************
double fractionToDecimal(Fraction f)
{
    return (f.num * 1.0) / f.den;
}

// *****************************************************************************
//
// pgcd
//
// Trouve le plus grand commun diviseur entre deux entiers en utilisant
// l'algorithme d'Euclide.
//
// INPUT
//     a : un entier
//     b : un deuxième entier
//
// OUTPUT
//     Le pgcd entre a et b.
//
// *****************************************************************************
int pgcd(int a, int b)
{
    if (b == 0) 
        return a;
    return pgcd(b, a % b);
}

// *****************************************************************************
//
// reduire
//
// Réduit la fraction à la plus simple expression.
//
// INPUT
//     f : une fraction à réduire
//
// OUTPUT
//     La plus simple expression de la fraction. Si elle est négative, le signe
//     est sur le numérateur. Si le dénominateur est nul, f est retournée.
//
// *****************************************************************************
Fraction reduire(Fraction f)
{
    if (f.den == 0)
        return f;
 
    int divCommun = pgcd(f.num, f.den);
    f.num /= divCommun;
    f.den /= divCommun;

    // Si la fraction est négative, alors le signe va sur le numérateur
    if (f.den < 0)
    {
        f.den *= -1;
        f.num *= -1;
    }
    return f;
}

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
    Fraction r = {a.num * b.den - b.num * a.den, a.den * b.den};
    return reduire(r);
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
    Fraction r = {a.num * b.num, a.den * b.den};
    return reduire(r);
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
    Fraction r = {a.num * b.den, a.den * b.num};
    return reduire(r);
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
    Fraction r = {a.num * b.den + b.num * a.den, a.den * b.den};
    return reduire(r);
}

// *****************************************************************************
//
// validerOperateur
//
// Détermine si un caractère est une des opérations permises
//
// INPUT
//     o : L'opération à valider
//
// OUTPUT
//     1 si operateur est +, -, * ou /. 0 sinon.
//
// *****************************************************************************
int validerOperateur(char o)
{
    return ((o == PLUS) || (o == MOINS) || (o == FOIS) || (o == DIV));
}

// *****************************************************************************
//
// evaluer
//
// Applique l'operateur aux deux opérandes fractionnelles.
//
// INPUT
//     a : La première fraction opérande
//     o : l'opérateur à appliquer
//     b : La deuxième fraction opérande
//
// OUTPUT
//     La fraction résultat
//
// *****************************************************************************
Fraction evaluer(Fraction a, Operateur o, Fraction b)
{
    switch (o)
    {
        case PLUS  : return addition(a, b);
        case MOINS : return soustraction(a, b);
        case FOIS  : return multiplication(a, b);
        default    : return division(a, b);
    }
}

// *****************************************************************************
//
// main
//
// Fonction pilote qui demande une fraction, un opérateur et une fraction à
// l'usager et affiche le résultat fractionnel et décimal.
//
// *****************************************************************************
int main()
{
    Fraction a = {0, 1};
    Fraction b = {0, 1};
    char op;
   
    // Lecture de l'équation
    printf("Entrez deux fractions séparées par un opérateur (+, -, * ou /).\n");
    scanf("%d/%d %c %d/%d", &a.num, &a.den, &op, &b.num, &b.den);

    // Arrêter si on demande un opérateur inexistant ou un dénonimateur nul
    if ((!validerOperateur(op)) || (a.den == 0) || (b.den == 0))
         return -1;

    // Évaluation de l'équation
    Fraction resultat = evaluer(a, op, b);

    // Arrêter si division par 0
    if (resultat.den == 0)
        return -1;
   
    // Impression du résultat de l'équation en forme fractionnelle et décimale.
    printf("%d", resultat.num);
    if ((resultat.den != 1) && (resultat.num != 0))
        printf("/%d\n%lf", resultat.den, fractionToDecimal(resultat));
    printf("\n");
   
    return 0;
}
