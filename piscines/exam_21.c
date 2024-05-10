// 42 projects
// Exam - 21

#include <stdio.h>

//E21 - Write a program that will take a string of characters as parameter and which writes on the standard output 'ok' if the expression is well parenthesized and 'error' otherwise, all followed by a newline. The symbols used as 'parentheses' will be brackets '(' and ')', brackets '[' and ']' as well as braces '{' and '}'. All other characters will simply be ignored. An opening parenthesis must be closed by a closing parenthesis and in the right order (nested parentheses). A chain with no parenthesis is considered as well-pared. Your program will evaluate all arguments. If no argument is provided, it will only display a Newline.

int is_matching(char opening, char closing) {
    if (opening=='(' && closing==')') return 1;
    if (opening=='[' && closing==']') return 1;
    if (opening=='{' && closing=='}') return 1;
    return 0;
}

int is_balanced(const char *str) {
    int stack[1024];
    int top=0;
    
    for (int i=0; str[i]!='\0'; i++) {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{') stack[top++]=str[i];
        else if (str[i]==')' || str[i]==']'||str[i]=='}') if (top==0 || !is_matching(stack[--top], str[i])) return 0;
    }
    
    return top==0;
}

void print_result(int is_balanced) {
    if (is_balanced) printf("OK\n");
    else printf("Error\n");
}

int main(int argc, char *argv[]) {
    if (argc==1) {
        printf("\n");
        return 0;
    }
    
    for (int i=1; i<argc; i++) print_result(is_balanced(argv[i]));
    return 0;
}