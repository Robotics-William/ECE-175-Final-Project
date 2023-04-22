#ifndef FILENAME_H
#define FILENAME_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


typedef struct card_s {
	char color[10];
	int value;
	char action[15];
	//struct card_s* pt;
} card;

void readCardFile(FILE *inp, int size, card carray[]) {
	int i;

	for (i = 0; i < size; i++) {
		fscanf(inp, "%s %d %s", carray[i].color, &carray[i].value, carray[i].action);
	}

}

void shuffleCard(card carray[], int size) {
	int i;
	int a, b; 
	card temp;

	srand(int(time(0)));

	for (i = 0; i < 108; i++) {

		a = rand() % size;
		b = rand() % size;

		temp = carray[a];
		carray[a] = carray[b];
		carray[b] = carray[a];

	}




}

card dealCard();

void printCardArray(card carray[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%s %d %s\n", carray[i].color, carray[i].value, carray[i].action);
	}

}


#endif