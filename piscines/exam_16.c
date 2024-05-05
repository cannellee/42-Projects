// 42 projects
// Exam - 16

//NOTE : RUN WITH ft_list.h !!

#include <stdio.h>
#include "ft_list.h"

//E16 - Write a function that takes a list and a pointer to function as parameters, and applies the function to each element in the list.
void ft_list_foreach(t_list *begin_list, void (*f)(void *)) {
    t_list *current=begin_list;
    while (current) {
        (*f)(current->data);
        current=current->next;
    }
}
