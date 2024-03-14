// 42 projects
// Piscine - 033-035

#include <stdio.h>

//Ex 033 - Write a function that capitalises each letter of each word. Note: It must return str.
char *ft_strupcase(char *str) {
	char *ptr=str;
	while (*str!='\0') {
		if (*str>='a' && *str<='z') *str-=32;
		str++;
	}
	return ptr;
}

//Ex 034 - Write a function that capitalises each letter of each word. Note: It should return str.
char *ft_strlowcase(char *str) {
	char *ptr=str;
	while (*str!='\0') {
		if (*str>='A' && *str<='Z') *str+=32;
		str++;
	}
	return ptr;
}

//Ex 035 - Write a function to capitalise the first letter of each word and lowercase the rest of the word. Note: This should return str.
char *ft_strcapitalize(char *str) {
	char *ptr=str;
	int capitalize_next=1;
	while (*str!='\0') {
		if (*str>='a' && *str<='z') {
			if (capitalize_next) {
				*str-=32;
				capitalize_next=0;
			}
		} else if (*str>='A' && *str<='Z') {
			if (!capitalize_next) *str+=32;
			capitalize_next=0;
		} else capitalize_next=1;
		str++;
	}
	return ptr;
}

int main() {
	char upcase[]="in upcase";
	char lowcase[]="IN LOWCASE";
	char capitalize[]="iN CAPitalize";
	ft_strupcase(upcase);
	ft_strlowcase(lowcase);
	ft_strcapitalize(capitalize);
	printf("033 : %s", upcase);
	printf("\n034 : %s", lowcase);
	printf("\n035 : %s", capitalize);
	return 0;
}
