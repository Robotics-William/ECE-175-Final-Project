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

	//scans a deck of an inputed size into an array
	for (i = 0; i < size; i++) {
		fscanf(inp, "%s %d %s", carray[i].color, &carray[i].value, carray[i].action);
		carray[i].pt = NULL;
		
	}

}

void shuffleCard(card carray[], int size) {
	int i;
	int a, b; 
	card temp;

	// gets a unique seed for the rand() function
	srand(int(time(0)));

	// transposes cards in the deck seven times each size
	for (i = 0; i < 7 * size; i++) {

		// gets two random indices betweeen the 0 and the size
		a = rand() % size;
		b = rand() % size;

		// swaps the cards located at these indices
		temp = carray[a];
		carray[a] = carray[b];
		carray[b] = temp;

	}
}

card dealCard(card carray[], int size) {
	int i;
	card pulledCard;

	// gets the top card
	pulledCard = carray[0];

	// sets each card in the deck to the next card
	for (i = 0; i < size - 1; i++) {
		carray[i] = carray[i + 1];

	}

	return pulledCard;

}

void printList(card *hand) {
	card* temp = hand;
	int length;
	int printLen;
	int i;

	// prints the first line
	while (temp != NULL) {
		printf(" =========    ");
		temp = temp->pt;
	}
	printf("\n");

	// prints the second line
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

	// prints the third line
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

	// prints the fourth line
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

	// prints the fifth line
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

	// prints the sixth line
	temp = hand;
	while (temp != NULL) {
		printf("|         |   ");
		temp = temp->pt;
	}
	printf("\n");

	// prints the seventh line
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

	// prints the last line
	temp = hand;
	while (temp != NULL) {
		printf(" =========    ");
		temp = temp->pt;
	}
	printf("\n");

}

card *addCard(card* hand, card drawCard) {
	card* temp;

	/* Based on code from the Lecture Slides*/

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
	// iterates through center to find centerCard
	temp = center;
	while (temp != NULL) {
		if (strcmp(temp->color, centerCard.color) == 0 && temp->value == centerCard.value) {
			exists++;
			break;
		}
		temp = temp->pt;
	}

	// iterates through hand to the find the first played card
	temp = hand;
	while (temp != NULL) {
		if (strcmp(temp->color, playCard[0].color) == 0 && temp->value == playCard[0].value) {
			exists++;
			address = temp;
			break;

		}
		temp = temp->pt;

	}

	// iterates through hand to the find the second card if such a card was played
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

	// checks if the values of centerCard and playCard are equal and returns the result
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
		else if (playCard[0].value == 11 && (centerCard.value > playCard[1].value)) {
			return true;
		}
		else if (playCard[1].value == 11 && playCard[0].value == 11 && centerCard.value > 2) {
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

	// initalizes the sum to zero
	sum = 0;

	// iterates through the plays
	for (i = 0; i < numPlayers; i++) {

		// if the player is not the current player
		temp = players[i];
		if (i != currentPlayer) {

			// iterates through the player's hand
			while (temp != NULL) {

				// adds the appropriate amount of points to the sum
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

bool getSingleBonus(card centerCard, card playCard[2]) {

	// if the centerCard is black
	if (strcmp(centerCard.color, "black") == 0) {
		return true;
	}
	else if (strcmp(centerCard.color, playCard[0].color) == 0) {
		return true;
	}
	
	return false; 
}

bool getDoubleBonus(card centerCard, card playCard[2]) {

	// if all three cards have the same color
	if (strcmp(centerCard.color, playCard[0].color) == 0 && strcmp(centerCard.color, playCard[1].color) == 0) {
		return true;
	}

	// if the second card played is wild, and the other two are the same color
	else if (strcmp(centerCard.color, playCard[0].color) == 0 && strcmp(playCard[1].color, "black") == 0) {
		return true;
	}

	// if the first card played is wild, and the other two are the same color
	else if (strcmp(centerCard.color, playCard[1].color) == 0 && strcmp(playCard[0].color, "black") == 0) {
		return true;

	}

	// if both played cards are wild
	else if (strcmp(playCard[0].color, playCard[1].color) == 0 && strcmp(playCard[0].color, "black") == 0) {
		return true;

	}

	// if both played cards are the same color, and the center card is wild
	else if (strcmp(playCard[0].color, playCard[1].color) == 0 && strcmp(centerCard.color, "black") == 0) {
		return true;

	}

	return false;

}

void printGame(card* players[], card* center, char array[][20], int currentPlayer) {
	int i;
	
	//prints the current player's name, hand, and center row
	printf("\n%s's turn to play:\n\n\n\n\n\tCenter Row:\n", array[currentPlayer]);
	printList(center);
	printf("\n\t%s's Hand:\n", array[currentPlayer]);
	printList(players[currentPlayer]);
	
	// prints additional new lines
	for (i = 0; i < 5; i++) {
		printf("\n");

	}
}

bool winCheck(int scores[], int numPlayers) {
	int i;
	
	// iterates through the player's scores
	for (i = 0; i < numPlayers; i++) {
		
		// if someone's score is greater or equal to 200
		if (scores[i] >= 200) {
			return true;

		}
	}

	return false;
}

card initCard() {
	card newCard;

	// initalizes the card variables to the default settings
	newCard.value = 0;
	newCard.pt = NULL;
	strcpy(newCard.color, "none");
	strcpy(newCard.action, "none");

	return newCard;
}

#endif