// 42 projects
// Piscine - 087-089

//NOTE : RUN WITH ft_opp.h !!

#include <stdio.h>
#include <stdlib.h>
#include "ft_opp.h"

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
    result[i]=NULL;
    return result;
}

void ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *)) {
    int i=0;
    while (tab[i]!=NULL) {
        int j=i+1;
        while (tab[j]!=NULL) {
            if ((*cmp)(tab[i], tab[j])>0) {
                char *temp=tab[i];
                tab[i]=tab[j];
                tab[j]=temp;
            }
            j++;
        }
        i++;
    }
}

int ft_strcmp(char *s1, char *s2) {
    while (*s1 && *s2 && *s1==*s2) {
        s1++;
        s2++;
    }
    return (*s1-*s2);
}

int ft_atoi(char *str) {
    if (str==NULL || *str=='\0') return 0;
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

int ft_usage(int a, int b) {
    return 0;
}

int ft_add(int a, int b) {
    return (a+b);
}

int ft_minus(int a, int b) {
    return (a-b);
}

int ft_mul(int a, int b) {
    return (a*b);
}

int ft_div(int a, int b) {
    if (b==0) return 0;
    return (a/b);
}

int ft_mod(int a, int b) {
    if (b==0) return 0;
    return (a%b);
}

int advanced_do_op(int value1, char *operator, int value2) {
    int i;
    for (i=0; gl_opptab[i].op[0]!='\0'; i++) if (gl_opptab[i].op[0]==operator[0]) return gl_opptab[i].func(value1, value2);
    return ft_usage(value1, value2);
}

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list *ft_create_elem(void *data) {
    t_list *new_elem=(t_list *)malloc(sizeof(t_list));
    if (new_elem==NULL) return NULL;
    new_elem->data=data;
    new_elem->next=NULL;
    return new_elem;
}

int main(int argc, char *argv[]) {
    char **words=ft_split_whitespaces("hello world how are you");
    if (words==NULL) return 1;

    ft_advanced_sort_wordtab(words, &ft_strcmp);

    printf("087 : \n");
    for (int i=0; words[i]!=NULL; i++) printf("%s\n", words[i]);

    for (int i=0; words[i]!=NULL; i++) free(words[i]);
    free(words);

    if (argc==4) {
        int value1=ft_atoi(argv[1]);
        int value2=ft_atoi(argv[3]);
        char *operator=argv[2];
        printf("088 : %d\n", advanced_do_op(value1, operator, value2));
    }

    printf("089 : ");
    int *num=(int *)malloc(sizeof(int));
    if (num!=NULL) {
    	*num=42;
    	t_list *list=ft_create_elem(num);
		if (list!=NULL) {
			free(list->data);
			free(list);
		}
    }

    return 0;
}
