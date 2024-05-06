// 42 projects
// Exam - 17

//NOTE : RUN WITH ft_list.h !!

#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>

//E17 - Write a function ft_list_remove_if that deletes from the list all items whose data is "equal" to the reference data. cmp takes two void* and returns 0 when the 2 parameters are equal. 
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()) {
    t_list *current=*begin_list;
    t_list *prev=NULL;

    while (current!=NULL) {
        if ((*cmp)(current->data, data_ref)==0) {
            t_list *next_node=current->next;
            free(current);
            if (prev!=NULL) prev->next=next_node;
            else *begin_list=next_node;
            current=next_node;
        } else {
            prev=current;
            current=current->next;
        }
    }
}
