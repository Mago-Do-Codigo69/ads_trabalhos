#include <stdio.h> // bibliotecas
#include <string.h>
#include <stdlib.h>

//definições
#define MAX_ITENS 10
#define MAX_NOME  30
#define MAX_TIPO  20

//estrutura dos items
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int totalItens = 0;

//limpar buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//converter para minusculo
void paraMinusculo(char *s) {
    for (int i = 0; s[i]; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;  // converte para minúsculo
        }
    }
}

//busca sequencial por nome
int buscarItem(const char *nome) {
    char nomeBusca[MAX_NOME];
    char nomeLista[MAX_NOME];

    strcpy(nomeBusca, nome);
    paraMinusculo(nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        strcpy(nomeLista, mochila[i].nome);
        paraMinusculo(nomeLista);

        if (strcmp(nomeLista, nomeBusca) == 0) {
            return i;
        }
    }

    return -1;
}

//adiciona 1 item caso houver espaço
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila está cheia! Remova algum item primeiro.\n");
        return;
    }

    Item novo;

    printf("\n=== Cadastro de Item ===\n");
    limparBuffer();

    printf("Nome: ");
    fgets(novo.nome, MAX_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    if (buscarItem(novo.nome) != -1) {
        printf("Este item já está cadastrado.\n");
        return;
    }

    printf("Tipo (arma, cura, etc.): ");
    fgets(novo.tipo, MAX_TIPO, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    if (scanf("%d", &novo.quantidade) != 1 || novo.quantidade <= 0) {
        printf("Quantidade inválida!\n");
        limparBuffer();
        return;
    }

    mochila[totalItens++] = novo;
    printf("Item adicionado com sucesso!\n");
}

//remove 1 item pelo nome
void removerItem() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nome[MAX_NOME];

    printf("\n=== Remover Item ===\n");
    limparBuffer();
    printf("Nome do item: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int indice = buscarItem(nome);

    if (indice == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    for (int i = indice; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;
    printf("Item removido!\n");
}

//lista todos os itens cadastrados
void listarItens() {
    printf("\n=== Itens na Mochila (%d/%d) ===\n", totalItens, MAX_ITENS);

    if (totalItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("%d) %s | Tipo: %s | Quantidade: %d\n",
            i + 1,
            mochila[i].nome,
            mochila[i].tipo,
            mochila[i].quantidade);
    }
}

//busca especifica
void buscarItemMenu() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    char nome[MAX_NOME];

    printf("\n=== Buscar Item ===\n");
    limparBuffer();
    printf("Nome: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int indice = buscarItem(nome);

    if (indice == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    Item *i = &mochila[indice];

    printf("\nItem localizado:\n");
    printf("- Nome: %s\n", i->nome);
    printf("- Tipo: %s\n", i->tipo);
    printf("- Quantidade: %d\n", i->quantidade);
}

//menu principal
void menu() {
    int opcao;

    do {
        printf("\n=================================\n");
        printf("       Sistema de Mochila        \n");
        printf("=================================\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            opcao = -1;
        }

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItemMenu(); break;
            case 0: printf("\nEncerrando...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);
}

//função principal
int main() {
    menu();
    return 0;
}

//repost de trabalho escolar para enriquecimento do github
