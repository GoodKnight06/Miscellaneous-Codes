#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define lli long long int

// Programming Project 1 - A program that generates n values (random or computed) into an array passed for sorting by 6 sorting algorithms
/* Authors: Clarizze Joanna Abigan, Lance Stephen Bronzal, Lean Jedfrey Deduque, Francis Maurice Miranda | BSCS 2A */

/*--Function Prototypes--*/
void randomize(lli[], lli[], lli[], lli[], lli[], lli[], lli);
void compute(lli[], lli[], lli[], lli[], lli[], lli[], lli, lli);
void bubbleSort(lli[], lli);
void selectionSort(lli[], lli);
void insertionSort(lli[], lli);
void mergeSort(lli[], lli, lli);
void merge(lli[], lli, lli, lli);
void quickSort(lli[], lli, lli);
lli partition(lli[], lli, lli);
lli medianOfThree(lli[], lli, lli);
void heapSort(lli[], lli);
void heapify(lli[], lli, lli);
void writeResults(lli[], lli, int);

int main(int argc, char *argv[]) {
	
	//variable declarations
	int choice;
	lli n, x;
	time_t t;
	clock_t start, end;
	double cpu_time_used;
	
	srand((unsigned) time(&t)); //resets seed based on time to avoid repeating random numbers across different runs
	do {
		//menu interface
		printf("\n\t*****************************************\n");
    	printf("\t\t    SORTING ALGORITHMS \n");
    	printf("\t*****************************************\n");
    	printf("\t\t\tMENU \n");
	    printf("\t*  Please choose from the options below *\n\n");
	    printf("\t1 - Randomly-generated values\n");
	    printf("\t2 - Computed values\n");
	    printf("\t3 - Exit program\n\n");
	    printf("\tEnter your choice: ");
	    scanf("%d", &choice);
	    printf("\t*****************************************\n");
		
		if(choice == 1 || choice == 2){
			printf("\tEnter n: ");
			scanf("%lld", &n); //n represents array size to sort
			
			//memory allocation for arrays to sort, one array for each sorting algorithm
			lli* arr1 = (lli*)malloc(n * sizeof(lli));
			lli* arr2 = (lli*)malloc(n * sizeof(lli));
			lli* arr3 = (lli*)malloc(n * sizeof(lli));
			lli* arr4 = (lli*)malloc(n * sizeof(lli));
			lli* arr5 = (lli*)malloc(n * sizeof(lli));
			lli* arr6 = (lli*)malloc(n * sizeof(lli));
			if(choice == 2){
				printf("\tEnter x: ");
				scanf("%lld", &x); //x is used for computing arrays' values
				compute(arr1, arr2, arr3, arr4, arr5, arr6, n, x); //function call to compute and generate arrays' values
			}
			else {
				randomize(arr1, arr2, arr3, arr4, arr5, arr6, n); //function call to randomize arrays' values
			}
			printf("\t*****************************************\n");
			
			/* starts timer, sorts array, stops timer, calculates duration, writes result, repeat with another sorting algorithm */
			start = clock();
			bubbleSort(arr1, n); //calls function to sort array using Bubble sort
			end = clock();
			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("\tBubble Sort runtime:\t\t%lfs\n", cpu_time_used);
			writeResults(arr1, n, 1);
			
			start = clock();
			selectionSort(arr2, n); //calls function to sort array using Selection sort
			end = clock();
			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("\tSelection Sort run time:\t%lfs\n", cpu_time_used);
			writeResults(arr2, n, 2);
			
			start = clock();
			insertionSort(arr3, n); //calls function to sort array using Insertion sort
			end = clock();
			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("\tInsertion Sort run time:\t%lfs\n", cpu_time_used);
			writeResults(arr3, n, 3);
			
			start = clock();
			mergeSort(arr4, 0, n - 1); //calls function to sort array using Merge sort
			end = clock();
			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("\tMerge Sort run time:\t\t%lfs\n", cpu_time_used);
			writeResults(arr4, n, 4);
			
			start = clock();
			quickSort(arr5, 0, n - 1); //calls function to sort array using Quick sort
			end = clock();
			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("\tQuick Sort run time:\t\t%lfs\n", cpu_time_used);
			writeResults(arr5, n, 5);
			
			start = clock();
			heapSort(arr6, n); //calls function to sort array using Heap sort
			end = clock();
			cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
			printf("\tHeap Sort run time:\t\t%lfs\n\n", cpu_time_used);
			writeResults(arr6, n, 6);
			
			//frees allocated memory for all arrays
			free(arr1);
			free(arr2);
			free(arr3);
			free(arr4);
			free(arr5);
			free(arr6);
			
			system("pause"); //allows viewing of results before clearing console
			system("cls");
		}
		else if (choice == 3){
			system("cls");
			printf("End of program. Thank you.\n\n");
			printf("Members:\n");
			printf("Clarizze Joanna Abigan\n");
			printf("Lance Stephen Bronzal\n");
			printf("Lean Jedfrey Deduque\n");
			printf("Francis Maurice Miranda\n");
		}
		else {
			printf("Invalid choice. Try again.\n");
			system("pause");
			system("cls");
		}
		
	} while(choice != 3); //repeats menu so long as not chosen to close
	return 0;
}

/*--Function Definitions--*/
void randomize(lli arr1[], lli arr2[], lli arr3[], lli arr4[], lli arr5[], lli arr6[], lli n){
	lli i, max = ULONG_MAX; //ULONG_MAX represents max value of unsigned long int data type
	FILE *f = NULL;
	
	max++; //incremented max because rand()'s highest possible value to generate if given a number m is m - 1
	f = fopen("output.out", "w");
	
	fprintf(f, "Original Array: ");
	for(i = 0; i < n; i++){
		arr1[i] = rand() % max; //randomizes value from 0 to ULONG_MAX
		//copies generated value to all arrays
		arr2[i] = arr1[i]; 
		arr3[i] = arr1[i];
		arr4[i] = arr1[i];
		arr5[i] = arr1[i];
		arr6[i] = arr1[i];
		fprintf(f, "%lld ", arr1[i]); //writes to file each generated element
	}
	fclose(f);
}

void compute(lli arr1[], lli arr2[], lli arr3[], lli arr4[], lli arr5[], lli arr6[], lli n, lli x){
	lli i;
	FILE *f = NULL;
	
	f = fopen("output.out", "w");
	
	fprintf(f, "Original Array: ");
	for(i = 0; i < n; i++){ //computes value for each element of the arrays
		arr1[i] = n + ((i + 1) * x);
		arr2[i] = n + ((i + 1) * x);
		arr3[i] = n + ((i + 1) * x);
		arr4[i] = n + ((i + 1) * x);
		arr5[i] = n + ((i + 1) * x);
		arr6[i] = n + ((i + 1) * x);
		fprintf(f, "%lld ", arr1[i]); //writes to file each computed element
	}
	fclose(f);
}

void bubbleSort(lli arr[], lli n){
	lli i, j, temp;
	
	//Bubble sort algorithm
	for(i = 0; i <  n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				//swaps adjacent elements if left is larger
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(lli arr[], lli n){
	lli i, j, minIndex, temp;
	
	//Selection sort algorithm
	for(i = 0; i < n - 1; i++){
		minIndex = i; //assumes index of current number as smallest number
		for(j = i + 1; j < n; j++){ //finds and selects index of smallest non-sorted element
			if(arr[j] < arr[minIndex]) minIndex = j;
		}
		//swaps smallest element to current element
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void insertionSort(lli arr[], lli n){
	lli i, j, key;
	
	//Insertion sort algorithm
	for(i = 1; i < n; i++){
		key = arr[i]; //gets current element for sorting reference
		j = i - 1;
		while(j >= 0 && key <= arr[j]){ //shifts numbers larger than current element to the right
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key; //inserts current element in correct index
	}
}

void mergeSort(lli arr[], lli start, lli end){
	if(start >= end){
		return;
	}
	lli mid = (start + end) / 2;
	mergeSort(arr, start, mid); //recursion call to merge sort left sub-array
	mergeSort(arr, mid + 1, end); //recursion call to merge sort right sub-array
	merge(arr, start, mid, end); //merges left and right sub-arrays
}

void merge(lli arr[], lli start, lli mid, lli end){
	lli left = mid - start + 1; //gets count of left sub-array
	lli right = end - mid; //gets count of right sub-array
	//temp arrays
	lli *temp_L = (lli*)malloc(sizeof(lli)*left);
	lli *temp_R = (lli*)malloc(sizeof(lli)*right);
	lli i, j, k = start;
	
	//copies elements of left and right sub-arrays to respective temp arrays
	for(i = 0; i < left; i++){
		temp_L[i] = arr[start + i];
	}
	for(j = 0; j < right; j++){
		temp_R[j] = arr[mid + 1 + j];
	}
	
	i = 0;
	j = 0;
	while(i < left && j < right){ //merges the two sub-arrays in ascending order
		if(temp_L[i] <= temp_R[j]){
			arr[k] = temp_L[i];
			i++;
		}
		else {
			arr[k] = temp_R[j];
			j++;
		}
		k++;
	}
	
	//adds remaining elements in case of uneven sub-arrays
	while(i < left){
		arr[k] = temp_L[i];
		i++;
		k++;
	}
	while(j < right){
		arr[k] = temp_R[j];
		j++;
		k++;
	}
	//frees allocated memory for temp arrays
	free(temp_L);
	free(temp_R);
}

void quickSort(lli arr[], lli start, lli end){
	if(start < end){
		lli p = partition(arr, start, end);
		quickSort(arr, start, p - 1);  //recursion call to quick sort left partition
		quickSort(arr, p + 1, end); //recursion call to quick sort right partition
	}
}

lli partition(lli arr[], lli start, lli end){
	lli index = medianOfThree(arr, start, end); //sorts start, middle, and last element of array and gets middle index
	lli pivot = arr[index]; //pivot chosen by median of three method
	lli i = start - 1, j = end + 1, temp; //added and deducted by 1 because of upcoming guaranteed increment/decrement
	
	while(1) {
		do {
			i++;
		} while(arr[i] < pivot); //starting from left, finds element larger than pivot
		do {
			j--;
		} while(arr[j] > pivot); //starting from right, finds element smaller than pivot
		if(i >= j){
			return j; //returns index of element sorted on correct position
		}
		//swaps found elements to separate the smaller elements from the larger elements to the left and right of pivot respectively
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

lli medianOfThree(lli arr[], lli start, lli end) {
    lli mid = (start + end) / 2, temp;
    
    //swaps and sorts start, middle, and last element of passed array
    if(arr[start] > arr[mid]){
    	temp = arr[start];
    	arr[start] = arr[mid];
    	arr[mid] = temp;
    }
	if(arr[start] > arr[end]){
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
	}
	if(arr[mid] > arr[end]){
		temp = arr[mid];
		arr[mid] = arr[end];
		arr[end] = temp;
	}
	return mid;
}

void heapSort(lli arr[], lli n){
	lli i, temp;
	
	for(i = (n / 2) - 1; i >= 0; i--){ //transforms array to max heap
		heapify(arr, n, i);
	}
	
	for(i = n - 1; i >= 0; i--){
		//swaps largest element to the back and ignores it from continued sorting
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0); //recursive function that transform array to max heap again
	}
}

void heapify(lli arr[], lli n, lli i){
	lli max = i, left = (2 * i) + 1, right = 2 * (i + 1), temp;
	
	//finds index of largest element
	if(left < n && arr[left] > arr[max]){
		max = left;
	}
	if(right < n && arr[right] > arr[max]){
		max = right;
	}
	if(max != i){
		//swaps elements to get the larger element to the start of array/top of heap
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		heapify(arr, n, max); //recurses to continue swapping smaller and larger numbers downwards and upwards respectively
	}
}

void writeResults(lli arr[], lli n, int count){
	lli i;
	FILE *f = NULL;
	
	f = fopen("output.out", "a");
	switch(count){ //writes appropriate sorting algorithm based on passed count
		case 1: fprintf(f, "\nBubble ");
		break;
		case 2: fprintf(f, "\nSelection ");
		break;
		case 3: fprintf(f, "\nInsertion ");
		break;
		case 4: fprintf(f, "\nMerge ");
		break;
		case 5: fprintf(f, "\nQuick ");
		break;
		case 6: fprintf(f, "\nHeap ");
		break;
	}
	fprintf(f, "Sort output: ");
	for(i = 0; i < n; i++){
		fprintf(f, "%lld ", arr[i]); //writes to file sorted elements
	}
	fclose(f);
}
