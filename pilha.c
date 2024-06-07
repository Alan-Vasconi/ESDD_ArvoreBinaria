#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

t_pilha* criar_pilha(int n) {
    t_pilha *p = (t_pilha *)malloc(sizeof(t_pilha));
    if (p == NULL) {
        perror("Erro ao alocar memória para a pilha");
        exit(EXIT_FAILURE);
    }
    p->max = n;
    p->itens = (t_elem *)malloc(sizeof(t_elem) * n);
    if (p->itens == NULL) {
        free(p);
        perror("Erro ao alocar memória para os itens da pilha");
        exit(EXIT_FAILURE);
    }
    p->index_topo = -1;
    return p;
}

bool esta_cheio(t_pilha *p) {
    return p->index_topo >= p->max - 1;
}

bool esta_vazio(t_pilha *p) {
    return p->index_topo == -1;
}

bool empurrar(t_pilha *p, t_elem x) {
    if (esta_cheio(p)) {
        return false;
    }
    p->itens[++(p->index_topo)] = x;
    return true;
}

t_elem remover(t_pilha *p) {
    if (esta_vazio(p)) {
        return NULL;
    }
    return p->itens[(p->index_topo)--];
}
