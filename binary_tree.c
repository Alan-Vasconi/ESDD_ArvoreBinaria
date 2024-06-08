#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "binary_tree.h"
#include "pilha.h"

int are_parentheses_balanced(const char *dados) {
    int balance = 0;
    for (const char *pos = dados; *pos != '\0'; pos++) {
        if (*pos == '(') {
            balance++;
        } else if (*pos == ')') {
            balance--;
        }
        if (balance < 0) {
            return 0; 
        }
    }
    return balance == 0; 
}

node* create_node(const char *element) {
    node* result = (node*) malloc(sizeof(node));
    if (result != NULL) {
        result->left = result->right = NULL;
        result->element = strdup(element);
        if (result->element == NULL) {
            free(result);
            return NULL;
        }
    }
    return result;
}

arvore_binaria* create_tree(const char *dados) {
    if (!are_parentheses_balanced(dados)) {
        printf("Erro: expressão mal formada. Parênteses desbalanceados.\n");
        return NULL;
    }

    arvore_binaria *arvore = (arvore_binaria*) malloc(sizeof(arvore_binaria));
    if (arvore == NULL) {
        printf("Erro ao alocar memória para a árvore.\n");
        return NULL;
    }
    arvore->root = NULL;

    const char *pos = dados;
    node **current = &(arvore->root);

    t_pilha *pilha = criar_pilha(100);
    if (pilha == NULL) {
        printf("Erro ao criar a pilha.\n");
        free(arvore);
        return NULL;
    }

    char buffer[256];
    while (*pos) {
        if (*pos == '(') {
            pos++;
            if (*pos != ',' && *pos != ')') {
                int i = 0;
                while (*pos != ',' && *pos != ')' && *pos != '\0') {
                    buffer[i++] = *pos++;
                }
                buffer[i] = '\0';
                printf("Criando nó com valor: %s\n", buffer);
                *current = create_node(buffer);
                if (*current == NULL) {
                    printf("Erro ao criar o nó.\n");
                    destruir_pilha(pilha);
                    free(arvore);
                    return NULL;
                }
                empurrar(pilha, *current);
                current = &((*current)->left);
            } else {
                pos++;
                current = &(pilha->itens[pilha->top]->right);
            }
        } else if (*pos == ',') {
            pos++;
            current = &(pilha->itens[pilha->top]->right);
        } else if (*pos == ')') {
            pos++;
            if (!pilha_vazia(pilha)) {
                remover(pilha);
                if (!pilha_vazia(pilha)) {
                    current = &(pilha->itens[pilha->top]->right);
                }
            }
        } else {
            pos++;
        }
    }

    destruir_pilha(pilha);

    printf("Árvore criada com sucesso.\n");
    return arvore;
}

void print_tree(node *node) {
    if (!node) { printf("()"); return; }
    printf("(%s", node->element);
    printf(",");
    print_tree(node->left);
    printf(",");
    print_tree(node->right);
    printf(")");
}

void pre_order(node *no) {
    if (no != NULL) {
        printf("%s\t", no->element);
        pre_order(no->left);
        pre_order(no->right);
    }
}

void in_order(node *no) {
    if (no != NULL) {
        in_order(no->left);
        printf("%s\t", no->element);
        in_order(no->right);
    }
}

void post_order(node *no) {
    if (no != NULL) {
        post_order(no->left);
        post_order(no->right);
        printf("%s\t", no->element);
    }
}

int height_node(node* node) {
    if (node == NULL)
        return 0;
    else {
        int left_height = height_node(node->left);
        int right_height = height_node(node->right);

        if (left_height > right_height)
            return (left_height + 1);
        else
            return (right_height + 1);
    }
}

int find_height(node* root, const char *element) {
    if (root == NULL)
        return -1;
    if (strcmp(root->element, element) == 0)
        return height_node(root) - 1;

    int left_height = find_height(root->left, element);
    if (left_height != -1)
        return left_height;

    return find_height(root->right, element);
}

void print_tree_hierarchy(node *root, int level) {
    if (root != NULL) {
        print_tree_hierarchy(root->right, level + 1);
        for (int i = 0; i < level; i++)
            printf("    ");
        printf("%s\n", root->element);
        print_tree_hierarchy(root->left, level + 1);
    }
}
