// 42 projects
// Exam - 05

#include <stdio.h>

//E05 - Write a program that takes a string as a parameter, and transforms all its lowercase characters into uppercase and all its uppercase characters into lowercase. All other characters remain unchanged. You must display the result followed by an '\n'. If the number of parameters transmitted is not 1, the program displays '\n'.
int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("\n");
        return 0;
    }

    char *str=argv[1];
    while (*str!='\0') {
        if (*str>='a' && *str<='z') *str=*str-32;
        else if (*str>='A' && *str<='Z') *str=*str+32;
        printf("%c", *str);
        str++;
    }
    printf("\n");

    return 0;
}
