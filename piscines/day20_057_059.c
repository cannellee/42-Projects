// 42 projects
// Piscine - 057-059

#include <stdio.h>
#include <stdlib.h>

//Ex 057 - Write a function that splits a string into words. The separators are spaces, tabs and line breaks. The function returns an array where each cell contains the address of a character string representing a word. The last element of the array must be 0 to mark the end of the array. Note: There must be no empty strings in your array. Draw the appropriate conclusions from this. The string transmitted cannot be modified.
int is_separator(char c) {
    return (c==' ' || c=='\t' || c=='\n');
}

int count_words(char *str) {
    int count=0;
    int in_word=0; // Flag to track if currently in a word
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

//Ex 058 - Write a function that displays the contents of the table created by the function in the previous exercise. Each word will stand alone on a line. Each word will be followed by an "\n", including the last one. This exercise will be compiled with your ft_split_whitespaces.c. Be careful not to make multiple defines.
void ft_print_words_tables(char **tab) {
    while (*tab) {
        printf("\"%s\"\n", *tab++);
    }
}


//Ex 059 - Write a function that returns the result of converting the string nbr expressed in a base_from into a base_to in the form of a string allocated with sufficient memory. The number represented by nbr fits into an int.
int find_index(char c, char *str) {
    int i=0;
    while (str[i]!='\0') {
        if (str[i]==c) return i;
        i++;
    }
    return -1;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to) {
    int num=0;
    int base_from_len=0;
    int base_to_len=0;
    while (base_from[base_from_len]) base_from_len++;
    while (base_to[base_to_len]) base_to_len++;
    int sign=1;
    if (*nbr=='-') {
        sign=-1;
        nbr++;
    }
    while (*nbr) {
        num=num*base_from_len+find_index(*nbr, base_from);
        nbr++;
    }
    int digits=0;
    int temp=num;
    while (temp>0) {
        temp/=base_to_len;
        digits++;
    }
    if (num==0) digits=1;

    char *result=(char *)malloc((digits+1)*sizeof(char));
    result[digits]='\0';
    while (num>0) {
        result[--digits]=base_to[num%base_to_len];
        num/=base_to_len;
    }
    if (sign==-1) {
        char *final_result=(char *)malloc((digits+2)*sizeof(char));
        final_result[0]='-';
        for (int i=0; i<=digits; i++) final_result[i+1]=result[i];
        free(result);
        return final_result;
    }
    return result;
}

int main() {
    char str[]="Hello\tworld\nHow are you?";
    char **words=ft_split_whitespaces(str);
    printf("057 & 058 : ");
    ft_print_words_tables(words);
  
    char nbr[]="10101";
    char base_from[]="01";
    char base_to[]="0123456789ABCDEF";
    printf("\n059 : number in base %s is %s, converted to base %s is %s", base_from, nbr, base_to, ft_convert_base(nbr, base_from, base_to));

    for (int i=0; words[i]!=NULL; i++) free(words[i]);
    free(words);
    return 0;
}
