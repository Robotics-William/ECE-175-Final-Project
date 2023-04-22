#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "functions.h"

#define deckSize 12

int main(void) {

	FILE* inputFile = NULL;
	card deck[deckSize];
	card center;
	card play[2];

	char player1[20];
	char player2[20];
	char inputChar = 'a';

	//get plater names
	printf("Let's play a game of DOS\nPlayer 1 Enter your name: ");
	fgets(player1, 20, stdin);
	printf("\nPlayer 2 Enter your name: ");
	fgets(player2, 20, stdin);

	//choose starting deck
	while ((inputChar != '1') && (inputChar != '2')) {
		printf("\nPress 1 to shuffle the DOS deck or 2 to load a deck from a file: ");
		scanf(" %c", &inputChar);

		if (inputChar == '1') {
			inputFile = fopen("CardDeck.txt", "r");
			readCardFile(inputFile, deck, deckSize);
			shuffleCard(deck, deckSize);

		}
		else if (inputChar == '2') {
			//opens file
			printf("Enter the name of the data file: ");
			scanf("%s", fileName);

			// Open file and read data into array
			inputFile = fopen(fileName, "r");
			if (inputFile == NULL) {
				printf("Error: Unable to open file try again\n");
				inputChar = 'a';
			}
			else {
				printf("loading a deck from a file\n");
				readCardFile(inputFile, deck, deckSize);
			}
		}
		else {
			printf("Invalid: Try it again\n");
		}
	}
	card drawnCard;

	//distribute a card
	drawnCard = dealCard(deck, deckSize);
	printf("\n%s\n%d\n\n", drawnCard.color, drawnCard.value);
		
	//prints the cards for code development 
	printCardArray(deck, deckSize);

	//verify the checkplay function works 
	center.value = 6;
	play[0].value = 5;
	play[1].value = 1;

	if (checkPlay(center, play)) {
		printf("YAY!!");
	}

	return 0;
}