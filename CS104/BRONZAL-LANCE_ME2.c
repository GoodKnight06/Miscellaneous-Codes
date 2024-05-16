#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 2B */

/* Machine Exercise 2 - This program implements basic functions of a linked list-implemented queue such as enqueue, dequeue, peek, and change.*/

//structure for linked-list queue elements
struct node {
	int data;
	struct node *next;
};

void enqueue(); //function prototype for enqueueing new element
void dequeue(); //function prototype for removing front element
void peek(); //function prototype for displaying front of the queue
void change(); //function prototype for changing a value of a queue element 
void displayQueue(); //function prototype for displaying the entire queue

struct node *front, *rear; //declaration of node pointers for the front and rear of queue

//main function
int main(int argc, char *argv[]) {
	
	int choice; //variable declaration for user input of activity choice
	do {
		printf("+-----------------------------+\n");
		printf("|      MACHINE EXERCISE 2     |\n");
		printf("+-----------------------------+\n");
		printf("Choices:\n");
		printf("1.) Enqueue\n");
		printf("2.) Dequeue\n");
		printf("3.) Peek\n");
		printf("4.) Change\n");
		printf("5.) Display All\n");
		printf("6.) Quit Program\n\n");
		printf("\nEnter your choice here: ");
		scanf("%d", &choice); // gets user input choice
		
		switch(choice){ // switch-case to do appropriate task depending on user input
			case 1: enqueue(); //calls function for enqueueing new element
			break;
			case 2: dequeue(); //calls function for dequeueing the front
			break;
			case 3: peek(); //calls function for displaying the front
			break;
			case 4: change(); //calls function for changing one element's value
			break;
			case 5: displayQueue(); //calls function to display all elements
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

//function definition that enqueues data
void enqueue(){
	struct node *ptr; //node pointer that points to new node
	int newNum; //variable for storing value of new element
	ptr = (struct node*)malloc(sizeof(struct node)); //allocation of memory for new node
	
	if(ptr==NULL){ //checks if memory allocation was successful
		printf("Overflow.\n\n");
	}
	else {
		printf("Enter data to enqueue: ");
		scanf("%d", &newNum); //takes input for the value to be enqueued
		ptr->data = newNum; //copies new item to new node
		if(front==NULL){ //if queue is empty, front and rear are set to the same node
			front = ptr;
			rear = ptr;
		}
		else { //if not, rear is moved to the next node
			rear->next = ptr;
			rear = rear->next;
		}
		ptr->next = NULL; //the new node is the rear (tail node) so its next is set to NULL
		printf("Data enqueued.\n\n");
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}

//function definition that dequeues the front
void dequeue(){
	struct node *temp; //node pointer for reference to the node to dequeue
	if(front==NULL){ //checks if queue is empty
		printf("Queue is empty.\n\n");
	}
	else { //if not empty
		temp = front; //temp is assigned to point to front
		front = front->next; //moves the front to the next node
		free(temp); //removes temp, the current front that will now be dequeued
		printf("Front dequeued.\n\n");
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}

//function definition for displaying the front
void peek(){
	front==NULL ? printf("Queue is empty.\n\n") : printf("Front: %d\n\n", front->data); //checks if queue is empty and displays so, otherwise displays the front
	system("pause"); //pauses terminal
	system("cls"); //causes terminal
}

//function definition for changing an element in the queue
void change(){
	struct node *temp; //node pointer for traversing the queue
	int newNum, ctr = 1, index; //integer variables for replacing value, index counter, and index marker for node subject to change
	
	if(front==NULL){ //checks if queue is empty
		printf("Queue is empty.\n\n");
	}
	else { //if not empty
		printf("Enter element placement (starting from 1) to change: ");
		scanf("%d", &index); //enters index of element to change
		if(index>=1){ //checks if index is valid
			temp = front; //assigns temp to front to begin traversal to indicated index
			while(temp!=NULL && ctr<index){ //while loop that repeats until either the indicated index or the end of the queue is reached 
				temp = temp->next; //transfers temp to next node
				ctr++; //increments ctr to keep track of indices passed
			}
			if(temp==NULL){ //checks if temp surpassed the bounds of the queue
				printf("Index is greater than queue length.\n\n");
			}
			else { //if temp stopped within the queue
				printf("Enter new value: ");
				scanf("%d", &newNum); //asks for the value that will replace the node where temp stopped a.k.a. the nth of the queue
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

//function definition that will display the elements of the queue
void displayQueue(){
	struct node *temp; // node pointer for traversing the queue if not empty
	if(front==NULL){ // checks if queue is empty
		printf("Queue is empty.\n\n");
	}
	else { // if not empty
		temp = front; // temp points to front to begin traversing the queue
		printf("Current queue: ");
		while(temp!=NULL){ // loop that traverses the queue until its end
			printf("%d->", temp->data); // prints current node, eventually all nodes in the queue
			temp = temp->next; // transfers pointer to the next node
		}
		printf("NULL\n");
	}
	system("pause"); //pauses terminal
	system("cls"); //clears terminal
}
