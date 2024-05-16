#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 6 - This program will ask the user to input 10 strings, all assumed to contain only letters. After each input, the program will convert the string to all lower
cases form, and then assigns its address to a pointer variable in an array of pointers. Using the addresses, the program will the arrange the strings in lexicographic order, where the
strings are arranged from shortest to longest. In the case of eequal lengths, the concerned strings are arranged alphabetically. After sorting, the arranged order is then displayed.*/

//function prototypes for arranging the strings and lowering the letter cases
void arrangeStrings(char*[]);
void toLower(char[]);

int main(int argc, char *argv[]) {
	
	char strArr[10][50]; //declaration of char matrix a.k.a. array of strings
	char *strArrPtr[10]; //declaration of pointers array for the strings
	int i=0; //declaration of loop counter variables
	
	for (i=0; i<10; i++){ //for-loop that will prompt the user to input the 10 strings, all the while lowering the cases after each input and then assigning a pointer to each input
		printf("Input string%d:", i+1); scanf("%s", *(strArr+i));
		toLower(*(strArr+i)); //calls the function that will make all letters in lower case form
		*(strArrPtr+i) = *(strArr+i); //assigns a pointer to each input
	}
	
	arrangeStrings(strArrPtr); //function call to arrange/sort the strings
	
	printf("\n\nLEXICOGRAPHIC ORDERING:\n\n"); //headers for the table display that will contain the sorted strings
	printf("STRING\t\t\tADDRESS\t\t\tLENGTH\n\n");
	
	for(i=0; i<10; i++){ //for-loop that outputs the strings, their addresses, and their lengths, arranged in lexicographic order
		printf("%-15s\t\t%p\t%d\n",*(strArrPtr+i), *(strArrPtr+i), strlen(*(strArrPtr+i)));
	}
	return 0;
}

void arrangeStrings(char* strArrPtr[]){ //function definition for the arranging of the strings
	int i,j, pos; //loop counter variables, and as well as a marker (pos) for swapping places
	char* tempPtr = NULL; //temporary pointer variable for swapping to what values the pointers are pointing
	
	for(i=0; i<10; i++){ //for-loop that sorts the strings, follows the selection sort algorithm
		pos=i;
		for(j=i; j<10; j++){
			if(strlen(*(strArrPtr+pos))>strlen(*(strArrPtr+j))) pos=j; //checks for the longest string and marks it for swapping places
			else if(strlen(*(strArrPtr+pos))==strlen(*(strArrPtr+j))){ //in the case of equal lengths, compares the two equally long strings which goes first in alphabetical order
				if (strcmp(*(strArrPtr+pos), *(strArrPtr+j))>0) pos=j;
			}
		}
		if(pos!=i){ //swaps the places of the strings
			tempPtr = *(strArrPtr+i);
			*(strArrPtr+i) = *(strArrPtr+pos);
			*(strArrPtr+pos) = tempPtr;
		}
	}
}

void toLower(char str[]){ //function definition that will change the upper cases to lower cases
	int i; //loop counter variable
	for(i=0; i<strlen(str); i++){ //for-loop that will check each element in the passed string and changes it to lower case if originally found to be upper case (using ASCII values)
		if(*(str+i)<97) *(str+i) += 32;
	}
}
