// 42 projects
// Piscine - 021-023

#include <stdio.h>

//Ex 021 - Write a recursive function that returns a power of a number. It must handle the same cases as the previous function.
int ft_recursive_power(int nb, int power) {
	if (power<0) return 0;
	if (power==0) return 1;
	return nb*ft_recursive_power(nb, power-1);
}

//Ex 022 - Write a recursive function ft_fibonacci that returns the nth element of the Fibonacci sequence, the first element being at index 0. We will assume that the Fibonacci sequence begins with 0, 1, 1, 2. If index is less than 0, the function returns -1.
int ft_fibonacci(int index) {
	if (index<0) return -1;
	else if (index==0) return 0;
	else if (index==1 || index==2) return 1;
	else return ft_fibonacci(index-1)+ft_fibonacci(index-2);
}

//Ex 023 - Write a function that returns the integer square root of a number if it exists, 0 if the square root is not integer. Note: Result in less than 2 seconds
int ft_sqrt(int nb) {
	int i=1;
	while (i<=nb) {
		if (i*i==nb) return i;
		i++;
	}
	return 0;
}

int main() {
	printf("021 : %d", ft_recursive_power(2, 3));
	printf("\n022 : %d", ft_fibonacci(3));
	printf("\n 023 : %d", ft_sqrt(5));
}