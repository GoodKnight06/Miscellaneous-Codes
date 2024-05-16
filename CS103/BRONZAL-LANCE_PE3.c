#include <stdio.h>
#include <stdlib.h>

//macrodefinitions
#define NROWS 100
#define NCOLUMNS 100

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 3 - This program will ask for the dimensions and the elements of a matrix of integers and will find for and display its transposed form or counterpart. Then,
it will display both the original matrix and its transposed form in a table, accompanied by each respective row's and column's sums and as well as the matrix's overall total of all its
elements. This tables will be displayed after calculating said sums.*/

//function prototypes for subtasks
void findTranspose(int M[][NCOLUMNS], int, int);
int getSums(int M[][NCOLUMNS], int rowSums[], int colSums[], int, int);

int main(int argc, char *argv[]) {
	
	//variables for number of rows and columns
	int rows, columns;
	
	//the variables for the matrix and its transpose
	int M[NROWS][NCOLUMNS];
	int t[NCOLUMNS][NROWS];
	
	//the arrays for the respective rows' and columns's sums
	int rowSums[NROWS];
	int colSums[NCOLUMNS];
	int sum; //variable for the sum of the entire matrix's elements
	int i, j; //loop control counter variables
	
	//gets input for the dimensions of the matrix
	printf("Input the dimension of the matrix(row column): ");
	scanf("%d %d", &rows, &columns);
	
	//nested for-loop that will take the input as elements of the original matrix
	printf("Please enter the elements of the %dx%d matrix:\n", rows, columns);
	for(i=0; i<rows; i++){
		for(j=0; j<columns; j++) scanf("%d", &M[i][j]);
	}
	printf("\n");
	
	findTranspose(M, rows, columns); //function call to find and display the transpose of original matrix
	
	sum = getSums(M, rowSums, colSums, rows, columns); //function call to get the respective sums of each row and column and as well as the total of entire matrix
	
	/*outputs the original matrix and its rows' and columns' respective totals and grand total on a table.
	Some of the extra for-loops are to imitate the formatting of the display in the sample given.
	The nested for-loop is for displaying the elements of the matrix elements itself, and the arrays are for the sums of each row and column*/
	printf("Sum of each row and column of the original matrix:\n\t\t");
	for(i=0; i<columns; i++) printf("    ");
	printf("Sum-of-Row\n");
	for(i=0; i<rows; i++){
		printf("\t\t");
		for(j=0; j<columns; j++) printf("%3d ", M[i][j]);
		printf("| %3d\n", rowSums[i]);
	}
	printf("\t\t  ");
	for(i=0; i<columns; i++) printf("-----");
	printf("\n");
	printf("Sum-of-Column   ");
	for(i=0; i<columns; i++) printf("%3d ", colSums[i]);
	printf("| %3d\n\n", sum);
	
	/*outputs the transpose matrix and its rows' and columns' respective totals and grand total on a table.
	Some of the extra for-loops are to imitate the formatting of the display in the sample given, the same for the original matrix displaying code above.
	The nested for-loop is for displaying the elements of the matrix elements itself, and the arrays are for the sums of each row and column*/
	printf("Sum of each row and column of the transpose matrix:\n\t\t");
	for(i=0; i<rows; i++) printf("    ");
	printf("Sum-of-Row\n");
	for(i=0; i<columns; i++){
		printf("\t\t");
		for(j=0; j<rows; j++) printf("%3d ", M[j][i]);
		printf("| %3d\n", colSums[i]);
	}
	printf("\t\t  ");
	for(i=0; i<columns; i++) printf("-----");
	printf("\n");
	printf("Sum-of-Column   ");
	for(i=0; i<rows; i++) printf("%3d ", rowSums[i]);
	printf("| %3d\n\n", sum);
	
	return 0;
}

void findTranspose(int M[][NCOLUMNS], int rows, int columns){
	
	int i, j; //loop control counter variables
	
	//nested for-loop the skims through the original matrix and prints each element in its transpose counterpart arrangement
	printf("Transpose of the matrix:\n");
	for(i=0; i<columns; i++){
		for(j=0; j<rows; j++) printf("%3d ", M[j][i]);
		printf("\n");
	}
	
}

int getSums(int M[][NCOLUMNS], int rowSums[], int colSums[], int rows, int columns){
	
	int sum=0; //variable for passed matrix's sum
	int i,j, k; //loop control counter variables
	
	for(i=0; i<rows; i++){//nested for-loop to get the totals of each row
		int subTotal=0; //variable for subtotal of each row
		for(j=0; j<columns; j++){
			subTotal+=M[i][j];
			sum+=M[i][j]; //while skimming through the original matrix, all the elements are added together
		}
		rowSums[i] = subTotal; //assigns the subtotal to the corresponding position in the arrray of subtotals of the rows
	}
	
	for(i=0; i<columns; i++){//nested for-loop to get the totals of each column
		int subTotal=0; //variable for subtotal of each column
		for(j=0; j<rows; j++) subTotal+=M[j][i];
		colSums[i] = subTotal; //assigns the subtotal to the corresponding position in the arrray of subtotals of the columns
	}
	
	return sum;
	
}
