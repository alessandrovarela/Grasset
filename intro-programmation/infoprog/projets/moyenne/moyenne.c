#include <stdio.h>
#include <stdlib.h>
int main() {

   double num1;
   double num2;
   double num3;
   double num4;

   double dMoyenne;
   


   printf("Entrez avec numero 1\n");
   scanf("%lf", &num1);
    
   printf("Entrez avec numero 2\n");
   scanf("%lf", &num2);

   printf("Entrez avec numero 3\n");
   scanf("%lf", &num3);

   printf("Entrez avec numero 4\n");
   scanf("%lf", &num4);


   dMoyenne = ( num1 + num2 + num3 + num4 ) / 4;


  printf("Moyenne\n");
  printf("%lf\n", dMoyenne );
 

}