// 42 projects
// Piscine - 093-095

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *ft_create_elem(void *data) {
    t_list *elem;

    elem=(t_list *)malloc(sizeof(t_list));
    if (elem==NULL) return NULL;
    elem->data=data;
    elem->next=NULL;
    return elem;
}

//Ex 093 - Write the ft_list_last function, which returns the last element in the list.
t_list *ft_list_last(t_list *begin_list) {
    if (begin_list==NULL) return NULL;
    while (begin_list->next!=NULL) begin_list=begin_list->next;
    return begin_list;
}

//Ex 094 - Write the function ft_list_push_params which creates a new list by putting the command line parameters into it. The first argument will be at the end of the list. The address of the first link in the list is returned.
t_list *ft_list_push_params(int ac, char **av) {
    t_list *list;
    t_list *tmp;

    list=NULL;
    int i=ac-1;
    while (i>=0) {
        tmp=ft_create_elem(av[i]);
        if (tmp==NULL) {
            while (list!=NULL) {
                tmp=list->next;
                free(list);
                list=tmp;
            }
            return NULL;
        }
        tmp->next=list;
        list=tmp;
        i--;
    }
    return list;
}

//Ex 095 - Write the ft_list_clear function which destroys all the links in the list. It will then set the pointer to the list to null.
void ft_list_clear(t_list **begin_list) {
    t_list *current;
    t_list *next;

    current=*begin_list;
    while (current!=NULL) {
        next=current->next;
        free(current);
        current=next;
    }
    *begin_list=NULL;
}

int main(int argc, char **argv) {
    t_list *list;
    t_list *last;

    list=ft_list_push_params(argc, argv);
    if (list==NULL) return 1;

    last=ft_list_last(list);
    if (last!=NULL) printf("093 : %s", (char *)(last->data));
    else printf("093 : Void");

    printf("\n094 : *done*");
    ft_list_clear(&list);
    if (list==NULL) printf("\n095 : Void");
    else printf("\n095 : Not void");

    return 0;
}
