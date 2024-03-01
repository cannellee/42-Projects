// 42 projects
// Piscine - 000-002

#include <stdio.h>

//Ex 000 - Write a function that displays the alphabet in lower case on a single line, in ascending order, starting with the letter 'a'.
void ft_print_alphabet(void) {
	char letter='a';
	printf("000 - Lower case alphabet :");
	while (letter<='z') {
		printf(" %c", letter);
		letter++;
	}
	printf("\n");
}

//Ex 001 - Write a function that displays the alphabet in lower case on a single line, in descending order, starting with the letter 'z'.
void ft_print_reverse_alphabet(void) {
	char letter='z';
	printf("001 - Lower case alphabet :");
	while (letter>='a') {
		printf(" %c", letter);
		letter--;
	}
	printf("\n");
}

//Ex 002 - Write a function that displays all the numbers on a single line, in ascending order.
void ft_print_numbers(void) {
	printf("002 - Number in ascending order :");
	for (int i=0; i<10; i++) {
		printf(" %d", i);
	}
	printf("\n");
}


int main() {
	ft_print_alphabet();
	ft_print_reverse_alphabet();
	ft_print_numbers();
	return 0;
}
