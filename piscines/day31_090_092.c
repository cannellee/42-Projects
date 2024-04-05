// 42 projects
// Piscine - 090-092

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

//Ex 090 - Write the ft_list_push_back function, which adds a new element of type t_list to the end of the list. It must assign data to the supplied parameter. If necessary, it will update the pointer to the start of the list.
void ft_list_push_back(t_list **begin_list, void *data) {
    t_list *new_elem=(t_list*)malloc(sizeof(t_list));
    if (new_elem==NULL) return;
    new_elem->data=data;
    new_elem->next=NULL;
    if (*begin_list==NULL) {
        *begin_list=new_elem;
        return;
    }
    t_list *current=*begin_list;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->next=new_elem;
}

//Ex 091 - Write the ft_list_push_front function, which adds a new element of type t_list to the beginning of the list. It must assign data to the parameter provided. If necessary, it will update the pointer to the start of the list.
void ft_list_push_front(t_list **begin_list, void *data) {
    t_list *new_elem=(t_list*)malloc(sizeof(t_list));
    if (new_elem==NULL) return;
    new_elem->data=data;
    new_elem->next=*begin_list;
    *begin_list=new_elem;
}

//Ex 092 - Write the ft_list_size function, which returns the number of elements in the list.
int ft_list_size(t_list *begin_list) {
    int size=0;
    t_list *current=begin_list;
    while (current!=NULL) {
        size++;
        current=current->next;
    }
    return size;
}


int main() {
    t_list *list=NULL;
    ft_list_push_back(&list, "Elmt 1"); //Change the value if you want
    ft_list_push_back(&list, "Elmt 2"); //Change the value if you want
    ft_list_push_back(&list, "Elmt 3"); //Change the value if you want
    printf("090 & 091 & 092 : \nSize : %d -> ", ft_list_size(list));
    ft_list_push_front(&list, "New Elmt");
    printf("%d\n", ft_list_size(list));

    printf("Content :");
    t_list *current=list;
    while (current!=NULL) {
        printf(" %s.", (char *)current->data);
        current=current->next;
    }

    return 0;
}
