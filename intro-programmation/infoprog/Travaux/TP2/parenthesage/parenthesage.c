// ************************************************************************************************
// Fonction : estBienParenthesee
// Auteur   : Alessandro Varela
// Date     : 30 septembre 2018
//
// Cette fonction reçoit une chaîne de caractères et retourne
// vrai si la hiérarchie des ouvertures et des fermetures des parenthèses, des 
// crochets et des accolades est correcte et faux sinon.
// INPUT :
//     char expression[] : Tableau avec la chaîne à valider
//
// OUTPUT :
//     int: Vrai se chaîne de caractères est correte, Faux sinon.
//
// Les caractères autres que les parenthèses, des crochets et des accolades sont
// ignorés par la fonction.
//
// NB: Le nombre maximum d'ouvertures sans fermetures est de 200 caractères.
// Pour valider plus grandes, vous devez augmenter la constante TAILLETABLEUVALID
// *************************************************************************************************

#include <stdio.h>
#include <stdlib.h>

int estBienParenthesee(char expression[])
{

	// Créer une deuzième tableau pour valider l'expression
	const int TAILLETABLEUVALID = 200;
	char cValidExpression[TAILLETABLEUVALID];
	int  iPositionValidExpression = 0;

	for (int i = 0; expression[i] != '\0'; ++i)
	{
		if ( (     expression[i] == '{' || expression[i] == '}' 
				|| expression[i] == '[' || expression[i] == ']'
				|| expression[i] == '(' || expression[i] == ')' ) )
		{  
			switch (expression[i])
			{
					// Vérifier les correspondances dans la position précédente dans le tableau de validation.
					// S'il trouve, prend la valeur de la position précédente et annule la dernière ouverture
					case '}':
						if ( cValidExpression[iPositionValidExpression-1] != '{' )
						{	return 0; }
						else 
						{	iPositionValidExpression--; }
						break;
					case ']':
						if ( cValidExpression[iPositionValidExpression-1] != '[' )
						{	return 0; }
						else 
						{    iPositionValidExpression--; }
						break;
					case ')':
						if ( cValidExpression[iPositionValidExpression-1] != '(' )
						{	return 0; }
						else 
						{    iPositionValidExpression--; }
						break;

					default:
					    // Insérer une nouvelle ouverture
						cValidExpression[iPositionValidExpression++] = expression[i];

			}
		}
	}
	// Si n'avez pas trouvé aucun ()[]{} 
	// ou si arrivé à la fin mais n'a pas ferme toutes les correspondances retourne 0
	if ( iPositionValidExpression != 0 )
		return 0;
	else   
		return 1;

}
// *****************************************************************************
// main
//
// Exemples d'utilisation de la fonction estBienParenthesee
//
// *****************************************************************************
int main()
{
	char cExemple1[]="((golf) (hotel, juliette)) kilo ( lima, mike)";
    
    printf("Exemple 01 - chaîne de caractères: %s\n", cExemple1 );
	printf("Retourne estBienParenthesee: %d\n\n\n", estBienParenthesee(cExemple1));

   	char cExemple2[] = "{([ [ {teste1} {teste2}] entre crochetes])}";   
    printf("Exemple 02 - chaîne de caractères: %s\n", cExemple2 );
	printf("Retourne estBienParenthesee: %d\n\n\n", estBienParenthesee(cExemple2));

   	char cExemple3[] = "echo foxtrot";   
    printf("Exemple 03 - chaîne de caractères: %s\n", cExemple3 );
	printf("Retourne estBienParenthesee: %d\n\n\n", estBienParenthesee(cExemple3));
		
}