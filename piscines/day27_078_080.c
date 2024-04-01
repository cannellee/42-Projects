// 42 projects
// Piscine - 078-080

#include <stdio.h>
#include <stdlib.h>

//Ex 078 - Write a function ft_join that joins the array passed as a parameter to a single character string. The separator argument will act as a "glue" between the elements.
char *ft_join(char **tab, char *sep) {
    if (tab==NULL || sep==NULL) return NULL;

	int len_tab=0;
	while (tab[len_tab]!=NULL) len_tab++;

	int len_sep=0;
	while (sep[len_sep]!='\0') len_sep++;

	char *result=(char *)malloc(len_tab+(len_tab-1)*len_sep+1);
	if (result==NULL) return NULL;

	int i, j, k=0;
    for (i=0; i<len_tab; i++) {
    	for (j=0; tab[i][j]!='\0'; j++) result[k++]=tab[i][j];
    	if (i<len_tab-1) for (j=0; sep[j]!='\0'; j++) result[k++]=sep[j];
    }
    result[k]='\0';
    return result;
}

//Ex 079 - Write a function ft_unmatch that returns the value of the element in the array that has no corresponding pair. Note: Only one element will not have a pair. Two examples: In the array [1, 1, 2, 3, 4, 3, 4], the element that has no pair is 2. In the array [1, 1, 2, 4, 3, 4, 2, 3, 4], the element that has no pair is 4.
int ft_unmatch(int *tab, int length) {
	if (tab==NULL) return -1;
	int count;

	for (int i=0; i<length; i++) {
		count=0;
		for (int j=0; j<length; j++) if (i!=j && tab[i]==tab[j]) count++;
		if (count%2==0) return tab[i];
	}
	return -1;
}

//Ex 080 - Write a function ft_foreach which, for a given array of integers, will apply a function to all the elements in this array. This function will be applied in the order of the array.
void ft_foreach(int *tab, int length, void(*f)(int)) {
	for (int i=0; i<length; i++) f(tab[i]);
}

void ft_print_int(int num) {
	printf("%d ", num);
}


int main() {
    char *tab[]={"hello", "world", "how", "are", "you", NULL}; //Change the value if you want
    char *sep=" : "; //Change the value if you want
    char *result=ft_join(tab, sep);
    printf("078 : %s", result);
    free(result);

    int numbers[]={1, 1, 2, 3, 4, 3, 4}; //Change the value if you want
	  int length=7; //Change the value if you want
	  printf("\n079 : %d", ft_unmatch(numbers, length));

	  int arr[]={1, 2, 3, 4, 5, 6, 7}; //Change the value if you want
	  int length_func=7; //Change the value if you want
	  printf("\n080 : ");
	  ft_foreach(arr, length, &ft_print_int);

    return 0;
}
