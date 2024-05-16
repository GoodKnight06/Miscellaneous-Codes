#include <stdio.h>
#include <stdlib.h>

/* Author: Lance Stephen L. Bronzal | BUCS BSCS 1A*/

int f1(int, int);
int f2(int);

int main(int argc, char *argv[]) {
	
	int X,Y;
	char choice;
	
	printf("Input two positive integers: "); scanf("%d %d", &X, &Y);
	printf("\nWhat would you like to do?\n");
	printf(" [A/a] Get sum of all the integers between %d and %d.\n", X, Y);
	printf(" [B/b] Find sum of the digits of %d and %d.\n", X, Y);
	printf("Enter letter of choice: "); scanf(" %c", &choice);
	printf("\n");
	
	switch(choice){
		case 'a':
		case 'A': if(X<Y) printf("The sum of the integers from %d up to %d is %d.", X, Y, f1(X,Y));
				  else printf("The sum of the integers from %d up to %d is %d.", Y, X, f1(X,Y));
				  break;
		case 'b':
		case 'B': printf("The sum of the digits of %d and %d is %d.", X, Y, f2(X)+f2(Y));
				  break;
		default: printf("Not a valid letter of choice!");
				 break;
	}
	
	return 0;
}

int f1(int x, int y){ //adds all integers from x to y if x is less than y, or y to x if otherwise x is greater than or equal to y (effectively sum will just be the same)
	int count, sum=0;
	if(x<y){
		for(count=x; count<=y; count++){
			sum+=count;
		}
	}
	else{
		count=x;
		do{
			sum+=count;
			count--;
		} while(count>=y);
	}
	return sum;
}

int f2(int n){
	return n<10?n:(n%10)+f2(n/10); //checks if number has only one digit and returns it if yes. otherwise, gets its one diigit and then checks the next digit and later add together.
}
