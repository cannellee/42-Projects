// 42 projects
// Exam - 19

#include <stdio.h>

//E19 - This function must sort (in place!) the 'tab' ints array, which contains exactly 'size' entries, in ascending order. Duplicates must be preserved. Entries will always be consistent.
void sort_int_tab(int *tab, unsigned int size) {
    for (unsigned int i=0; i<size-1; ++i) {
        for (unsigned int j=0; j<size-i-1; ++j) {
            if (tab[j]>tab[j+1]) {
                int temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

int main() {
    int tab[]={5, 2, 8, 5, 9, 1, 2};
    unsigned int size=sizeof(tab)/sizeof(tab[0]);
    
    for (unsigned int i=0; i<size; ++i) printf("%d ", tab[i]);
    printf("->");
    sort_int_tab(tab, size);
    for (unsigned int i=0; i<size; ++i) printf("%d ", tab[i]);
    
    return 0;
}
