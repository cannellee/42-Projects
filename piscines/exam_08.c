// 42 projects
// Exam - 08

#include <stdio.h>

//E08 - Write a function that takes a byte, inverts it bit by bit (as in the example) and returns the result.
void print_bits(unsigned char octet) {
    for (int i=7; i>=0; i--) printf("%d", (octet>>i)&1);
}

unsigned char reverse_bits(unsigned char octet) {
    unsigned char result=0;
    for (int i=0; i<8; i++) result|=((octet>>i)&1)<<(7-i);
    return result;
}

int main() {
    unsigned char octet=65;
    printf("E08 : ");
    print_bits(reverse_bits(octet));
    return 0;
}
