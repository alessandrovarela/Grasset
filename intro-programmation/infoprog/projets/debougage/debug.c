#include <stdio.h>
#include <stdlib.h>
int main() {
   int y;
   float x = 100;
   y = 45;
   x = 45.5;
   
   x = 45.5;
   y = 10;
   
   
   x = y = 22;

   // Pour lire un entire

   int entree1;
   int entree2;
   int entree3;


   printf("Entrez avec nombre 1\n");
   scanf("%d", &entree1);
   
   printf("Entrez avec nombre 2\n");
   scanf("%d", &entree2);

   printf("Entrez avec nombre 3\n");
   scanf("%d", &entree3);


   printf("Result somme\n");
   printf("%d\n" , entree1 + entree2 + entree3 );

   printf("Result Soustracion\n");
   printf("%d\n" , entree1 - entree2 - entree3 );

   printf("Result Multiplicacion\n");
   printf("%d\n" , entree1 * entree2 * entree3 );


}
 