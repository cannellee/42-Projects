// 42 projects
// Piscine - 066-068

//NOTE : RUN WITH ft_ultimator.h" !!

#include <stdio.h>
#include <stdlib.h>
#include "ft_ultimator.h"

//Ex 069 - Write a function ft_destroy() which will destroy (by calling the free function) the factory passed in parameter.
void ft_destroy(char ***factory) {
    char **temp=*factory;
    while (*temp!=NULL) {
        free(*temp);
        temp++;
    }
    free(*factory);
    *factory=NULL;
}

//Ex 070 - Write a recursive function ft_collatz_conjecture which returns the "flight time" for the argument passed.
unsigned int ft_collatz_conjecture(unsigned int base) {
    if (base==1) return 0;
    else if (base%2==0) return 1+ft_collatz_conjecture(base/2);
    else return 1+ft_collatz_conjecture(3*base+1);
}

//Ex 071 - Write the ft_spy.c file which will display Alert!!!, followed by a carriage return if one of the arguments passed as a parameter matches the words president, attack or Powers. Note: "omnipresident" does not work.
int is_keyword(char *word) {
    char *keywords[]={"president", "attack", "powers"};
    int num_keywords=sizeof(keywords)/sizeof(keywords[0]);

    for (int i=0; i<num_keywords; i++) {
        int j=0;
        while (keywords[i][j]!='\0' && word[j]!='\0' && keywords[i][j]==word[j]) j++;
        if (keywords[i][j]=='\0' && word[j]=='\0') return 1;
    }
    return 0;
}

void ft_spy(int argc, char **argv) {
    for (int i=1; i<argc; i++) {
        if (is_keyword(argv[i])) {
            printf("Alert!!!\n");
            return;
        }
    }
}

int main(int argc, char **argv) {
	char **factory=(char **)malloc(3*sizeof(char *));
	factory[0]=(char *)malloc(10*sizeof(char));
	factory[1]=(char *)malloc(10*sizeof(char));
	factory[2]=NULL;

	//EXEMPLES :
	factory[0][0] = 'H';
	factory[0][1] = 'e';
	factory[0][2] = 'l';
	factory[0][3] = 'l';
	factory[0][4] = 'o';
	factory[0][5] = '\0';

	factory[1][0] = 'C';
	factory[1][1] = 'i';
	factory[1][2] = 'a';
	factory[1][3] = 'o';
	factory[1][4] = '\0';

	ft_destroy(&factory);
	printf("069 : ");
	if (factory==NULL) printf("Memory freed successfully.");
	else printf("Memory freeing failed.");

    unsigned int base=27; //Change the value if you want
    printf("\n070 : Time of flight for %u according to Collatz conjecture: %u\n", base, ft_collatz_conjecture(base));

    printf("071 : alert ? ");
    ft_spy(argc, argv);

    return 0;
}
