#include <stdio.h>
#include <stdlib.h>
#define N 100

// Esta função devolve 1 se a string s contém uma
// sequência bem-formada de parênteses e colchetes
// e devolve 0 se a sequência é malformada.

int bemFormada (char s[]) {
   char pilha[N]; int t; 
   int i;

   t = 0;
   for (i = 0; s[i] != '\0'; ++i) {
      // pilha[0..t-1] é uma pilha de '(' e '['
      switch (s[i]) {
         case ')': if (t == 0) return 0;
                   if (pilha[--t] != '(') return 0; 
                   break;
         case ']': if (t == 0) return 0;
                   if (pilha[--t] != '[') return 0; 
                   break;
         default:  pilha[t++] = s[i];
      }
   }
   return t == 0;
}

int main()
{
    char par[]="(()[()])";
    int bem = bemFormada(par);
    printf("String:%d\n", bem);
    return 0;
}
