#include <stdio.h>
 
//inicio do desafio(variaveis)
 int main(){

    char estado1[50], estado2[50];
    char codigo_da_carta1[40], codigo_da_carta2[40];
    char nome_da_cidade1[50], nome_da_cidade2[50];
    int população1, população2 ;
    float area1, area2;
    float pib1, pib2;
    float densidade_populacional1, densidade_populacional2;
    float pib_porcapita1, pib_porcapita2;
    int pontos_turisticos1, pontos_turisticos2;

     //inicio das definiçoes de valores
    printf("defina os valores das cartas\n");
    printf("CARTA 1\n");

    printf("estado:");
    scanf("%s", estado1);

    printf("codigo da carta:");
    scanf("%s", codigo_da_carta1);

    printf("cidade:");
    scanf("%s", nome_da_cidade1);

    printf("população da cidade:");
    scanf("%d", &população1);

    printf("área da cidade:");
    scanf("%f", &area1);

    printf("pib:");
    scanf("%f", &pib1);

    printf("pontos turisticos:");
    scanf("%d", &pontos_turisticos1);

    densidade_populacional1 = população1 / area1;
    pib_porcapita1 = pib1 / população1;

    printf("valores da carta 1 definidos\n\n");
    
    //definiçoes de valores da segunda carta
    printf("defina os valores da carta 2\n\n");

    printf("estado:");
    scanf("%s", estado2);

    printf("codigo da carta:");
    scanf("%s", codigo_da_carta2);

    printf("cidade:");
    scanf("%s", nome_da_cidade2);

    printf("população da cidade:");
    scanf("%d", &população2);

    printf("área da cidade:");
    scanf("%f", &area2);

    printf("pib:");
    scanf("%f", &pib2);

    printf("pontos turisticos:");
    scanf("%d", &pontos_turisticos2);

    densidade_populacional2 = população2 / area2;
    pib_porcapita2 = pib2 / população2;

    //exibindo o resultado do cadastro das cartas
    printf("\nvalores configurados\n");

    printf("carta 1\n");
    printf("estado: %s\n", estado1);
    printf("codigo da carta: %s\n", codigo_da_carta1);
    printf("nome da cidade: %s\n", nome_da_cidade1);
    printf("população: %d\n", população1);
    printf("área: %.2f\n", area1);
    printf("pib: %.2f\n", pib1);
    printf("pontos turisticos: %d\n", pontos_turisticos1);
    printf("densidade populacional: %.2f\n", densidade_populacional1);
    printf("pib por capita: %.2f\n", pib_porcapita1);

    printf("carta 2\n");
    printf("estado: %s\n", estado2);
    printf("codigo da carta: %s\n", codigo_da_carta2);
    printf("nome da cidade: %s\n", nome_da_cidade2);
    printf("população: %d\n", população2);
    printf("área: %.2f\n", area2);
    printf("pib: %.2f\n", pib2);
    printf("pontos turisticos: %d\n", pontos_turisticos2);
    printf("densidade populacional: %.2f\n", densidade_populacional2);
    printf("pib por capita: %.2f\n", pib_porcapita2);

  return 0;
 }
