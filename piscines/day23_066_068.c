// 42 projects
// Piscine - 066-068

#include <stdio.h>
#include <time.h>

//Ex 066 - Write a function ft_takes_place that displays the time on the standard output in the format THE FOLLOWING TAKES PLACE BETWEEN X.00 A.M. AND Y.00 A.M. followed by a carriage return. Note: The hour parameter will be a valid int, in 24h format. The output will be in am/pm format.
void ft_takes_place(int hour) {
	char period[4];
    (hour>12) ? (period[0]='P'): (period[0]='A');
    period[1]='.';
    period[2]='M';
    period[3]='\0';

    int new_hour=(hour%12==0) ? 12 : hour%12;
    if (hour==12) period[0]='P';
    else if (hour==24) period[0]='A';
    printf("THE FOLLOWING TAKES PLACE BETWEEN %d.00 %s AND %d.00 %s\n", new_hour, period, (new_hour+1)%12, period);
}

//Ex 067 - Write a function ft_rot42 which returns the string passed as a parameter, rotating the necessary characters by 42.
char *ft_rot42(char *str) {
	char *ptr=str;
	while (*ptr) {
		if ((*ptr>='a' && *ptr<='z') || (*ptr>='A' && *ptr<='Z')) {
			if (*ptr>='a' && *ptr<='z') *ptr=((*ptr-'a'+42)%26)+'a';
			else if (*ptr>='A' || *ptr<='Z') *ptr=((*ptr-'A'+42)%26)+'A';
		}
		ptr++;
	}
	return str;
}

//Ex 068 - Write a function ft_bouton which takes three int as parameters and returns the middle value.
int ft_bouton(int i, int j, int k) {
	if (i>j) {
		int temp=i;
		i=j;
		j=temp;
	}
	if (j>k) {
		int temp=j;
		j=k;
		k=temp;
	}
	if (j<i) {
		int temp=j;
		j=i;
		i=temp;
	}
	return j;
}

int main() {
	printf("066 : ");
	ft_takes_place(12); //Change the value if you want

	char str[]="Hello, World!"; //Change the value if you want
	printf("\n067 : %s -> ", str);
	printf("%s\n", ft_rot42(str));

	printf("\n068 : %d", ft_bouton(5, 3, 6)); //Change the value if you want
    return 0;
}
