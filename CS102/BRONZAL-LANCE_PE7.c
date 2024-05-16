#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

/* Programming Exercise 7 - This program will ask the user to input a character. If the input is any letter of the English alphabet, the program will output a line or a stanza
that which output depends on what the letter is. Otherwise, should the input be not a letter of the English alphabet, the program will simply state that the input is an invalid
character.*/

int main(int argc, char *argv[]) {
	
	char letter;
	printf("ALPHABET SONG\n");
	printf("Enter a letter: "); scanf("%c", &letter);
	
	printf("       '%c' - ", letter);
	switch(letter){
		case 'a':
		case 'A': printf("You're adorable");
				  break;
		case 'b':
		case 'B': printf("You're so beautiful");
				  break;
		case 'c':
		case 'C': printf("You're a cutie full of charms");
				  break;
		case 'd':
		case 'D': printf("You're a darling and");
				  break;
		case 'e':
		case 'E': printf("You're exciting and");
				  break;
		case 'f':
		case 'F': printf("You're a feather in my arms");
				  break;
		case 'g':
		case 'G': printf("You look good to me");
				  break;
		case 'h':
		case 'H': printf("You're so heavenly");
				  break;
		case 'i':
		case 'I': printf("You're the one I idolize");
				  break;
		case 'j':
		case 'J': printf("We're like Jack and Jill");
				  break;
		case 'k':
		case 'K': printf("You're so kissable");
				  break;
		case 'l':
		case 'L': printf("Is the love light in your eyes");
				  break;
		case 'm':
		case 'M':
		case 'n':
		case 'N':
		case 'o':
		case 'O':
		case 'p':
		case 'P': printf("I could go on all day");
				  break;
		case 'q':
		case 'Q':
		case 'r':
		case 'R':
		case 's':
		case 'S':
		case 't':
		case 'T': printf("Alphabetically speaking you're okay");
				  break;
		case 'u':
		case 'U': printf("Made my life complete");
				  break;
		case 'v':
		case 'V': printf("Means you're very sweet");
				  break;
		case 'w':
		case 'W':
		case 'x':
		case 'X':
		case 'y':
		case 'Y':
		case 'z':
		case 'Z': printf("It's fun to wander through\n"
						 "             The alphabet with you\n"
						 "             To tell you what you mean to me");
				  break;
		default: printf("Invalid character");
				 break;
	}
	
	return 0;
	
}
