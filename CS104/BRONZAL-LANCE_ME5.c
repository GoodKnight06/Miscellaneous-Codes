#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node *head;

void begin_Insert();
struct node* merge_Sort();
struct node* merge();
void display();

int main(int argc, char *argv[]) {
	
	int choice; // variable declaration for user input for activity choice
	do {
		printf("+-----------------------------+\n");
		printf("|      MACHINE EXERCISE 5     |\n");
		printf("+-----------------------------+\n");
		printf("Choices:\n");
		printf("1.) Insert node at the beginning\n");
		printf("2.) Sort the list in ascending order\n");
		printf("3.) Quit program\n\n");
		display(); // calls function that displays the current list
		printf("\nEnter your choice here: ");
		scanf("%d", &choice); // gets user input choice
		
		switch(choice){ // switch-case to do appropriate task depending on user input
			case 1: begin_Insert(); // calls function for inserting new element at beginning of list
			break;
			case 2: head = merge_Sort(head); // calls function for sorting the elements in the list
			printf("List has been sorted.\n\n");
			system("pause");
			system("cls");
			break;
			case 3: printf("Thank you, have a nice day.\n");
			exit(0);  // exits the program
			break;
			default: printf("Invalid choice input. Try again.\n");
			system("pause"); // pauses terminal
			system("cls"); // clears terminal
			break;
		}
	} while(choice!=3); // do-while loop that allows repetition of the menu after accomplishing a certain task or prompt, unless otherwise closed
	
	return 0;
}

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

struct node* merge_Sort(struct node* source){
	struct node *left, *right; //node pointers for left and right sublists
	
	if(source==NULL){ //if called with empty source argument
		return;
	}
	else if(source->next==NULL){ //if called with a single node
		return source;
	}
	else { //if called with a sublist (head of sublist as argument)
		struct node *mid, *fast; //node pointers for mid and fast traverser
		mid = source; //assigns mid to the head of sublist
		fast = mid->next; //assigns traverser next to the mid
		
		while(fast!=NULL){ //while loop that traverses the traverser and mid, ends with the mid in the middle of the sublist
			fast = fast->next;
			if(fast!=NULL){
				mid = mid->next;
				fast = fast->next;
			}
		}
		
		left = source; //source as head of left sublist
		right = mid->next; //mid's next node as head of right sublist
		mid->next = NULL; //cuts the link between the two sublists
		
		left = merge_Sort(left); //recursive call to split, sort, and merge left sublist, and assigns new left head
		right = merge_Sort(right); //recursive call to split, sort, and merge right sublist, and assigns new right head
		
		return merge(left, right); //merges both sublist and returns the head of the merged list
	}
}

struct node* merge(struct node *left, struct node *right){
	struct node* ptr; //node pointer stands in to mark the smaller element to merge
	
	if(left==NULL){ //if left is null, right will be returned to merge
		return right;
	}
	else if (right==NULL){ //if right is null, left will be returned to merge
		return left;
	}
	else { //else, checks which of the two nodes is smaller
		if(left->data  <= right->data){ 
			ptr = left;
			ptr->next = merge(left->next, right); //recursive call to check which element should follow the merge
		}
		else {
			ptr = right;
			ptr->next = merge(left, right->next); //recursive call to check which element should follow the merge
		}
		return ptr; //returns the smaller number for merging
	}
}

//function definition that will display the elements of the list
void display(){
	struct node *ptr; // node pointer for traversing the list if not empty
	if(head==NULL){ // checks if list is empty
		printf("List is currently empty.\n");
	}
	else { // if not empty
		ptr = head; // ptr points to head to begin traversing the list
		printf("Current list: ");
		while(ptr!=NULL){ // loop that traverses the list until its end
			printf("%d->", ptr->data); // prints current node, eventually all nodes in the list
			ptr = ptr->next; // transfers pointer to the next node
		}
		printf("NULL\n");
	}
}
