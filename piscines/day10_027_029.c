// 42 projects
// Piscine - 027-029

#include <stdio.h>

//Ex 027 - Write a recursive function that displays all the possibilities of placing the eight queens on the board without them being able to reach each other.
int is_safe(int board[8][8], int row, int col) {
    int i, j;
    for (i=0; i<col; i++) if (board[row][i]) return 0;
    for (i=row, j=col; i>=0 && j>=0; i--, j--) if (board[i][j]) return 0;
    for (i=row, j=col; j>=0 && i<8; i++, j--) if (board[i][j]) return 0;
    return 1;
}

void print_solution(int board[8][8]) {
    static int count=1;
    for (int i=0; i<8; i++) for (int j=0; j<8; j++) if (board[i][j]) printf("%c", "12345678"[j]);
    if (count++!=92) printf("\n");
}

void solve_queens(int board[8][8], int col) {
    if (col>=8) {
        print_solution(board);
        return;
    }

    for (int i=0; i<8; i++) {
        if (is_safe(board, i, col)) {
            board[i][col]=1;
            solve_queens(board, col+1);
            board[i][col]=0;
        }
    }
}

void ft_eight_queens_puzzle_2(void) {
    int board[8][8]={0};
    solve_queens(board, 0);
}

//Ex 028 - Replicate the operation of the strcpy function (man strcpy).
char *ft_strcpy(char *dest, char *src) {
	char *dest_start=dest;

	while (*src!='\0') {
		*dest=*src;
		src++;
		dest++;
	}
	*dest='\0';
    return dest_start;
}

//Ex 029 - Replicate the operation of the strncpy function (man strncpy).
char *ft_strncpy(char *dest, char *src, unsigned int n) {
	char *start=dest;

	while (n>0 && *src!='\0') {
		*dest++=*src++;
		n--;
	}
	while (n>0) {
		*dest++='\0';
		n--;
	}
	return start;
}

int main() {
	printf("027 : ");
	ft_eight_queens_puzzle_2();

	char src[]="Hello"; //Change the value if you want
	char dest[10]; //Change the value if you want
	printf("\n028 : %s", ft_strcpy(dest, src));

	char src2[]="Hola";  //Change the value if you want
	char dest2[10];  //Change the value if you want
	unsigned int n=11;  //Change the value if you want
	ft_strncpy(dest2, src2, n);
	dest2[n]='\0';
	printf("\n029 : %s", dest2);

	return 0;
}
