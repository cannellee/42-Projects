// 42 projects
// Exam - 07

#include <stdio.h>

//E07 - Write a function that takes a byte and displays it in binary, without a newline at the end.
void print_bits(unsigned char octet) {
    for (int i=7; i>=0; i--) printf("%d", (octet>>i)&1);
}

int main() {
    unsigned char octet=65;
    printf("E07 : ");
    print_bits(octet);
    return 0;
}
