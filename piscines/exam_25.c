// 42 projects
// Exam - 25

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

//E25 - Write a program that takes a string as a first argument corresponding to a written equation in reverse Polish or NPI notation, evaluates it and returns the result on the standard output followed by a newline. The operands and operators must have at least one space between them. You will need to implement the "+", "-", "*", "/" and "%" operators. If the string is invalid or there is not a single argument, you will need to display "error" on the standard output, followed by a newline. All operands of the string of characters must be able to be contained in an int.
typedef struct {
    int top;
    int items[STACK_SIZE];
} Stack;

void push(Stack *s, int val) {
    if (s->top==STACK_SIZE-1) {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)]=val;
}

int pop(Stack *s) {
    if (s->top==-1) {
        printf("Error\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

int is_operator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='%';
}

int is_digit(char c) {
    return c>='0' && c<='9';
}

int evaluate_rpn(char *expression) {
    Stack stack;
    stack.top=-1;

    char *token=strtok(expression, " ");
    while (token!=NULL) {
        if (is_digit(*token)) push(&stack, atoi(token));
        else if (is_operator(*token)) {
            int operand2=pop(&stack);
            int operand1=pop(&stack);
            switch (*token) {
                case '+':
                    push(&stack, operand1+operand2);
                    break;
                case '-':
                    push(&stack, operand1-operand2);
                    break;
                case '*':
                    push(&stack, operand1*operand2);
                    break;
                case '/':
                    if (operand2==0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                case '%':
                    if (operand2==0) {
                        printf("Error: Modulo by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&stack, operand1 % operand2);
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    exit(EXIT_FAILURE);
            }
        } else {
            printf("Error: Invalid character\n");
            exit(EXIT_FAILURE);
        }
        token=strtok(NULL, " ");
    }
    if (stack.top!=0) {
        printf("Error: Invalid expression\n");
        exit(EXIT_FAILURE);
    }
    return pop(&stack);
}

int main(int argc, char *argv[]) {
    if (argc!=2) {
        printf("Error\n");
        return EXIT_FAILURE;
    }

    int result=evaluate_rpn(argv[1]);
    printf("%d\n", result);

    return EXIT_SUCCESS;
}
