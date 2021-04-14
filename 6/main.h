#include <stdio.h>

struct tree {
    int info;
    struct tree* left;
    struct tree* right;
};
long int filesize(FILE* fp);
void print_tree(struct tree* r, int l, int n);
void treeremove(struct tree* root);
void checkPtr(void *ptr);
