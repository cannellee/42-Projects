// 42 projects
// Colle 04

#include <stdio.h>

//Write the function colle, taking as parameters two integer variables named x and y respectively, and displaying on screen a rectangle x characters wide and y characters high with border : A C & center : B
void print_top(int width) {
    printf("A");
    for (int i=0; i<width-2; i++) printf("B");
    if (width>1) printf("C");
    printf("\n");
}

void print_middle(int width) {
    printf("B");
    for (int i=0; i<width-2; i++) printf(" ");
    if (width>1) printf("B");
    printf("\n");
}

void print_bottom(int width) {
    printf("C");
    for (int i=0; i<width-2; i++) printf("B");
    if (width>1) printf("A");
    printf("\n");
}

void colle(int width, int height) {
    if (width<=0 || height<=0) {
        printf("Invalid dimensions\n");
        return;
    }

    print_top(width);
    for (int i=0; i<height-2; i++) print_middle(width);
    if (height>1) print_bottom(width);
}

int main() {
    colle(5, 3);
    return 0;
}
