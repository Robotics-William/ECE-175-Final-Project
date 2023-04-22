#ifndef FILENAME_H
#define FILENAME_H
#include "cards.c"

typedef struct card_s {
	char color[10];
	int value;
	char action[15];
	//struct card_s* pt;
} card;

void readCardFile(FILE *inp, int size, card carray[]) {

	for (int i = 0; i < size; i++) {
		fscanf(inp, "%s %d %s", carray[i].color, &carray[i].value, carray[i].action);
	}

}

void printCardArray(card carray[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%s %d %s\n", carray[i].color, carray[i].value, carray[i].action);
	}

}


#endif