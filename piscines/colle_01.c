// 42 projects
// Colle 01

#include <stdio.h>

//Write the function colle, taking as parameters two integer variables named x and y respectively, and displaying on screen a rectangle x characters wide and y characters high with border : / \ & center : *
void print_top_bottom(int width, int is_top) {
    if (is_top) printf("/");
    else printf("\\");
    for (int i=0; i<width-2; i++) printf("*");

    if (width>1) {
        if (is_top) printf("\\");
        else printf("/");
    }
    printf("\n");
}

void print_middle(int width) {
    printf("*");
    for (int i=0; i<width-2; i++) printf(" ");
    if (width>1) printf("*");
    printf("\n");
}

void colle(int width, int height) {
    if (width<=0 || height<=0) {
        printf("Invalid dimensions\n");
        return;
    }
    print_top_bottom(width, 1);
    for (int i=0; i<height-2; i++) print_middle(width);
    if (height>1) print_top_bottom(width, 0);
}

int main() {
    colle(5, 3);
    return 0;
}
