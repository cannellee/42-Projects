// 42 projects
// Exam - 24

#include <stdio.h>

//E24 - Write a function that takes and displays the pointed memory.
void print_memory(const void *addr, size_t size) {
    const unsigned char *ptr=addr;
    size_t i;

    for (i=0; i<size; i++) {
        printf("%02x", ptr[i]); 
        if ((i+1)%4==0) printf(" ");
        if ((i+1)%16==0) printf("\n");
    }
    printf("\n");
}

int main() {
    int tab[10]={0, 23, 150, 255, 12, 16, 21, 42};
    print_memory(tab, sizeof(tab));
    return 0;
}
