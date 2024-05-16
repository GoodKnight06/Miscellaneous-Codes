#include <stdio.h>
#include <stdlib.h>

struct process{
	char name;
	int prio;
	int burstTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
	struct process *next;
} *head;

struct queuer{
	char name;
	int remainingBT;
	struct queuer *next;
} *first;

int count, quantumTime;
float aveTAT = 0, aveWT = 0;

void askInput();
void askInputRR();
void fcfs();
void sjf();
void priority();
void rr();
void display(int);

int main(int argc, char *argv[]) {
	int choice = 0;
	do {
		printf("\tScheduling Algorithms\n");
		printf("\t1. FCFS\n");
		printf("\t2. SJF (NP)\n");
		printf("\t3. Priority (NP)\n");
		printf("\t4. Round Robin\n");
		printf("\t5. Exit\n\n");
		printf("\tEnter choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1: askInput();
			fcfs();
			display(choice);
			break;
			case 2: sjf();
			fcfs();
			display(choice);
			break;
			case 3: priority();
			fcfs();
			display(choice);
			break;
			case 4: askInputRR();
			rr();
			display(choice);
			break;
			case 5: printf("\tProgram exited.\n");
			exit(0);
			break;
			default: printf("\tInvalid input.\n");
			break;
			
		}
		system("pause");
		system("cls");
	} while (choice!=5);
	
	return 0;
}

void askInput(){
	int i, tempBT;
	struct process *newP, *temp;
	
	printf("\tEnter number of processes: ");
	scanf("%d", &count);
	
	for(i = 0; i < count; i++){
		newP = (struct process*)malloc(sizeof(struct process));
		newP->name = (char)(i + 65);
		printf("\tEnter burst time for process %c: ", i + 65);
		scanf("%d", &tempBT);
		newP->burstTime = tempBT;
		newP->next = NULL;
		
		if(head == NULL){
			head = newP;
		}
		else {
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newP;
		}
	}
}

void askInputRR(){
	int i, tempBT;
	struct process *newP, *temp;
	
	printf("\tEnter Quantum Time: ");
	scanf("%d", &quantumTime);
	printf("\tEnter number of processes: ");
	scanf("%d", &count);
	
	for(i = 0; i < count; i++){
		newP = (struct process*)malloc(sizeof(struct process));
		newP->name = (char)(i + 65);
		printf("\tEnter burst time for process %c: ", i + 65);
		scanf("%d", &tempBT);
		newP->burstTime = tempBT;
		newP->next = NULL;
		
		if(head == NULL){
			head = newP;
		}
		else {
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newP;
		}
	}
}

void fcfs(){
	int qClock = 0;
	float totalTAT = 0, totalWT = 0;
	struct process *temp;
	
	temp = head;
	while(temp!=NULL){
		qClock += temp->burstTime;
		temp->completionTime = qClock;
		temp->turnAroundTime = temp->completionTime;
		temp->waitingTime = temp->turnAroundTime - temp->burstTime;
		
		totalTAT += temp->turnAroundTime;
		totalWT += temp->waitingTime;
		
		temp = temp->next;
	}
	aveTAT = totalTAT / count;
	aveWT = totalWT / count;
}

void sjf(){
	int i, tempBT;
	struct process *newP, *temp, *prev;
	
	printf("\tEnter number of processes: ");
	scanf("%d", &count);
	
	for(i = 0; i < count; i++){
		newP = (struct process*)malloc(sizeof(struct process));
		newP->name = (char)(i + 65);
		printf("\tEnter burst time for process %c: ", i + 65);
		scanf("%d", &tempBT);
		newP->burstTime = tempBT;
		newP->next = NULL;
		
		if(head == NULL){
			head = newP;
		}
		else {
			if(newP->burstTime < head->burstTime){
				newP->next = head;
				head = newP;
			}
			else {
				temp = head;
				while(temp != NULL && newP->burstTime >= temp->burstTime){
					prev = temp;
					temp = temp->next;
				}
				prev->next = newP;
				newP->next = temp;
			}
		}
	}
}

void priority(){
	int i, tempBT, tempPrio;
	struct process *newP, *temp, *prev;
	
	printf("\tEnter number of processes: ");
	scanf("%d", &count);
	
	for(i = 0; i < count; i++){
		newP = (struct process*)malloc(sizeof(struct process));
		newP->name = (char)(i + 65);
		printf("\tEnter priority number of process %c: ", i + 65);
		scanf("%d", &tempPrio);
		printf("\tEnter burst time for process %c: ", i + 65);
		scanf("%d", &tempBT);
		newP->burstTime = tempBT;
		newP->prio = tempPrio;
		newP->next = NULL;
		
		if(head == NULL){
			head = newP;
		}
		else {
			if(newP->prio < head->prio){
				newP->next = head;
				head = newP;
			}
			else {
				temp = head;
				while(temp != NULL && newP->prio > temp->prio){
					prev = temp;
					temp = temp->next;
				}
				prev->next = newP;
				newP->next = temp;
			}
		}
	}
}

void rr(){
	int quantumClock = 0;
	struct process *temp;
	struct queuer *tempQ, *newQ;
	float totalTAT = 0, totalWT = 0, totalBT = 0;
	
	temp = head;
	while(temp!=NULL){
		newQ = (struct queuer*)malloc(sizeof(struct queuer));
		newQ->name = temp->name;
		newQ->remainingBT = temp->burstTime;
		newQ->next = NULL;
		totalBT += newQ->remainingBT;
		
		if(first == NULL){
			first = newQ;
			newQ->next = newQ;
		}
		else {
			tempQ = first;
			while(tempQ->next != first){
				tempQ = tempQ->next;
			}
			tempQ->next = newQ;
			newQ->next = first;
		}
		temp = temp->next;
	}
	
	tempQ = first;
	while(totalBT > 0){
		if(tempQ->remainingBT > 0){
			if(tempQ->remainingBT <= quantumTime){
				quantumClock += tempQ->remainingBT;
				totalBT -= tempQ->remainingBT;
				tempQ->remainingBT -= quantumTime;
				
				temp = head;
				while(temp->name != tempQ->name){
					temp = temp->next;
				}
				temp->completionTime = quantumClock;
				temp->turnAroundTime = temp->completionTime;
				temp->waitingTime = temp->turnAroundTime - temp->burstTime;
				
				totalTAT += temp->turnAroundTime;
				totalWT += temp->waitingTime;
				
			}
			else {
				quantumClock += quantumTime;
				totalBT -= quantumTime;
				tempQ->remainingBT -= quantumTime;
				tempQ = tempQ->next;
			}
		}
		else {
			tempQ = tempQ->next;
		}
	}
	
	aveTAT = totalTAT / count;
	aveWT = totalWT / count;
}

void display(int choice){
	struct process *temp, *prev;
	struct queuer *tempQ, *prevQ;
	int totalTAT = 0, totalWT = 0;
	
	temp = head;
	tempQ = first;
	printf("\n");
	switch (choice){
		case 1: printf("\tFCFS Algorithm\n\n");
		break;
		case 2: printf("\tSJF (NP) Algorithm\n\n");
		break;
		case 3: printf("\tPriority (NP) Algorithm\n\n");
		break;
		case 4: printf("\tRound Robin Algorithm, Quantum Time = %d\n\n", quantumTime);
		break;
	}
	printf("Process\tBT\tCT\tTAT\tWT\tPriority\n");
	while(temp!=NULL){
		printf("%c\t", temp->name);
		printf("%d\t", temp->burstTime);
		printf("%d\t", temp->completionTime);
		printf("%d\t", temp->turnAroundTime);
		printf("%d\t", temp->waitingTime);
		if(choice == 3) printf ("%d\n", temp->prio);
		else printf("#\n");
		
		totalTAT += temp->turnAroundTime;
		totalWT += temp->waitingTime;
		
		prev = temp;
		temp = temp->next;
		free(prev);
		
		if(choice == 4){
			prevQ = tempQ;
			tempQ = tempQ->next;
			free(prevQ);
		}
	}
	printf("Total\t\t\t%d\t%d\n", totalTAT, totalWT);
	printf("Average Turnaround Time = %.3f\n", aveTAT);
	printf("Average Waiting Time = %.3f\n", aveWT);
	head = NULL;
	first = NULL;
}
