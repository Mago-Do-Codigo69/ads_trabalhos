//bibliotecas
#include <stdio.h>
#include <stdlib.h>

//definiçoes e estruturas

#define TAMANHO_MAXIMO 10
#define TAMANHO_INICIAL 5

typedef struct {
    char nome;
    int id;
} Peca;

typedef struct {
    Peca itens[TAMANHO_MAXIMO];
    int frente;
    int tras;
    int contador;
} FilaCircular;

//variaveis globais

char tipos[4] = {'I', 'O', 'T', 'L'};
int proximoID = 0;

//gerar peça automaticamente
Peca gerarPeca() {
    Peca nova;
    nova.nome = tipos[proximoID % 4];
    nova.id = proximoID;
    proximoID++;
    return nova;
}

//verificar se a fila esta cheia
int estaCheia(FilaCircular *fila) {
    return fila->contador == TAMANHO_MAXIMO;
}

//verificar se a fila esta vazia
int estaVazia(FilaCircular *fila) {
    return fila->contador == 0;
}

//mostrar fila
void exibirFila(FilaCircular *fila) {

    printf("\n+==============================================+\n");
    printf("|                FILA DE PEÇAS                |\n");
    printf("+==============================================+\n");

    if (estaVazia(fila)) {
        printf("|                  [VAZIA]                    |\n");
        printf("+==============================================+\n");
        return;
    }

    printf("| ");

    int i = fila->frente;
    for (int c = 0; c < fila->contador; c++) {
        printf("[%c %d] ", fila->itens[i].nome, fila->itens[i].id);
        i = (i + 1) % TAMANHO_MAXIMO;
    }

    printf("\n+==============================================+\n");
}

//inserir peça no final
void inserirPeca(FilaCircular *fila) {
    if (estaCheia(fila)) {
        printf("\n[ERRO] Fila cheia. Nao ha espaco para nova peca.\n");
        return;
    }

    Peca nova = gerarPeca();
    fila->itens[fila->tras] = nova;
    fila->tras = (fila->tras + 1) % TAMANHO_MAXIMO;
    fila->contador++;

    printf("\n+-----------------------------+\n");
    printf("| PEÇA INSERIDA: [%c %d]        |\n", nova.nome, nova.id);
    printf("+-----------------------------+\n");

    exibirFila(fila);
}

//remove a peça da frente
void jogarPeca(FilaCircular *fila) {
    if (estaVazia(fila)) {
        printf("\n[ERRO] Fila vazia. Nenhuma peca para jogar.\n");
        return;
    }

    Peca removida = fila->itens[fila->frente];
    fila->frente = (fila->frente + 1) % TAMANHO_MAXIMO;
    fila->contador--;

    printf("\n+-----------------------------+\n");
    printf("| PEÇA JOGADA: [%c %d]           |\n", removida.nome, removida.id);
    printf("+-----------------------------+\n");

    exibirFila(fila);
}

//inicio da fila
void inicializarFila(FilaCircular *fila) {
    fila->frente = 0;
    fila->tras = 0;
    fila->contador = 0;

    printf("\nInicializando a fila com %d pecas...\n", TAMANHO_INICIAL);

    for (int i = 0; i < TAMANHO_INICIAL; i++) {
        Peca p = gerarPeca();
        fila->itens[fila->tras] = p;
        fila->tras = (fila->tras + 1) % TAMANHO_MAXIMO;
        fila->contador++;
    }

    exibirFila(fila);
}

//menu do tetris
void exibirMenu() {
    printf("\n+-----------------------------+\n");
    printf("|            MENU             |\n");
    printf("+-----------------------------+\n");
    printf("| 1 - Jogar peca              |\n");
    printf("| 2 - Inserir nova peca       |\n");
    printf("| 0 - Sair                    |\n");
    printf("+-----------------------------+\n");
    printf("Escolha: ");
}

//função principal

int main() {
    FilaCircular fila;
    int opcao;

    inicializarFila(&fila);

    do {
        exibirMenu();
        scanf("%d", &opcao);

        if (opcao == 1)
            jogarPeca(&fila);
        else if (opcao == 2)
            inserirPeca(&fila);

    } while (opcao != 0);

    printf("\nEncerrando o programa...\n");
    return 0;
}

//projeto escolar respostado para enriquecimento do github
