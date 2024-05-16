#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 2 (Merge Sort) - This program uses the Merge Sort algorithm to sort an unsorted array of numbers but instead of sorting it in ascending order, this program is
modified to sort the array in descending order.*/

//prototype declaration for functions
void mergeSort(int arr[], int, int, int);
void merge(int arr[], int, int, int, int, int);

int main(int argc, char *argv[]) {
	
	//variable declaration for storing the size of array
	int n;
	
	//prompt that asks for the size of the array
	printf("Enter the size of array: ");
	scanf("%d", &n);
	
	//declaration of the array itself
	int arr[n];
	
	//declaration of the for-loop counter variable
	int i;
	
	printf("Enter the elements of the %d-size array:\n");
	
	//for-loop to enter the elements of the arrray
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	mergeSort(arr, 0, n-1, n); //calls for the function that will begin [merge] sorting the given array (0 and n-1 represents the first and last indices, thus covering the entire array)
	
	//displays the array sorted in descending order
	printf("Array after sorting:\n");
	for(i=0; i<n; i++) printf("%d ", arr[i]);
	
	return 0;
}

void mergeSort(int arr[], int i, int j, int n){ //function definition for splitting the array into sub-arrays and later merge them back to one after sorting

	int mid; //variable for the middle index
	
	if(i<j){
		mid=(i+j)/2; //gets middle index of passed array (or sub-array for recursive cases)
		mergeSort(arr, i, mid, n); //recursion covering the left half of the given array (or sub-array)
		mergeSort(arr, mid+1, j, n); //recursion covering the right half of the given array (or sub-array)
		merge(arr, i, mid, mid+1, j, n); //merge back two sorted sub-arrays to one
	}

}

void merge(int arr[], int a, int b, int x, int y, int n){ //function definition for merging two sub-arrays into one
	
	int temp[n], i = a, j = x, k = 0; //variables for temporary array, first sub-array's first element, second sub-array's first element, and later index loop-counters along with k
	
	while(i<=b && j<=y){ //while-loop that that merges two sub-arrays, prioritizing elements according to [descending] order
		if (arr[i]>arr[j]) temp[k++] = arr[i++];
		else temp[k++]=arr[j++];
	}
	
	//the next two while-loops are for cases where the two sub-arrays are not equal in size (uneven distribution/splitting of array to two sub-arrays)
	while(i<=b) temp[k++]=arr[i++];
	while(j<=y) temp[k++]=arr[j++];
	
	//for-loop that will put [sorted] elements back to arr[] (effectively manipulating the original array)
	for(i=a, j=0; i<=y; i++, j++) arr[i]=temp[j];
	
}
