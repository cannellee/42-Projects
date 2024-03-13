// 42 projects
// Piscine - 030-032

#include <stdio.h>

//Ex 030 - Replicate the operation of the strstr function (man strstr).
char *ft_strstr(char *str, char *to_find) {
	while (*str!='\0') {
		char *start=str;
		char *pattern=to_find;

		while (*pattern!='\0' && *str==*pattern) {
			str++;
			pattern++;
		}

		if (*pattern=='\0') return start;
		str=start+1;
	}
	return NULL;
}

//Ex 031 - Replicate the operation of the strcmp function (man strcmp).
int ft_strcmp(char *s1, char *s2) {
    while (*s1!='\0' && *s2!='\0') {
        if (*s1>*s2) return 1;
        else if (*s1<*s2) return -1;
        s1++;
        s2++;
    }
    return 0;
}

//Ex 032 - Replicate the operation of the strncmp function (man strncmp).
int ft_strncmp(char *s1, char *s2, unsigned int n) {
    while (*s1!='\0' && *s2!='\0' && n>0) {
        if (*s1>*s2) return 1;
        else if (*s1<*s2) return -1;
        s1++;
        s2++;
        n--;
    }
    return 0;
}

int main() {
	char str[]="Hellollo"; //Change the value if you want
	char to_find[]="llo"; //Change the value if you want
	char* result=ft_strstr(str, to_find);
	(result!=NULL) ? printf("030 : index %ld", result - str) : printf("030 : not found");

    char s1[]="Hello"; //Change the value if you want
    char s2[]="Hel"; //Change the value if you want
    printf("\n031 : %d", ft_strcmp(s1, s2));

    unsigned int n=3; //Change the value if you want
    printf("\n032 : %d", ft_strncmp(s1, s2, n));
	return 0;
}
