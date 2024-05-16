#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Midterm Practical Exam - This program will ask the user to input a string of at most 200 characters. The program will then check the characters of the string and count the instances
of each letter in both lower and upper cases. The frequency counts are stored in an integer matrix, where 2 rows are occupied by ASCII values of all the letters and the third row for
the counts of instances for each letter. After checking the string, the program then displays the length of the string and as well as all letters with at least one instance, along with
how many instances of that letter (accounting both upper and lower cases) were seen inside the input string. */

void frequencyCheck(char*, int[][26]); //function prototype for checking how many instances per letter

int main(int argc, char *argv[]) {
	
	char input[200]; //the char array for input string
	char* strPtr; //the pointer for the input string
	int i; //loop counter variable
	
	int frequencyTable[3][26] = { //the 2d array (or matrix) where the ASCII values and instances are stored
								{65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81,82, 83, 84, 85, 86, 87, 88, 89, 90},
								{97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122},
								{0}	};
	
	printf("Please input a string(at most 200 characters):\n\t"); //prompts the user to input a string
	scanf("%s", input); //will take the input and store to char array
	strPtr = input; //assigns the pointer to point towards the string (first element of the string to be exact)
	
	frequencyCheck(strPtr, frequencyTable); //calls the function that will check how many instances per letter is present in the input
	
	printf("\nString length:%d\n\n", strlen(strPtr)); //displays the length of the input string
	printf("Frequency of letters in the string:\n"); 
	for(i=0; i<26; i++){ //for-loop that will traverse the matrix' 3rd row and look for all letters with at least one instance, along with how many instances were counted
		//will check if a certain letter has at least one instance and prints it and its frequency if present; otherwise, the letter will not be displayed 
		if(frequencyTable[2][i]>0) printf("\t%c/%c\t%d\n", frequencyTable[0][i], frequencyTable[1][i], frequencyTable[2][i]); 
	}
	
	return 0;
}

void frequencyCheck(char* strPtr, int frequencyTable[][26]){ //function definition for checking how many instances per letter present in the input
	int i; //loop counter variable
	
	for(i=0; i<strlen(strPtr); i++){ //for-loop that will traverse the string and manipulate the integer matrix per instance of letter encountered
		if (*(strPtr+i)>=65 && *(strPtr+i)<=90) frequencyTable[2][(*(strPtr+i))-65]++; //adds 1 to the frequency count for the corresponding letter (this is for upper case letters)
		else if (*(strPtr+i)>=97 && *(strPtr+i)<=122) frequencyTable[2][(*(strPtr+i))-97]++; //adds 1 to the frequency count for the corresponding letter (this is for lower case letters)
	}
	
}
