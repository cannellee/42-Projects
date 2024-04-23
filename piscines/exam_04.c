// 42 projects
// Exam - 04

#include <stdio.h>

//E04 - Write a program called rotone, which takes a string of characters as a parameter, and displays this string by replacing each alphabetical character with the next character in alphabetical order. z' becomes 'a' and 'Z' becomes 'A'. Upper case remains upper case, lower case remains lower case. The display always ends with a line break. If the number of parameters transmitted is not 1, the program displays '\n'.
void replace_alphabetical(char *str) {
    if (str==NULL) {
        printf("\n");
        return;
    }

    while (*str!='\0') {
        if ((*str>='a' && *str<'z') || (*str>='A' && *str<'Z')) *str+=1;
        else if (*str=='z') *str='a';
        else if (*str=='Z') *str='A';
        str++;
    }
    printf("%s\n", str);
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("\n");
        return 1;
    }
    replace_alphabetical(argv[1]);
    return 0;
}
