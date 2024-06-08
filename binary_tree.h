#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node {
    char *element;
    struct node *left;
    struct node *right;
} node;

typedef struct {
    node *root;
} arvore_binaria;

node* create_node(const char *element);
arvore_binaria* create_tree(const char *dados);
void print_tree(node *node);
void pre_order(node *no);
void in_order(node *no);
void post_order(node *no);
void print_tree_hierarchy(node *node, int level);
int find_height(node* root, const char *element);

#endif
