#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 2 (Insertion Sort) - This program uses the Insertion Sort algorithm to sort an unsorted array of numbers. However, this program is modified such that the sorted
array is in descending order, instead of ascending.*/

int main(int argc, char *argv[]) {
	
	//variable declaration for storing the size of array
	int n;
	
	//prompt that asks for the size of the array
	printf("Enter the size of array: ");
	scanf("%d", &n);
	
	//declaration of the array itself
	int arr[n];
	
	//declaration of the variables 2 for-loop counters, and a temp (short for temporary-valued) variable for swapping elements
	int i, j, temp;
	
	printf("Enter the elements of the %d-size array:\n");
	
	//for-loop to enter the elements of the arrray
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	//for-loop for the sorting of the array itself
	for(i=1; i<n; i++){
		
		temp=arr[i]; //gets the element to be swapped to its right place
		j=i-1;
		
		//will continously shift (smaller) numbers to the right until there are no more elements (the temp value will be the array's first)
		//or checked element is greater than temp (in which case, temp will be inserted to the right of this larger number)
		while(j>=0 && arr[j]<temp){ 
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1]=temp; //inserts the temp value to its correct index such that the element to its left is greater than the temp and the right, smaller than the temp
		
	}
	
	//displays the array sorted in descending order
	printf("Array after sorting:\n");
	for(i=0; i<n; i++) printf("%d ", arr[i]);
	
	return 0;
}
