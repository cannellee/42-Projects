// 42 projects
// Exam - 12

#include <stdio.h>

//E12 - Write a program that takes two strings representing non-zero positive integers as parameters. The integers represented by the parameters fit into an int. Display the greatest common divisor of these two numbers, followed by '\n'. The PGCD is always a positive non-zero integer. If the number of parameters is not 2, the program displays only '\n'.
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

int ft_abs(int x) {
    return (x<0) ? -x : x;
}

int pgcd(int a, int b) {
    int temp;
    while (b!=0) {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main(int argc, char *argv[]) {
    if (argc==3) {
        int a=ft_atoi(argv[1]);
        int b=ft_atoi(argv[2]);

        if (a!=0 && b!=0) printf("%d\n", pgcd(ft_abs(a), ft_abs(b)));
        else printf("\n");
    } else printf("\n");
    return 0;
}