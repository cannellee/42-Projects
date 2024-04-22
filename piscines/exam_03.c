// 42 projects
// Exam - 03

#include <stdio.h>

//E03 - Write a repeat_alpha program that takes a string and displays it by repeating each alphabetic character as many times as its index in the alphabet, followed by a newline. a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc... Case does not change. If the number of arguments is not 1, just display a newline.
int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("\n");
        return 0;
    }

    char *str=argv[1];
    int i=0;
    while (str[i]) {
        if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            char c=str[i];
            int j;
            if (c>='a' && c<='z') for (j=0; j<c-'a'+1; j++) printf("%c", c);
            else for (j=0; j<c-'A'+1; j++) printf("%c", c);
        } else printf("%c", str[i]);
        i++;
    }
    printf("\n");
    return 0;
}
