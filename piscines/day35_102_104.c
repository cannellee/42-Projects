// 42 projects
// Piscine - 102-104

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

//Ex 102 - Write the ft_list_merge function, which places the elements of a begin2 list at the end of another begin1 list. The creation of elements is not authorised.
void ft_list_merge(t_list **begin_list1, t_list *begin_list2) {
    t_list *temp=*begin_list1;
    if (!temp) *begin_list1=begin_list2; return;
    while (temp->next) temp=temp->next;
    temp->next=begin_list2;
}

//Ex 103 - Write the ft_list_sort function, which sorts the contents of the list in ascending order by comparing two links using a data comparison function.
void ft_list_sort(t_list **begin_list, int (*cmp)()) {
    t_list *current=*begin_list;
    t_list *index=NULL;
    void *temp_data;

    if (!current) return;

    while (current) {
        index=current->next;
        while (index) {
            if (cmp(current->data, index->data)>0) {
                temp_data=current->data;
                current->data=index->data;
                index->data=temp_data;
            }
            index=index->next;
        }
        current=current->next;
    }
}

//Ex 104 - Write the ft_list_reverse_fun function, which reverses the order of the elements in the list. Only sets of pointers are allowed.
void ft_list_reverse_fun(t_list *begin_list) {
    t_list *prev=NULL;
    t_list *current=begin_list;
    t_list *next=NULL;

    if (!current || !current->next) return;
    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    begin_list=prev;
}


int compare_int(void *a, void *b) {
    int *int_a=(int *)a;
    int *int_b=(int *)b;
    return (*int_a-*int_b);
}

void print_list(t_list *begin_list) {
    while (begin_list) {
        printf("%d ", *(int *)(begin_list->data));
        begin_list=begin_list->next;
    }
}

int main() {
    int data1=10, data2=20, data3=5, data4=15; //Change the values if you want

    t_list *list1=malloc(sizeof(t_list));
    t_list *list2=malloc(sizeof(t_list));
    list1->data=&data1;
    list1->next=malloc(sizeof(t_list));
    list1->next->data=&data2;
    list1->next->next=NULL;
    list2->data=&data3;
    list2->next=malloc(sizeof(t_list));
    list2->next->data=&data4;
    list2->next->next=NULL;

    ft_list_merge(&list1, list2);
    printf("102 : ");
    print_list(list1);

    ft_list_sort(&list1, compare_int);
    printf("\n103 : ");
    print_list(list1);

    ft_list_reverse_fun(list1);
    printf("\n104 : ");
    print_list(list1);

    free(list1->next->next);
    free(list1->next);
    free(list1);

    return 0;
}
