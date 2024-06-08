#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

t_pilha* criar_pilha(int capacidade) {
    t_pilha *pilha = (t_pilha*)malloc(sizeof(t_pilha));
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    pilha->capacity = capacidade;
    pilha->top = -1;
    pilha->itens = (node**)malloc(capacidade * sizeof(node*));
    if (pilha->itens == NULL) {
        printf("Erro ao alocar memória para os itens da pilha.\n");
        exit(EXIT_FAILURE);
    }
    return pilha;
}

void destruir_pilha(t_pilha *pilha) {
    free(pilha->itens);
    free(pilha);
}

int pilha_vazia(t_pilha *pilha) {
    return pilha->top == -1;
}

int pilha_cheia(t_pilha *pilha) {
    return pilha->top == pilha->capacity - 1;
}

void empurrar(t_pilha *pilha, node *item) {
    if (pilha_cheia(pilha)) {
        printf("Erro: a pilha está cheia.\n");
        exit(EXIT_FAILURE);
    }
    pilha->itens[++pilha->top] = item;
}

node* remover(t_pilha *pilha) {
    if (pilha_vazia(pilha)) {
        printf("Erro: a pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    return pilha->itens[pilha->top--];
}
