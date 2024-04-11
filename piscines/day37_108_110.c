// 42 projects
// Piscine - 108-110

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

//Ex 108 - Write the btree_apply_prefix function, which applies the function passed in parameter to the item of each node, traversing the tree in a prefix manner.
void btree_apply_prefix(t_btree *root, void (*applyf)(void *)) {
    if (root) {
        applyf(root->item);
        btree_apply_prefix(root->left, applyf);
        btree_apply_prefix(root->right, applyf);
    }
}

//Ex 109 - Write the btree_apply_infix function, which applies the function passed in parameter to the item of each node, traversing the tree using infix.
void btree_apply_infix(t_btree *root, void (*applyf)(void *)) {
    if (root) {
        btree_apply_infix(root->left, applyf);
        applyf(root->item);
        btree_apply_infix(root->right, applyf);
    }
}

//Ex 110 - Write the btree_apply_suffix function, which applies the function passed in parameter to the item of each node, traversing the tree as a suffix.
void btree_apply_suffix(t_btree *root, void (*applyf)(void *)) {
    if (root) {
        btree_apply_suffix(root->left, applyf);
        btree_apply_suffix(root->right, applyf);
        applyf(root->item);
    }
}

void print_item(void *item) {
    printf("%d ", *((int *)item));
}

int main() {
    t_btree *root=(t_btree *)malloc(sizeof(t_btree));
    root->item=(void *)malloc(sizeof(int));
    *((int *)root->item)=1;

    root->left=(t_btree *)malloc(sizeof(t_btree));
    root->left->item=(void *)malloc(sizeof(int));
    *((int *)root->left->item)=2;
    root->left->left=NULL;
    root->left->right=NULL;

    root->right=(t_btree *)malloc(sizeof(t_btree));
    root->right->item=(void *)malloc(sizeof(int));
    *((int *)root->right->item)=3;

    root->right->left=(t_btree *)malloc(sizeof(t_btree));
    root->right->left->item=(void *)malloc(sizeof(int));
    *((int *)root->right->left->item)=4;
    root->right->left->left=NULL;
    root->right->left->right=NULL;

    root->right->right=(t_btree *)malloc(sizeof(t_btree));
    root->right->right->item=(void *)malloc(sizeof(int));
    *((int *)root->right->right->item)=5;
    root->right->right->left=NULL;
    root->right->right->right=NULL;

    printf("108 : ");
    btree_apply_prefix(root, print_item);

    printf("\n109 : ");
    btree_apply_infix(root, print_item);

    printf("\n110 : ");
    btree_apply_suffix(root, print_item);

    free(root->right->right->item);
    free(root->right->right);
    free(root->right->left->item);
    free(root->right->left);
    free(root->right->item);
    free(root->left->item);
    free(root->left);
    free(root->item);
    free(root);

    return 0;
}
