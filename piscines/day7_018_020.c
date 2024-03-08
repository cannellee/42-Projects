// 42 projects
// Piscine - 018-020

#include <stdio.h>

//Ex 018 - Write an iterative function that returns a number. This number is the result of the factorial operation based on the number passed in parameter. In the event of an error, the function should return 0. Note: Results in less than 2 seconds.
int ft_iterative_factorial(int nb) {
	int result=1;
	for (int i=1; i<nb+1; i++) {
		result*=i;
	}
	return result;
}

//Ex 019 - Write a recursive function that returns the factorial of the number passed in parameter. It must handle the same cases as the previous function.
int ft_recursive_factorial(int nb) {
	if (nb==0) return 1;
	else return nb*ft_recursive_factorial(nb-1);
}

//Ex 020 - Write an iterative function that returns a power of a number. A power less than 0 will return 0. Overflows should not be handled. Note: Results in less than 2 seconds.
int ft_iterative_power(int nb, int power) {
	if (power<0) return 0;
	int number=nb;
	for (int i=1; i<power; i++) {
		nb*=number;
	}
	return nb;
}

int main() {
	printf("018 : %d", ft_iterative_factorial(5)); //Change the value into () if you want
	printf("\n019 : %d", ft_recursive_factorial(5)); //Change the value into () if you want
	printf("\n020 : %d", ft_iterative_power(2, 3)); //Change the value into (,) if you want
	return 0;
}
