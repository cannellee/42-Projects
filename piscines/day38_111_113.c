// 42 projects
// Piscine - 111-113

#include <stdio.h>
#include <stdlib.h>

typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

//Ex 111 - Write the function btree_insert_data which inserts the item element into a tree. The tree passed as a parameter will be sorted: for each node, all the lower elements will be on the left and all the higher or equal elements on the right. A comparison function with the same behaviour as strcmp is sent as a parameter. The root parameter points to the root node of the tree. On the first call, it points to NULL.
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *)) {
    if (*root==NULL) {
        *root=(t_btree *)malloc(sizeof(t_btree));
        (*root)->item=item;
        (*root)->left=NULL;
        (*root)->right=NULL;
    } else {
        if (cmpf(item, (*root)->item)<0) btree_insert_data(&((*root)->left), item, cmpf);
        else btree_insert_data(&((*root)->right), item, cmpf);
    }
}

//Ex 112 - Write the function btree_search_item which returns the first element corresponding to the reference data passed in parameter. The tree must be browsed infix. If the element is not found, the function must return NULL.
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *)) {
    if (root==NULL) return NULL;
    void *result=btree_search_item(root->left, data_ref, cmpf);
    if (result!=NULL) return result;
    if (cmpf(root->item, data_ref)==0) return root->item;
    return btree_search_item(root->right, data_ref, cmpf);
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

//Ex 113 - Write the btree_level_count function, which returns the size of the largest branch passed in parameter.
int btree_level_count(t_btree *root) {
    if (root==NULL) return 0;

    int left_depth=btree_level_count(root->left);
    int right_depth=btree_level_count(root->right);

    return 1+max(left_depth, right_depth);
}


int compare_int(void *a, void *b) {
    int num1=*(int *)a;
    int num2=*(int *)b;
    if (num1<num2) return -1;
    if (num1>num2) return 1;
    return 0;
}

void print_tree_inorder(t_btree *root) {
    if (root==NULL) return;

    print_tree_inorder(root->left);
    printf("%d ", *((int *)root->item));
    print_tree_inorder(root->right);
}

int main() {
    t_btree *root = NULL;

    int values[]={5, 3, 7, 2, 4, 6, 8}; //Change the values if you want
    for (int i=0; i<sizeof(values)/sizeof(values[0]); i++) btree_insert_data(&root, (void *)&values[i], compare_int);

    printf("111 : ");
    print_tree_inorder(root);

    int target=4; //Change the value if you want
    int *found=(int *)btree_search_item(root, (void *)&target, compare_int);
    if (found!=NULL) printf("\n112 : Found.");
    else printf("\n112 : Not found.");

    printf("\n113 : %d", btree_level_count(root));

    return 0;
}
