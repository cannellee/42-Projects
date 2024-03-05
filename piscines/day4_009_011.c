// 42 projects
// Piscine - 009-011

#include <stdio.h>

//Ex 009 - Write a function that takes a pointer to a pointer to a pointer to a pointer to a pointer to a pointer to a pointer to a pointer to a pointer to a pointer to an int as a parameter and gives the int the value 42.
void ft_ultimate_ft(int *********nbr) {
	*********nbr=42;
}

//Ex 010 - Write a function that exchanges the contents of two integers whose addresses are given as parameters.
void ft_swap(int *a, int *b) {
	int c=*a;
	*a=*b;
	*b=c;
}

//Ex 011 - This function divides the two parameters a and b and stores the result in the int pointed to by div. It also stores the remainder of the division of a and b in the int pointed to by mod.
void ft_div_mod(int a, int b, int *div, int *mod) {
	*div=a/b;
	*mod=a%b;
}

int main() {
	//Ex 009 :
	int a;
    int *ptr1=&a;
    int **ptr2=&ptr1;
    int ***ptr3=&ptr2;
    int ****ptr4=&ptr3;
    int *****ptr5=&ptr4;
    int ******ptr6=&ptr5;
    int *******ptr7=&ptr6;
    int ********ptr8=&ptr7;
    int *********ptr9=&ptr8;
	ft_ultimate_ft(ptr9);
	printf("009 : %d", a);

	//Ex 010 :
	int va=2; //Change the value of va if you want
	int vb=4; //Change the value of vb if you want
	int *pa=&va;
	int *pb=&vb;
	ft_swap(pa, pb);
	printf("\n010 : a=%d b=%d", va, vb);

	//Ex 011 :
	int division=0; //Change the value of division if you want
	int *div=&division;
	int modulo=4; //Change the value of modulo if you want
	int *mod=&modulo;
	ft_div_mod(6, 3, div, mod);  //Change the values if you want
	printf("\n011 : div=%d mod=%d", division, modulo);
}
