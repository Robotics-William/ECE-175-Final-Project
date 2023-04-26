#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "functions.h"

#define deckSize 108

int main(void) {

	FILE* inputFile = NULL;
	card deck[deckSize];
	card drawnCard;
	card center;
	card play[2];

	player players[4];
	char inputChar = 'a';
	char fileName[20];

	int i;
	int playerNum;

	//get plater names
	printf("Let's play a game of DOS\n");
	while (inputChar != 'q') {
		printf("Enter the number of players: ");
		scanf("%d", &playerNum);

		if (playerNum >= 1 && playerNum < 5) {
			initPlayers(players, playerNum);
			inputChar = 'q';
		}
		else {
			printf("The number of players must be between 2 and 4\n");

		}
	}

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
	

	//TODO initalize player hands
		//TODO create function to intialize player hands
	
	dealHands(players, deck, deckSize);

	//card* playerHand = (card*)malloc(7 * sizeof(card));

	//for (i = 0; i < 7; i++) {
	//	playerHand[i] = dealCard(deck, deckSize);

	//}
		//create function to add card
	players[0].hand = (card*)realloc(players[0].hand, 8 * sizeof(card));
	players[0].hand[7] = dealCard(deck, deckSize);

	printf("\n");
	printCardArray(players[0].hand, 8);
	printf("\n");
	printCardArray(players[1].hand, 7);


	//TODO Create Game loop
		//pull two cards to center
		//add bonus cards from previous player
		//prompt player to play card
		//check if play is valid
		//increment bonuses
		//deal out cards

	//distribute a card
	//drawnCard = dealCard(deck, deckSize);


	//printf("\n%s\n%d\n\n", drawnCard.color, drawnCard.value);
		
	//prints the cards for code development 
	/*printCardArray(deck, deckSize);*/

	//verify the checkplay function works 
	//center.value = 6;
	//play[0].value = 5;
	//play[1].value = 1;

	//if (checkPlay(center, play)) {
	//	printf("YAY!!");
	//}

	return 0;
}