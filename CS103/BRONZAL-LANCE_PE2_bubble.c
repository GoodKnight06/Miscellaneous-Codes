#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 2 (Bubble Sort) - This program uses the Bubble Sort algorithm to sort an unsorted array of numbers but is modified such that the program will sort the array in
descending order.*/

int main(int argc, char *argv[]) {
	
	//variable declaration for storing the size of array
	int n;
	
	//prompt that asks for the size of the array
	printf("Enter the size of array: ");
	scanf("%d", &n);
	
	//declaration of the array itself
	int arr[n];
	
	//declaration of the variables 2 for-loop counters, and a temp variable to swap adjacent elements
	int i, j, temp;
	
	printf("Enter the elements of the %d-size array:\n");
	
	//for-loop to enter the elements of the arrray
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	//for-loop for the sorting of the array itself
	for(i=1; i<n; i++){ //for every iteration, will swap adjacent numbers across the array such that the larger of the two is on the left and the smaller on the right
		
		for(j=0; j<n-i; j++){//across the array, adjacent numbers are compared and will swap places if necessary
			
			if(arr[j]<arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}	
		}
	}
	
	//displays the array sorted in descending order
	printf("Array after sorting:\n");
	for(i=0; i<n; i++) printf("%d ", arr[i]);
	
	return 0;
}
