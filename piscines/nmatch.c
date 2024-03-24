// 42 projects
// Mini-projects - 1.1

#include <stdio.h>

//MP1.1 - The aim of the function is to count the number of times two strings match. When there are two or more stars, several combinations of strings may be suitable. nmatch will calculate and return the total number of such combinations.
int nmatch(char *str, char *pattern) {
    if (*pattern=='\0') return (*str=='\0') ? 1 : 0;

    if (*str=='\0') {
        while (*pattern=='*') pattern++;
        return (*pattern=='\0') ? 1 : 0;
    }

    int len_str=0;
    while (str[len_str]) len_str++;

    if (*pattern=='*') {
        int count=0;
        for (int i=0; i<=len_str; i++) count+=nmatch(str+i, pattern+1);
        return count;
    }

    if (*pattern==*str || *pattern=='?') return nmatch(str+1, pattern+1);
    return 0;
}

int main() {
    char str[]="abacd"; //Change the value if you want
    char pattern[]="*a**"; //Change the value if you want
    printf("Nombre de correspondances: %d\n", nmatch(str, pattern));
    return 0;
}
