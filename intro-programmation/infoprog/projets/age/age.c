#include <stdio.h>
#include <stdlib.h>
int main() {

   int iAge;
   int iAge5an;
   int iAnsApre;

   printf("Entrez votre Age\n");
   scanf("%d", &iAge);
    
   
   iAnsApre = iAge - 18;
   iAge5an  = iAge + 5;


   printf("Votre Age Dans 5 ans\n");
   printf("%d\n" , iAge5an );


   printf("Ans plus Majeur\n");
   printf("%d\n" , iAnsApre );


}