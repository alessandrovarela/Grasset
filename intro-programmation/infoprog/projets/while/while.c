

#include <stdio.h>
#include <stdlib.h>

int main()
{


	int compteur = 0;
	int compteur2 = 0;
	while (compteur < 10)
	{
 	    compteur2 = compteur;
	    
	    	while(compteur2 >= 0)
	 		{
				printf("%d ", compteur2);
				compteur2--;
			}
		compteur++;
		printf("\n");
	}
	

}