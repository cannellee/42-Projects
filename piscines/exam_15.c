// 42 projects
// Exam - 15

#include <stdio.h>

//E15 - Write a program that takes a strictly positive integer as parameter, and displays its decomposition into prime factors on the standard output, followed by an '\n'. The factors should be displayed in ascending order, separated by '*', so that the expression displayed gives the correct result. If the number of parameters is not 1, the program should display '\n'. The input, when passed, will always be a valid number with no extraneous characters.
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

void prime_factors(int n) {
    if (n<=1) {
        printf("%d", n);
        return;
    }

    int factor=2;
    while (n!=1) {
        if (n%factor==0) {
            printf("%d", factor);
            n/=factor;
            if (n!=1) printf("*");
        } else factor++;
    }
}

int main(int argc, char *argv[]) {
    if (argc==2) {
        int num=ft_atoi(argv[1]);
        if (num>0) prime_factors(num);
    }
    printf("\n");
    return 0;
}