#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);
int factorial(int);

int main(int argc, char *argv[]) {
	
	int input, i;
	do {
		printf("Enter a non-negative integer: ");
		scanf("%d", &input);
		if(input < 0) {
			printf("Invalid input. Try again!\n");
		}
	} while(input < 0);
	printf("Fibonacci: ");
	for(i = 0; i <= input; i++){
		printf("%d ", fibonacci(i));
	}
	printf("\nFactorial: ");
	for(i = 1; i <= input; i++){
		printf("%d ", factorial(i));
	}
	return 0;
}

int fibonacci(int i){
	switch (i){
		case 0: return 0;
		break;
		case 1: return 1;
		break;
		default: return fibonacci(i - 2) + fibonacci(i - 1);
		break;
	}
}

int factorial(int i){
	if(i == 1){
		return 1;
	}
	else {
		return i * factorial(i - 1);
	}
}
