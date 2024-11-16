#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char question[100];
	char option[4][50];
	char correctAns;
} Question;


/* loadQuestions();
 * startGame();
 * mainMenu();
 * saveScore();
*/
int main(){
	

	printf("Welcome to the quiz game\n");


	/*Question *q = (Question *)malloc(sizeof(Question));
	int count = 3;
	int size = sizeof(Question);
	
	printf("You will be asked %d questions: \n", count);	
	
	strcpy(q[0].question, "What is 2+2?");
	printf("Question: %s\n", q[0].question);
	printf("size: %d\n", size);

	free(q);
	q = NULL;
	*/
	return 0;
}

	/*
int loadQuestions(char *a){
	FILE *file;
	int n;
	int i = 0;

	file = fopen("question.txt", "r");
	fscanf(file, "%d" , &n);
	
	

	fclose(file);


	return n;
}
*/
