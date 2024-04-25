// 42 projects
// Exam - 06

#include <stdio.h>
#include <stdbool.h>

//E06 - Write a program that takes a string of characters as a parameter, and displays the last word of that string, followed by an '\n'. A “word” is a portion of a character string delimited either by spaces and/or tabs, or by the beginning/end of the string. If the number of parameters transmitted is other than 1, or if there are no words to display, the program displays '\n'.
bool isSpaceOrTab(char c) {
    return c==' ' || c=='\t';
}

void lastWord(const char *str) {
    const char *end=str;
    while (*end!='\0') end++;
    if (end==str) {
        printf("\n");
        return;
    }

    while (end>str && isSpaceOrTab(*(end-1))) end--;
    if (end==str) {
        printf("\n");
        return;
    }

    const char *start=end;
    while (start>str && !isSpaceOrTab(*(start-1))) start--;
    while (start<end) printf("%c", *start++);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("\n");
        return 0;
    }

    lastWord(argv[1]);
    return 0;
}
