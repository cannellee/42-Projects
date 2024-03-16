// 42 projects
// Piscine - 039-041

#include <stdio.h>

//Ex 039 - Write a function which returns 1 if the string passed in parameter contains only upper case alphabetic characters and returns 0 if the function contains other types of characters. Note: It must return 1 if str is an empty string.
int ft_str_is_uppercase(char *str) {
	while (*str!='\0') {
		if (!(*str>='A' && *str<='Z')) return 0;
		str++;
	}
	return 1;
}

//Ex 040 - Write a function that returns 1 if the string passed as a parameter contains only displayable characters and returns 0 if the function contains other types of characters. Note: It must return 1 if str is an empty string.
int ft_str_is_printable(char *str) {
	while (*str!='\0') {
		if (!(*str>=32 && *str<=126)) return 0;
		str++;
	}
	return 1;
}


//Ex 041 - Replicate the operation of the strcat function (man strcat).
char *ft_strcat(char *dest, char *src) {
	char *ptr=dest;
	while (*ptr!='\0') ptr++;
	while (*src!='\0') *ptr++=*src++;
	*ptr='\0';
	return dest;
}


int main() {
	char is_upcase[]="HELLO"; //Change the value if you want
	char is_printable[]="Hello Hi!"; //Change the value if you want
	printf("039 : %d", ft_str_is_uppercase(is_upcase));
	printf("\n040 : %d", ft_str_is_printable(is_printable));
	char dest[50]="Hello, "; //Change the value if you want
	char src[]="world!"; //Change the value if you want
	ft_strcat(dest, src);
	printf("\n041 : %s", dest);
	return 0;
}