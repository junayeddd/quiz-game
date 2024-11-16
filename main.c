#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char question[256];
	char option[4][50];
	char correctAns;
} Question;

int main(){
	
	Question q;
	q.correctAns = 'a';
	printf("%c", q.correctAns);
	return 0;
}

