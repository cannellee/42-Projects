// 42 projects
// Exam - 22

#include <stdio.h>

#define MEMORY_SIZE 2048

//E22 - Write a program capable of interpreting Brainfuck. The source code will be passed to the first parameter. The transmitted code will still be valid, and will not include more than 4096 operations. Brainfuck is a minimalist language consisting of an array of bytes (as part of this exercise, 2048 bytes) all initialized at 0, and a pointer on its first byte. Here are the different Brainfuck operators: '>' increments the pointer. '<' Decrements the pointer. '+' increments the dot byte. '-' Decrements the dot byte. '.' Displays the byte pointed to the standard output. '[' goes to the corresponding ']' if the dotted byte is 0 (start of loop). ']' Goes to the corresponding '[' if the dot byte is different from 0 (end of loop). Any other character is a comment.

void interpret(const char* code) {
    char memory[MEMORY_SIZE]={0};
    char *ptr=memory;
    const char *ptrCode=code;

    while (*ptrCode) {
        switch (*ptrCode) {
            case '>': ++ptr; break;
            case '<': --ptr; break;
            case '+': ++(*ptr); break;
            case '-': --(*ptr); break;
            case '.': printf("%c", *ptr); break;
            case '[':
                if (*ptr==0) {
                    int loopCount=1;
                    while (loopCount>0) {
                        ++ptrCode;
                        if (*ptrCode=='[') ++loopCount;
                        else if (*ptrCode == ']') --loopCount;
                    }
                }
                break;
            case ']':
                if (*ptr!=0) {
                    int loopCount=1;
                    while (loopCount>0) {
                        --ptrCode;
                        if (*ptrCode=='[') --loopCount;
                        else if (*ptrCode == ']') ++loopCount;
                    }
                }
                break;
            default:
                break;
        }
        ++ptrCode;
    }
}

int main(int argc, char* argv[]) {
    if (argc!=2) {
        printf("Usage: %s <Brainfuck code>\n", argv[0]);
        return 1;
    }
    interpret(argv[1]);
    return 0;
}
