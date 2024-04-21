// 42 projects
// Exam - 02

#include <stdio.h>

//E02 - Write a program that displays the alphabet upside down, with every 2nd letter in lower case, and the rest in upper case, followed by an '\n'.
int main() {
    for(char c='z'; c>='a'; c--) {
        if((c-'a')%2==0) printf("%c", c-('a'-'A'));
        else printf("%c", c);
    }
    printf("\n");
    return 0;
}
