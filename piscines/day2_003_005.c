// 42 projects
// Piscine - 003-005

#include <stdio.h>

//Ex 003 - Write a function that displays 'N' or 'P' depending on the sign of the integer passed as a parameter. If n is negative then display 'N'. If n is positive or zero then display 'P'.
void ft_is_negative(int n) {
	(n>=0) ? printf("P") : printf("N");
}

//Ex 004 - Write a function that displays, in ascending order, all the different combinations of three different digits.
void ft_print_comb(void) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<10; k++) {
				if (i!=j && i!=k && j!=k) printf(" %d%d%d", i, j, k);
			}
		}
	}
}

//Ex 005 - Write a function that displays all the different combinations of two numbers between 0 and 99, in ascending order.
void ft_print_comb2(void) {
	int number_one=00;
	int number_two=00;
	while (number_one<100) {
		while (number_two<100) {
			if (number_one<10 && number_two<10) printf("0%d 0%d,  ", number_one, number_two);
			else if (number_one<10) printf("0%d %d,  ", number_one, number_two);
			else if (number_two<10) printf("%d 0%d,  ", number_one, number_two);
			else printf("%d %d,  ", number_one, number_two);
			number_two++;
		}
		number_one++;
		number_two=0;
	}
}

int main() {
	printf("003 : ");
	ft_is_negative(); //Add a number into ()
	printf("\n\n004 : ");
	ft_print_comb();
	printf("\n\n005 : ");
	ft_print_comb2();
	return 0;
}