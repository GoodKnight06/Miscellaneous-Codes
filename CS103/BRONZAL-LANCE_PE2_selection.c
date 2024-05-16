#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 2 (Selection Sort) - This program uses the Selection Sort algorithm to sort an unsorted array of elements. However, this program is modified such that the sorting
is done in descending order.*/

int main(int argc, char *argv[]) {
	
	//variable declaration for storing the size of array
	int n;
	
	//prompt that asks for the size of the array
	printf("Enter the size of array: ");
	scanf("%d", &n);
	
	//declaration of the array itself
	int arr[n];
	
	//declaration of the variables 2 for-loop counters, and the position in the array of the largest unsorted number and its value (for swapping) respectively
	int i, j, pos, swap; 
	
	printf("Enter the elements of the %d-size array:\n");
	
	//for-loop to enter the elements of the arrray
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	//for-loop for the sorting of the array itself
	for(i=0; i<n-1; i++){
		
		pos=i; //the position of the element to be sorted, with its corresponding value as the assumed smallest number
		
		for(j=i; j<n; j++){ //this for-loop will look for the smallest number
			if(arr[pos]<arr[j]) pos=j;
		}
		if (pos!=i){ //if a smaller number was found (i.e. the position is different with the presumed position), the i-element will swap places with the smaller number
			swap=arr[i];
			arr[i]=arr[pos];
			arr[pos]=swap;
		}
		
	}
	
	//displays the array sorted in descending order
	printf("Array after sorting:\n");
	for(i=0; i<n; i++) printf("%d ", arr[i]);
	
	return 0;
}
