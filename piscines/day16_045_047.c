// 42 projects
// Piscine - 045-047

#include <stdio.h>

//Ex 045 - Write a function that displays a number on the screen in a given base. This number is supplied in the form of an int and the base in the form of a character string. The base contains all the symbols that can be used to display the number: 0123456789 (decimal numbers), 01 (binary base), 0123456789ABCDEF (hexadecimal base), poneyvif (octal base) The function must handle negative numbers. Note: If a parameter contains an error, the function does not display anything. An error can be: base is empty or is of size 1; base contains the same character twice; base contains the characters + or -; etc.
void ft_putnbr_base(int nbr, char *base) {
	int len_base=0;
	if (*base=='\0') return;
	while (base[len_base]!='\0') len_base++;

	for (int i=0; i<len_base; i++) {
		if (base[i]=='+' || base[i]=='-') return;
		for (int j=i+1;j<len_base; j++)
		if (base[i]==base[j]) return;
	}

	if (nbr<0) {
		printf("-");
		nbr*=-1;
	}

	if (nbr>=len_base) ft_putnbr_base(nbr/len_base, base);
	printf("%c", base[nbr%len_base]);
}


//Ex 046 - Write a function that returns a number. This number is known in the form of a character string. The character string expresses the number in a particular base passed as the second parameter. The function must handle negative numbers. The function must handle signs such as man atoi. Note: If a parameter contains an error, the function returns 0. An error can be: str is an empty string; the base is empty or is of size 1; str contains characters which are not in the base and are not + or -; the base contains the same character twice; the base contains the characters + or -; etc.
int ft_atoi_base(char *str, char *base) {
	if (!str || !base) return 0;
	int result=0;
	int sign=1;
	int len_base=0;

	while (base[len_base]!='\0') len_base++;
	while (*str==' ' || (*str>='\t' && *str<='\r')) str++;

	if (*str=='-') {
		sign=-1;
		str++;
	} else if (*str=='+') str++;

	while (*str>='0' && *str<='9') {
		result=result*10+(*str-'0');
		str++;
	}

	while (*str != '\0') {
		int i=0;
		while (base[i]!='\0') {
			if (*str==base[i]) {
				result=result*len_base+i;
				break;
			}
			i++;
		}
		if (base[i]=='\0') return 0;
		str++;
	}

	return sign*result;
}

//Ex 047 - Write a function that displays a string of characters on the screen. If this string contains non-printable characters, they must be displayed in hexadecimal form (in lower case) preceded by a backslash.
void ft_putstr_non_printable(char *str) {
	while (*str) {
		if (*str>=32 && *str<=126) printf("%c", *str);
		else printf("\\%02x", (unsigned char)*str);
		str++;
	}
}


int main() {
	int number=-150; //Change the value if you want
	char base[]="0123456789ABCDEF"; //Change the value if you want
	printf("045 : ");
	ft_putnbr_base(number, base);
	printf("\n046 : ");
	printf("%d", ft_atoi_base("A5", "0123456789ABCDEF")); //Change the value if you want
	printf("\n047 : ");
    ft_putstr_non_printable("Bonjour\tle\nmonde!"); //Change the value if you want
	return 0;
}
