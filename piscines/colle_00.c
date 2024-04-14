// 42 projects
// Colle 00

#include <stdio.h>

//Write the function colle, taking as parameters two integer variables named x and y respectively, and displaying on screen a rectangle x characters wide and y characters high with border : • & center : - |
void print_horizontal(int width) {
    printf("o");
    for (int i=0; i<width-2; i++) printf("-");
    if (width>1) printf("o");
    printf("\n");
}

void print_vertical(int width) {
    printf("|");
    for (int i=0; i<width-2; i++) printf(" ");
    if (width>1) printf("|");
    printf("\n");
}

void colle(int width, int height) {
    if (width<=0 || height<=0) {
        printf("Invalid dimensions.\n");
        return;
    }
    print_horizontal(width);
    for (int i=0; i<height-2; i++) print_vertical(width);
    if (height>1) print_horizontal(width);
}

int main() {
    colle(9, 3);
    return 0;
}
