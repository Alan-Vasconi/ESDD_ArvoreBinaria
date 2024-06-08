#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct t_binary_tree {
    char data;
    struct t_binary_tree *left;
    struct t_binary_tree *right;
} t_binary_tree;


t_binary_tree* create_tree(const char* str);
void pre_order(t_binary_tree* root);
void in_order(t_binary_tree* root);
void post_order(t_binary_tree* root);
int height(t_binary_tree* root);
void print_tree(t_binary_tree* root, int depth);
void free_tree(t_binary_tree* root);

#endif
