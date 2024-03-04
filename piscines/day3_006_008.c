// 42 projects
// Piscine - 006-008

#include <stdio.h>
#include <math.h>

//Ex 006 - Write a function that displays a number passed as a parameter. The function must be able to display all the possible values in a variable of type int.
void ft_putnbr(int nb) {
	printf("%d", nb);
}

//Ex 007 - Write a function that displays all the different combinations of n (0<n<10) digits in ascending order.
void ft_print_combn(int n) {
	if (n>10 || n<0) printf("Error");
	for (int i=00; i<pow(10, n); i++) {
		printf("%d ", i);
	}
}

//Ex 008 - Write a function that takes a pointer to int as a parameter and sets the value of int to 42.
void ft_ft(int *nbr) {
	*nbr=42;
}

int main() {
	printf("006 : ");
	ft_putnbr();  //Add a number into ()
	printf("\n007 : ");
	ft_print_combn(); //Add a number into ()

	int a=0;
	int *ptr=&a;
	ft_ft(ptr);
	printf("\n008 : %d", *ptr);
}
