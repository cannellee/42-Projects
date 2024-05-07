// 42 projects
// Exam - 18

#include <stdio.h>

//E18 - Write a program that takes a string as a parameter, and that displays this string by rotating a word from right to left. Thus, the first word will be the last and the others remain in order. We call "word" a portion of the string of characters delimited either by spaces and/or tabs, or by the beginning/end of the string. The words will be displayed separated by a single space. If the number of parameters is less than 1, the program should display '\n'.
int ft_strlen(char *str) {
    int len=0;
    while (str[len]) len++;
    return len;
}

void rostring(char *str) {
    int i=0;
    int start=0;
    int end=0;
    int len=ft_strlen(str);

    while (str[i] && (str[i]==' ' || str[i]=='\t')) i++;
    start=i;
    while (str[i] && str[i]!=' ' && str[i]!='\t') i++;
    end=i;
    while (str[i]) {
        if (str[i] && (str[i]==' ' || str[i]=='\t')) {
            while (str[i] && (str[i]==' ' || str[i]=='\t')) i++;
            start=i;
            while (str[i] && str[i]!=' ' && str[i]!='\t') i++;
            end=i;
        }
        else i++;
    }
    while (start<end) {
        while (str[start] && str[start]==' ') start++;
        while (str[start] && str[start]!=' ') {
            printf("%c", str[start]);
            start++;
        }
        if (start<end) printf(" ");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc<2) printf("\n");
    else rostring(argv[1]);
    return 0;
}
