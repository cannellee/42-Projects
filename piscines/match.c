// 42 projects
// Mini-projects - 1.0

#include <stdio.h>

//MP1.0 - The aim of the function is to find out whether two strings match (=when s1 and s2 are identical). It should return 1 if s1 matches s2 or 0 otherwise.
        //Note: If s2 contains a star ('*'), you can replace this star with any string (even an empty one) to make s1 and s2 identical. s2 can contain as many stars as you like.
int match(char *s1, char *s2) {
	if (*s1=='\0' && *s2=='\0') return 1;
	if (*s1=='\0' || *s2=='\0') return 0; //a tester

	if (*s2=='*') {
		while (*s1!='\0') {
			if (match(s1, s2+1)) return 1;
			s1++;
		}
		return match(s1, s2+1);
	}

	if (*s1==*s2) return match(s1+1, s2+1);
	return 0;
}

int main() {
	char s1[]="hey"; //Change the value if you want
	char s2[]="h*y"; //Change the value if you want
	printf("%d", match(s1, s2));
	return 0;
}
