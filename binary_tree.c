#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "binary_tree.h"
#include "pilha.h"

node* create_node(int element) {
    node* result = (node*) malloc(sizeof(node));
    if (result != NULL) {
        result->left = result->right = NULL;
        result->element = element;
    }
    return result;
}

arvore_binaria* create_tree(const char *dados) {
    arvore_binaria *arvore = (arvore_binaria*) malloc(sizeof(arvore_binaria));
    arvore->root = NULL;
    const char *pos = dados;
    node **current = &(arvore->root);

    t_pilha *pilha = criar_pilha(100); 

    while (*pos) {
        if (*pos == '(') {
            pos++;
            if (*pos != ',' && *pos != ')') { 
                int num = 0, sign = 1;
                if (*pos == '-') { sign = -1; pos++; }
                while (isdigit(*pos)) {
                    num = num * 10 + (*pos - '0');
                    pos++;
                }
                *current = create_node(num * sign);
                empurrar(pilha, *current); 
                current = &((*current)->left);
            }
        } else if (*pos == ',') {
            pos++;
            current = &(pilha->itens[pilha->index_topo]->right);
        } else if (*pos == ')') {
            pos++;
            remover(pilha);
        } else {
            pos++;
        }
    }

    free(pilha->itens);
    free(pilha);

    return arvore;
}

void print_tree(node *node) { // Imprime de forma padrão, tem que atualizar para hierarquia
    if (!node) { printf("()"); return; }
    printf("(%d", node->element);
    printf(",");
    print_tree(node->left);
    printf(",");
    print_tree(node->right);
    printf(")");
}

void pre_order(node *no){
    if (no != NULL){
        prinft("%d\t", no->element);
        pre_order(no->left);
        pre_order(no->right);
    }
}

void in_order(node *no){
    if(no != NULL){
        in_order(no->left);
        printf("%d\t",no->element);
        in_order(no->right);
    }
}

void post_order(node *no){
    if(no != NULL){
        post_order(no->left);
        post_order(no->right);
        printf("%d\t",no->element);
    }
}


