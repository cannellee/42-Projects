// 42 projects
// Mini-projects - 0

#include <stdio.h>

//MP0 - Write a function that displays the Sastantua pyramid on the screen as a function of a given size. A pyramid of size 0 displays nothing.
void sastantua(int size) {
	if (size<1) return;

	int number_lines=0;
	int blocks[size];
	int last_line=1;

	for (int i=1; i<=size; i++) {
		number_lines+=i+2;
		blocks[i-1]=number_lines;
	}

	for (int j=1; j<number_lines; j++) {
		for (int k=0; k<size; k++) {
			if (blocks[k]==j) {
				if ((k+2)%2!=0) last_line+=(k+3);
				else last_line+=(k+4);
			}
		}
		last_line+=2;
	}

	int spaces=last_line/2;
	int stars=1;

	for (int j=1; j<number_lines+1; j++) {
		for (int k=0; k<spaces; k++) printf(" ");
		printf("/");
		if ((number_lines+1)-j<=size) {
			int stars_last_bloc_right=(stars-size)/2;
			int stars_last_bloc_left=stars-stars_last_bloc_right-size;
			for (int i=0; i<stars_last_bloc_right; i++) printf("*");
			if (size>3 && size%2!=0 && number_lines+1-j==size/2+1) {
				for (int n=0; n<size/2+1; n++) printf("|");
				printf("$");
				for (int n=0; n<size/2-1; n++) printf("|");
			} else for (int n=0; n<size; n++) printf("|");
			for (int o=0; o<stars_last_bloc_left; o++) printf("*");
		} else for (int l=0; l<stars; l++) printf("*");

		printf("\\\n");
		spaces-=1;
		stars+=2;

		for (int m=0; m<size; m++) {
			if (blocks[m]==j) {
				if ((m+2)%2!=0) {
					stars+=m+3;
					spaces-=(m+3)/2;
				}
				else {
					stars+=m+4;
					spaces-=(m+4)/2;
				}
			}
		}
	}
}

int main() {
	sastantua(5);
	return 0;
}
