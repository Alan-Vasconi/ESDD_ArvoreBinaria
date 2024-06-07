#include <stdio.h>
#include "binary_tree.h"

int main() {
    const char *dados = "1(2(4,5),3(6,7))";
    arvore_binaria *arvore = create_tree(dados);
    print_tree(arvore->root);
    printf("\n");
    return 0;
}
