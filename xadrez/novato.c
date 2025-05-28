#include <stdio.h>

 int main() {
 
// variaveis
 int torre = 5;
 int rainha = 8;
 int bispo = 5;


 //movimento da torre
 printf("movimento da torre\n");
 while (torre > 0)
 {
    printf("andou 1 casa a direita\n");
            torre--;  //impede a continuação infinita de direita
 }
   printf("a torre andou 5 casas a direita\n");

   //movimento da rainha
   printf("motimento da rainha\n");
      for(int i = 0; i < rainha; i++)
   {
      printf("andou 1 casa a esquerda\n");
   }
    printf("rainha andou 8 casas a esquerda\n");

  //movimento do bispo
   printf("movimento do bispo\n");
   do{
      printf("andou 1 casa a cima/esquerda\n");
            bispo--;   //impede a continuação infinita a cima/esquerda
   }
    while (bispo > 0);
    printf("bispo andou 8 casas a cima/esquerda\n");

    return 0;
}

