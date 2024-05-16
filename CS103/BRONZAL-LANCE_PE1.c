#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 1 - This program will ask the user to input 10 integers and afterwards will ask for a key value. The program will then look from the 10 integers for numbers
less than the key value, to be followed by looking for numbers greater than the key value. Afterwards, the program will look for the key value itself in the array. If found, it will
display its corresponding index. Otherwise, will display that the key value is absent in the array.*/

//function prototypes
void getLessThanKey(int list[], int);
void getMoreThanKey(int list[], int);
int findKey(int list[], int);

int main(int argc, char *argv[]) {
	
	//Declaration of array 
	int list[10];
	
	//Variables for Key value and, if applicable, the index of the key value if found later in the array
	int key, index;
	
	printf("Input the 10 integers each separated by a space: \n\t");
	
	//for-loop to get 10 integers input
	int i;
	for(i=0; i<10; i++){
		scanf("%d", &list[i]);
	}
	
	//Prompt to input key value
	printf("Please enter the key value: ");
	scanf("%d", &key);
	printf("\n");
	
	//calls function that will get values less than key value
	getLessThanKey(list, key);
	
	//calls function that will get values greater than key value
	getMoreThankKey(list, key);
	
	//calls function that will find if key value is in array and return index (position in array) if found
	index=findKey(list, key);
	
	//checks if key value was found in array and displays the appropriate prompt
	if (index==-1){
		printf("The key=%d was not found in the array.", key);
	}
	else{
		printf("The key=%d was found at index %d.", key , index);
	}
	
	return 0;
}

//function definition to display values less than key
void getLessThanKey(int list[], int key){
	
	printf("Values in the array that are less than %d:\n\t", key);
	
	//for-loop that will find values less than key and display it
	int i;
	for(i=0; i<10; i++){
		if(list[i]<key) printf("%d ", list[i]);
	}
	printf("\n");
	
}

//function definition to display values greater than key
void getMoreThankKey(int list[], int key){
	
	printf("Values in the array that are greater than %d:\n\t", key);
	
	//for-loop that will find values greater than key and display it
	int i;
	for(i=0; i<10; i++){
		if(list[i]>key) printf("%d ", list[i]);
	}
	printf("\n");
	
}

//function definition that checks if key value is in array and return its index if found. Otherwise, will return an invald index to indicate the key value's absence in the array
int findKey(int list[], int key){
	
	//for-loop that will look for the key value in the array
	int i;
	for(i=0; i<10; i++){
		if(list[i]==key) return i;
	}
	return -1;
	
}
