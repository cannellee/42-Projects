// 42 projects
// Piscine - 054-056

#include <stdio.h>
#include <stdlib.h>

//Ex 054 - Write a function ft_range that returns an array of int. This array of int will contain all the values between min and max. Min included - max excluded. If the min value is greater than or equal to the max value, a null pointer will be returned.
int *ft_range(int min, int max) {
    if (min>=max) return NULL;
    int size=max-min;
    int *range=(int *)malloc(size*sizeof(int));
    if (range==NULL) return NULL;
    for (int i=0; i<size; i++) *(range+i)=min+i;
    return range;
}

//Ex 055 - Write a function ft_ultimate_range that allocates and assigns an array of int. This array of int will contain all the values between min and max. Min included - max excluded. If the min value is greater than or equal to the max value, range will point to NULL.  The size of range will be returned (or 0 in the event of a problem).
int ft_ultimate_range(int **range, int min, int max) {
    if (min>=max) {
        *range=NULL;
        return 0;
    }

    int size=max-min;
    *range=(int *)malloc(size*sizeof(int));
    if (*range==NULL) return 0;
    for (int i=0; i<size; i++) *(*range+i)=min+i;
    return size;
}

//Ex 056 - Write a function that transforms the arguments received on the command line into a single character string. The arguments will be separated by an "\n".
char *ft_concat_params(int argc, char **argv) {
    int total_length=0;
    for (int i=0; i<argc; i++) {
        for (int j=0; argv[i][j]!='\0'; j++) total_length++;
        total_length++;
    }

    char *result=(char *)malloc(total_length*sizeof(char));

    if (result==NULL) return NULL;

    int currentPosition=0;
    for (int i=0; i<argc; i++) {
        for (int j=0; argv[i][j]!='\0'; j++) {
            *(result+currentPosition)=argv[i][j];
            currentPosition++;
        }
        *(result+currentPosition)='\n';
        currentPosition++;
    }

    *(result+currentPosition-1)='\0';
    return result;
}


int main() {
    printf("054 : ");
    int min=5; //Change the value if you want
    int max=10; //Change the value if you want
    int *range=ft_range(min, max);
    if (range!=NULL) {
        for (int i=0; i<max-min; i++) printf("%d ", range[i]);
        free(range);
    }

    printf("\n055 : ");
    int *ultimate_range=NULL;
    int size=ft_ultimate_range(&ultimate_range, min, max);
    if (ultimate_range!=NULL) {
        for (int i = 0; i < size; i++) printf("%d ", ultimate_range[i]);
        free(ultimate_range);
    }

    printf("\n056 : ");
    char *arguments[]={"Hello", "World", "Bonjour", "Monde"}; //Change the value if you want
    char *concatenated=ft_concat_params(4, arguments);
    if (concatenated!=NULL) {
        printf("%s\n", concatenated);
        free(concatenated);
    }

    return 0;
}
