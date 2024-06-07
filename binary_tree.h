#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node {
    int element;
    struct node *left;
    struct node *right;
} node;

typedef struct {
    node *root;
} arvore_binaria;

node* create_node(int element);
arvore_binaria* create_tree(const char *dados);
void print_tree(node *node);
void pre_order(node *no);
void in_order(node *no);
void post_order(node *no);

#endif
