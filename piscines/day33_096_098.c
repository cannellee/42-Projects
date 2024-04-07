// 42 projects
// Piscine - 096-098

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

//Ex 096 - Write the function ft_list_at which returns the nth element of the list. It will return a null pointer on error.
t_list *ft_list_at(t_list *begin_list, unsigned int nbr) {
    while (nbr>0 && begin_list!=NULL) {
        begin_list=begin_list->next;
        nbr--;
    }
    return begin_list;
}

//Ex 097 - Write the function ft_list_reverse which reverses the order of the elements in the list. Only sets of pointers are allowed.
void ft_list_reverse(t_list **begin_list) {
    t_list *prev=NULL;
    t_list *current=*begin_list;
    t_list *next=NULL;

    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *begin_list=prev;
}

//Ex 098 - Write the function ft_list_foreach which applies a function given in parameter to the information contained in each link of the list. Note: The function pointed to by f will be used as follows: (*f)(list_ptr->data);
void ft_list_foreach(t_list *begin_list, void (*f)(void *)) {
    while (begin_list!=NULL) {
        (*f)(begin_list->data);
        begin_list=begin_list->next;
    }
}

void print_int(void *data) {
    printf("%d ", *(int *)data);
}

int main() {
    t_list *head=malloc(sizeof(t_list));
    int a=1, b=2, c=3, d=4; //Change the values if you want
    head->data=&a;
    head->next=malloc(sizeof(t_list));
    head->next->data=&b;
    head->next->next=malloc(sizeof(t_list));
    head->next->next->data=&c;
    head->next->next->next=malloc(sizeof(t_list));
    head->next->next->next->data=&d;
    head->next->next->next->next=NULL;

    printf("Initial list : ");
    ft_list_foreach(head, &print_int);

    unsigned int index=2; //Change the value if you want
    t_list *element_at_index=ft_list_at(head, index);
    if (element_at_index!=NULL) printf("\n096 : %d", *(int *)(element_at_index->data));
    else printf("\n096 : Element at index %u does not exist.", index);

    ft_list_reverse(&head);
    printf("\n097 & 098 : ");
    ft_list_foreach(head, &print_int);

    t_list *temp;
    while (head!=NULL) {
        temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}
