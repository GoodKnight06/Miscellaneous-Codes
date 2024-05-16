#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

/* Programming Exercise 6 - This program asks for the grades for each criterion as input and will compute for the actual grade using the inputs and their pre-determined weight coefficient.
After computing for the actual grade, the program now computes for the transmuted grade using the calculated actual grade, and afterwards determine the corresponding grade point and
description. The program then displays the inputted criterion grades in a table, the computed actual and transmuted grades, and the corresponding gradepoint and description.*/

int main(int argc, char *argv[]) {
	
	float quizGrade, midtermGrade, finalsGrade, projectGrade, recitationGrade, actualGrade, gradePoint;
	int transmutedGrade;
	char *description;
	
	printf("Enter grade for Quizzes: "); scanf("%f", &quizGrade);
	printf("Enter grade for Midterm exam: "); scanf("%f", &midtermGrade);
	printf("Enter grade for Final exam: "); scanf("%f", &finalsGrade);
	printf("Enter grade for Project: "); scanf("%f", &projectGrade);
	printf("Enter grade for Recitation: "); scanf("%f", &recitationGrade);
	
	actualGrade = (quizGrade * 0.25) + (midtermGrade * 0.20) + (finalsGrade * 0.25) + (projectGrade * 0.20) + (recitationGrade * 0.10);
	if(actualGrade<60) transmutedGrade = 60 + (actualGrade/4);
	else transmutedGrade = 75 + ((actualGrade-60)/1.6);
	
	if(transmutedGrade>=95){
		gradePoint = 1.00;
		description = "Outstanding";
	}
	else if (transmutedGrade>=91){
		gradePoint = 1.25;
		description = "Superior";
	}
	else if (transmutedGrade>=86){
		description = "Very Satisfactory";
		if (transmutedGrade>=88) gradePoint = 1.50;
		else gradePoint = 1.75;
	}
	else if (transmutedGrade>=82){
		description = "Satisfactory";
		if (transmutedGrade>=84) gradePoint = 2.00;
		else gradePoint = 2.25;
	}
	else if (transmutedGrade>=75){
		description = "Fair";
		if (transmutedGrade>=79) gradePoint = 2.50;
		else if (transmutedGrade>=77) gradePoint = 2.75;
		else gradePoint = 3.00;
	}
	else {
		description = "Failure";
		gradePoint = 5.00;
	}
	
	printf("\n----------------------------------\n");
	printf("REQUIREMENT      GRADE     WEIGHT \n");
	printf("----------------------------------\n");
	printf("Quizzes          %5.2f     25%%\n", quizGrade);
	printf("Midterm Exam     %5.2f     20%%\n", midtermGrade);
	printf("Final Exam       %5.2f     25%%\n", finalsGrade);
	printf("Project          %5.2f     20%%\n", projectGrade);
	printf("Recitation       %5.2f     10%%\n\n", recitationGrade);
	printf("Actual Grade:     %4.2f\n", actualGrade);
	printf("Transmuted Grade: %d\n", transmutedGrade);
	printf("Grade Point:      %4.2f\n", gradePoint);
	printf("Description:      %s", description);
	
	return 0;
}
