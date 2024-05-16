#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDLENGTH 50

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 4 - This program will continuously ask the user for a string input. The program will then output its plural form by using a very general pattern, meaning special
cases would be erroneously pluralized (e.g. ox to oxes instead of oxen). That aside, the program will end once the user has inputted the end of file special character.*/

void pluralize(char word[WORDLENGTH], char plural[WORDLENGTH]); //function prototype for getting the plural form of input string

int main(int argc, char *argv[]) {
	
	//declaration of strings or char arrays
	char word[WORDLENGTH];
	char plural[WORDLENGTH];
	
	printf("Input a singular noun: ");
	while(scanf("%s", word)!= EOF){ //while-loop that will continiously ask for input and ends if end-of-file is entered
		
		pluralize(word, plural); //function call to pluralize the input noun
		
		//displays the plural form of the input, and then asks for another word to pluralize
		printf("Plural form: %s\n\n", plural); 
		printf("Input a singular noun: ");
		
	}
	
	printf("End of program.");
	
	return 0;
}

void pluralize(char word[], char plural[]){ //function definition for finding the appropriate plural form of the input
	
	int len = strlen(word); //takes the length of the input
	strcpy(plural, word); //copies the input to another string variable that will be later modified into its plural form
	
	//a cascaded block of if and if-else statements that will properly categorize the input to give its plural counterpart the right string manipulation
	if(word[len-1]=='y'){
		if(word[len-2]=='a' || word[len-2]=='e' || word[len-2]=='i' || word[len-2]=='o' || word[len-2]=='u'){
			strcat(plural, "s"); //adds 's' to the end of the string
		}
		else { //removes the last element and adds 'ies' to the end of the string
			plural[len-1]='\0';
			strcat(plural, "ies");
		}
	}
	else if(word[len-1]=='s' || (word[len-1]=='h' && (word[len-2]=='s' || word[len-2]=='c')) || word[len-1]=='x' || word[len-1]=='z'){
		strcat(plural, "es"); //adds 'es' to the end of the string
	}
	else {
		strcat(plural, "s"); //adds 's' to the end of the string
	}
	
}
