// 42 projects
// Exam - 20

#include "list.h"

//E20 - This function must sort the passed list as the first parameter, using the CMP function pointer to determine the order to apply, and return a pointer to the first item in the sorted list. Duplicates must be preserved. Entries will always be consistent. You must use the t_List type described in the list.h file provided to you. Functions passed as cmp will always return a value other than 0 if a and b are in the correct order, otherwise they will return 0.
t_list *sort_list(t_list *lst, int (*cmp)(int, int)) {
    if (lst==NULL || lst->next==NULL) return lst;
    
    t_list *sorted=NULL;
    t_list *current=lst;
    
    while (current!=NULL) {
        t_list *next=current->next;
        sorted=insert_sorted(sorted, current, cmp);
        current=next;
    }
    
    return sorted;
}

t_list *insert_sorted(t_list *sorted, t_list *node, int (*cmp)(int, int)) {
    if (sorted==NULL || cmp(*(int *)node->data, *(int *)sorted->data)) {
        node->next=sorted;
        return node;
    }
    
    t_list *current=sorted;
    while (current->next!=NULL && cmp(*(int *)current->next->data, *(int *)node->data)) {
        current=current->next;
    }
    
    node->next=current->next;
    current->next=node;
    
    return sorted;
}
