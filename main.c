#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char question[100];
	char option[4][50];
	char correctAns;
} Question;

void mainMenu();

/* loadQuestions();
 * startGame();
 * saveScore();
*/

int main(){
	
	int total_ques = 10;
	printf("\n\nYou will be asked %d questions!\n\n", total_ques);

	Question questions[total_ques];

	mainMenu();

	

	return 0;
}


void mainMenu(){

	printf("\nWelcome to the quiz game!\n\n");

    printf("  /\\_/\\  (\n");        
    printf(" ( ^.^ ) _)\n");
    printf("   \\\"/  (\n");       
    printf(" ( | | )\n");
    printf("(__d b__)\n");


	printf("\n");
	printf("(1) Start Game\n");
	printf("(2) Exit Game\n");

	printf("Option: ");
	int flag = 0;
	scanf("%d", &flag);
	printf("\n");
	
	if(flag == 1){
		printf("Starting game.....");
	}
	else if(flag == 2){
		printf("Exiting game.....");
	}
	else{
		printf("Enter a valid option!");
	}

}
