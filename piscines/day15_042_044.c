// 42 projects
// Piscine - 042-044

#include <stdio.h>

//Ex 042 - Replicate the operation of the strncat function (man strncat).
char *ft_strncat(char *dest, char *src, int nb) {
	char *ptr=dest;
	while (*ptr!='\0') ptr++;
	while (*src!='\0' && nb>0) {
		*ptr++=*src++;
		nb--;
	}
	*ptr='\0';
	return dest;
}

//Ex 043 - Replicate the operation of the strlcat function (man strlcat).
unsigned int ft_strlcat(char *dest, const char *src, unsigned int size) {
    unsigned int len_dest=0, len_src=0;
    char *d=dest;
    const char *s=src;
    char *initial_dest=dest;

    while (*d && len_dest<size) {
        len_dest++;
        d++;
    }
    while (*s) {
        len_src++;
        s++;
    }
    if (len_dest==size) return len_dest+len_src;
    while (*src && len_dest<size-1) {
        *d++=*src++;
        len_dest++;
    }
    *d='\0';
    return len_dest+len_src;
}


//Ex 044 - Replicate the operation of the strlcpy function (man strlcpy).
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size) {
	unsigned int len_src=0;
	const char *ptr_src=src;
	while (*ptr_src!='\0') {
		ptr_src++;
		len_src++;
	}
	int i=0;
	while (*src && i<size-1) {
		*dest++=*src++;
		i++;
	}
	*dest='\0';
	return len_src;
}


int main() {
	char dest[50]="Hello, "; //Change the value if you want
	char src[]="world!"; //Change the value if you want
	int nb=10; //Change the value if you want
	ft_strncat(dest, src, nb);
	printf("042 : %s", dest);

	char dest2[20]="Hello"; //Change the value if you want
	const char *src2=" world!"; //Change the value if you want
	unsigned int size=20; //Change the value if you want
	printf("\n043 : size - %u ; dest - %s", ft_strlcat(dest2, src2, size), dest2);

  char dest3[50]="Hello"; //Change the value if you want
  char src3[]="hey"; //Change the value if you want
  unsigned int size2=4; //Change the value if you want
  printf("\n044 : len of src - %u ; dest - %s", ft_strlcpy(dest3, src3, size2), dest3);
	return 0;
}
