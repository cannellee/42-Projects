// 42 projects
// Exam - 10

#include <stdio.h>

//E10 - Write a program called union that takes two character strings as parameters and displays, without duplication, the characters that appear in one or the other. The characters will be displayed in the order in which they appear in the command line. The display must be followed by a line break. If the number of parameters transmitted is different from 2, the program displays \n.
void ft_union(char *str1, char *str2) {
    int ascii[256]={0};
    int i=0;

    while (str1[i]) {
        if (!ascii[(int)str1[i]]) {
            ascii[(int)str1[i]]=1;
            printf("%c", str1[i]);
        }
        i++;
    }

    i=0;
    while (str2[i]) {
        if (!ascii[(int)str2[i]]) {
            ascii[(int)str2[i]]=1;
            printf("%c", str2[i]);
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc==3) ft_union(argv[1], argv[2]);
    else printf("\n");
    printf("\n");
    return 0;
}