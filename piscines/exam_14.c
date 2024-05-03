// 42 projects
// Exam - 14

#include <stdio.h>

//E14 - Write a program to display the multiplication table for a number passed as a parameter. The parameter will always be a strictly positive number that fits into an int, and this number multiplied by 9 will also fit into an int. If there is no parameter, the program displays \n.
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

void print_multiplication_table(int n) {
    if (n<=0) return;
    for (int i=1; i<=9; i++) printf("%d*%d=%d\n", i, n, i * n);
}

int main(int argc, char *argv[]) {
    if (argc==2) {
        int num=ft_atoi(argv[1]);
        print_multiplication_table(num);
    }
    printf("\n");
    return 0;
}
