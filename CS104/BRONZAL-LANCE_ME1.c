#include <stdio.h>
#include <stdlib.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 2B */

/* Machine Exercise 1 -  With the implementation of singly-linked lists, this program can add nodes to a linked list (the beginning or end), reverse the order 
of the data in the linked list, sort the elements in the list in ascending order, and remove nodes with duplicate data among the list. These tasks are performed 
in accordance to user input when prompted.*/

//structure for linked list's nodes
struct node {
	int data; //data of each node
	struct node *next; //pointer to the next node
};

void begin_Insert(); //funtion prototype for inserting a node at the beginning of the linked list
void end_Insert(); //function prototype for inserting a node at the end of the linked list
void reverse_List(); //function prototype for reversing the order of the elements in the linked list
void sort_List(); //function prototype for sorting the elements of the linked list in ascending order
void pop_Duplicates(); //function prototype for removing duplicate elements in the list
void display_List(); //function prototype for displaying the elements of the list

struct node *head; //declaration for the pointer to the linked list's head/beginning.

//main function
int main(int argc, char *argv[]) {
	
	int choice; // variable declaration for user input for activity choice
	do {
		printf("+-----------------------------+\n");
		printf("|      MACHINE EXERCISE 1     |\n");
		printf("+-----------------------------+\n");
		printf("Choices:\n");
		printf("1.) Insert node at the beginning\n");
		printf("2.) Insert node at the end\n");
		printf("3.) Reverse the order of the linked list\n");
		printf("4.) Sort the list in ascending order\n");
		printf("5.) Remove duplicate elements in the list\n");
		printf("6.) Quit program\n\n");
		display_List(); // calls function that displays the current list
		printf("\nEnter your choice here: ");
		scanf("%d", &choice); // gets user input choice
		
		switch(choice){ // switch-case to do appropriate task depending on user input
			case 1: begin_Insert(); // calls function for inserting new element at beginning of list
			break;
			case 2: end_Insert(); // calls function for inserting new element at the end of the list
			break;
			case 3: reverse_List(); // calls function for reversing the order of the elements in the list
			break;
			case 4: sort_List(); // calls function for sorting the list in ascending order
			break;
			case 5: pop_Duplicates(); // calls function for removing data-duplicate nodes
			break;
			case 6: printf("Thank you, have a nice day.\n"); // exits the program after a friendly display
			exit(0);
			break;
			default: printf("Invalid choice input. Try again.\n");
			system("pause"); // pauses terminal
			system("cls"); // clears terminal
			break;
		}
	} while(choice!=6); // do-while loop that allows repetition of the menu after accomplishing a certain task or prompt, unless otherwise closed
	
	return 0;
}

//function definition that will insert new node at the beginning of the list
void begin_Insert(){
	struct node *ptr; // node pointer that points to new node to be inserted to the list
	int newNum; // variable for storing the new item
	ptr = (struct node*)malloc(sizeof(struct node)); // allocation of memory for new node
	
	if(ptr==NULL){ // checks if allocation of memory was successful
		printf("Overflow!\n");
	}
	else { // if memory allocation did not fail
		printf("Enter new data: ");
		scanf("%d", &newNum); // asks user for the new number to be inserted
		ptr->data = newNum; // stores input to the new node
		ptr->next = head; // the current head of the list is assigned as the next node of the new node
		head = ptr; // the new node pointed by ptr is now assigned as the new head of the list
	}
	printf("Node inserted at the beginning.\n\n");
	system("pause"); // pauses terminal
	system("cls"); // clears terminal
}

//function definition that will insert new node at the end of the list
void end_Insert(){
	struct node *ptr, *temp; // node pointers that points to new node and for traversing the list to its end
	int newNum; // integer variable for storing the value of the new node's data
	ptr = (struct node*)malloc(sizeof(struct node)); // allocation of memory for new node
	
	if(ptr==NULL){ // checks if memory allocation was successful
		printf("Overflow");
	}
	else { // if memory allocation did not fail
		printf("Enter new data: ");
		scanf("%d", &newNum); // asks user for the new number to be inserted
		ptr->data = newNum; // stores input to new node
		if(head==NULL){ // checks if the list is currently empty
			head = ptr; // the new node is now, by default, the head of the list
		}
		else { // if list is not empty
			temp = head; // temporary pointer duplicate that will traverse the list
			while(temp->next!=NULL){ // loop that makes temp point to each node, until the very end
				temp = temp->next; // transfers temp to its next node
			}
			temp->next = ptr; // at the end of the list, the new node ptr is inserted as the next node of the previously last node
		}
		ptr->next = NULL; // new node's next node is set to NULL (signifying it as the end of the list)
	}
	printf("Node inserted at the end.\n\n");
	system("pause"); // pauses terminal
	system("cls"); // clears terminal
}

//function definition that will reverse the order of the elements in the list
void reverse_List(){
	struct node *temp, *prevHead; // node pointers used for traversing the list and pointer to the head of the list before the reversal
	prevHead = head; // marks the current head of the list that will soon be its end
	
	if(head==NULL){ // checks if list is empty
		printf("List is empty. No list to reverse.\n\n");
	}
	else {
		while(prevHead->next!=NULL){ // loop that keeps on reiterating until the previous head becomes the end
			temp=prevHead; // resets the traversing pointer back to the pre-reversal head of the list
			while(temp->next->next!=NULL){ // loop that reiterates until temp reaches the 2nd to the last node with a yet to be reversed next pointer
				temp=temp->next; //transfers temp to the next node
			}
			if(prevHead==head) head = temp->next; //check if head and previous head still points to the same node (meaning head is not yet moved) and moves head to the end node if true
			temp->next->next = temp; // temp's next node will now point back to temp, reversing the direction of the 'edge'
			temp->next = NULL; // temp's next is set to null as a mark for the next iteration of the innermost while loop
		}
		printf("List reversed.\n\n");
		system("pause"); // pauses terminal
		system("cls"); // clears terminal
	}
}

//function definition that will sort the list in ascending order, using a selection sort-esque algorithm
void sort_List(){
	struct node *ptr, *temp, *swap; // node pointers used for traversing the list and swap pointer to mark which node to swap data with ptr
	int swapData; // integer variable used for temporarily storing node data for swapping
	
	if(head==NULL){ // checks if list is empty
		printf("List is empty. No data to sort.\n\n");
	}
	else {
		ptr = head; // sets current node at beginning
		while(ptr->next!=NULL){ // loop that traverses the list until its end
			swap = ptr; // sets current node as default smallest data
			temp = ptr; // resets temp to start of unsorted data
			while(temp!=NULL){ // loop that traverses the list until after its end, starting from the foremost unsorted element
				if(swap->data > temp->data) swap = temp; // if there is data value found to be smaller than current node, marks the node with smaller data value as the smallest
				temp = temp->next; // transfers temp to the next node
			}
			if(ptr!=swap){ // if current node is not the smallest
				// smallest data will be swapped places with current node
				swapData = swap->data;
				swap->data = ptr->data;
				ptr->data = swapData;
			}
			ptr = ptr->next; // transfers current node to the next node
		}
		printf("List sorted.\n\n");
		system("pause"); // pauses terminal
		system("cls"); // clears terminal
	}	
}

//function definition that will remove nodes with duplicate data values in the list
void pop_Duplicates(){
	struct node *ptr, *temp, *pop; // node pointers for 'unique' elements, for traversing list and popping duplicate nodes
	int pop_ctr = 0; // counter for number of duplicates removed from list
	
	if(head==NULL){ // checks if list is empty
		printf("List is empty. Cannot pop duplicates.\n\n");
	}
	else {
		ptr = head; // begins 'unique' elements with head
		while(ptr!=NULL){ // loop that traverses each unique element to find all its duplicates
			pop = ptr; // begins duplicate hunting at 'unique' marker
			while(pop->next!=NULL){ //loop that traverses the rest of the list
				temp = pop; // 'checkpoint' node in case of necessary node popping
				pop = pop->next; // transfers pop to the next node
				if(pop->data == ptr->data){ // if pop ended up on a node with a duplicate data value compared to the 'unique' marker node
					temp->next = pop->next; // 'checkpoint' node will take pop's next node as its own next node
					free(pop); // removes the duplicate node
					pop = temp; // pop goes back to 'checkpoint' to continue traversing the remaining list in search of duplicates
					pop_ctr++; // increments the count of duplicate nodes removed
				}
			}
			ptr = ptr->next; // after all duplicates are found, ptr is transferred to its next node, guaranteed to be of different data value and become the new 'unique' marker
		}
		//selects proper display text in accordance to the number of nodes removed
		if(pop_ctr>1) printf("%d duplicates removed.\n\n", pop_ctr);
		else if (pop_ctr==1) printf("Only %d duplicate found and removed.\n\n", pop_ctr);
		else printf("No duplicates found.\n\n");
		system("pause"); // pauses terminal
		system("cls"); // clears terminal
	}
}

//function definition that will display the elements of the list
void display_List(){
	struct node *ptr; // node pointer for traversing the list if not empty
	if(head==NULL){ // checks if list is empty
		printf("List is currently empty.\n");
	}
	else { // if not empty
		ptr = head; // ptr points to head to begin traversing the list
		printf("Current list: ");
		while(ptr!=NULL){ // loop that traverses the list until its end
			printf("%d ", ptr->data); // prints current node, eventually all nodes in the list
			ptr = ptr->next; // transfers pointer to the next node
		}
		printf("\n");
	}
}
