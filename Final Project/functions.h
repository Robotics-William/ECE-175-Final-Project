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

typedef struct player_s {

	bool active;
	char name[20];
	card* hand;

} player;

void readCardFile(FILE *inp, card carray[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		fscanf(inp, "%s %d %s", carray[i].color, &carray[i].value, carray[i].action);

	/*	
		fscanf(inp, "%s %d", carray[i].color, &carray[i].value);
		if (carray[i].value == 11 || carray[i].value == 2) {
			fscanf(inp, "%s", carray[i].action);
		}
		else {
			strcpy(carray[i].action, "");
		}
	*/
		
	}

}

bool checkPlay(card centerCard, card* playCards) {

	if (centerCard.value == playCards->value) {
		return true;
	
	}
	else if (centerCard.value == (playCards[0].value + playCards[1].value)) {
		return true;
	}

	return false; 

}

void shuffleCard(card carray[], int size) {
	int i;
	int a, b; 
	card temp;

	srand(int(time(0)));

	for (i = 0; i < 7 * size; i++) {

		a = rand() % size;
		b = rand() % size;

		temp = carray[a];
		carray[a] = carray[b];
		carray[b] = temp;

	}
}

card dealCard(card carray[], int size) {
	int i;
	card pulledCard;

	pulledCard = carray[0];
	for (i = 0; i < size - 1; i++) {
		carray[i] = carray[i + 1];

	}

	return pulledCard;

}

//void addCard(card carray[], int size) {}

void dealHands(player parray[], card deck[], int size) {
	int i;
	int j;

	for (i = 0; i < 4; i++) {

		if (parray[i].active == true) {
			parray[i].hand = (card*)malloc(7 * sizeof(card));

			for (j = 0; j < 7; j++) {
				parray[i].hand[j] = dealCard(deck, size);
			}
		}
	}
}

void printCardArray(card carray[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		printf("%s %d %s\n", carray[i].color, carray[i].value, carray[i].action);
	}
}

void initPlayers(player parray[4], int numPlayers) {
	int i;
	char dummy;

	for (i = 0; i < 4; i++) {
		parray[i].active = false;
		parray[i].hand = NULL;
	}
	for (i = 0; i < numPlayers; i++) {
		parray[i].active = true;
		printf("\nPlayer %d Enter your name: ", i + 1);
		if (i == 0) {
			scanf("%c", &dummy);
		}
		fgets(parray[i].name, 20, stdin);
		parray[i].name[strlen(parray[i].name) - 1] = '\0';
		printf("%s", parray[i].name);
	}
}

#endif