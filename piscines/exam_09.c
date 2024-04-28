// 42 projects
// Exam - 09

#include <stdio.h>

//E09 - Write a function that takes a byte, inverts its halves (as in the example), then returns the result.
void print_bits(unsigned char octet) {
    for (int i=7; i>=0; i--) printf("%d", (octet>>i)&1);
}

unsigned char swap_bits(unsigned char octet) {
    return ((octet&0xF0)>>4) | ((octet&0x0F)<<4);
}

int main() {
    unsigned char octet=65;
    printf("E09 : ");
    print_bits(octet);
    printf(" -> ");
    print_bits(swap_bits(octet));
    return 0;
}