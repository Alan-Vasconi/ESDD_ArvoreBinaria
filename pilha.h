#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct node* t_elem;

typedef struct {
    int max;
    int index_topo;
    t_elem *itens;
} t_pilha;

t_pilha* criar_pilha(int n);
bool esta_cheio(t_pilha *p);
bool esta_vazio(t_pilha *p);
bool empurrar(t_pilha *p, t_elem x);
t_elem remover(t_pilha *p);

#endif
