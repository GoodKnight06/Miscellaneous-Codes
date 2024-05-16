#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

/* Programming Exercise 10 - This program will continously ask for the user to input an integer. Once it receives an input, the program will then count how many zeros (0) are present
on the inputted integer, and in turn display the count along with the input itself. To terminate the run of this program, the user will have to input the End-of-file, which is ctrl-D
for Linux OS devices, and ctrl-Z for Windows OS.*/

int checkDigits(int num){
	int zeros = 0;
	if(num>=10){
		if(num%10==0){
			zeros = 1;
		}
		return zeros + checkDigits(num/10);
	}
	else {
		switch (num){
			case 0: return 1;
					break;
			default: return 0;
					 break;
		}
		return 0;
	}
}

int main(int argc, char *argv[]) {
	
	int num;
	
	printf("Enter an integer(ctrl-D or ctrl-Z to end): ");
	while(scanf("%d", &num) != EOF){
		
		printf(" There is/are %d zero(s) in %d\n\n", checkDigits(num), num);
		
		printf("Enter an integer(ctrl-D or ctrl-Z to end): ");
	}
	printf(" End of program.Thanks");
	
	return 0;
}
