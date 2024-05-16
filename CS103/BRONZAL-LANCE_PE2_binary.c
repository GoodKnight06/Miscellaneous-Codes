#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 2 (Binary Search) - This program uses the Binary Search algorithm to search for a key element. However, this is modified so that this program will search the key
element in an array sorted in descending order, contrary to the standard Binary Search algorithm that searches for an element within an array sorted in ascending order.*/

int main(int argc, char *argv[]) {
	
	//variable declaration for storing the size of array
	int n;
	
	//prompt that asks for the size of the array
	printf("Enter the size of array: ");
	scanf("%d", &n);
	
	//declaration of the array itself
	int arr[n];
	
	//declaration of the variables for-loop counter, key value, first, last and middle index for searching in array, and flag for the presence/absence of key value in array respectively
	int i, key, first, last, mid, flag=0; 
	
	printf("Enter the elements of the %d-size array in descending order:\n");
	
	//for-loop to enter the elements of the arrray
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	//prompts to enter the key number to search for
	printf("Enter the key value to be searched: ");
	scanf("%d", &key);
	
	//assignment of the index values of the first and last element of the array respectively
	first=0;
	last=n-1;
	
	//while-loop that will search for key value and will stop either once the key is found or the search area in the array has been exhausted
	while(first<=last){
		
		mid=(first+last)/2; //gets the middle index of the search area
		
		//checks if the middle element of the search area matches the key and stops the search if yes but if not, the search area will be shifted accordingly
		if(key==arr[mid]){ 
			flag=1;
			break;
		}
		else if(key>arr[mid]) last=mid-1; //shifts the search area to the left half for the next iteration of the loop
		else first=mid+1; //shifts the search area to the right half for the next iteration of the loop
		
	}
	
	//prompts a display that corresponds to whether the key value is found or not
	if(flag) printf("Key=%d is found in position %d", key, mid+1);
	else printf("Key=%d was not found in the array.", key);
	
	return 0;
}
