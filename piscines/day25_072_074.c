// 42 projects
// Piscine - 072-074

//NOTE : RUN WITH ft_perso.h !!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_point.h"

//Ex 072 - Write a function ft_scrambler() which swaps the int's pointed to by the pointers to int's passed as parameters. This function will put a into c; c into d; d into b; and b into a.
void ft_scrambler(int ***a, int *b, int *******c, int ****d) {
    int tmp_a=***a;
    int tmp_b=*b;
    int tmp_c=*******c;
    int tmp_d=****d;

    ***a=tmp_b;
    *b=tmp_d;
    *******c=tmp_a;
    ****d=tmp_c;
}

//Ex073 - Write a file ft_perso.h which will compile the main
//	-> check the center part of the main

//Ex 074 - Write a function ft_compact that takes an array of char * as a parameter and overwrites all elements that point to 0. This function returns the new size of the array.
int ft_compact(char **tab, int length) {
    int i, j;
    for (i=0, j=0; i<length; i++) {
        if (tab[i]!=NULL) {
            tab[j]=tab[i];
            j++;
        }
    }
    return j;
}

int main() {
    int a_val=1; //Change the value if you want
    int *a_ptr=&a_val;
    int **a_double_ptr=&a_ptr;
    int ***a_triple_ptr=&a_double_ptr;

    int b_val=2; //Change the value if you want
    int *b_ptr=&b_val;

    int c_val=3; //Change the value if you want
    int *c_ptr=&c_val;
    int **c_double_ptr=&c_ptr;
    int ***c_triple_ptr=&c_double_ptr;
    int ****c_quad_ptr=&c_triple_ptr;
    int *****c_five_ptr=&c_quad_ptr;
    int ******c_six_ptr=&c_five_ptr;
    int *******c_sev_ptr=&c_six_ptr;

    int d_val=4; //Change the value if you want
    int *d_ptr=&d_val;
    int **d_double_ptr=&d_ptr;
    int ***d_triple_ptr=&d_double_ptr;
    int ****d_quad_ptr=&d_triple_ptr;
    ft_scrambler(a_triple_ptr, b_ptr, c_sev_ptr, d_quad_ptr);
    printf("072 : a=%d, b=%d, c=%d, d=%d", *a_ptr, *b_ptr, ***c_triple_ptr, ****d_quad_ptr);


    enum profession {SAVE_AUSTIN_POWERS};
    t_perso donnie;
    donnie.life=100.0;
    donnie.age=24;
    donnie.profession=SAVE_AUSTIN_POWERS;
    printf("\n073 : Donnie :\n");
    printf("Name : %s\n", donnie.name);
    printf("Life : %.2f\n", donnie.life);
    printf("Age : %d\n", donnie.age);
    printf("Profession : %d", donnie.profession);
    free(donnie.name);


    char *tab[]={"hello", NULL, "world", NULL, "!", NULL}; //Change the value if you want
    int length=sizeof(tab)/sizeof(tab[0]);
    printf("\n074 : %d", ft_compact(tab, length));
    return 0;
}
