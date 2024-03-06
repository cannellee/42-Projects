// 42 projects
// Piscine - 012-014

#include <stdio.h>

//Ex 012 - This function divides the int's pointed to by a and b. The result of the division is stored in the int pointed to by a. The result of the remainder of the division is stored in the int pointed to by b.
void ft_ultimate_div_mod(int *a, int *b) {
	int temp_a=*a;
	*a=temp_a/(*b);
	*b=temp_a%(*b);
}

//Ex 013 - Write a function that displays the characters in a string one by one. The address of the first character in the string is contained in the pointer passed as a parameter to the function.
void ft_putstr(char *str) {
	while (*str!='\0') {
		printf(" %c", *str); //Remove space (and/or add a \n) if you want
		str++;
	}
}


//Ex 014 - Write a function that counts the number of characters in a string and returns the number found.
int ft_strlen(char *str) {
	int count=0;
	while (*str!='\0') {
		str++;
		count++;
	}
	return count;
}

int main() {
	//Ex 012 :
	int a=2; //Change the value of a if you want
	int *pa=&a;
	int b=4; //Change the value of b if you want
	int *pb=&b;
	ft_ultimate_div_mod(pa, pb);
	printf("012 : a=%d b=%d", a, b);

	//Ex 013 :
	char str[50]="Hi everyone !"; //Change the value if you want
	printf("\n013 :");
	ft_putstr(str);

	//Ex 014 :
	printf("\n014 :");
	printf("%d", ft_strlen(str));
	return 0;
}
