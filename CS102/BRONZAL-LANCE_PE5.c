#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

/* Programming Exercise 5 - this program asks the user to input 5 pairs of integer numbers, which are the number of items and a student's score for a quiz respectively, 
and then outputs these items and scores in a table along with its corresponding percentage rate. Additionally, this program calculates and outputs the total average
of the student's scores. This program also uses the least number of variables [declared] possible to complete the task.*/

int main(int argc, char *argv[]) {
	
	unsigned int items1, items2, items3, items4, items5;
	unsigned int score1, score2, score3, score4, score5;
	
	printf("Please input five pairs of integer values representing the total number of points and score of a student's quizzes.\n");
	printf("Input Quiz 1 : "); scanf("%d %d", &items1, &score1);
	printf("Input Quiz 2 : "); scanf("%d %d", &items2, &score2);
	printf("Input Quiz 3 : "); scanf("%d %d", &items3, &score3);
	printf("Input Quiz 4 : "); scanf("%d %d", &items4, &score4);
	printf("Input Quiz 5 : "); scanf("%d %d", &items5, &score5);
	
	printf("---------------------------------\n");
	printf(" QUIZ#| SCORE | TOTAL |  RATE   |\n");
	printf("---------------------------------\n");
	printf("1     | %5d | %5d | %6.2f%% |\n", score1, items1, 100.00*score1/items1);
	printf("2     | %5d | %5d | %6.2f%% |\n", score2, items2, 100.00*score2/items2);
	printf("3     | %5d | %5d | %6.2f%% |\n", score3, items3, 100.00*score3/items3);
	printf("4     | %5d | %5d | %6.2f%% |\n", score4, items4, 100.00*score4/items4);
	printf("5     | %5d | %5d | %6.2f%% |\n", score5, items5, 100.00*score5/items5);
	
	printf("\nRATE AVERAGE: %5.2f%%", ((100.00*score1/items1)+(100.00*score2/items2)+(100.00*score3/items3)+(100.00*score4/items4)+(100.00*score5/items5))/5);
	return 0;
}
