// 42 projects
// Piscine - 015-017

#include <stdio.h>

//Ex 015 - Write a function that inverts a string of characters.
char *ft_strrev(char *str) {
	int count=0;
	while (str[count]!='\0') {
		count++;
	}
	int start=0;
	for (int i=0; i<count/2; i++) {
		char temp=str[i];
		str[i]=str[count-1-i];
		str[count-1-i]=temp;
	}
	return str;
}


//Ex 016 - Replicate the operation of the atoi function (man atoi).
int ft_atoi(char *str) {
	int result=0;
	int sign=1;

	while (*str==' ' || (*str>='\t' && *str<='\r')) {
		str++;
	}

	if (*str=='-') {
		sign=-1;
		str++;
	} else if (*str=='+') str++;

	while (*str>='0' && *str<='9') {
		result=result*10+(*str-'0');
		str++;
	}
	return sign*result;
}


//Ex 017 - Write a function that sorts an array of integers in ascending order. The parameters are a pointer to integer and the number of integers in the array.
void ft_sort_integer_table(int *tab, int size) {
	for (int i=0; i<size-1; i++) {
		for (int j=0; j<size-1-i; j++) {
			if (tab[j]>tab[j+1]) {
				int temp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=temp;
			}
		}
	}
}


int main() {
	//Ex 015 :
	char str[]="Hello c'est moi"; //Change the value if you want
	ft_strrev(str);
	printf("015 : %s", str);

	//Ex 016 :
	char str2[]="12345"; //Change the value if you want
	printf("\n016 : %d", ft_atoi(str2));

	//Ex 017 :
	int tab[]={2, 3, 5, 4, 9, 1}; //Change the value if you want
	int size=sizeof(tab)/sizeof(tab[0]);
	ft_sort_integer_table(tab, size);
	printf("\n017 :");
	for (int i=0; i<size; i++) {
        printf(" %d", tab[i]);
    }
	return 0;
}