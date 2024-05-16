#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 5 - This program will display preset values of int, float, and char data types along with their addresses and the address of their respective addresses. After the
first table, the program will ask the user for a new set of values of each data type and then display them again in table similar to that of the first.*/

void replaceValues(int*, float*, char*); //function prototype for getting new set of values later

int main(int argc, char *argv[]) {
	
	//declaration of variables, initialized to a preset of values of the author's choice
	int kutsINTa = 183;
	float cokeFloat = 76.83;
	char charizard = 'g';
	
	//declaration of pointer variables that points to the addresses of the variables declared before
	int* intPtr = &kutsINTa;
	float* floatPtr = &cokeFloat;
	char* charPtr = &charizard;
	
	//displays the variable names, the data types, the addresses, the values, and the addresses of their respective addresses in a table
	printf("Variable_name\tType\tAddress\t\t\t\tValue\n");
	printf("----------------------------------------------------------------\n");
	printf("cokeFloat\tfloat\t%p\t\t%5.2f\n", floatPtr, cokeFloat);
	printf("kutsINTa\tint\t%p\t\t%5d\n", intPtr, kutsINTa);
	printf("charizard\tchar\t%p\t\t%5c\n", charPtr, charizard);
	printf("floatPtr\tfloat*\t%p\t%p\n", &floatPtr, &cokeFloat);
	printf("intPtr\t\tint*\t%p\t%p\n", &intPtr, &kutsINTa);
	printf("chartPtr\tchar*\t%p\t%p\n\n", &charPtr, &charizard);
	
	replaceValues(intPtr, floatPtr, charPtr); //calls the function that will allow the user to input a new value for each data type
	
	//displays the variable names, the data types, the addresses, the new values, and the addresses of their respective addresses in a table
	printf("Variable_name\tType\tAddress\t\t\t\tNew_Value\n");
	printf("----------------------------------------------------------------\n");
	printf("cokeFloat\tfloat\t%p\t\t%5.2f\n", floatPtr, cokeFloat);
	printf("kutsINTa\tint\t%p\t\t%5d\n", intPtr, kutsINTa);
	printf("charizard\tchar\t%p\t\t%5c\n", charPtr, charizard);
	printf("floatPtr\tfloat*\t%p\t%p\n", &floatPtr, &cokeFloat);
	printf("intPtr\t\tint*\t%p\t%p\n", &intPtr, &kutsINTa);
	printf("chartPtr\tchar*\t%p\t%p\n", &charPtr, &charizard);
	
	return 0;
}

void replaceValues(int* intPtr, float* floatPtr, char* charPtr){ //function definition for getting the new set of values
	
	//prompts the appropriate input and scans that input to replace the author's preset values
	printf("Input a new value for cokeFloat: "); scanf("%f", floatPtr);
	printf("Input a new value for kutsINTa: "); scanf("%d", intPtr);
	printf("Input a new value for charizard: "); scanf(" %c", charPtr);
	printf("\n");
	
}
