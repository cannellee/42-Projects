// 42 projects
// Piscine - 099-101

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

//Ex 099 - Write the function ft_list_foreach_if which applies a function given in parameter to the information contained in certain links in the list. The reference information and a comparison function allow us to select the correct links in the list: those which are "equal" to the reference information. Note: The functions pointed to by f and by cmp will be used as follows: (*f)(list_ptr->data); (*cmp)(list_ptr->data, data_ref);
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)()) {
    t_list *current=begin_list;
    while (current) {
        if ((*cmp)(current->data, data_ref)==0) (*f)(current->data);
        current=current->next;
    }
}

//Ex 100 - Write the function ft_list_find which returns the address of the first link whose data is "equal" to the reference data.
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)()) {
    t_list *current=begin_list;
    while (current) {
        if ((*cmp)(current->data, data_ref)==0) return current;
        current=current->next;
    }
    return NULL;
}

//Ex 101 - Write the ft_list_remove_if function, which deletes from the list all the elements whose data is "equal" to the reference data.
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) {
    t_list *current=*begin_list;
    t_list *prev=NULL;

    while (current) {
        if ((*cmp)(current->data, data_ref)==0) {
            if (prev==NULL) {
                *begin_list=current->next;
                free(current);
                current=*begin_list;
            } else {
                prev->next=current->next;
                free(current);
                current=prev->next;
            }
        } else {
            prev=current;
            current=current->next;
        }
    }
}

int int_cmp(void *a, void *b) {
    int *x=(int *)a;
    int *y=(int *)b;
    return (*x==*y) ? 0 : 1;
}

void print_int(void *data) {
    int *x=(int *)data;
    printf("%d ", *x);
}

int main() {
    t_list *list=(t_list *)malloc(sizeof(t_list));
    int a=10, b=20, c=10, d=30;
    list->data=&a;
    list->next=(t_list *)malloc(sizeof(t_list));
    list->next->data=&b;
    list->next->next=(t_list *)malloc(sizeof(t_list));
    list->next->next->data=&c;
    list->next->next->next=(t_list *)malloc(sizeof(t_list));
    list->next->next->next->data=&d;
    list->next->next->next->next=NULL;

    printf("099 : ");
    ft_list_foreach_if(list, &print_int, &a, &int_cmp);

    int *value_to_find=(int *)malloc(sizeof(int));
    *value_to_find=20;
    t_list *found=ft_list_find(list, value_to_find, &int_cmp);
    if (found) printf("\n100 : Find.");
    else printf("\n100 : Not find.");
    free(value_to_find);

    ft_list_remove_if(&list, &a, &int_cmp);

    printf("\n101 : ");
    ft_list_foreach_if(list, &print_int, &a, &int_cmp);

    t_list *current=list;
	while (current) {
		print_int(current->data);
		current=current->next;
	}

	current=list;
	t_list *next;
    while (current) {
        next=current->next;
        free(current);
        current=next;
    }

    return 0;
}
