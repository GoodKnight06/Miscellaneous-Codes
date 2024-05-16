#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Author: Lance Stephen L. Bronzal | BUCS BSCS 1A */

int main(int argc, char *argv[]) {
	
	int num1, num2, num3, num4, num5;
	
	printf("\"CS102 Practical Exam 1\"\n\n");
	printf("Input the five integers separated by a space:\n");
	scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
	
	printf("\nSquares of the numbers: %d, %d, %d, %d, %d\n", num1*num1, num2*num2, num3*num3, num4*num4, num5*num5);
	printf("Sum of the squares: %d\n", (num1*num1)+(num2*num2)+(num3*num3)+(num4*num4)+(num5*num5));
	printf("Average of the squares: %.2f\n", ((num1*num1)+(num2*num2)+(num3*num3)+(num4*num4)+(num5*num5)*1.0)/5);
	printf("Square root of the squares' sum: %.4f\n", sqrt((num1*num1)+(num2*num2)+(num3*num3)+(num4*num4)+(num5*num5)));
	
	return 0;
}
