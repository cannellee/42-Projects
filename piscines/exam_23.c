// 42 projects
// Exam - 23

#include <stdio.h>
#include <stdlib.h>

//E23 - Write a function that takes an int and converts it to a string terminated by a null character, using the passed base as a parameter. This function returns the result as an array of chars that you need to allocate. The base is expressed by an integer that goes from 2 to 16. The characters making up the base are the digits from 0 to 9 followed by the uppercase letters A to F. For example, the base 4 would be "0123" and the base 16 "0123456789ABCDEF". If the base is 10 and the value is negative, the output string must be preceded by a '-' character. For any other base, the value is always considered unsigned.
char *ft_itoa_base(int value, int base) {
    if (base<2 || base>16) return NULL;

    int max_size=sizeof(int)*8+2;
    char *result=(char *)malloc(max_size * sizeof(char));
    if (result==NULL) return NULL;

    int negative=(value<0 && base==10) ? 1 : 0;
    unsigned int n=(negative) ? -value : value;

    char *base_chars="0123456789ABCDEF";

    int index=max_size-1;
    result[index--]='\0';

    do {
        result[index--]=base_chars[n % base];
        n/=base;
    } while (n>0);

    if (negative) result[index--]='-';

    char *final_result=&result[index+1];

    return final_result;
}