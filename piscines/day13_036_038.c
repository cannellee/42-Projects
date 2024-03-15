// 42 projects
// Piscine - 036-038

#include <stdio.h>

//Ex 036 - Write a function that returns 1 if the string passed as a parameter contains only alphabetic characters and returns 0 if the function contains other types of characters. Note: It should return 1 if str is an empty string.
int ft_str_is_alpha(char *str) {
	while (*str!='\0') {
		if (!((*str>='A' && *str<='Z') || (*str>='a' && *str<='z'))) return 0;
		str++;
	}
	return 1;
}

//Ex 037 - Write a function which returns 1 if the string passed in parameter contains only numbers and returns 0 if the function contains other types of characters. Note: It must return 1 if str is an empty string.
int ft_str_is_numeric(char *str) {
	while (*str!='\0') {
		if (!(*str>='0' && *str<='9')) return 0;
		str++;
	}
	return 1;
}

//Ex 038 - Write a function which returns 1 if the string passed as a parameter contains only lowercase alphabetic characters and returns 0 if the function contains other types of characters. Note: It must return 1 if str is an empty string.
int ft_str_is_lowercase(char *str) {
	while (*str!='\0') {
		if (!(*str>='a' && *str<='z')) return 0;
		str++;
	}
	return 1;
}

int main() {
	char is_alpha[]="Hello"; //Change the value if you want
	char is_num[]="123"; //Change the value if you want
	char is_lowcase[]="hello"; //Change the value if you want
	printf("036 : %d", ft_str_is_alpha(is_alpha));
	printf("\n037 : %d", ft_str_is_numeric(is_num));
	printf("\n038 : %d", ft_str_is_lowercase(is_lowcase));
	return 0;
}
