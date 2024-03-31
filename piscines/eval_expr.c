// 42 projects
// Mini-projects - 2

#include <stdio.h>
#include <ctype.h>

//MP2 - This function receives a parameter string representing an arithmetic expression. For example: "3 + 42*(1-2/(3+4)-1%21) + 1". This expression must be calculated and the result returned as the function's return value. The string sent to you must be valid (no bugs, no bogus addresses, no letters or syntax errors, no division by zero, etc.). The following five operators must be supported: + for addition, - for subtraction, / for division, * for multiplication, % for modulo. The function must also handle any number of parentheses.
int eval_term(char **);
int eval_factor(char **);
int eval_number(char **);


int eval_expr(char *str) {
    return eval_term(&str);
}


int eval_term(char **str) {
    int result=eval_factor(str);
    char op;

    while (**str=='+' || **str=='-') {
        op=**str;
        (*str)++;

        int next_factor=eval_factor(str);

        if (op=='+') result+=next_factor;
        else result-=next_factor;
    }

    return result;
}


int eval_factor(char **str) {
    int result=eval_number(str);
    char op;

    while (**str=='*' || **str=='/' || **str=='%') {
        op=**str;
        (*str)++;

        int next_number=eval_number(str);

        if (op=='*') result*=next_number;
        else if (op=='/') result/=next_number;
        else result%=next_number;
    }

    return result;
}


int eval_number(char **str) {
    int result=0;
    int sign=1;

    if (**str=='-') {
        sign=-1;
        (*str)++;
    }

    if (**str=='(') {
        (*str)++;
        result=eval_term(str);
        (*str)++;
    } else {
        while (isdigit(**str)) {
            result=result*10+(**str-'0');
            (*str)++;
        }
    }

    return result*sign;
}


int main() {
    char expression[]="2-4-5+6/2"; //Change the value if you want
    int result=eval_expr(expression);
    printf("Result : %d\n", result);
    return 0;
}
