#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

#define MAX_INPUT_SIZE 256

void process_commands() {
    char input[MAX_INPUT_SIZE];
    t_binary_tree* tree = NULL;

    while (1) {
        printf("Enter command: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strncmp(input, "create ", 7) == 0) {
            if (tree != NULL) free_tree(tree);
            tree = create_tree(input + 7);
            if (tree == NULL) printf("Invalid expression\n");
        } else if (strcmp(input, "pre") == 0) {
            pre_order(tree);
            printf("\n");
        } else if (strcmp(input, "in") == 0) {
            in_order(tree);
            printf("\n");
        } else if (strcmp(input, "post") == 0) {
            post_order(tree);
            printf("\n");
        } else if (strncmp(input, "height ", 7) == 0) {
            printf("%d\n", height(tree));
        } else if (strcmp(input, "print") == 0) {
            print_tree(tree, 0);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    if (tree != NULL) free_tree(tree);
}

int main() {
    process_commands();
    return 0;
}
