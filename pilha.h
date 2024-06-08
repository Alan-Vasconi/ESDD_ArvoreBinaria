#ifndef PILHA_H
#define PILHA_H

#include "binary_tree.h"

typedef struct {
    int capacity;
    int top;
    node **itens;
} t_pilha;

t_pilha* criar_pilha(int capacidade);
void destruir_pilha(t_pilha *pilha);
int pilha_vazia(t_pilha *pilha);
int pilha_cheia(t_pilha *pilha);
void empurrar(t_pilha *pilha, node *item);
node* remover(t_pilha *pilha);

#endif
