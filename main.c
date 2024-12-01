/* ADD MORE QUESTIONS IN questions.txt AND IMPLEMENT THE USE OF POINTERS IN THIS CODE BASE BY TOMORROW */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// DONOT CHANGE THIS VALUES WITHOUT DISCUSSING!!
#define MAX_QUES 5
#define MAX_OPTIONS 4

typedef struct {
	char question[256];
	char option[4][50];
	char correctAns;
} Question;

// declaring functions
int mainMenu();
int startGame();
int saveScore(int *s, int t);

// Derclare the array structure and the pointer to that array
Question questions[MAX_QUES];
Question *q = questions;


int main(){
	
	// Load Questions in the structure array
	FILE *fp = fopen("question.txt", "r");
	if (fp == NULL)
	{
		printf("File not opened!");
		return 1;
	}
	
	int i, j;
	for ( i = 0; i < MAX_QUES; i++)
	{	
		fgets((q+i)->question, 256, fp);
		(q+i)->question[strcspn((q+i)->question, "\n")] = '\0'; 

		for ( j = 0; j < MAX_OPTIONS; j++)
		{
			fgets((q+i)->option[j], 50, fp);
			(q+i)->option[j][strcspn((q+i)->option[j], "\n")] = '\0';
		}
		
		
		fscanf(fp, "%c\n", &(q+i)->correctAns);

	}
	
	// Display Main Menu
	mainMenu();

	fclose(fp);

	return 0;
}

int startGame(){
	printf("\n\nYou will be asked %d questions!\n\n", MAX_QUES);

	int i, score = 0;
	for ( i = 0; i < MAX_QUES; i++)
	{
		printf("\n%d. %s\n", i+1, (q+i)->question);
		printf("A) %s\n", (q+i)->option[0]);
		printf("B) %s\n", (q+i)->option[1]);
		printf("C) %s\n", (q+i)->option[2]);
		printf("D) %s\n", (q+i)->option[3]);

		char ans;

		printf("Your answer: ");
		scanf(" %c", &ans);


		if(toupper(ans) == (q+i)->correctAns){
			printf("\nCorrect answer!\n");
			score++;
		}
		else{
			printf("\nWrong answer! Correct answer is %c\n", (q+i)->correctAns);
		}

	}


	// Show and save scores in a file
	printf("\n\nQuiz is finished. Your score: %d/%d", score, MAX_QUES);	
	saveScore(&score, MAX_QUES);
	printf("\nScore saved in score.txt file!");

	

	// Retry the quiz option
	printf("\n\n\n");
	printf("(1) Retry Game\n");
	printf("(2) Main Menu\n");

	printf("\nEnter your choice: ");
	int flag = 0;
	scanf("%d", &flag);
	printf("\n");
	
	if(flag == 1){
		printf("\n\nRestarting game.....");
		startGame();
		
	}
	else if(flag == 2){
		printf("\n\nReturning to mainmenu.....");
		mainMenu();
	}
	else{
		printf("\nEnter a valid option!");
		return 1;
	}


}

int saveScore(int *s, int t){
	FILE *fp = fopen("score.txt", "a");
	if(fp == NULL){
		printf("score.txt File not opened!");
		return 1;
	}

	fprintf(fp, "%d/%d\n", *s, t);

	fclose(fp);
}


int mainMenu(){

	printf("\nWelcome to the quiz game!\n\n");

    printf("  /\\_/\\  (\n");        
    printf(" ( ^.^ ) _)\n");
    printf("   \\\"/  (\n");       
    printf(" ( | | )\n");
    printf("(__d b__)\n");


	printf("\n");
	printf("(1) Start Game\n");
	printf("(2) Exit Game\n");

	printf("Enter your choice: ");
	int flag = 0;
	scanf("%d", &flag);
	printf("\n");
	
	if(flag == 1){
		printf("Starting game.....");
		startGame();
		
	}
	else if(flag == 2){
		printf("Exiting game.....");
		return 1;
	}
	else{
		printf("Enter a valid option!");
		return 1;
	}

};