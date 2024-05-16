#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 7 - This program will read a file named "in.txt" and will then check its content. Should the program encounter a vowel in the input file, regardless of
capitalization, it will replace that vowel with a 1 for A/a, 2 for E/e, 3 for I/i, 4 for O/o, and 5 for U/u in the output file, which is/will be named "out.txt". In addition to replacing
the vowels with their respective letters in the output, the program will also count the number of occurences for each vowel and then display it, along with the content of the input file.*/

int main(int argc, char *argv[]) {
	
	int i; //loop counter variable
	FILE *inputFile = NULL, *outputFile = NULL; //pointers for input and output files
	char inputString[100]; //char array (string) for storing content from input file
	int vowelCount[5] = {0}; //array for counting the vowels
	
	inputFile = fopen("in.txt", "r"); //opens input file for reading
	outputFile = fopen("out.txt", "w"); //opens output file for writing
	
	printf("Content of the file:\n");
	
	while(fscanf(inputFile, "%s", inputString)==1){ //loops to check all lines/strings in the input file
		
		int length = strlen(inputString); //gets length of current line 
		for(i=0; i<length; i++){ //loops to iterate throughout the entire string
			printf("%c", inputString[i]); //displays on screen each letter/character
			switch(inputString[i]){ //switch-case statement for proper response to the current character whether it's a vowel or not.
				case 'a':
				case 'A': vowelCount[0]++;
				fprintf(outputFile, "%c", '1'); //replaces letter a/A with 1 in output file
				break;
				case 'e':
				case 'E': vowelCount[1]++;
				fprintf(outputFile, "%c", '2'); //replaces letter e/E with 2 in output file
				break;
				case 'i':
				case 'I': vowelCount[2]++;
				fprintf(outputFile, "%c", '3'); //replaces letter i/I with 3 in output file
				break;
				case 'o':
				case 'O': vowelCount[3]++;
				fprintf(outputFile, "%c", '4'); //replaces letter o/O with 4 in output file
				break;
				case 'u':
				case 'U': vowelCount[4]++;
				fprintf(outputFile, "%c", '5'); //replaces letter u/U with 5 in output file
				break;
				default: fprintf(outputFile, "%c", inputString[i]); //writes on output file the character if it is not a vowel
				break;	
			}
		}
		
		fprintf(outputFile, "\n"); //writes a new line in output file after reaching the end of the current string
		printf("\n");
		
	}
	
	printf("\n");
	printf("A/a occurred %d time(s).\n", vowelCount[0]); //prints how many of the letter a/A was found in the entire input file
	printf("E/e occurred %d time(s).\n", vowelCount[1]); //prints how many of the letter e/E was found in the entire input file
	printf("I/i occurred %d time(s).\n", vowelCount[2]); //prints how many of the letter i/I was found in the entire input file
	printf("O/o occurred %d time(s).\n", vowelCount[3]); //prints how many of the letter o/O was found in the entire input file
	printf("U/u occurred %d time(s).\n", vowelCount[4]); //prints how many of the letter u/U was found in the entire input file
	
	return 0;
}
