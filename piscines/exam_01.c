// 42 projects
// Exam - 01

#include <stdio.h>

//E01 - Write a program that takes a string of characters as a parameter, and displays on standard output the first character 'z' encountered in the string, followed by '\n'. If no 'z' is encountered in the string, the program displays 'z' followed by '\n'. If the number of parameters is not 1, the program displays 'z' followed by '\n'.
int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("z\n");
        return 0;
    }

    char *str=argv[1];
    while (*str!='\0') {
        if (*str=='z') {
            printf("z\n");
            return 0;
        }
        str++;
    }

    printf("z\n");
    return 0;
}
