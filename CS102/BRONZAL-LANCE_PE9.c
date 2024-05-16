#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

/* Programming Exercise 9 - This program will continuously ask for the user to input positive integers. Every input, the program will test the inputted number to see if it is a prime
number or not, and as well as to check if whether or not the input is a perfect number. After the computations, the program will then display if the number passes the conditions for
both being as a prime number or a perfect number. The program will stop running once the user inputs zero (0).*/

int isPrime(int num){
	int factor;
	for(factor=2; factor<=num/2; factor++){
		if(num%factor==0){
			return 0;
		}
	}
	return 1;
}

int isPerfect(int num){
	int sum = 1, factor;
	for(factor=2; factor<=num/2; factor++){
		if(num%factor==0){
			sum+=factor;
		}
	}
	if(sum==num) return 1;
	else return 0;
}

int main(int argc, char *argv[]) {
	
	int num;
	
	printf("Enter a positive integer(0 to end): "); scanf("%d", &num);
	while(num>0){
		
		if(isPrime(num)){
			printf(" prime: YES\n");
		}
		else{
			printf(" prime: NO\n");
		}
		if(isPerfect(num)){
			printf(" perfect: YES\n\n");
		}
		else{
			printf(" perfect: NO\n\n");
		}
		
		printf("Enter a positive integer(0 to end): "); scanf("%d", &num);
	}
	printf(" End of program.Thanks!");
	return 0;
}
