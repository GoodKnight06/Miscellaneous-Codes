#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int p, r, i, j, k = 0, length, executable, flag, marker = 0;
	printf("Enter number of processes: ");
	scanf("%d", &p);
	printf("Enter number of types of resources: ");
	scanf("%d", &r);
	
	int totalMatrix[r], allocationMatrix[p][r], maxNeedMatrix[p][r], availableMatrix[p][r], needMatrix[p][r], sequence[p], safeState = 1, totalAllocated[r], isExecuted[p];
	
	printf("\nInputting Total Matrix:\n");
	for(i = 0; i < r; i++){
		printf("Enter total available of resource %c: ", i + 65);
		scanf("%d", &totalMatrix[i]);
		totalAllocated[i] = 0;
	}
	
	system("cls");
	
	printf("Inputting Allocation Matrix:\n");
	for(i = 0; i < p; i++){
		isExecuted[i] = 0;
		for(j = 0; j < r; j++){
			printf("Enter allocation of resource %c for P%d: ", j + 65, i);
			scanf("%d", &allocationMatrix[i][j]);
			totalAllocated[j] += allocationMatrix[i][j];
		}
		printf("\n");
	}
	
	system("cls");
	
	printf("Inputting Max Need Matrix:\n");
	for(i = 0; i < p; i++){
		for(j = 0; j < r; j++){
			printf("Enter max need of resource %c for P%d: ", j + 65, i);
			scanf("%d", &maxNeedMatrix[i][j]);
			
			needMatrix[i][j] = maxNeedMatrix[i][j] - allocationMatrix[i][j];
		}
		printf("\n");
	}
	
	for(i = 0; i < r; i++){
		availableMatrix[0][i] = totalMatrix[i] - totalAllocated[i];
	}
	
	while(k < p && safeState != 0){
		system("pause");
		system("cls");
		
		executable = 1;
		
		printf("Total    Matrix\n");
		for(i = 0; i < r; i++){
			printf(" %c ", i + 65);
		}
		printf("\n");
		for(i = 0; i < r; i++){
			printf("%2d ", totalMatrix[i]);
		}
		printf("\n\n");
		printf("Process |	Allocation  Matrix |	Max  Need   Matrix |	Available   Matrix |	Need        Matrix |\n");
		printf("	|	");
		for(i = 0; i < 4; i++){
			length = 0;
			for(j = 0; j < r; j++){
				printf(" %c ", j + 65);
				length += 3;
			}
			while(length < 18){
				printf("   ");
				length += 3;
			}
			printf(" |	");
		}
		printf("\n");
		for(i = 0; i < p; i++){
			printf("P%d      |	", i);
			length = 0;
			for(j = 0; j < r; j++){
				printf("%2d ", allocationMatrix[i][j]);
				length += 3;
			}
			while(length < 18){
				printf("   ");
				length += 3;
			}
			printf(" |	");
			
			length = 0;
			for(j = 0; j < r; j++){
				printf("%2d ", maxNeedMatrix[i][j]);
				length += 3;
			}
			while(length < 18){
				printf("   ");
				length += 3;
			}
			printf(" |	");
			
			length = 0;
			for(j = 0; j < r; j++){
				if(i <= k){
					printf("%2d ", availableMatrix[i][j]);
				}
				else {
					printf("   ");
				}
				length += 3;
			}
			while(length < 18){
				printf("   ");
				length += 3;
			}
			printf(" |	");
			
			length = 0;
			for(j = 0; j < r; j++){
				if(isExecuted[i] == 0){
					printf("%2d ", needMatrix[i][j]);
				}
				else {
					printf("   ");
				}
				length += 3;
			}
			while(length < 18){
				printf("   ");
				length += 3;
			}
			printf(" |\n");
		}
		printf("TOTAL	|	");
		for(i = 0; i < r; i++){
			printf("%2d ", totalAllocated[i]);
		}
		printf("\n\n");
		
		if(marker >= p){
			marker = 0;
		}
		flag = marker;
		do {
			
			if(isExecuted[marker] == 0){
				executable = 1;
				for(i = 0; i < r; i++){
					if(needMatrix[marker][i] > availableMatrix[k][i]){
						executable = 0;
						break;
					}
				}
				if(executable == 1){
					isExecuted[marker] = 1;
					for(i = 0; i < r; i++){
						availableMatrix[k + 1][i] = availableMatrix[k][i] + allocationMatrix[marker][i];
					}
					sequence[k] = marker;
					k++;
					marker++;
					break;
				}
				else {
					printf("Skipped P%d; not executable, need more resources.\n", marker);
					marker++;
				}
			}
			else {
				printf("P%d already executed.\n", marker);
				marker++;
			}
			if(marker >= p){
				marker = 0;
			}
		} while(flag != marker);
		
		if(flag == marker){
			printf("UNSAFE STATE!\n");
			safeState = 0;
		}
		else {
			printf("P%d executed! Freeing allocated resources.\n", marker - 1);
		}
		
	}
	
	if(safeState == 1){
		printf("SAFE STATE!\n");
		printf("Sequence: ");
		for(i = 0; i < p - 1; i++){
			printf("P%d->", sequence[i]);
		}
		printf("P%d\n", sequence[p - 1]);
	}
	return 0;
}
