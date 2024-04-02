// 42 projects
// Piscine - 081-083

#include <stdio.h>
#include <stdlib.h>

//Ex 081 - Write a function ft_map which, for a given array of integers, applies a function to all the elements of this array (in order) and returns an array of all the return values. This function will be applied in the order of the array.
int *ft_map(int *tab, int length, int(*f)(int)) {
	int *result=(int *)malloc(length+1);
	if (result==NULL) return NULL;
	for (int i=0; i<length; i++) result[i]=f(tab[i]);
	return result;
}

int double_num(int num) {
	return num*2;
}


//Ex 082 - Write a function ft_any which returns 1 if, by passing it to the function f, at least one element of the array returns 1, 0 otherwise. The array will be delimited by 0.
int ft_any(char **tab, int(*f)(char*)) {
	while (*tab!=0) {
		if (f(*tab)==1) return 1;
		tab++;
	}
	return 0;
}

int a_first_letter(char *letter) {
	if (*letter=='a') return 1;
	return 0;
}

//Ex 083 - Write a function ft_count_if which returns the number of elements in the array which, when passed to the function f, return 1. The array will be delimited by 0.
int ft_count_if(char **tab, int(*f)(char*)) {
	int count=0;
	for (int i=0; tab[i]!=NULL; i++) if (f(tab[i])==1) count++;
	return count;
}

int contains_b_or_d(char* str) {
    while (*str!='\0') {
        if (*str=='b' || *str=='d') return 1;
        str++;
    }
    return 0;
}


int main() {
	int tab[]={1, 2, 3, 4, 5};
	int length=5;
	printf("081 : ");
	int *result=ft_map(tab, length, &double_num);
	for (int i=0; i<length; i++) printf("%d ", result[i]);
	free(result);

	char *words[]={"apple", "banana", "orange", "grape", "avocado", NULL};
	printf("\n082 : %d", ft_any(words, &a_first_letter));

	printf("\n083 : %d", ft_count_if(words, &contains_b_or_d));

	return 0;
}
