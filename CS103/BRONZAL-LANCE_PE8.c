#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A  */

/* Programming Exercise 8 - This program will read from an input file "students.txt" a list of N students and will group the students together according to their gender. After grouping
the students to their respective genders, the program will then sort the students by arranging them alphabetically and later output them on the terminal in addition to write the grouped 
and sorted list in an output file named "sorted.txt".*/

//structure for students containing their respective details
struct student{
	char name[15];
	int number;
	int age;
	char gender;
}males[50], females[50]; //declaration of structure array for male and female students
	
void groupAndSort(struct student[]); //function prototype for reading, grouping, sorting, and displaying the students

int main(int argc, char *argv[]) {
	
	struct student students[50]; //structure array where the raw list (ungrouped and unsorted yet) of students will be stored
	FILE *input = NULL; //FILE pointer for input file
	
	input = fopen("students.txt", "r"); //opens input file
	if(input!=NULL){ //checks if input file exists
		groupAndSort(students); //calls function to read, group, sort, then display the students according to instructions
	}
	else {
		printf("No input file detected.\n"); //prompts that the input file does not exist
	}
	
	fclose(input); //closes input file reading
	return 0;
	
}

void groupAndSort(struct student students[]){ //function definition for accomplishing tasks
	
	int malesNum=0, femalesNum=0, N, i, j, k, pos, swapInt; //variables for number of male and female students, the total number of students, loop counters, and temp variable for swap
	FILE *input = NULL, *output = NULL; //FILE pointers for input and output files
	struct student *sPtr; //struct pointer for switching between males and females struct arrays
	char swapName[15]; //temp string for swapping (sorting)
	int *nPtr; //int pointer for switching between number of males and number of females
	
	input = fopen("students.txt", "r"); //opens input file for reading
	fscanf(input, "%d", &N); //reads how many students in total
	for(i=0; i<N; i++){ //loops to read all students in the input file
		fscanf(input, "%s %d %d %c", students[i].name, &students[i].number, &students[i].age, &students[i].gender); //reads and stores into struct array the details in the input file
		
		if(students[i].gender=='M'){ //checks if current student is male or female and pointers will switch to respective variables for males and females
			sPtr = males;
			nPtr = &malesNum;
		}
		else {
			sPtr = females;
			nPtr = &femalesNum;
		}
		
		//copies current student's details to pointed struct array in respective index, effectively grouping the males and females together, in order of appearance in input file
		strcpy((sPtr+(*nPtr))->name, students[i].name); 
		(sPtr+(*nPtr))->number = students[i].number;
		(sPtr+(*nPtr))->age = students[i].age;
		(sPtr+(*nPtr))->gender = students[i].gender;
		(*nPtr)++;
		
	}
	
	for(i=0; i<2; i++){ //loop for sorting both males and females list
		if(i==0){ //switches pointers to each group, males first and then females
			sPtr = males;
			nPtr = &malesNum;
		}
		else {
			sPtr = females;
			nPtr = &femalesNum;
		}
		
		for(j=0; j<(*nPtr)-1; j++){ //sorts current pointed struct array, selection algorithm used
			pos=j;
			for(k=j; k<*nPtr; k++){
				if(strcmp((sPtr+pos)->name, (sPtr+k)->name)>0) pos=k; //checks for shortest and foremost name in terms of alphabetical arrangement
			}
			if(pos!=j){ //if a shorter and a more forerunning name is found, the students' details will swap places in their respective struct arrays
				//swaps the places of their numbers
				swapInt = (sPtr+j)->number;
				(sPtr+j)->number = (sPtr+pos)->number;
				(sPtr+pos)->number = swapInt;
				
				//swaps the places of their ages
				swapInt = (sPtr+j)->age;
				(sPtr+j)->age = (sPtr+pos)->age;
				(sPtr+pos)->age = swapInt;
				
				//swaps the places of their names
				strcpy(swapName, (sPtr+j)->name);
				strcpy((sPtr+j)->name, (sPtr+pos)->name);
				strcpy((sPtr+pos)->name, swapName);
			}
		}
	}
	fclose(input); //closes reading of input file
	
	output = fopen("sorted.txt", "w"); //opens output file for writing / create output file if it does not exist
	
	//displays and writes in output file the details of each respective student in the list, grouped together according to gender, and arranged alphabetically
	printf("NAME\t\t#  AGE\n");
	fprintf(output, "NAME\t\t#  AGE\n");
	printf("---------------------------\nMALE:\n");
	fprintf(output, "---------------------------\nMALE:\n");
	for(i=0; i<malesNum; i++){ //loop that will traverse the sorted list of male students
		printf("%-15s %02d %02d\n", males[i].name, males[i].number, males[i].age);
		fprintf(output, "%-15s %02d %02d\n", males[i].name, males[i].number, males[i].age);
	}
	printf("\nFEMALE:\n");
	fprintf(output, "\nFEMALE:\n");
	for(i=0; i<femalesNum; i++){ //loop that will traverse the sorted list of female students
		printf("%-15s %02d %02d\n", females[i].name, females[i].number, females[i].age);
		fprintf(output, "%-15s %02d %02d\n", females[i].name, females[i].number, females[i].age);
	}
	fclose(output); //closes output file
}
