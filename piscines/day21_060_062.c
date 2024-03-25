// 42 projects
// Piscine - 060-062

//NOTE : RUN WITH ft_boolean.h & ft_abs.h !!

#include <stdio.h>
#include <stdlib.h>
#include "ft_boolean.h"
#include "ft_abs.h"

//Ex 060 - Write a function that splits a character string according to another character string. Each character in the charset string must be used as a separator. The function returns an array where each cell contains the address of a character string between two separators. The last element of the array must be 0 to mark the end of the array. Note: There must be no empty strings in your array. Draw the appropriate conclusions from this. The string transmitted cannot be modified.
int is_charset(char c, char *charset) {
	while (*charset) {
		if (c==*charset) return 1;
		charset++;
	}
	return 0;
}

char **ft_split(char *str, char *charset) {
	int len_str=0;
	while (str[len_str]!='\0') len_str++;

	char **result=(char **)malloc((len_str+1)*sizeof(char *));
	if (result==NULL) return NULL;

	int i=0;
	while (*str) {
		while (*str && is_charset(*str, charset)) str++;
		if (!*str) break;

		char *start=str;
		while (*str && !is_charset(*str, charset)) str++;
		int word_length=str-start;
		result[i]=(char *)malloc((word_length+1)*sizeof(char));
		if (result[i]==NULL) {
			while (i>0) free(result[--i]);
			free(result);
			return NULL;
		}
		char *current_word=result[i];
        for (int j=0; j<word_length; j++) current_word[j]=start[j];
        current_word[word_length]='\0';
        i++;
    }
    result[i]=0;
    return result;
}

//Ex 061 - Write a file ft_boolean.h. This program should display: I have an even number of arguments. or I have an odd number of arguments. followed by a line break, in the appropriate case.
void ft_putstr(char *str){
	while (*str) {
		printf("%c", *str);
		str++;
	}
}

t_bool ft_is_even(int nbr) {
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

//Ex 062 - Write an ABS macro which replaces its parameter with its absolute value: #define ABS(Value)
void test_abs() {
	int num=-10;
	int result=ABS(num);
	printf("Absolute value of %d is %d\n", num, result);
}

int main(int argc, char **argv) {
    char str[]="Hello, world! This is a test string."; //Change the value if you want
    char charset[]=" ,.!"; //Change the value if you want
    char **words=ft_split(str, charset);
    if (words!=NULL) {
        for (int i=0; words[i]!=NULL; i++) {
            printf("\"%s\", \n", words[i]);
            free(words[i]);
        }
        free(words);
    }

    printf("\n061 : ");
    (void)argv;
	if (ft_is_even(argc-1)==TRUE) ft_putstr(EVEN_MSG);
	else ft_putstr(ODD_MSG);

	printf("\n062 : ");
	test_abs();
	return (SUCCESS);
}
