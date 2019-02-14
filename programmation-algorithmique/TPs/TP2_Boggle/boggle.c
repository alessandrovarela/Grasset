//*************************************************
// Nom du fichier: boggle.c
//
// Date: 12 decembre 2018
//
// Auteurs: Carolina Spaniol | Alessandro Varela
//
// Initialiser le jeu Boogle
//*************************************************

#include "boggle.h"
#include "dictionnaire.h"

int nbCase() {	
	return rand() % MAXCOL + MINCOL;
}

int nbCaseGrille() {	
	return rand() % MAXGRILLE + MINGRILLE;
}

char lancerLesDes(int nbRangee) {
	return DES[nbRangee][nbCase()];
}

void imprimerGrille(char grille[RANGEES][COLONNES]) {
	for (int i = 0; i < RANGEES; i++)
	{
		for (int j = 0; j < COLONNES; j++)
		{
			printf("%c ", grille[i][j]);
		}
		printf("\n");
	}
}

int grilleComplete(char grille[RANGEES][COLONNES]) {
	for(int i = 0; i < RANGEES; i++)
	{
		for(int j = 0; j < COLONNES; j++) {
			if (grille[i][j] == 0)
				return 0;
		}	
	}	
	return 1;
}					

void remplirGrille(char grille[RANGEES][COLONNES]) {
	while (!grilleComplete(grille))
	{	
		for(int i = 0; i < (RANGEES * COLONNES); i++) {
			int iGrille = nbCaseGrille();
	    	int jGrille = nbCaseGrille();

			if (grille[iGrille][jGrille] == 0)
				grille[iGrille][jGrille] = lancerLesDes(i);
		}
	}
}

void reinitialiserVisite(char visite[RANGEES][COLONNES]) {
	for(int i = 0; i < RANGEES; i++)
	{	
		for(int j = 0; j < COLONNES; j++) {
			visite[i][j] = 0;
		}		
	}
}
int formerMot(char grille[RANGEES][COLONNES],char visite[RANGEES][COLONNES],char mot[], int r , int c) {
    if (strlen(mot) == 0) 
		return 1;

	if (grille[r][c] != mot[0])
		return 0;
	//case à droite
	if (c + 1 < COLONNES) {
		if (visite[r][c+1] == 0) {	
			visite[r][c+1] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r, c+1))
				return 1;
			else
				visite[r][c+1] = 0;
		}
 	}
	//case ci-dessous
	if (r + 1 < RANGEES) {
		if (visite[r+1][c] == 0) {	
			visite[r+1][c] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r+1, c))
				return 1;
			else
				visite[r+1][c] = 0;
		}
	}
	//case à gauche
	if (c-1 >= MINGRILLE) {
		if (visite[r][c-1] == 0) {	
			visite[r][c-1] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r, c-1))
				return 1;
			else
				visite[r][c-1] = 0;
		}
	}
    // case au-dessus
	if (r-1 >= MINGRILLE) {
		if (visite[r-1][c] == 0) {	
			visite[r-1][c] = 1; // marque comme visité
			if (formerMot(grille, visite,mot+1,r-1,c))
				return 1;
			else
				visite[r-1][c] = 0;
		}
	}
	// diagonale à gauche (au-dessus)
	if (r-1 >= MINGRILLE && c-1 >= MINGRILLE) {
		if (visite[r-1][c-1] == 0) {	
			visite[r-1][c-1] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r-1, c-1))
				return 1;
			else
				visite[r-1][c-1] = 0;
		}		
	}
	// diagonale à gauche (ci-dessous)
	if (r+1 < RANGEES && c-1 >= MINGRILLE) {
		if (visite[r+1][c-1] == 0) {	
			visite[r+1][c-1] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r+1, c-1))
				return 1;
			else
				visite[r+1][c-1] = 0;
		}
	}
	// diagonale à droite (au-dessus)
	if (r-1 >= MINGRILLE && c+1 < COLONNES) {
		if (visite[r-1][c+1] == 0) {	
			visite[r-1][c+1] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r-1, c+1))
				return 1;
			else
				visite[r-1][c+1] = 0;
		}
	}
	// diagonale à droite (ci-dessous)
	if (r+1 < RANGEES && c+1 < COLONNES) {
		if (visite[r+1][c+1] == 0) {	
			visite[r+1][c+1] = 1; // marque comme visité
			if (formerMot(grille, visite, mot+1, r+1, c+1))
				return 1;
			else
				visite[r+1][c+1] = 0;
		}
	}	
	return 0;
}

int motDansGrille(char grille[RANGEES][COLONNES], char visite[RANGEES][COLONNES], char mot[]) {
	reinitialiserVisite(visite);

	for(int i = 0; i < RANGEES; i++) {
		for(int j = 0; j < COLONNES; j++) {
			visite[i][j] = 1;
			if (formerMot(grille, visite, mot, i, j))
				return 1;
			visite[i][j] = 0;
		}		
	}
	return 0;
}

void imprimerMotPossible(char grille[RANGEES][COLONNES], char visite[RANGEES][COLONNES], char** dictionnaire, int tailleDict) {
	char mot[BUFF];
	int plusLongMot = 0;
	int indexMot = 0;

	printf("Les mots possible dans la grille sont:\n");
	for (int i = 0; i < tailleDict; i++) {	
		if (motDansGrille(grille, visite, strcpy(mot, dictionnaire[i]))) {
		   printf("%s ", dictionnaire[i]);
		   if (strlen(mot) > plusLongMot) {
				plusLongMot = strlen(mot);
				indexMot = i;
		   }
		}
	}
	printf("\n\nPlus long Mot dans La Grille:%s\n", dictionnaire[indexMot]);
}

void libererMemoire(char** matrice, int tailleMatrice) {
	for (int i = 0; i < tailleMatrice; i++) {
		free( matrice[i] );
	}	
	free(matrice);
}

char** creerTabStocker() {
	char** stocker = (char**)malloc(BUFF * sizeof(char*));
	return stocker;
}

void augmenterStocker(char** stocker, int taille) {
		stocker = realloc(stocker, taille * sizeof(char*));
}

void ajouterMotStocker(char** stocker, int indexStocker, char mot[]) {
	int l = strlen(mot);
	stocker[indexStocker] = (char*)malloc(l * sizeof(char)); 
	stocker[indexStocker] = strcpy(stocker[indexStocker], mot);		
}

int calculerScore(char mot[]) {
	if (strlen(mot) > 3)
		return (strlen(mot) - 2);
	return 0;
}

int validerDuplicite(char** stocker, int tailleStocker, char mot[]) {
	for(int i = 0; i < tailleStocker ; i++)	{
		if (strcmp(mot, stocker[i]) == 0)
                return 1;
	}
	return 0;
}

void imprimerStocker(char** stocker,int tailleStocker) {
	for(int i = 0; i < tailleStocker; i++)
		printf("%s ", stocker[i]);	
}

void imprimerMeilleurMotJouer(char** stocker,int tailleStocker) {
	int plusLongMot = 0;
	int indexMot = 0;

	for (int i = 0; i < tailleStocker; i++) {	
		if (strlen(stocker[i]) > plusLongMot) {
			plusLongMot = strlen(stocker[i]);
			indexMot = i;
		}
	}
	printf("Plus long Mot Jouer:%s\n\n", stocker[indexMot]);
}

void imprimerInstrutions() {
	printf("********************* BOGGLE *********************\n");
	printf("ENTREZ LES MOTS EN FRANÇAIS EN UTILISANT MAJUSCULE\n");
	printf("LES CARACTÈRES SPÉCIAUX NE PEUVENT PAS ÊTRE UTILISÉS\n");
	printf("ENTREZ (QUIT) POUR SORTIR LE JEU\n");
	printf("****************************************************\n\n");
}

int main()
{
    system("clear");
    srand(time(0));
	int compteDict = 0;
	int* pCompteDic = &compteDict; // compte les mots du dictionnaire

	char grille [RANGEES][COLONNES] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}; //initialisation de la grille du jeu
	char visite [RANGEES][COLONNES] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}; //initialisation de la grille visité
	
	imprimerInstrutions();
	remplirGrille(grille);
	imprimerGrille(grille);
	
	char** dictionnaire = chargeDictionnaire(&compteDict);
	char** stocker = creerTabStocker();
	char mot[BUFF];
	int tailleStocker = BUFF;
	int compteRangeesStock = 0;
	int totalMotValid = 0;
	int totalScore = 0;

 	while (strcmp(mot, "QUIT") != 0) {
		scanf("\n%s", mot);
		if (! validerDuplicite(stocker, totalMotValid, mot)) {
			if (trouverMotDict (mot, dictionnaire, compteDict)) {
				if (motDansGrille(grille,visite,mot)) {
					compteRangeesStock++;
					if (compteRangeesStock >= BUFF) {
						tailleStocker += tailleStocker;
						augmenterStocker (stocker, tailleStocker);
						compteRangeesStock = 0;
					}
					ajouterMotStocker(stocker,totalMotValid, mot);
					totalScore += calculerScore(mot);
					totalMotValid++;
				}
			}
		}
		system("clear");
		imprimerInstrutions();
		imprimerGrille(grille);
		printf("\nVous avez trouvé %d mots. (%d pts)\n", totalMotValid , totalScore);
		imprimerStocker(stocker,totalMotValid);
	}
	printf("\n\n");
	imprimerMotPossible(grille, visite, dictionnaire, compteDict);
	imprimerMeilleurMotJouer(stocker,totalMotValid);
	libererMemoire(dictionnaire, compteDict);
	libererMemoire(stocker, totalMotValid);
}

