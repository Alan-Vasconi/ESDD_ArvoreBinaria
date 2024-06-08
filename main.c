#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

int main() {
    arvore_binaria *arvore = NULL;
    char comando[256];
    char input[256];
    char n[256];

    while (1) {
        printf("Digite um comando (create, pre, in, post, height <n>, print, exit): ");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = '\0'; 

        if (strncmp(comando, "create", 6) == 0) {
            if (comando[6] == ' ') {
                strncpy(input, comando + 7, sizeof(input) - 1);
                input[sizeof(input) - 1] = '\0'; 
                printf("Comando recebido: create %s\n", input); 
                arvore = create_tree(input);
                if (arvore) {
                    printf("Árvore criada com sucesso.\n");
                } else {
                    printf("Falha ao criar a árvore.\n");
                }
            } else {
                printf("Comando invalido.\n");
            }
        } else if (strcmp(comando, "pre") == 0) {
            if (arvore && arvore->root) {
                pre_order(arvore->root);
                printf("\n");
            } else {
                printf("Arvore nao criada.\n");
            }
        } else if (strcmp(comando, "in") == 0) {
            if (arvore && arvore->root) {
                in_order(arvore->root);
                printf("\n");
            } else {
                printf("Arvore nao criada.\n");
            }
        } else if (strcmp(comando, "post") == 0) {
            if (arvore && arvore->root) {
                post_order(arvore->root);
                printf("\n");
            } else {
                printf("Arvore nao criada.\n");
            }
        } else if (strncmp(comando, "height", 6) == 0) {
            if (comando[6] == ' ') {
                strncpy(n, comando + 7, sizeof(n) - 1);
                n[sizeof(n) - 1] = '\0'; 
                if (arvore && arvore->root) {
                    int h = find_height(arvore->root, n);
                    if (h == -1) {
                        printf("No %s nao encontrado.\n", n);
                    } else {
                        printf("Altura do no %s: %d\n", n, h);
                    }
                } else {
                    printf("Arvore nao criada.\n");
                }
            } else {
                printf("Comando invalido.\n");
            }
        } else if (strcmp(comando, "print") == 0) {
            if (arvore && arvore->root) {
                print_tree_hierarchy(arvore->root, 0);
            } else {
                printf("Arvore nao criada.\n");
            }
        } else if (strcmp(comando, "exit") == 0) {
            break;
        } else {
            printf("Comando invalido.\n");
        }
    }

    return 0;
}
