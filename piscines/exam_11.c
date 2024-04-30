// 42 projects
// Exam - 11

#include <stdio.h>

//E11 - Write a program that takes a string of characters as a parameter, and displays this string with exactly one space between each word, with no spaces or tabs either at the beginning or end of the string, followed by an '\n'. A “word” is a portion of a character string delimited either by spaces and/or tabs, or by the beginning/end of the string. If the number of parameters transmitted is other than 1, or if there are no words to display, the program displays '\n'.
void epur_str(char *str) {
    int i=0;
    int word_start=-1;
    int word_end=-1;

    while (str[i] && (str[i]==' ' || str[i]=='\t')) i++;

    while (str[i]) {
        if (str[i]!=' ' && str[i]!='\t') {
            if (word_start==-1) word_start=i;
            word_end=i;
        } else {
            if (word_start!=-1) {
                for (int j=word_start; j<=word_end; j++) printf("%c", str[j]);
                word_start=-1;
                word_end=-1;
                printf(" ");
            }
        }
        i++;
    }

    if (word_start!=-1) for (int j=word_start; j<=word_end; j++) printf("%c", str[j]);
}

int main(int argc, char *argv[]) {
    if (argc==2) epur_str(argv[1]);
    printf("\n");
    return 0;
}