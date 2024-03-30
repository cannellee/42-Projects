// 42 projects
// Piscine - 075-077

//NOTE : RUN WITH ft_perso.h !!

#include <stdio.h>
#include <stdlib.h>
#include "ft_perso.h"

//Ex 075 - Write a function ft_decrypt. This function will take a character string as a parameter and split it into an array of structure t_perso. The array will be delimited by a 0. Note: The string passed as a parameter will be formatted as follows: Age|Name;Age2|Name2;Age3|Name3
int ft_strlen(char *str) {
	int count=0;
	while (*str!='\0') {
		str++;
		count++;
	}
	return count;
}

int ft_atoi(char *str) {
	int result=0;
	int sign=1;
	while (*str==' ' || (*str>='\t' && *str<='\r')) str++;
	if (*str=='-') {
		sign=-1;
		str++;
	} else if (*str=='+') str++;
	while (*str>='0' && *str<='9') {
		result=result*10+(*str-'0');
		str++;
	}
	return sign*result;
}

char *ft_strdup(char *src) {
    int len=0;
    while (src[len]!='\0') len++;
    char *dup=(char *)malloc(len + 1);
    if (dup==NULL) return NULL;
    for (int i=0; i<=len; i++) dup[i] = src[i];
    return dup;
}

t_perso **ft_decrypt(char *str) {
	int num_pers=0;
	for (int i=0; str[i]!='\0'; i++) if (str[i]==';') num_pers++;
	t_perso **pers_array=(t_perso **)malloc((num_pers+1)*sizeof(t_perso *));
	if (pers_array==NULL) return NULL;

	int index=0;
	char *age_start=str;
	while (*str!='\0') {
		if (*str=='|' || *str==';') {
			*str='\0';
			if (*age_start=='\0') {
				str++;
				age_start=str;
				continue;
			}
			if (*str=='|' && *(str+1)!='\0') {
				int age=ft_atoi(age_start);
				char *name=ft_strdup(str+1);
				if (name==NULL) {
					for (int i=0; i<index; i++) {
						free(pers_array[i]->name);
						free(pers_array[i]);
					}
					free(pers_array);
					return NULL;
				}

				t_perso *pers=(t_perso *)malloc(sizeof(t_perso));
				if (pers==NULL) {
					free(name);
					for (int i=0; i<index; i++) {
						free(pers_array[i]->name);
						free(pers_array[i]);
					}
					free(pers_array);
					return NULL;
				}

				pers->age=age;
				pers->name=name;
				pers->life=100.0;
				pers->profession=0;
				pers_array[index]=pers;
				index++;

				str++;
				age_start=str;
			} else if (*str==';') {
				*str='\0';
				str++;
				age_start=str;
			}
		} else str++;
	}
	pers_array[index]=NULL;
	return pers_array;
}

void free_persons_array(t_perso **pers_array) {

}

//Ex 076 - Write a function ft_active_bits which returns the number of active bits in the int passed in parameter.
unsigned int ft_active_bits(int value) {
    unsigned int count=0;
    while (value!=0) {
        count+=value&1;
        value>>=1;
    }
    return count;
}

//Ex 077 - Write a function ft_max which returns the value of the largest element in the array.
int ft_max(int *tab, int length) {
	int max=tab[0];
	for (int i=0; i<length; i++) if (tab[i]>max) max=tab[i];
	return max;
}

int main() {
	printf("075 : ");
	char *str="30|Alice;25|Bob;35|Charlie"; //Change the value if you want
	t_perso **pers_array=ft_decrypt(str);
	if (pers_array==NULL) return 1;
	for (int i=0; pers_array[i]!=NULL; i++) {
		printf("Person %d:\n", i+1);
		printf("Age : %d\n", pers_array[i]->age);
		printf("Name : %s\n", pers_array[i]->name);
		printf("Life : %.2f\n", pers_array[i]->life);
		printf("Profession : %d\n", pers_array[i]->profession);
		printf("\n");
	}

	for (int i=0; pers_array[i]!=NULL; i++) {
		free(pers_array[i]->name);
		free(pers_array[i]);
	}
	free(pers_array);


    int num=4; //Change the value if you want
    printf("\n076 : %u", ft_active_bits(num));

    int tab[]={-50, 8, -9, -2}; //Change the value if you want
    int length=4; //Change the value if you want
    printf("\n077 : %d", ft_max(tab, length));
    return 0;
}
