// 42 projects
// Piscine - 063-065

//NOTE : RUN WITH ft_point.h & ft_stock_par.h !!

#include <stdio.h>
#include <stdlib.h>
#include "ft_point.h"
#include "ft_stock_par.h"

//Ex 063 - Write a file ft_point.h which will compile the following main.
void set_point(t_point *point) {
	point->x = 42;
	point->y = 21;
}

//Ex 064 - Write a function that stores the program parameters in an array of structures and returns the address of the first cell in the array. All the elements of the array must be processed, including av[0]. Note: The array of structures must be allocated and the last cell will contain 0 in its str element to signal the end.
int ft_strlen(char *str) {
	int count=0;
	while (*str!='\0') {
		str++;
		count++;
	}
	return count;
}

char *ft_strdup(char *src) {
    int len=0;
    while (src[len]!='\0') len++;
    char *dup=(char *)malloc(len + 1);
    if (dup==NULL) return NULL;
    for (int i=0; i<=len; i++) dup[i]=src[i];
    return dup;
}

int is_separator(char c) {
    return (c==' ' || c=='\t' || c=='\n');
}

int count_words(char *str) {
    int count=0;
    int in_word=0;
    while (*str) {
        if (is_separator(*str)) in_word = 0;
        else if (!in_word) {
            count++;
            in_word=1;
        }
        str++;
    }
    return count;
}

char **ft_split_whitespaces(char *str) {
    int word_count=count_words(str);
    char **result=(char **)malloc((word_count+1)*sizeof(char *));
    if (result==NULL) return NULL;
    int i=0;
    while (*str) {
        while (is_separator(*str)) str++;
        if (*str) {
            char *start=str;
            while (*str && !is_separator(*str)) str++;
            int word_length=str-start;
            result[i]=(char *)malloc((word_length+1)*sizeof(char));
            if (result[i]==NULL) {
                while (i>0) free(result[--i]);
                free(result);
                return NULL;
            }
            for (int j=0; j<word_length; j++) result[i][j]=start[j];
            result[i][word_length]='\0';
            i++;
        }
    }
    result[i]=0;
    return result;
}

t_stock_par *ft_param_to_tab(int ac, char **av) {
	t_stock_par *tab;

	tab=(t_stock_par *)malloc(sizeof(t_stock_par)*(ac+1));
	if (tab==NULL) return NULL;

	for (int i=0; i<ac; i++) {
		tab[i].size_param=ft_strlen(av[i]);
		tab[i].str=av[i];
		tab[i].copy=ft_strdup(av[i]);
		tab[i].tab=ft_split_whitespaces(av[i]);
	}

	tab[ac].size_param=0;
	tab[ac].str=NULL;
	tab[ac].copy=NULL;
	tab[ac].tab=NULL;

	return tab;
}

//Ex 065 - Write a function which displays the contents of an array created by the previous function. For each cell, display (one element per line): the parameter, the size, each word (one per line).
void ft_show_tab(struct s_stock_par *par) {
    for (int i=0; par[i].str!=NULL; i++) {
        printf("Parameter: %s\n", par[i].str);
        printf("Size: %d\n", par[i].size_param);
        printf("Copy: %s\n", par[i].copy);
        printf("Words:\n");
        for (int j=0; par[i].tab[j]!=NULL; j++) {
            printf("- %s\n", par[i].tab[j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
	t_point point;
	set_point(&point);
	printf("063 : x=%d, y=%d", point.x, point.y);

	t_stock_par *result=ft_param_to_tab(argc, argv);
	if (result==NULL) return 1;
	printf("\n064 & 065 : ");
	ft_show_tab(result);

	for (int i=0; result[i].str!=NULL; i++) {
		free(result[i].copy);
		for (int j=0; result[i].tab[j]!=NULL; j++) free(result[i].tab[j]);
		free(result[i].tab);
	}
	free(result);
	return 0;
}
