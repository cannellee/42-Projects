// 42 projects
// Piscine - 024-026

#include <stdio.h>
#include <stdbool.h>

#define N 8

//Ex 024 - Write a function that returns 1 if the number is prime and 0 if it is not.
int ft_is_prime(int nb) {
	if (nb<2) return 0;
	for (int i=2; i<nb; i++) {
		if (nb%i==0) return 0;
	}
	return 1;
}

//Ex 025 - Write a function that returns the prime number immediately greater than or equal to the number passed in parameter. Note: Result in less than 2 seconds.
int ft_find_next_prime(int nb) {
	while(!ft_is_prime(nb)) {
		nb++;
	}
	return nb;
}

//Ex 026 - Write a recursive function that returns the number of possibilities of placing the eight queens on the chessboard without them being able to reach each other. Note: Result in less than 2 seconds.
int g_count=0;

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i=0; i<col; i++) if (board[row][i]) return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--) if(board[i][j]) return false;
    for (i=row, j=col; j>=0 && i<N; i++, j--) if (board[i][j]) return false;
    return true;
}

void solveNQUtil(int board[N][N], int col) {
    if (col>=N) {
        g_count++;
        return;
    }
    for (int i=0; i<N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col]=1;
            solveNQUtil(board, col+1);
            board[i][col]=0;
        }
    }
}

int ft_eight_queens_puzzle(void) {
    int board[N][N];
    g_count=0;
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) board[i][j]=0;
    solveNQUtil(board, 0);
    return g_count;
}


int main() {
	printf("024 : %d", ft_is_prime(97)); //Change the value into () if you want
	printf("\n025 : %d", ft_find_next_prime(1)); //Change the value into () if you want
	printf("\n026 : %d", ft_eight_queens_puzzle());
	return 0;
}
