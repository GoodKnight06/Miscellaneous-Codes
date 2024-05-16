#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

/* Programming Exercise 8 - This program will ask the user for inputs of a pair of integers and then calculates and outputs the payment given the rate and time, with corresponding
increase in rate depending on the number of hours. This program will keep asking for inputs until the user inputs the end-of-file special character (ctrl-z for windows, ctrl-d for linux)
and when the case arrives that the end-of-file character is inputted, the program will then output the total of all the payments so far and then stop running afterwards.*/

int main(int argc, char *argv[]) {
	
	int rate, hours;
	float total = 0, payment;
	
	printf("Please input a pair of integers(ctrl-Z or ctrl-D to end): ");
	
	while (scanf("%d %d", &rate, &hours) != EOF){
		if(hours<=40){
			payment = (rate * hours) / 100.00;
			total += payment;
		}
		else if (hours<=60){
			payment = rate*40 + ((rate*1.5)*(hours-40));
			payment /= 100;
			total += payment;
		}
		else {
			payment = rate*40 + ((rate*1.5)*20) + ((rate*2)*(hours-60));
			payment /= 100;
			total += payment;
		}
		printf("Pay at %d centavos/hr for %d hours is %.2f pesos\n\n", rate, hours, payment);
		printf("Please input a pair of integers(ctrl-Z or ctrl-D to end): ");
	}
	printf("Total pay is %.2f pesos", total);
	
	return 0;
}
