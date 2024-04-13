// 42 projects
// Piscine - 114-116

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree_rb.h"

//Ex 114 - Write the function btree_apply_by_level which applies the function passed in parameter to each node of the tree. The tree must be traversed level by level. The called function will take three parameters: The first parameter, of type void *, corresponds to the node item; The second parameter, of type int, corresponds to the level on which we are: 0 for the root, 1 for his children, 2 for his grandchildren, etc.; The third parameter, of type int, is 1 if it's the first node on the level, 0 otherwise.
typedef struct s_btree {
    void *item;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

typedef struct s_queue {
    t_btree *node;
    int level;
    struct s_queue *next;
} t_queue;

void enqueue(t_queue **queue, t_btree *node, int level) {
    t_queue *new_node=malloc(sizeof(t_queue));
    if (new_node==NULL) return;
    new_node->node=node;
    new_node->level=level;
    new_node->next=NULL;

    if (*queue==NULL) *queue=new_node;
    else {
        t_queue *temp=*queue;
        while (temp->next!=NULL) temp=temp->next;
        temp->next=new_node;
    }
}

t_btree *dequeue(t_queue **queue, int *level) {
    if (*queue==NULL) return NULL;
    t_queue *temp=*queue;
    *queue=(*queue)->next;
    t_btree *node=temp->node;
    *level=temp->level;
    free(temp);
    return node;
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) {
    if (root==NULL) return;

    t_queue *queue=NULL;
    enqueue(&queue, root, 0);

    int prev_level=-1;
    while (queue!=NULL) {
        t_btree *current_node=dequeue(&queue, &prev_level);
        if (current_node!=NULL) {
            if (prev_level==-1 || prev_level!=prev_level) applyf(current_node->item, prev_level, 1);
            else applyf(current_node->item, prev_level, 0);

            if (current_node->left!=NULL) enqueue(&queue, current_node->left, prev_level+1);
            if (current_node->right!=NULL) enqueue(&queue, current_node->right, prev_level+1);
        }
    }
}

void print_item(void *item, int current_level, int is_first_elem) {
    if (is_first_elem) printf("Level %d: ", current_level);
    printf("%d ", *((int *)item));
    if (is_first_elem) printf("\n");
}


//Ex 115 - Write the rb_insert function, which adds new data to the tree so that it continues to respect the constraints of a red and black tree. The root parameter points to the root node of the tree. On the first call, it points to NULL. A comparison function with the same behavior as strcmp will also be sent as a parameter.
t_rb_node *create_rb_node(void *data) {
    t_rb_node *node=(t_rb_node *)malloc(sizeof(t_rb_node));
    if (node==NULL) return 1;
    node->data=data;
    node->parent=NULL;
    node->left=NULL;
    node->right=NULL;
    node->color=RB_RED;
    return node;
}

void left_rotate(t_rb_node **root, t_rb_node *x) {
    t_rb_node *y=x->right;
    x->right=y->left;
    if (y->left!=NULL) y->left->parent=x;
    y->parent=x->parent;
    if (x->parent==NULL) *root=y;
    else if (x==x->parent->left) x->parent->left=y;
    else x->parent->right=y;
    y->left=x;
    x->parent=y;
}

void right_rotate(t_rb_node **root, t_rb_node *y) {
    t_rb_node *x=y->left;
    y->left=x->right;
    if (x->right!=NULL) x->right->parent=y;
    x->parent=y->parent;
    if (y->parent==NULL) *root=x;
    else if (y == y->parent->left) y->parent->left=x;
    else y->parent->right=x;
    x->right=y;
    y->parent=x;
}

void rb_insert_fixup(t_rb_node **root, t_rb_node *z) {
    while (z!=*root && z->parent->color==RB_RED) {
        if (z->parent==z->parent->parent->left) {
            t_rb_node *y=z->parent->parent->right;
            if (y!=NULL && y->color==RB_RED) {
                z->parent->color=RB_BLACK;
                y->color=RB_BLACK;
                z->parent->parent->color=RB_RED;
                z=z->parent->parent;
            } else {
                if (z==z->parent->right) {
                    z=z->parent;
                    left_rotate(root, z);
                }
                z->parent->color=RB_BLACK;
                z->parent->parent->color=RB_RED;
                right_rotate(root, z->parent->parent);
            }
        } else {
            t_rb_node *y=z->parent->parent->left;
            if (y!=NULL && y->color==RB_RED) {
                z->parent->color=RB_BLACK;
                y->color=RB_BLACK;
                z->parent->parent->color=RB_RED;
                z=z->parent->parent;
            } else {
                if (z==z->parent->left) {
                    z=z->parent;
                    right_rotate(root, z);
                }
                z->parent->color=RB_BLACK;
                z->parent->parent->color=RB_RED;
                left_rotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color=RB_BLACK;
}

void rb_insert(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *)) {
    t_rb_node *z=create_rb_node(data);
    t_rb_node *y=NULL;
    t_rb_node *x=*root;

    while (x!=NULL) {
        y=x;
        if (cmpf(z->data, x->data)<0) x=x->left;
        else x=x->right;
    }

    z->parent=y;
    if (y==NULL) *root=z;
    else if (cmpf(z->data, y->data)<0) y->left=z;
    else y->right=z;

    rb_insert_fixup(root, z);
}

t_rb_node *tree_minimum(t_rb_node *x) {
    while (x->left!=NULL) x=x->left;
    return x;
}

void rb_delete_fixup(t_rb_node **root, t_rb_node *x) {
    while (x!=*root && x->color==RB_BLACK) {
        if (x==x->parent->left) {
            t_rb_node *w=x->parent->right;
            if (w->color==RB_RED) {
                w->color=RB_BLACK;
                x->parent->color=RB_RED;
                left_rotate(root, x->parent);
                w=x->parent->right;
            }
            if (w->left->color==RB_BLACK && w->right->color==RB_BLACK) {
                w->color=RB_RED;
                x=x->parent;
            } else {
                if (w->right->color==RB_BLACK) {
                    w->left->color=RB_BLACK;
                    w->color=RB_RED;
                    right_rotate(root, w);
                    w=x->parent->right;
                }
                w->color=x->parent->color;
                x->parent->color=RB_BLACK;
                w->right->color=RB_BLACK;
                left_rotate(root, x->parent);
                x=*root;
            }
        } else {
            t_rb_node *w=x->parent->left;
            if (w->color==RB_RED) {
                w->color=RB_BLACK;
                x->parent->color=RB_RED;
                right_rotate(root, x->parent);
                w=x->parent->left;
            }
            if (w->right->color==RB_BLACK && w->left->color==RB_BLACK) {
                w->color=RB_RED;
                x=x->parent;
            } else {
                if (w->left->color==RB_BLACK) {
                    w->right->color=RB_BLACK;
                    w->color=RB_RED;
                    left_rotate(root, w);
                    w=x->parent->left;
                }
                w->color=x->parent->color;
                x->parent->color=RB_BLACK;
                w->left->color=RB_BLACK;
                right_rotate(root, x->parent);
                x=*root;
            }
        }
    }
    x->color=RB_BLACK;
}

//Ex 116 - Write the rb_remove function, which removes data from the tree so that it continues to respect the constraints of a red and black tree. The root parameter points to the root node of the tree. A comparison function with the same behavior as strcmp will also be sent as a parameter, as well as a pointer to function freef, which will be called with the tree element to be deleted as a parameter.
void rb_delete_node(t_rb_node **root, t_rb_node *z, void (*freef)(void *)) {
    t_rb_node *y=z;
    t_rb_node *x=NULL;
    enum e_rb_color y_original_color=y->color;

    if (z->left==NULL) {
        x=z->right;
        rb_transplant(root, z, z->right);
    } else if (z->right==NULL) {
        x=z->left;
        rb_transplant(root, z, z->left);
    } else {
        y=tree_minimum(z->right);
        y_original_color=y->color;
        x=y->right;
        if (y->parent==z) if (x != NULL) x->parent=y;
        else {
            rb_transplant(root, y, y->right);
            y->right=z->right;
            if (y->right!=NULL) y->right->parent=y;
        }
        rb_transplant(root, z, y);
        y->left=z->left;
        y->left->parent=y;
        y->color=z->color;
    }
    if (y_original_color==RB_BLACK) rb_delete_fixup(root, x);
    freef(z->data);
    free(z);
}

void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), void (*freef)(void *)) {
    t_rb_node *z=*root;
    while (z!=NULL) {
        int cmp_result=cmpf(data, z->data);
        if (cmp_result==0) {
            rb_delete_node(root, z, freef);
            return;
        } else if (cmp_result<0) z=z->left;
        else z=z->right;
    }
}

int cmp_int(void *a, void *b) {
    int *int_a=(int *)a;
    int *int_b=(int *)b;
    return (*int_a>*int_b)-(*int_a<*int_b);
}

void free_int(void *data) {
    free(data);
}

int main() {
    t_btree *root=malloc(sizeof(t_btree));
    int *root_item=malloc(sizeof(int));
    *root_item=5; //Change the value if you want
    root->item=root_item;
    root->left=malloc(sizeof(t_btree));
    int *left_item=malloc(sizeof(int));
    *left_item=3; //Change the value if you want
    root->left->item=left_item;
    root->right=malloc(sizeof(t_btree));
    int *right_item=malloc(sizeof(int));
    *right_item=7; //Change the value if you want
    root->right->item=right_item;
    root->left->left=NULL;
    root->left->right=NULL;
    root->right->left=NULL;
    root->right->right=NULL;

    printf("114 : ");
    btree_apply_by_level(root, &print_item);

    free(root->left->item);
    free(root->left);
    free(root->right->item);
    free(root->right);
    free(root);

    t_rb_node *root_two = NULL;
	int values[]={10, 20, 30, 15, 25}; //Change the values if you want
	for (int i=0; i<5; i++) {
		int *data=malloc(sizeof(int));
		*data=values[i];
		rb_insert(&root_two, data, &cmp_int);
	}

	printf("\n115 : ");

	int value_to_remove=20;
	rb_remove(&root_two, &value_to_remove, &cmp_int, &free_int);

	printf("\n116 : %d", value_to_remove);
    return 0;
}
