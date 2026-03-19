//bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura que representa cada cômodo da mansão.
// Cada sala é um nó da árvore binária.
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;


// Função criarSala
// Cria dinamicamente uma sala, copiando o nome recebido.
// Retorna um ponteiro para a nova sala.
Sala* criarSala(const char nome[]) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));

    if (nova == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;

    return nova;
}

// Função explorarMansao
// Permite ao jogador caminhar pela mansão 
// A navegação continua até o jogador sair manualmente ou chegar a um nó-folha
void explorarMansao(Sala *atual) {
    char opcao;

    while (atual != NULL) {

        printf("\nVocê está agora em: %s\n", atual->nome);
        printf("Escolha um caminho:\n");
        printf("[e] Ir para a esquerda\n");
        printf("[d] Ir para a direita\n");
        printf("[s] Sair da exploração\n> ");
        scanf(" %c", &opcao);

        switch (opcao) {

            case 'e':
                if (atual->esq != NULL) {
                    atual = atual->esq;
                } else {
                    printf("\nNão há caminho à esquerda!\n");
                    return;
                }
                break;

            case 'd':
                if (atual->dir != NULL) {
                    atual = atual->dir;
                } else {
                    printf("\nNão há caminho à direita!\n");
                    return;
                }
                break;

            case 's':
                printf("\nExploração encerrada pelo usuário.\n");
                return;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    printf("\nVocê chegou ao fim deste caminho! (Nó-folha)\n");
}


// Função principal main
// Monta a árvore binária representando a mansão
// Depois, inicia a exploração a partir do Hall

int main() {

// Criação automática da árvore (mansão)
    Sala *hall     = criarSala("Hall de Entrada");
    Sala *estar    = criarSala("Sala de Estar");
    Sala *corredor = criarSala("Corredor");
    Sala *biblio   = criarSala("Biblioteca");
    Sala *cozinha  = criarSala("Cozinha");

//Definição das conexões (estrutura da mansão)
    hall->esq     = estar;
    hall->dir     = corredor;
    estar->esq    = biblio;
    estar->dir    = cozinha;

// Início da exploração
    explorarMansao(hall);

    return 0;
}
//repost para enriquecimento do github
