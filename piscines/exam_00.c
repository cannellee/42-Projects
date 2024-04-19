// 42 projects
// Exam - 00

#include <stdio.h>

//E00 - Write a program that takes strings, and displays its last argument followed by a newline. If there is less than one argument, the program just displays a newline.
int main(int argc, char *argv[]) {
    if (argc<2) printf("\n");
    else printf("%s\n", argv[argc-1]);
    return 0;
}
