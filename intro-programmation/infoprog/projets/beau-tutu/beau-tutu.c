#include <stdio.h>
#include <stdlib.h>


int main()
{

	char phrase [] = {'B', 'A', 'T', 'E', 'A', 'U', ' ', 'N', 'O', 'I', 'R'};
	/* code */
	printf("%c" , phrase[5]); // U
	printf("%c" , phrase[7]); // N
	printf("%c" , phrase[6]); // space
	printf("%c" , phrase[0]); // B
	printf("%c" , phrase[3]); // E
	printf("%c" , phrase[1]); // A
	printf("%c" , phrase[5]); // U
	printf("%c" , phrase[6]); // space
	printf("%c" , phrase[2]); // T
	printf("%c" , phrase[5]); // U
	printf("%c" , phrase[2]); // T
	printf("%c\n" , phrase[5]); // U

    char cMonNom[] = "Alessandro";
    printf("%c" , cMonNom[0]); // A
 
    printf("\n"); // U


    int iEnfan[12];

    iEnfan[0] = 2;
    iEnfan[1] = 0;
    iEnfan[2] = 0;
    iEnfan[3] = 0;
    iEnfan[4] = 1;
    iEnfan[5] = 0;
    iEnfan[6] = 3;
    iEnfan[7] = 1;
    iEnfan[8] = 0;
    iEnfan[9] = 0;
    iEnfan[10] = 0;
    iEnfan[11] = 0;

    
    for (int i = 0; i < 12; ++i)
    {
    	printf("personne %d: %d enfants\n", i+1, iEnfan[i] );
    }


    // NOTES

    printf("NOTES\n\n");
    int notes [] = {90, 75, 81, 88, 69, 100};

    printf("Primeire for\n");
	for (int i = 0; i < 6; i++)
		printf("notes[%d] = %d\n", i, notes[ i]);

    

    printf("Duzieme for\n");
	for (int i = 5; i >= 0; i--)
	printf("notes[%d] = %d\n", i, notes[i]);
	
	printf("Troi for\n");
	for (int i = 1; i <= 6; i++)
	printf("notes[%d] = %d\n", i, notes[i]);



    // Total Enfants
	int iTotalEnfant = 0;
	int iTotalZero   = 0;
	int iMaximum     = 0;
	int iPersonePlus = 0;


	for (int i = 0; i < 12; i++)
    {
		 iTotalEnfant += iEnfan[i];
	 	 iTotalZero += ( iEnfan[i] == 0 );

		 if ( iEnfan[i] > iMaximum )
		 { 	
		 	iMaximum     = iEnfan[i];
		 	iPersonePlus = i+1;
		 }

	}

	printf("Total %d enfants\n", iTotalEnfant);
	printf("Total avezc 0  %d \n", iTotalZero);	
	printf("Maximum  %d \n", iMaximum);
	printf("personne Plus  %d \n", iPersonePlus);


 

}

