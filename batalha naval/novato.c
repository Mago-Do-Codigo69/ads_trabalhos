#include <stdio.h>

int main() {
    //dados do tabuleiro do jogo
int tabuleiro[10][10];
int i,j;
//definindo o tabuleiro
  for(i = 0; i < 10; i++){
  for(j = 0; j < 10; j++){
  tabuleiro[i][j] = 0;
  }
}
//tamanho dos navios
int tamanho_do_navio = 3;
// os navios do jogo
int navio_horizontal[3] = {3,3,3};
int navio_vertical[3] = {3,3,3};

//as cordenadas em que começam
int linha_horizontal = 2;
int linha_vertical = 5;
int coluna_horizontal = 4;
int coluna_vertical = 7;

  if (tamanho_do_navio + coluna_horizontal <= 10 && tamanho_do_navio + linha_vertical <= 10) {//aqui dira se eles cabem no tabuleiro ou não
    //posição do horizontal
    for( i = 0; i < tamanho_do_navio; i++){
    tabuleiro[linha_horizontal][coluna_horizontal = i] = navio_horizontal[i];
    }
    // posição do vertical, tambem diz se pode ou nao coloca-lo la
    for(i = 0; i < tamanho_do_navio; i++) {
    if (tabuleiro[linha_vertical + i][coluna_vertical] !=0) {
        printf(" não pode-se alocar um navio aqui\n");
        return 1;
    }
      tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
  }

}else{
    printf("aqui não pode companheiro\n");
    return 1;
}

  printf("Tabuleiro Batalha Naval:\n\n");
        for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
                  printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
} 
