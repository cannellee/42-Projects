// 42 projects
// Piscine - 048-050

#include <stdio.h>

//Ex 048 - Write a function that displays a memory area on the screen. The memory area is displayed in three columns: The hexadecimal address of the first character on the line; The hexadecimal content; The content in printable characters. If a character is non-printable, it will be replaced by a dot. Each line must handle sixteen characters. If size is 0, nothing will be displayed. Note: It must return addr.
void print_memory_line(void *addr, unsigned int size) {
    unsigned char *ptr=(unsigned char *)addr;
    printf("%p: ", addr);
    for (unsigned int i=0; i<16; i++) {
        if (i<size) printf("%02x ", ptr[i]);
        else printf("   ");
    }
    printf(" ");
    for (unsigned int i=0; i<16; i++) {
        if (i<size) {
            if (ptr[i]>=32 && ptr[i]<=126) printf("%c", ptr[i]);
            else printf(".");
        }
    }
    printf("\n");
}

void *ft_print_memory(void *addr, unsigned int size) {
    unsigned char *ptr=(unsigned char *)addr;
    if (size==0) return addr;
    for (unsigned int i=0; i<size; i+=16) print_memory_line(ptr+i, size-i);
    return addr;
}

//Ex 049 - Write a program to display the program name.
void ft_print_program_name() {
    extern char *__progname;
    printf("%s\n", __progname);
}

//Ex 050 - Write a program to display the arguments received on the command line.
void ft_print_params(int argc, char **argv) {
    for (int i=0; i<argc; i++) printf("Argument %d: %s\n", i, argv[i]);
}

int main(int argc, char **argv) {
    unsigned char memory[]="Hello, world! This is a test."; //Change the value if you want
    printf("048 : ");
    ft_print_memory(memory, sizeof(memory));
    printf("\n049 : ");
    ft_print_program_name();
    printf("\n050 : ");
    ft_print_params(argc, argv);
    return 0;
}
