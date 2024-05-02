// 42 projects
// Exam - 13

#include <stdio.h>

//E13 - Write a program that takes a positive or zero integer expressed in base 10, and displays it in base 16 (lowercase) followed by a newline. If the number of parameters is not 1, the program displays a newline.
int ft_atoi(char *str) {
    int result=0;
    int sign=1;
    int i=0;

    while (str[i]==' ' || str[i]=='\t' || str[i]=='\n') i++;

    if (str[i]=='-' || str[i]=='+') {
        sign=(str[i]=='-') ? -1 : 1;
        i++;
    }

    while (str[i]>='0' && str[i]<='9') {
        result=result*10+(str[i]-'0');
        i++;
    }

    return result*sign;
}

void print_hex(int n) {
    char hex_digits[]="0123456789abcdef";

    if (n==0) {
        printf("0");
        return;
    }

    char result[20];
    int i=0;

    while (n!=0) {
        result[i++]=hex_digits[n%16];
        n/=16;
    }

    for (int j=i-1; j>=0; j--) printf("%c", result[j]);
}

int main(int argc, char *argv[]) {
    if (argc==2) {
        int num=ft_atoi(argv[1]);
        print_hex(num);
    }
    printf("\n");
    return 0;
}