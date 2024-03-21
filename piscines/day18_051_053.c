// 42 projects
// Piscine - 051-053

#include <stdio.h>
#include <stdlib.h>

//Ex 051 - Write a program that displays the arguments received on the command line in reverse order. You must display all the arguments except argv[0]. All arguments should be on a separate line.
void ft_rev_params(int argc, char **argv) {
    for (int i=argc-1; i>0; i--)  printf("%s\n", argv[i]);
}

//Ex 052 - Write a program that displays the arguments received on the command line sorted in ascii order. You must display all the arguments except argv[0]. All arguments should be on a separate line.
int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1==*s2) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1-*(unsigned char *)s2;
}

void ft_sort_params(int argc, char **argv) {
    for (int i=2; i<argc; i++) {
        char *key=argv[i];
        int j=i-1;
        while (j>=1 && ft_strcmp(argv[j], key)>0) {
            argv[j+1]=argv[j];
            j--;
        }
        argv[j+1]=key;
    }
    for (int i=1; i<argc; i++) printf("%s\n", argv[i]);
}

//Ex 053 - Reproduce the operation of the strdup function identically (man strdup).
char *ft_strdup(char *src) {
    int len=0;
    while (src[len]!='\0') len++;
    char *dup=(char *)malloc(len + 1);
    if (dup==NULL) return NULL;
    for (int i=0; i<=len; i++) dup[i] = src[i];
    return dup;
}

int main(int argc, char **argv) {
    printf("051 : ");
    ft_rev_params(argc, argv);
    printf("\n052 : ");
    ft_sort_params(argc, argv);
    printf("\n053 : ");
    char *src="Hello, world!"; //Change the value if you want
    char *dup=ft_strdup(src);
    if (dup!=NULL) {
        printf("Original: %s\nDuplicate: %s\n", src, dup);
        free(dup);
    } else printf("Fail.\n");

    return 0;
}
