#include <stdio.h>
#include <stdlib.h>
int main() {

  printf("Quelle huere est-il?");
  
  int h = 0;
  
  scanf("%d", &h) ;


  if ( h > 6 )

  {
 	if ( h < 12 ) 
 	{	
 		printf("Frere Jacuqes\n");
 	}
 	else
 	{
 		if ( h < 20 )
 			printf("La laine des moutons\n");
 		else
 		    printf("Dodo l'enfant Do\n");
 	}

  }

  else

  { printf("Silence\n"); }
}