#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

t_binary_tree* new_node(char data) {
    t_binary_tree* node = (t_binary_tree*)malloc(sizeof(t_binary_tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_binary_tree* create_tree(const char** str) {
    if (**str == '\0' || **str == ')') return NULL;

    if (**str == '(') (*str)++;

    if (**str == '\0' || **str == ')') return NULL;

    t_binary_tree* root = new_node(**str);
    (*str)++;

    if (**str == ',') {
        (*str)++;
        root->left = create_tree_recursive(str);
    }

    if (**str == ',') {
        (*str)++;
        root->right = create_tree_recursive(str);
    }

    if (**str == ')') (*str)++;

    return root;
}

void pre_order(t_binary_tree* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(t_binary_tree* root) {
    if (root == NULL) return;
    in_order(root->left);
    printf("%c ", root->data);
    in_order(root->right);
}

void post_order(t_binary_tree* root) {
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%c ", root->data);
}

int height(t_binary_tree* root) {
    if (root == NULL) return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

void print_tree(t_binary_tree* root, int depth) {
    if (root == NULL) return;
    print_tree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("   ");
    printf("%c\n", root->data);
    print_tree(root->left, depth + 1);
}

void free_tree(t_binary_tree* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}