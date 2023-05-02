#ifndef FILENAME_H
#define FILENAME_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//#include "cards.c"

typedef struct card_s {
	char color[10];
	int value;
	char action[15];
	struct card_s* pt;
} card;


void readCardFile(FILE *inp, card carray[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		fscanf(inp, "%s %d %s", carray[i].color, &carray[i].value, carray[i].action);
		carray[i].pt = NULL;

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

//bool checkPlay(card centerCard, card* playCards) {
//
//	if (centerCard.value == playCards->value) {
//		return true;
//	
//	}
//	else if (centerCard.value == (playCards[0].value + playCards[1].value)) {
//		return true;
//	}
//
//	return false; 
//
//}

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

void printCardArray(card carray[], int size) {
	int i;
	int j;
	int length;
	int printLen;

	for (i = 0; i < size; i++) {
		
		printf(" =========    ");
		
	}
	printf("\n");

	for (i = 0; i < size; i++) {

		length = strlen(carray[i].color);
		printLen = (9 - length) / 2;

		printf("/");
		for (j = 0; j < printLen; j++) {
			printf(" ");

		}
		if (length % 2 == 0) {
			printf(" ");

		}
		printf("%s", carray[i].color);

		for (j = 0; j < printLen; j++) {
			printf(" ");

		}
		printf("\\   ");

	}
	printf("\n");

	for (i = 0; i < size; i++) {
		if (carray[i].value == 1 || carray[i].value == 4) {
			printf("|         |   ");

		}
		else if (carray[i].value == 10) {
			printf("|     __  |   ");

		}
		else if (carray[i].value == 11) {
			printf("|  _/___/_|   ");
		}
		else {
			printf("|   __    |   ");
		}

	}
	printf("\n");

	for (i = 0; i < size; i++) {
		if (carray[i].value == 1) {
			printf("|    |    |   ");

		}
		else if (carray[i].value == 2 || carray[i].value == 3) {
			printf("|   __|   |   ");

		}
		else if (carray[i].value == 4 || carray[i].value == 8 || carray[i].value == 9) {
			printf("|  |__|   |   ");
		}
		else if (carray[i].value == 5 || carray[i].value == 6) {
			printf("|  |__    |   ");
		}
		else if (carray[i].value == 7) {
			printf("|     |   |   ");
		}
		else if (carray[i].value == 10) {
			printf("|  | |  | |   ");
		}
		else {
			printf("| _/___/_ |   ");
		}

	}
	printf("\n");

	for (i = 0; i < size; i++) {
		if (carray[i].value == 1) {
			printf("|    |    |   ");

		}
		else if (carray[i].value == 2) {
			printf("|  |__    |   ");
		}
		else if (carray[i].value == 3 || carray[i].value == 5 || carray[i].value == 9) {
			printf("|   __|   |   ");
		}
		else if (carray[i].value == 4 || carray[i].value == 7) {
			printf("|     |   |   ");
		}
		else if (carray[i].value == 6 || carray[i].value == 8) {
			printf("|  |__|   |   ");
		}
		else if (carray[i].value == 10) {
			printf("|  | |__| |   ");

		}
		else {
			printf("| /   /   |   ");
		}

	}
	printf("\n");

	for (i = 0; i < size; i++) {

		printf("|         |   ");

	}
	printf("\n");

	for (i = 0; i < size; i++) {

		length = strlen(carray[i].color);
		printLen = (9 - length) / 2;

		printf("\\");
		for (j = 0; j < printLen; j++) {
			printf(" ");

		}
		printf("%s", carray[i].color);
		for (j = 0; j < printLen; j++) {
			printf(" ");

		}
		if (length % 2 == 0) {
			printf(" ");

		}
		printf("/   ");

	}
	printf("\n");

	for (i = 0; i < size; i++) {

		printf(" =========    ");

	}

	//printf("%s %d %s\n", carray[i].color, carray[i].value, carray[i].action);
}

void printList(card *hand) {
	card* temp = hand;
	int length;
	int printLen;
	int i;

	while (temp != NULL) {
		printf(" =========    ");
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {

		length = strlen(temp->color);
		printLen = (9 - length) / 2;

		printf("/");
		for (i = 0; i < printLen; i++) {
			printf(" ");

		}
		if (length % 2 == 0) {
			printf(" ");

		}
		printf("%s", temp->color);

		for (i = 0; i < printLen; i++) {
			printf(" ");

		}
		printf("\\   ");
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {
		if (temp->value == 1 || temp->value == 4) {
			printf("|         |   ");

		}
		else if (temp->value == 10) {
			printf("|     __  |   ");

		}
		else if (temp->value == 11) {
			printf("|  _/___/_|   ");
		}
		else {
			printf("|   __    |   ");
		}
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {
		if (temp->value == 1) {
			printf("|    |    |   ");

		}
		else if (temp->value == 2 || temp->value == 3) {
			printf("|   __|   |   ");

		}
		else if (temp->value == 4 || temp->value == 8 || temp->value == 9) {
			printf("|  |__|   |   ");
		}
		else if (temp->value == 5 || temp->value == 6) {
			printf("|  |__    |   ");
		}
		else if (temp->value == 7) {
			printf("|     |   |   ");
		}
		else if (temp->value == 10) {
			printf("|  | |  | |   ");
		}
		else {
			printf("| _/___/_ |   ");
		}
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {
		if (temp->value == 1) {
			printf("|    |    |   ");

		}
		else if (temp->value == 2) {
			printf("|  |__    |   ");
		}
		else if (temp->value == 3 || temp->value == 5 || temp->value == 9) {
			printf("|   __|   |   ");
		}
		else if (temp->value == 4 || temp->value == 7) {
			printf("|     |   |   ");
		}
		else if (temp->value == 6 || temp->value == 8) {
			printf("|  |__|   |   ");
		}
		else if (temp->value == 10) {
			printf("|  | |__| |   ");

		}
		else {
			printf("| /   /   |   ");
		}
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {
		printf("|         |   ");
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {
		length = strlen(temp->color);
		printLen = (9 - length) / 2;

		printf("\\");
		for (i = 0; i < printLen; i++) {
			printf(" ");

		}
		printf("%s", temp->color);
		for (i = 0; i < printLen; i++) {
			printf(" ");

		}
		if (length % 2 == 0) {
			printf(" ");

		}
		printf("/   ");
		temp = temp->pt;
	}
	printf("\n");

	temp = hand;
	while (temp != NULL) {
		printf(" =========    ");
		temp = temp->pt;
	}
	printf("\n");

	//printf("%d\n", size);
	//printf("\n");



	//while (temp != NULL) {
	//	printf("%s-%d\n", temp->color, temp->value);
	//	temp = temp->pt;
	//}
}

card *addCard(card* hand, card drawCard) {
	card* temp;

	/* Based on */

	//dynamically allocates memory to the added card
	card* newCard = (card*)malloc(sizeof(card));
	*newCard = drawCard;

	//checks if the hand is empty
	if (hand == NULL) {
		return newCard;
	}

	//checks if value is smaller than the first card
	if (newCard->value < hand->value) {
		newCard->pt = hand;
		return newCard;
	}

	//finds location where the value fits in the hand
	temp = hand;
	while ((temp->pt != NULL) && (temp->pt->value < newCard->value)) {
		temp = temp->pt;
	}
	
	//adds the card to that location
	newCard->pt = temp->pt;
	temp->pt = newCard;

	return hand;
}

card *deleteCard(card* hand, card disCard) {
	int i;
	card* found = NULL;
	card* temp;

	// check if list exists
	if (hand == NULL) {
		return NULL;
	}
	//check if the first node is the card
	if ((strcmp(hand->color, disCard.color) == 0) && (hand->value == disCard.value)) {
		found = hand;
		hand = hand->pt;
	}
	else {
		temp = hand; //set temp to the first node
		while (temp->pt != NULL && found == NULL) {
			if ((strcmp(temp->pt->color, disCard.color) == 0) && (temp->pt->value == disCard.value)) {
				found = temp->pt;
				temp->pt = found->pt;
			}
			else {
				temp = temp->pt;
			
			}
		}
	}

	if (found != NULL) {
		free(found);
		return hand;
	}
	else {
		return hand;
	}
	
}

bool checkPlay(card* center, card* hand, card centerCard, card playCard[]) {

	card* temp;
	int exists;
	card* address = NULL;

	exists = 0;
	//iterate through center to find centerCard
	temp = center;
	while (temp != NULL) {
		if (strcmp(temp->color, centerCard.color) == 0 && temp->value == centerCard.value) {
			exists++;
			break;
		}
		temp = temp->pt;
	}

	//iterate through hand to the find the first played card
	temp = hand;
	while (temp != NULL) {
		if (strcmp(temp->color, playCard[0].color) == 0 && temp->value == playCard[0].value) {
			exists++;
			address = temp;
			break;

		}
		temp = temp->pt;

	}

	//iterate through hand to the find the second card if such a card was played
	temp = hand;
	if (playCard[1].value != 0) {
		while (temp != NULL) {

			if (strcmp(temp->color, playCard[1].color) == 0 && temp->value == playCard[1].value && address != temp) {
				exists++;
				break;

			}
			temp = temp->pt;

		}
	}

	//checks if the values of centerCard and playCard are equal and return the result
	if (exists == 3) {
		if (centerCard.value == (playCard[0].value + playCard[1].value)) {
			return true;
		}
		else if (playCard[1].value == 11 && centerCard.value > playCard[0].value) {
			return true; 
		}
		else if (centerCard.value == 11 && (playCard[0].value + playCard[1].value) <= 10) {
			return true;
		}
	}
	else if (exists == 2) {
		if (centerCard.value == playCard[0].value) {
			return true;
		}
		else if (playCard[0].value == 11) {
			return true;
		}
		else if (centerCard.value == 11 && playCard[0].value <= 10) {
			return true;
		}
	}
	return false;
}

int getPoints(card* players[], int currentPlayer, int numPlayers) {
	int i;
	int sum;
	card* temp;

	sum = 0;
	for (i = 0; i < numPlayers; i++) {
		temp = players[i];
		if (i != currentPlayer) {
			while (temp != NULL) {

				if (temp->value == 11) {
					sum += 40; 
				}
				else if (temp->value == 2) {
					sum += 20;
				
				}
				else {
					sum = sum + temp->value;
				}

				temp = temp->pt;
			}

		}
	}

	return sum;

}

bool getDoubleBonus(card centerCard, card playCard[2]) {

	if (strcmp(centerCard.color, playCard[0].color) == 0 && strcmp(centerCard.color, playCard[1].color) == 0) {
		return true;
	}
	else if (strcmp(centerCard.color, playCard[0].color) == 0 && strcmp(playCard[1].color, "black") == 0) {
		return true;

	}
	else if (strcmp(centerCard.color, playCard[1].color) == 0 && strcmp(playCard[0].color, "black") == 0) {
		return true;

	}
	else if (strcmp(playCard[0].color, playCard[1].color) == 0 && strcmp(playCard[0].color, "black") == 0) {
		return true;

	}
	else if (strcmp(playCard[0].color, playCard[1].color) == 0 && strcmp(centerCard.color, "black") == 0) {
		return true;

	}

	return false;

}

void printGame(card* players[], card* center, int currentPlayer) {
	int i;

	printf("\nPlayer %d's turn to play:\n\n\n\n\n\tCenter Row:\n", currentPlayer + 1);
	printList(center);
	printf("\n\tPlayer %d's Hand:\n", currentPlayer + 1);
	printList(players[currentPlayer]);
	

	for (i = 0; i < 5; i++) {
		printf("\n");

	}
}

#endif