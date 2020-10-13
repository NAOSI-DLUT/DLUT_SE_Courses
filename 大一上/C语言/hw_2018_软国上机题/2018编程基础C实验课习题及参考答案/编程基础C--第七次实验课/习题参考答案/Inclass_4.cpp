#include<stdio.h>
void inputScores(int scores[5][4]){
	int i,j;
	for(i=0;i<5;i++){
		printf("Please input student %d's scores:\n", i+1);
		for(j=0;j<4;j++){
			scanf("%d", &scores[i][j]);
		}
	}
}
void failedClassNum(int scores[5][4], int failed[5]){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			if(scores[i][j]<60)
				failed[i]++;
		}
	}
}

void passRate(int scores[5][4], float pass[4]){
	int i,j;
	for(j=0;j<4;j++){
		for(i=0;i<5;i++){
			if(scores[i][j]>=60)
				pass[j] += 1/5.0;
		}
	}
}

void printScores(int scores[5][4]){
	int i,j;
	for(i=0;i<5;i++){
		printf("Student %d's scores.\n", i+1);
		for(j=0;j<4;j++){
			printf("%d\t", scores[i][j]);
		}
		printf("\n");
	}
}

void printArray(int failed[5], float pass[4]){
	int i=0;
	for(i=0;i<5;i++){
		printf("Student %d's failed class: %d\n", i+1, failed[i]);
	}
	for(i=0;i<4;i++){
		printf("Class %d's pass rate: %.2f%%\n", i+1, pass[i]*100);
	}
}

int main(){
	int scores[5][4], failed[5]={0};
	float pass[4]={0};
	inputScores(scores);
	failedClassNum(scores, failed);
	passRate(scores, pass);
	printArray(failed, pass);
	printScores(scores);
	return 0;
}
