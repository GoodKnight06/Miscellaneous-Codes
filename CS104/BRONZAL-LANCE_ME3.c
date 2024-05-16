#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 2B */

/* Machine Exercise 3 - This program implements basic functions of a linked list-implemented stack such as push, pop, peek, and change.*/

//structure for linked-list stack elements
struct node {
	int data;
	struct node *next;
};

void push(); //function prototype for pushing new element
void pop(); //function prototype for removing top of stack
void peek(); //function prototype for displaying the top of the stack
void change(); //function prototype for changing the value of an element in the stack
void displayStack(); //function prototype for displaying the entire stack

struct node *top; //declaration of node pointer for the top of the stack

//main function
int main(int argc, char *argv[]) {
	
	int choice; //variable declaration for user input of activity choice
	do {
		printf("+-----------------------------+\n");
		printf("|      MACHINE EXERCISE 3     |\n");
		printf("+-----------------------------+\n");
		printf("Choices:\n");
		printf("1.) Push\n");
		printf("2.) Pop\n");
		printf("3.) Peek\n");
		printf("4.) Change\n");
		printf("5.) Display All\n");
		printf("6.) Quit Program\n\n");
		printf("\nEnter your choice here: ");
		scanf("%d", &choice); // gets user input choice
		
		switch(choice){ // switch-case to do appropriate task depending on user input
			case 1: push(); //calls function for pushing new element
			break;
			case 2: pop(); //calls function for popping the top off
			break;
			case 3: peek(); //calls function for displaying the top
			break;
			case 4: change(); //calls function for changing one element's value
			break;
			case 5: displayStack(); //calls function to display all elements
			break;
			case 6: printf("Thank you, have a nice day.\n"); // exits the program after a friendly display
			exit(0);
			break;
			default: printf("Invalid choice input. Try again.\n");
			system("pause"); // pauses terminal
			system("cls"); // clears terminal
			break;
		}
	} while(choice!=6); //do-while loop that allows repitition of the menu after finishing a task
	
	return 0;
}

//function definition that pushes elements for a new node
void push(){
	struct node *ptr; //node pointer for new node
	int newNum; //integer for storing new number
	ptr = (struct node*)malloc(sizeof(struct node)); //memory allocation for new node
	
	if(ptr==NULL){ //checks if memory allocation was not successful
		printf("Overflow.\n\n");
	}
	else { //if memory allocation was successful
		printf("Enter new value: ");
		scanf("%d", &newNum); //asks user for new value to push
		ptr->data = newNum; //copies input value to new node's data
		ptr->next = top; //new node now points to the current top of the stack
		top = ptr; //top is transferred to the new node
		printf("New value pushed into stack.\n\n");
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}

//function definition that pops the top of the stack
void pop(){
	struct node *temp; //node pointer for reference to the node to pop
	if(top==NULL){ //checks if stack is empty
		printf("Stack is empty.\n\n");
	}
	else { //if not empty
		temp = top; //temp now points to top
		top = top->next; //top is transferred to the next to become the new top
		free(temp); //temp is removed from stack
		printf("Top popped.\n\n");
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}

//function definition for displaying the top of the stack
void peek(){
	top==NULL ? printf("Stack is empty.\n\n") : printf("Top: %d\n\n", top->data); //checks if stack is empty and displays so, otherwise displays the top
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}

//function definition for changing an element in the stack
void change(){
	struct node *temp; //node pointer for traversing the stack
	int newNum, ctr = 1, index; //integer variables for replacing value, index counter, and index marker for node subject to change
	
	if(top==NULL){ //checks if stack is empty
		printf("Stack is empty.\n\n");
	}
	else { //if not empty
		printf("Enter element placement (starting from 1) to change: ");
		scanf("%d", &index); //enters index of element to change
		if(index>=1){ //checks if index is valid
			temp = top; //assigns temp to top to begin traversal to indicated index
			while(temp!=NULL && ctr<index){ //while loop that repeats until either the indicated index or the bottom of the stack is reached 
				temp = temp->next; //transfers temp to next node
				ctr++; //increments ctr to keep track of indices passed
			}
			if(temp==NULL){ //checks if temp surpassed the bounds of the stack
				printf("Index is greater than stack height.\n\n");
			}
			else { //if temp stopped within the stack
				printf("Enter new value: ");
				scanf("%d", &newNum); //asks for the value that will replace the node where temp stopped a.k.a. the nth of the stack
				temp->data = newNum; //copies new value to the node
				printf("Value changed.\n\n");
			}
		}
		else { //if entered index is not valid
			printf("Invalid index input.\n\n");
		}
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}

//function definition that will display the elements of the stack
void displayStack(){
	struct node *temp; // node pointer for traversing the stack if not empty
	if(top==NULL){ // checks if stack is empty
		printf("Stack is empty.\n\n");
	}
	else { // if not empty
		temp = top; // temp points to top to begin traversing the stack
		printf("Current stack:\n");
		while(temp!=NULL){ // loop that traverses the stack until its end
			printf("| %4d |\n", temp->data); // prints current node, eventually all nodes in the stack
			temp = temp->next; // transfers pointer to the next node
		}
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}
