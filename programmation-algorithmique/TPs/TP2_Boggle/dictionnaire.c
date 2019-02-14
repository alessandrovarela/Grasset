#include "dictionnaire.h"

char** chargeDictionnaire(int* pCompteDic) {
   	int taille = BUFFRANGEESDIC;
	int compteBuffRangees = 0;
	
	char** dict = (char**)malloc(BUFFRANGEESDIC * sizeof(char*)); // cree le tableau où les tableaux de mots seront stockés

	FILE *file = fopen(FICHIERDIC, "r");
	
	if (file == NULL ) {
		perror("fopen");
		exit(1);
	}

	char mot[BUFF];
    
    while (fgets(mot, BUFF, file) != NULL) {
		int l = strlen(mot);
		mot[l - 1] = '\0';
		dict[*pCompteDic] = (char*)malloc(l * sizeof(char)); // cree le tableau où les mots du dictionnaire seront stockés
		dict[*pCompteDic] = strcpy(dict[*pCompteDic], mot); 		

		*pCompteDic+=1;
		compteBuffRangees++;

		if (compteBuffRangees >= BUFFRANGEESDIC) {
			taille += BUFFRANGEESDIC;
			dict = realloc(dict, taille * sizeof(char*));

			compteBuffRangees = 0;
		}
    }
    fclose(file);
    return dict;
}

int trouverMotDict(char mot[], char** dictionnaire, int tailleDict) {
	int gauche = 0;
    int droit = tailleDict - 1;

	while (gauche <= droit) {
    	int index = (droit + gauche) / 2;

		if (strcmp(mot, dictionnaire[index]) == 0)
                return 1;

		if (strcmp(dictionnaire[index],mot) > 0) 
            droit = index - 1;
		else
            gauche = index + 1;
	}
	return 0;
}
