#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Authors:
Abigan, Clarizze Joanna "CJ"
Bronzal, Lance Stephen
Garcia, John Carl Angelo

BUCS BSCS 1A
CS103 Year-end Programming Project
*/

int toDoListLength = 0; //global variable for user's number of tasks in to do list
struct Todo { //data structure for each to-do task
	char title[50];
	int day, month, year;
} todos[20];
 
struct record { //data structure for diary record
	char name[50], place[50], note[200];
	int month, date, year, hour, minutes;
} details;
 
//function prototypes for Main Menu
void checkAccount();
void mainMenu(char[]);
 
//function prototypes for To-Do List
void isThisFirstTime(char[]);
void showOptions(char[]);
void deleteToDo();
void printAllToDo(char[]);
void addToDo();
void readFromFile();
void getFileSize();
void saveToFile();
 
//function prototypes for Diary
void diary(char[]);
void addRecord(char[]);
void showRecord(char[]);
 
//function prototypes for Academic Assistant
void acadHandbook(char[]);
void showVision();
void showMission();
void showQuaPolCoreVal();
void gradesCalc(char[]);
void inputGrades();
void showGWA(char[]);
void classSched(char[]);
void inputSched();
void showSched(char[]);

int main(int argc, char *argv[]) {
	checkAccount(); //calls function to get user's name
	
	return 0;
}

//Main Menu functions definitions
void checkAccount(){ //function definition that asks for user's name
	char tempName[100], tempPass[100], passGet[100]; //variables that will store user's name and password and another for comparing passwords
	FILE *account = fopen("account.txt", "r");
	
	if(account==NULL){ //checks if user is new: asks to log in if not, prompts to sign if yes
		fclose(account);
		account = fopen("account.txt", "w");
		printf("Enter name of new user: ");
		scanf("%[^\n]s", tempName); //user can input as many words as name
		printf("Enter new password: ");
		scanf("%s", tempPass); //new user can input only one word as password
		fprintf(account, "%s\n%s", tempName, tempPass);
		fclose(account);
		printf("Welcome, %s.\n\n", tempName);
		system("pause");
		system("cls");
		mainMenu(tempName); //calls the main menu of this project
	}
	else {
		fscanf(account, "%s", tempName); //gets user's name 
		printf("Welcome back, %s. Please enter your password to begin: ", tempName);
		scanf("%s", tempPass); //gets user input for password
		fscanf(account, "%s", passGet); //gets correct password for existing account
		if(strcmp(passGet, tempPass)==0){ //compares the input and correct password, proceeds to main menu if match
			printf("Authentication passed. ");
			system("pause");
			system("cls");
			mainMenu(tempName); //calls the main menu of this project
		}
		else{
			printf("Authentication failed... ");
			system("pause");
			system("cls");
			checkAccount(); //recursive call to allow user to input again
		}
	}
	
}

void mainMenu(char name[]){ //function definition of the main menu
	int menuItem;
	
	/* displays user's name, a prompt of options and then asks for user's input for what activity to open */
	printf("\tWelcome, %s! What would you like to do?\n\n", name);
	printf("\t\t\t(1)-Check To-Do list\n\n"
		   "\t\t\t(2)-Check Diary\n\n"
		   "\t\t\t(3)-Check Academic Tracker\n\n"
		   "\tTo Log Out, enter any other single digit number\n\n"
		   "\t\tEnter desired activity: ");
	scanf("%d", &menuItem);
	system("cls");
	switch(menuItem){
		case 1: isThisFirstTime(name);
		break;
		case 2: diary(name);
		break;
		case 3: acadHandbook(name);
		break;
		default: printf("Goodbye, %s", name);
		exit(0);
		break;
	}
}

//To Do List functions definitions
void isThisFirstTime(char name[]){ //function definition for checking if it's the first time the user opened this activity
	FILE *fp = fopen("Todos.txt", "r");
	if(!fp){ //if first time, asks to input first task
		printf("Welcome to your To-Do list, %s\nTo get started, enter your first task\n", name);
		addToDo(); //calls function that will add new task
		saveToFile(); //calls function that will write new task to file
		printAllToDo(name); //calls function that will display the entire to-do list
		showOptions(name); //calls function that will display options to do and ask user's desired activity
	}
	else { //if not first time, proceeds to read all tasks from file and displays all tasks and options
		readFromFile();
		printAllToDo(name);
		showOptions(name);
	}
}

void addToDo(){ //function definition that adds new task
	char userInput[50];
	printf("Type your task to do\n>> ");
	scanf(" %[^\n]s", userInput);
	strcpy(todos[toDoListLength].title, userInput); //copies new task to the end of the array of tasks
	printf("Enter date of your task [dd-mm-yyyy]\n>> ");
	scanf("%d%*c%d%*c%d", &todos[toDoListLength].day, &todos[toDoListLength].month, &todos[toDoListLength].year);
	toDoListLength++; //increases index to appropriately match lenght of to-do lists
	system("cls");
}

void saveToFile(){ //function definition that writes to file the list of tasks
	int i;
	FILE *fp = fopen("Todos.txt", "w"); //opens file of tasks for writing
	for(i=0; i<toDoListLength; i++){
		fprintf(fp, "%d\t%02d-%02d-%d\t%s\n", i+1, todos[i].day, todos[i].month, todos[i].year, todos[i].title); //writes each task to file
		
	}
	fclose(fp);
}

void printAllToDo(char name[]){ //function definition that reads all tasks from file
	int i;
	printf("\tHere is your To Do List,  %s\n", name);
	printf("+----+-------------------------------------+----------------+\n");
    printf("| ID |            Your To Dos              |     Date       |\n");
    printf("+----+-------------------------------------+----------------+\n");
    
    if(toDoListLength>0){ //if to-do list is not empty, displays all tasks read from file
    		for(i=0; i<toDoListLength; i++){
    		printf("|%3d | %-35s | %02d-%02d-%d     |\n", i + 1, todos[i].title, todos[i].day, todos[i].month, todos[i].year);
        	printf("+----+-------------------------------------+----------------+\n");
		}
	}
	else { //if to-do list is empty, displays that the user's to-do list is empty
		printf("|\tYour To-do list is empty! :D\t   |                | \n");
		printf("+----+-------------------------------------+----------------+\n");
	}
    
}

void showOptions(char name[]){ //function definition that shows options to do and ask for user's desired activity
	char userChoice;
    printf("Type 'A' to add, 'D' to delete, 'Q' to quit\n\t>>");
    scanf(" %c", &userChoice); //gets user's activity of choice
    if(userChoice>=97) userChoice-=32; //capitalizes user's input if user's input is in lower case
    switch (userChoice) { //switch case statement for checking of what the user desires
    case 'A':
        addToDo(); //calls function to add another task
        break;
    case 'D':
        deleteToDo(); //calls function to delete an existing task
        break;
    case 'Q':
    	system("cls");
        mainMenu(name); //goes back to the main menu of the project
        break;
    default:
        printf("\tInvalid input. Please refer to the given choices.\n"); //displays that the user inputted an invalid option
        showOptions(name); //recursion to display options again and ask user's input
        break;
    }
    saveToFile(); //function call to write to file newly-modified list of tasks
    printAllToDo(name); //function call to display all tasks
    showOptions(name); //recursive call to display options and ask's user desired activity
}

void readFromFile(){ //function definition for reading tasks from file and storing them
	int i, numCatch, dayCatch, monthCatch, yearCatch;
	char taskTemp[50];
	FILE *fp = fopen("Todos.txt", "r"); //opens file of tasks for reading
	
	getFileSize(); //gets size of to-do list by counting the length of the list
	for(i=0; i<toDoListLength; i++){
		fscanf(fp, "%d %d%*c%d%*c%d %[^\n]s ", &numCatch, &dayCatch, &monthCatch, &yearCatch, taskTemp); //reads from file the task number and task name
		strcpy(todos[i].title, taskTemp); //stores read task name to array of tasks
		todos[i].day=dayCatch;
		todos[i].month=monthCatch;
		todos[i].year=yearCatch;
	}
	fclose(fp);
}

void getFileSize(){ //function definition for counting the size or length of to-do list in the file
	int count = 0;
	char tempString[50];
	FILE *fp = fopen("Todos.txt", "r"); //opens file of tasks for reading
	while(fgets(tempString, 100, fp)) count++; //counts each task read from file
	toDoListLength = count; //stores the size of list to global variable
	fclose(fp);
}

void deleteToDo(){ //function definition that deletes a task
	int toDoID, i;
	printf("Enter the ID of task to remove \n>>");
    scanf("%d", &toDoID); //asks for which task to delete
    if (toDoID < 1 || toDoID > toDoListLength){ //checks if entered task to delete is valid
        printf("Invalid task number to delete \n");
    }
    else {
        toDoID--; //decrement to match appropriate index in array of tasks
        for(i=toDoID; i<toDoListLength-1; i++){ 
        	todos[i]=todos[i+1]; //shifts succeeding tasks to the left, effectively overriding the value of index to delete
		}
        toDoListLength--; //reduces the stored length of the list of tasks
        printf("Task was deleted.\n");
    }
    system("pause");
	system("cls");
}

//Diary functions definitions
void diary(char name[]){ //function definition of the mini menu of diary
	int diaryChoice;
	
	printf("\t--------------------\n");
    printf("\t---PERSONAL DIARY---\n");
    printf("\t--------------------\n");
    printf("\n\tWhat do you want to do, %s? ", name); //displays user's name and options to do in diary
    printf("\n\n\t\t[1] ADD NEW RECORD");
    printf("\n\n\t\t[2] VIEW RECORDS");
    printf("\n\n\t\t[3] GO BACK TO MAIN MENU");
    
    printf("\n\n\tENTER A NUMBER...");   
    scanf("%d", &diaryChoice); //asks user input for desired activity
    //checks input to call appropriate function that the user desires
    if(diaryChoice==1){
    	addRecord(name); //calls function to add new record in diary
    	diary(name); //recursive call for diary mini menu
	}
	else if (diaryChoice==2){
		showRecord(name); //calls function to read a record in diary
		diary(name); //recursive call for diary mini menu
	}
	else if (diaryChoice==3){
		system("cls");
		mainMenu(name); //function call to go back to main menu
	}
	else {
		printf("INVALID INPUT\n");
		system("pause");
		system("cls");
		diary(name); //recursive call for diary mini menu
	}
}

void addRecord(char name[]){ //function definition for adding new record 
	FILE *entry = NULL;
	char filename[15], view, dateName[3], monthName[3], yearName[5], completeDate[9];
	int dateValid = 0, timeValid = 0;
	do { //do-while loop that will keep asking for user input until the user inputs valid date
		printf("\nENTER DATE OF RECORD [dd-mm-yyyy]: ");
		scanf("%d%*c%d%*c%d", &details.date, &details.month, &details.year);
		switch (details.month){ //switch-case statement that validates month and appropriate date range
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12: 
				if(details.date>=1 && details.date<=31) dateValid=1;
				break;
			case 2:
				if(details.year%4==0){ //if-else section that validates february according to leap year rules or not
					if(details.year%100==0 && details.year%400!=0){
						if(details.date>=1 && details.date<=28) dateValid=1;
					}
					else {
						if(details.date>=1 && details.date<=29) dateValid=1;
					}
				}
				else if(details.date>=1 && details.date<=28) dateValid=1;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if(details.date>=1 && details.date<=30) dateValid=1;
				break;
			default: 
				dateValid=0;
				break;
		}
		if(details.year<0) dateValid=0; //checks if year is valid (not negative)
		if(dateValid==0) printf("INVALID DATE. TRY AGAIN...\n");
	} while(dateValid==0);
	/*converts date, month, and year to string so it can be used as filename*/
	sprintf(dateName, "%02d", details.date);
	strcpy(completeDate, dateName);
	strcat(completeDate, "-");
	sprintf(monthName, "%02d", details.month);
	strcat(completeDate, monthName);
	strcat(completeDate, "-");
	sprintf(yearName, "%d", details.year);
	strcat(completeDate, yearName);
	strcpy(filename, completeDate);
	strcat(filename, ".txt"); //uses concatenated date format as filename
	entry = fopen(filename, "w");  //opens/creates file with the date as name
	fprintf(entry, "DATE: %s\n", completeDate);
	do{ //do-while loop that keeps asking for user's input of time until such inputted time is valid
		printf("ENTER TIME OF RECORD [hh:mm]: ");
		scanf("%d%*c%d", &details.hour, &details.minutes);
		if(details.hour>=0 && details.hour<=23){ //checks if hour follows the 24-hour format
			if(details.minutes>=0 && details.minutes<=59) timeValid=1; //checks if minute is valid
		}
		if(timeValid==0) printf("INVALID TIME. TRY AGAIN...\n\n");
	} while(timeValid==0);
	/*gets input for each information and writes them to diary record */
	fprintf(entry, "TIME: %d:%d\n", details.hour, details.minutes);
	fprintf(entry, "BY: %s\n", name);
	printf("ENTER PLACE: ");
	scanf(" %[^\n]ss", details.place);
	fprintf(entry, "AT: %s\n", details.place);
	printf("WRITE YOUR HEART OUT IN ONE LINE:\n");
	scanf(" %[^\n]s", details.note);
	fprintf(entry, "\n%s", details.note);
	fclose(entry);
	printf("\nDIARY ENTRY ADDED. DO YOU WANT TO VIEW IT? (Y/N): ");
	while(view!='Y' && view!='y' && view!='n' && view!='N'){ //while loop that will keep asking for confirmation until input is valid
		scanf(" %c", &view);
		if(view=='Y' || view=='y'){ //prints all entered detail about the record if user desires
			printf("\nDATE: %s\n", completeDate);
			printf("TIME: %d:%d\n", details.hour, details.minutes);
			printf("BY: %s\n", name);
			printf("AT: %s\n", details.place);
			printf("\n%s\n\n", details.note);
			system("pause");
			system("cls");
		}
		else if (view=='N' || view=='n'){ //proceeds w/o displaying new record if no
			system("cls");
		}
		else { //invalid input read
			printf("INVALID INPUT. TRY AGAIN... ");
		}
	}
}

void showRecord(char name[]){ //function definition to show a record in the diary
	FILE *entry = NULL;
	char filename[15], ch;
	
	printf("ENTER DATE OF DAIRY ENTRY YOU WISH TO VIEW [dd-mm-yyyy]: "); //asks the date of which record the user desires to read
	scanf("%s", filename);
	strcat(filename, ".txt");
	entry = fopen(filename, "r"); //opens record for reading
	if(entry==NULL){ //checks if record exists
		printf("DIARY ENTRY DOES NOT EXIST.\n\n"); //prompts if entered record does not exist
	}
	else {
		printf("\n");
		while((ch=fgetc(entry))!=EOF){
			printf("%c", ch); //displays on terminal all characters in the record
		}
		printf("\n\n");
	}
	fclose(entry);
	system("pause");
	system("cls");
}

//Academic Assistant functions definitions
void acadHandbook(char name[]){ //function definition for handbook mini menu
	int handbookItem;
	
	printf("\tWelcome to your Academic Tracker, %s. How can you be helped?\n\n", name);
	printf("\t\t\t(1)-Show Vision\n\n\t\t\t(2)-Show Mission\n\n\t\t\t(3)-Show Quality Policy and Core Values\n\n\t\t\t(4)-Grades Calculator\n\n\t\t\t(5)-Class Schedule\n\n\tTo return to Main Menu, enter any other single digit number");
	printf("\n\n\t\tEnter desired activity: ");
	scanf("%d", &handbookItem); //asks user input
	system("cls");
	if(handbookItem>=1 && handbookItem<=3){
		switch(handbookItem){
			case 1: showVision(); break; //function call for the displaying of BU's vision
			case 2: showMission(); break; //function call for the displaying of BU's mission
			case 3: showQuaPolCoreVal(); break; //function call for the displaying of BU's quality policy and core values
		}
		acadHandbook(name); //recursive call for handbook mini menu
	}
	else {
		switch(handbookItem){
			case 4: gradesCalc(name); break; //function call for grades calculating
			case 5: classSched(name); break; //function call for schedule displaying
			default: mainMenu(name); break; //function call  to go back to main menu
		}
	}
}

void showVision(){ //function definiton that shows BU's vision
	printf("Vision:\tA world-class university producing leaders and\n\tchange agents for social transformation and development.\n\n");
	system("pause");
	system("cls");
}

void showMission(){ //function definition that shows BU' mission
	printf("Mission: The Bicol University shall give professional\n\t and technical training, and provide advanced and\n\t specialized instruction in literature, philosophy, the sciences and arts,\n\t besides providing for the promotion of scientific\n\t and technological researches. (RA 5521, Sec. 3.0)\n");
	printf("\n");
	system("pause");
	system("cls");
}

void showQuaPolCoreVal(){ //function definition that shows BU's quality policy and core values
	printf("Quality Policy: Bicol University commits to continually strive for\n\t\texcellence in instruction, research, and extension by meeting\n\t\tthe highest level of clientele satisfaction and adhering to\n\t\tquality standards and applicable statutory and regulatory requirements.\n\n");
	printf("4 Core Values: Scholarship, Leadership, Service, Character\n\n");
	system("pause");
	system("cls");
}

void gradesCalc(char name[]){ //function definition for grades calculating
	int calcItem;
	
	printf("\tWelcome to Grades Calculator, %s. What do you want to do?\n\n", name);
	printf("\t\t\t(1)-Input New Grades\n\n\t\t\t(2)-Compute GWA\n\n\tEnter any other single digit number to go back to your Academic Tracker\n\n\t\tEntire desired activity: ");
	scanf("%d", &calcItem); //asks user input for desired calculator activity
	system("cls");
	switch(calcItem){
		case 1: inputGrades(); //function call to input user's grades
		gradesCalc(name); //recursive call for grades calculator
		break;
		case 2: showGWA(name); break; //function call to show user's GWA according to inputted grades read from file
		default: acadHandbook(name); break; //function call to go back to handbook mini menu
	}
}

void inputGrades(){ //function definition for inputting grades and writing them to file
	struct Subject{ //data structure for each subject
		char code[10];
		float score;
		int units;
	}tempSubject;
	int subjNum, i;
	char suffix[3];
	FILE *grades = fopen("grades.txt", "w"); //creates/opens file for writing the grades
	/*asks how many subjects the user has and loops to input each subject's code, grade attained, and units and later write them into file*/
	printf("How many subjects do you have? (Exclude NSTP): ");
	scanf("%d", &subjNum);
	printf("\nEnter each subject's code, your grade, and the units of the subject:\n\n");
	printf("Example:\nCS101 1.3 3\n\n");
	for(i=1; i<=subjNum; i++){
		if(i%10==1) strcpy(suffix, "st");
		else if (i%10==2) strcpy(suffix, "nd");
		else if (i%10==3) strcpy(suffix, "rd");
		else strcpy(suffix, "th");
		printf("Enter %d%s subject: ", i, suffix);
		scanf("%s %f %d", tempSubject.code, &tempSubject.score, &tempSubject.units);
		fprintf(grades, "%s\t%.2f\t%d\n", tempSubject.code, tempSubject.score, tempSubject.units);
	}
	fclose(grades);
	printf("\nGrades Entered.\n");
	system("pause");
	system("cls");
}

void showGWA(char name[]){ //function call that reads from file the user's grades and computing GWA
	FILE *grades = fopen("grades.txt", "r");
	struct Subject{ //data structure for each subject
		char code[10];
		float score;
		int units;
	}inputTemp, total, highestSub, lowestSub;
	float GWA, trueScore;
	struct Subject *highPtr = &highestSub, *lowPtr = &lowestSub, *temp = &inputTemp, *totalPtr = &total;
	highPtr->score = 5.0;
	lowPtr->score = 1.0;
	totalPtr->score=0;
	totalPtr->units=0;
	
	if(grades==NULL){ //checks if grades have been inputted already
		printf("Looks like you have not entered grades yet. This program can't calculate empty grades, %s. Enter them first. XD\n\n", name);
		fclose(grades);
		inputGrades();
	}
	grades = fopen("grades.txt", "r");
	while(fscanf(grades, "%s %f %d", temp->code, &(temp->score), &(temp->units))==3){ //loops to check each subject code, grade, and unit and adds them to total
		trueScore = temp->units * temp->score;
		totalPtr->score+=trueScore;
		totalPtr->units+=temp->units;
		if(trueScore<highPtr->score){
			highPtr->score = trueScore;
			highPtr->units = temp->units;
			strcpy(highPtr->code, temp->code);
		}
		if(trueScore>lowPtr->score){
			lowPtr->score = trueScore;
			lowPtr->units = temp->units;
			strcpy(lowPtr->code, temp->code);
		}
	}
	GWA=totalPtr->score/totalPtr->units; //computes GWA
	/*displays GWA, highest scoring subject and least scoring subject*/
	printf("Your GWA is %.3f\n", GWA);
	printf("Your most valuable subject is %s with a grade of %.2f\n", highPtr->code, highPtr->score/highPtr->units);
	printf("Your least scoring subject is %s with a grade of %.2f\n\n", lowPtr->code, lowPtr->score/lowPtr->units);
	system("pause");
	system("cls");
	fclose(grades);
	gradesCalc(name); //function call to go back to schedule assistant
}

void classSched(char name[]){ //function definition for schedule assistant
	int schedItem;
	
	printf("\tWelcome to your Class Schedule Assistant, %s. What do you want to do?\n\n", name);
	printf("\t\t\t(1)-Input Schedule\n\n\t\t\t(2)-Show Schedule\n\n\tEnter any other single digit number to go back to your Academic Tracker\n\n\t\tEntire desired activity: ");
	scanf("%d", &schedItem); //asks user's desired activity
	system("cls");
	switch(schedItem){
		case 1: inputSched(); //function call that will make user input schedule
		classSched(name); //recursive call for schedule assistant menu
		break;
		case 2: showSched(name); break; //function call for displaying schedule in a table
		default: acadHandbook(name); break; //function call that goes back to handbook mini menu
	}
}

void inputSched(){ //function definition for inputting user's class schedule
	int subjNum, meetNum, i, j, tempTime, tempEnd;
	char suffix[3], tempCode[10], tempDay[3];
	FILE *schedule = fopen("schedule.txt", "w");
	
	printf("How many subjects do you have? (Include NSTP): ");
	scanf("%d", &subjNum);
	
	for(i=1; i<=subjNum; i++){ //for-loop for displaying a prompt and inputting each subject's number of meetings and date and time of each meeting
		if(i%10==1) strcpy(suffix, "st");
		else if (i%10==2) strcpy(suffix, "nd");
		else if (i%10==3) strcpy(suffix, "rd");
		else strcpy(suffix, "th");
		printf("Enter how many meetings for %d%s subject: ", i, suffix);
		scanf("%d", &meetNum);
		printf("Enter code of %d%s subject (e.g. CS102): ", i, suffix);
		scanf("%s", tempCode);
		for(j=1; j<=meetNum; j++){
			if(j%10==1) strcpy(suffix, "st");
			else if (j%10==2) strcpy(suffix, "nd");
			else if (j%10==3) strcpy(suffix, "rd");
			else strcpy(suffix, "th");
			printf("Enter day (M T W Th F Sa Su), time start, and time end (e.g. M 0930 1200) for the %d%s meeting of %s: \n", j, suffix, tempCode);
			scanf("%s %d %d", tempDay, &tempTime, &tempEnd);
			if(tempTime>=0 && tempTime<2400 && tempTime%100<60 && tempEnd>=0 && tempEnd<2400 && tempEnd%100<60){
				if(strcmp(tempDay, "M")==0 || strcmp(tempDay, "m")==0) fprintf(schedule, "%s\tM\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else if(strcmp(tempDay, "T")==0 || strcmp(tempDay, "t")==0) fprintf(schedule, "%s\tT\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else if(strcmp(tempDay, "W")==0 || strcmp(tempDay, "w")==0) fprintf(schedule, "%s\tW\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else if((tempDay[0]=='T' || tempDay[0]=='t') && (tempDay[1]=='H' || tempDay[1]=='h')) fprintf(schedule, "%s\tTh\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else if(strcmp(tempDay, "F")==0 || strcmp(tempDay, "f")==0) fprintf(schedule, "%s\tF\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else if((tempDay[0]=='S' || tempDay[0]=='s') && (tempDay[1]=='A' || tempDay[1]=='a')) fprintf(schedule, "%s\tSa\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else if((tempDay[0]=='S' || tempDay[0]=='s') && (tempDay[1]=='U' || tempDay[1]=='u')) fprintf(schedule, "%s\tSu\t%04d\t%04d\n", tempCode, tempTime, tempEnd);
				else {
					printf("Invalid input. Try again: ");
					j--;
				}
			}
			else {
				printf("Invalid input. Try again: ");
				j--;
			}
		}
	}
	fclose(schedule);
	printf("\nSchedule registered.\n");
	system("pause");
	system("cls");
}

void showSched(char name[]){ //function definition for showing the schedule of the user
	struct meeting{
		char code[10];
		int time, endTime;
	}mondays[10], tuesdays[10], wednesdays[10], thursdays[10], fridays[10], saturdays[10], sundays[10]; //database for each meeting for each day of the week
	char tempCode[10], tempDay[3];
	char datesArr[][3] = {"M", "T", "W", "Th", "F", "Sa", "Su"};
	char fullDayName[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	struct meeting *sortPtr = NULL;
	FILE *schedule = NULL;
	int i, j, k, tempTime, tempEnd, dayMeetings[7] = {0}, pos, mid;
	schedule = fopen("schedule.txt", "r");
	if (schedule!=NULL){
		fclose(schedule);
		for(i=0; i<7; i++){ //for loop that will read the file 7 times over for proper grouping of meetings per day of the week
			switch(i){
				case 0: sortPtr = mondays; break;
				case 1: sortPtr = tuesdays; break;
				case 2: sortPtr = wednesdays; break;
				case 3: sortPtr = thursdays; break;
				case 4: sortPtr = fridays; break;
				case 5: sortPtr = saturdays; break;
				case 6: sortPtr = sundays; break;
			}
			j=0;
			schedule = fopen("schedule.txt", "r");
			while(fscanf(schedule, "%s %s %d %d", tempCode, tempDay, &tempTime, &tempEnd)==4){
				if(strcmp(tempDay, datesArr[i])==0){
					dayMeetings[i]++;
					strcpy((sortPtr+j)->code, tempCode);
					(sortPtr+j)->time = tempTime;
					(sortPtr+j)->endTime = tempEnd;
					j++;
				}
			}
			fclose(schedule);
		}
		for(i=0; i<7; i++){ //for-loop that will sort all meetings each day according to time start using selection sort algorithm
			switch(i){
				case 0: sortPtr = mondays; break;
				case 1: sortPtr = tuesdays; break;
				case 2: sortPtr = wednesdays; break;
				case 3: sortPtr = thursdays; break;
				case 4: sortPtr = fridays; break;
				case 5: sortPtr = saturdays; break;
				case 6: sortPtr = sundays; break;
			}
			for(j=0; j<dayMeetings[i]-1; j++){
				pos=j;
				for(k=j; k<dayMeetings[i]; k++){
					if((sortPtr+pos)->time>(sortPtr+k)->time) pos=k;
				}
				if(pos!=j){
					tempTime = (sortPtr+j)->time;
					(sortPtr+j)->time = (sortPtr+pos)->time;
					(sortPtr+pos)->time = tempTime;
					tempEnd = (sortPtr+j)->endTime;
					(sortPtr+j)->endTime = (sortPtr+pos)->endTime;
					(sortPtr+pos)->endTime = tempEnd;
					strcpy(tempCode, (sortPtr+j)->code);
					strcpy((sortPtr+j)->code, (sortPtr+pos)->code);
					strcpy((sortPtr+pos)->code, tempCode);
				}
			}
		}
	}
	
	/*diplays the sorted schedule of meetings for all days of the week*/
	printf("+------------------------------------------------------------+\n");
	printf("|\t\t\tYour Schedule\t\t\t     |\n");
	printf("+------------------------------------------------------------+\n");
	for(i=0; i<7; i++){
		switch(i){
			case 0: sortPtr = mondays; break;
			case 1: sortPtr = tuesdays; break;
			case 2: sortPtr = wednesdays; break;
			case 3: sortPtr = thursdays; break;
			case 4: sortPtr = fridays; break;
			case 5: sortPtr = saturdays; break;
			case 6: sortPtr = sundays; break;
		}
		if(dayMeetings[i]>0){
			for(j=0; j<dayMeetings[i]; j++){
				mid=dayMeetings[i]/2;
				if(dayMeetings[i]%2!=0) mid++;
				if(j+1==mid) printf("| %s Meetings\t|", fullDayName[i]);
				else printf("|\t\t\t|");
				printf("|\t%s\tTime: %04d-%04d\t     |\n", (sortPtr+j)->code, (sortPtr+j)->time, (sortPtr+j)->endTime);
			}
		}
		else {
			printf("| %s Meetings\t||\tNo meetings scheduled.       |\n", fullDayName[i]);
		}
		printf("+-----------------------++-----------------------------------+\n");
	}
	printf("\n");
	system("pause");
	system("cls");
	classSched(name); //function call to go back to schedule assistant
}

