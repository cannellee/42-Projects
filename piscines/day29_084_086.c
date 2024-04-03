// 42 projects
// Piscine - 084-086

#include <stdio.h>
#include <stdlib.h>

//Ex 084 - Write a function ft_is_sort which returns 1 if the array is sorted and 0 if it is not. The function passed as a parameter will return a negative integer if the first argument is less than the second, 0 if they are equal and a positive integer otherwise.
int ft_is_sort(int *tab, int length, int(*f)(int, int)) {
	for (int i=0; i<length; i++) if (f(tab[i], tab[i+1])==1) return 0;
	return 1;
}

int comparison(int first, int second) {
	if (first<second) return -1;
	else if (first==second) return 0;
	else return 1;
}

//Ex 085 - Write a program called do-op. The operator character will correspond to the appropriate function in an array of pointers to functions.
int ft_add(int a, int b) {
    return a+b;
}

int ft_minus(int a, int b) {
    return a-b;
}

int ft_mult(int a, int b) {
    return a*b;
}

int ft_div(int a, int b) {
    if (b!=0) return a/b;
    else return 0;
}

int (*operations[])(int, int)={ft_add, ft_minus, ft_mult, ft_div};

int do_op(int value1, char operateur, int value2) {
    int result;
    switch (operateur) {
        case '+': result=operations[0](value1, value2); break;
        case '-': result=operations[1](value1, value2); break;
        case '*': result=operations[2](value1, value2); break;
        case '/': result=operations[3](value1, value2); break;
        default: result=0; break;
    }
    return result;
}

//Ex 086 - Write the function ft_sort_wordtab which sorts the words obtained using ft_split_whitespaces in ascii order. The sorting is done by exchanging the pointers in the array.
int is_separator(char c) {
    return (c==' ' || c=='\t' || c=='\n');
}

int count_words(char *str) {
    int count=0;
    int in_word=0;
    while (*str) {
        if (is_separator(*str)) in_word=0;
        else if (!in_word) {
            count++;
            in_word=1;
        }
        str++;
    }
    return count;
}

char **ft_split_whitespaces(char *str) {
    int word_count=count_words(str);
    char **result=(char **)malloc((word_count+1)*sizeof(char *));
    if (result==NULL) return NULL;
    int i=0;
    while (*str) {
        while (is_separator(*str)) str++;
        if (*str) {
            char *start=str;
            while (*str && !is_separator(*str)) str++;
            int word_length=str-start;
            result[i]=(char *)malloc((word_length+1)*sizeof(char));
            if (result[i]==NULL) {
                while (i>0) free(result[--i]);
                free(result);
                return NULL;
            }
            for (int j=0; j<word_length; j++) result[i][j]=start[j];
            result[i][word_length]='\0';
            i++;
        }
    }
    result[i]=0;
    return result;
}

void ft_sort_wordtab(char **tab) {
    int count=0;
    while (tab[count]!=NULL) count++;
    for (int i=0; i<count-1; i++) {
        for (int j=0; j<count-i-1; j++) {
            int k=0;
            while (tab[j][k]!='\0' && tab[j+1][k]!='\0' && tab[j][k]==tab[j+1][k]) k++;
            if (tab[j][k]>tab[j+1][k]) {
                char *temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}

int main() {
	int is_sort[]={1, 2, 3, 4, 5}; //Change the value if you want
	int length=5; //Change the value if you want
	printf("084 : %d", ft_is_sort(is_sort, length, &comparison));
	printf("\n085 : %d", do_op(5, '*', 4)); //Change the value if you want

	printf("\n086 : ");
	char test_string[]="This is a test string"; //Change the value if you want
	char **word_array=ft_split_whitespaces(test_string);
	ft_sort_wordtab(word_array);
	for (int i=0; word_array[i]!=NULL; i++) printf("%s\n", word_array[i]);
	int i=0;
	while (word_array[i]!=NULL) {
		free(word_array[i]);
		i++;
	}
	free(word_array);
	return 0;
}
