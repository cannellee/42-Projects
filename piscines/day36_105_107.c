// 42 projects
// Piscine - 105-107

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

//Ex 105 - Write the ft_sorted_list_insert function, which creates a new element and inserts it into a sorted list so that the list remains sorted in ascending order.
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()) {
    t_list *new_node=(t_list *)malloc(sizeof(t_list));
    if (new_node==NULL) return;
    new_node->data=data;
    new_node->next=NULL;

    if (*begin_list==NULL || cmp(data, (*begin_list)->data)<0) {
        new_node->next=*begin_list;
        *begin_list=new_node;
    } else {
        t_list *current=*begin_list;
        while (current->next!=NULL && cmp(data, current->next->data)>=0) {
            current=current->next;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
}

//Ex 106 - Write the function ft_sorted_list_merge which integrates the elements of a sorted list begin2 into another sorted list begin1, so that the list begin1 remains sorted in ascending order.
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)()) {
    t_list *current1=*begin_list1;
    t_list *current2=begin_list2;
    t_list *temp;

    if (current1==NULL) {
        *begin_list1=begin_list2;
        return;
    }
    while (current2!=NULL) {
        while (current1->next!=NULL && cmp(current1->next->data, current2->data)<0) {
            current1=current1->next;
        }
        temp=current2->next;
        current2->next=current1->next;
        current1->next=current2;
        current2=temp;
    }
}

//Ex 107 - Write the function btree_create_node which allocates a new element, initializes its item to the value of the parameter and all the other elements to 0. The address of the node created is returned.
t_btree *btree_create_node(void *item) {
    t_btree *new_node=(t_btree *)malloc(sizeof(t_btree));
    if (new_node==NULL) return NULL;
    new_node->item=item;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}


int compare_int(void *a, void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    return int_a - int_b;
}

int main() {
    t_list *list1=NULL;
    int arr1[]={5, 10, 15}; //Change the values if you want
    for (int i=0; i<sizeof(arr1)/sizeof(arr1[0]); i++) ft_sorted_list_insert(&list1, &arr1[i], compare_int);

    t_list *list2=NULL;
    int arr2[]={2, 7, 12}; //Change the values if you want
    for (int i=0; i<sizeof(arr2)/sizeof(arr2[0]); i++) ft_sorted_list_insert(&list2, &arr2[i], compare_int);

    ft_sorted_list_merge(&list1, list2, compare_int);

    printf("105 & 106 : ");
    t_list *current=list1;
    while (current!=NULL) {
        printf("%d ", *((int*)current->data));
        current=current->next;
    }

    t_btree *tree=btree_create_node(&arr1[0]);
    tree->left=btree_create_node(&arr1[1]);
    tree->right=btree_create_node(&arr1[2]);

    printf("\n107 : %d, %d, %d\n", *((int*)tree->item), *((int*)tree->left->item), *((int*)tree->right->item));

    return 0;
}
