#include <stdio.h>
#include <stdlib.h>
int main() {

   int iEntreeSeconds;
   int iHeures;
   int iMinutes;
   int iSec;


   printf("Entrez nombre secondes\n");
   scanf("%d", &iEntreeSeconds);
    
   iHeures  = iEntreeSeconds / 3600;
   iMinutes = iEntreeSeconds % 60;
   iSec = iMinutes % 3600;


   printf("%dh", iHeures );
   printf("%dm"  , iMinutes );
   printf("%ds\n"  , iSec );


}