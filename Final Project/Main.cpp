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

	char inputChar = 'a';
	char dummy;
	char fileName[20];
	char scan[12];
	
	char playerNames[4][20] = { NULL, NULL, NULL, NULL };

	int i;
	int j;
	int playerIndex;
	int playerNum;
	int centerNum;
	int discards;
	int draws;

	int* scores;

	bool valid = false;

	card drawnCard;
	card centerCard;
	card playCard[2];
	
	card* temp = NULL;
	card* center = NULL;
	card* players[4] = { NULL, NULL, NULL, NULL };


	// inputs the number of players
	printf("Let's play a game of DOS\n\nInput your cards using the format 'color number'\nEnter 11 as the number for Wild # Cards\n\n");
	while (inputChar != 'q') {
		printf("Enter the number of players: ");
		scanf("%d", &playerNum);

		if (playerNum >= 1 && playerNum < 5) {
			//initPlayers(players, playerNum);
			inputChar = 'q';
		}
		else {
			printf("The number of players must be between 2 and 4\n");

		}
	}
	
	// chooses starting deck
	while ((inputChar != '1') && (inputChar != '2')) {
		printf("\nPress 1 to shuffle the DOS deck or 2 to load a deck from a file: ");
		scanf(" %c", &inputChar);

		if (inputChar == '1') {
			inputFile = fopen("CardDeck.txt", "r");
			readCardFile(inputFile, deck, deckSize);
			shuffleCard(deck, deckSize);

		}
		else if (inputChar == '2') {
			//opens files
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
	
	// allocate memory to integer scores
	scores = (int*)malloc(playerNum * sizeof(int));
	for (i = 0; i < playerNum; i++) {
		scores[i] = 0;
	}

	//get the player names
	for (i = 0; i < playerNum; i++) {
		printf("\nPlayer %d Enter your name: ", i + 1);
		if (i == 0) {
			scanf("%c", &dummy);
		}
		fgets(playerNames[i], 20, stdin);
		playerNames[i][strlen(playerNames[i])] = '\0';
		
	}

	// deals out seven alternating cards to each player
	for (i = 0; i < 7; i++) {
		for (j = 0; j < playerNum; j++) {
			drawnCard = dealCard(deck, deckSize);
			players[j] = addCard(players[j], drawnCard);

		}
		
	}
	drawnCard = dealCard(deck, deckSize);

	// initalizes variables for playCard, centerCard, and drawnCard
	playCard[0].pt = NULL;
	playCard[1].pt = NULL;
	centerCard.pt = NULL;
	drawnCard.pt = NULL;
	strcpy(playCard[0].action, "none");
	strcpy(playCard[1].action, "none");
	strcpy(centerCard.action, "none");
	strcpy(drawnCard.action, "none");

	/* italizes the number of center cards to zero before drawing 
	and choose a random starting player */
	centerNum = 0;
	playerIndex = rand() % playerNum;

	//TODO add multiple rounds
	//TODO reshuffle and deal new cards

	// adds up to two cards to the center
	for (i = centerNum; i < 2; i++) {
		drawnCard = dealCard(deck, deckSize);
		center = addCard(center, drawnCard);
		centerNum++;
	}

	while (true) {
		
		//TODO add player names
		// prints the first center row and player hand
		printGame(players, center, playerNames, playerIndex);

		// initalzes the number of bonus cards to play and deal to zero
		discards = 0;
		draws = 0;
		
		// prompt the player to draw or play a card 
		while (true) {
			printf("Enter 'draw' or 'play' to take an action: ");
			scanf("%s", scan);

			// draw a card
			if (strcmp(scan, "draw") == 0) {
				drawnCard = dealCard(deck, deckSize);
				players[playerIndex] = addCard(players[playerIndex], drawnCard);
				strcpy(scan, "continue");
				break;
			}

			// obtain user input to make the first play
			else if (strcmp(scan, "play") == 0) {
				printf("Choose a card on the center row: ");
				scanf("%s %d", &centerCard.color, &centerCard.value);
				printf("Enter a card to play: ");
				scanf("%s %d", &playCard[0].color, &playCard[0].value);
				playCard[1].value = 0;

				// if the center card is a Wild # card, 
				if (centerCard.value == 11) {
					printf("Would you like to add another card? (Yes/No):");
					scanf("%s", scan);
				}

				// check if the single match is valid 
				if (checkPlay(center, players[playerIndex], centerCard, playCard) && (strcmp(scan, "Yes") != 0 && strcmp(scan, "yes") != 0)) {
					
					// play the card from the player's hand and check for bonuses
					players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
					center = deleteCard(center, centerCard);
					centerNum--;
					printGame(players, center, playerNames, playerIndex);
					if (strcmp(centerCard.color, playCard[0].color) == 0) {
						discards++;
					}
					break;
				}

				/* if the single match is invalid or the user wishes to play two cards on a wildcard,
				prompt for an additional card */
				else if (playCard[0].value < centerCard.value) {
					printf("Enter another card to play: ");
					scanf("%s %d", &playCard[1].color, &playCard[1].value);
					
					// if the double match is valid, play the cards and check for bonuses 
					if (checkPlay(center, players[playerIndex], centerCard, playCard)) {
						players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
						players[playerIndex] = deleteCard(players[playerIndex], playCard[1]);
						center = deleteCard(center, centerCard);
						centerNum--;
						printGame(players, center, playerNames, playerIndex);
						if (getDoubleBonus(centerCard, playCard)) {
							discards++;
							draws++;
						}
						break;
					}
					else {
						printf("This is not a valid action\n");
					}
				}
				else {
					printf("This is not a valid action\n");
				}
			}
		}

		// prompt them to play any additional cards
		while (strcmp(scan, "continue") != 0) {
			printf("Enter 'play' to play anothor card or 'continue' to continue your turn: ");
			scanf("%s", scan);
			
			// obtain user input to make additionally plays
			if (strcmp(scan, "play") == 0) {
				printf("Choose a card on the center row: ");
				scanf("%s %d", &centerCard.color, &centerCard.value);
				printf("Enter a card to play: ");
				scanf("%s %d", &playCard[0].color, &playCard[0].value);
				playCard[1].value = 0;
				
				// if the center card is a Wild # card, 
				if (centerCard.value == 11) {
					printf("Would you like to add another card? (Yes/No):");
					scanf("%s", scan);
				}

				// check if the single match is valid 
				if (checkPlay(center, players[playerIndex], centerCard, playCard) && (strcmp(scan, "Yes") != 0 && strcmp(scan, "yes") != 0)) {

					// play the card from the player's hand and check for bonuses 
					players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
					center = deleteCard(center, centerCard);
					centerNum--;
					printGame(players, center, playerNames, playerIndex);
					if (strcmp(centerCard.color, playCard[0].color) == 0) {
						discards++;
					}
				}
				/* if the single match is invalid or the user wishes to play two cards on a wildcard,
				prompt for an additional card */
				else if (playCard[0].value < centerCard.value) {
					printf("Enter another card to play: ");
					scanf("%s %d", &playCard[1].color, &playCard[1].value);

					// if the double match is valid, play the cards and check for bonuses 
					if (checkPlay(center, players[playerIndex], centerCard, playCard)) {
						players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
						players[playerIndex] = deleteCard(players[playerIndex], playCard[1]);
						center = deleteCard(center, centerCard);
						centerNum--;
						printGame(players, center, playerNames, playerIndex);
						if (getDoubleBonus(centerCard, playCard)) {
							discards++;
							draws++;
						}
					}
					else {
						printf("This is not a valid action\n");
					}
				}
				else {
					printf("This is not a valid action\n");
				}
				if (players[playerIndex] == NULL || center == NULL) {
					break;
				}
 			}
		}

		// checks if there is a winner
		if (players[playerIndex] == NULL) {
			scores[playerIndex] = getPoints(players, playerIndex, playerNum);
			break;
		}

		// draw up to two cards from the deck to the center row
		for (i = centerNum; i < 2; i++) {
			drawnCard = dealCard(deck, deckSize);
			center = addCard(center, drawnCard);
			centerNum++;
		}

		printGame(players, center, playerNames, playerIndex);

		// discard to the center row
		i = 0;
		while (i < discards) {	
			printf("Enter a card to add to the center row: ");
			scanf("%s %d", &centerCard.color, &centerCard.value);
			temp = players[playerIndex];
			while (temp != NULL) {

				//if the inputed card exists, discard it to the center row
				if (strcmp(temp->color, centerCard.color) == 0 && temp->value == centerCard.value) {
					players[playerIndex] = deleteCard(players[playerIndex], centerCard);
					center = addCard(center, centerCard);
					centerNum++;
					i++;
					break;
				
				}
				temp = temp->pt;
			}
			

			if (players[playerIndex] == NULL) {
				break;
			}

		}

		// deal out cards for the double match bonus
		for (i = 0; i < draws; i++) {
			for (j = 0; j < playerNum; j++) {
				if (j != playerIndex) {
					drawnCard = dealCard(deck, deckSize);
					players[j] = addCard(players[j], drawnCard);

				}
			}
		}

		// check if there is a winner 
		if (players[playerIndex] == NULL) {
			scores[playerIndex] = getPoints(players, playerIndex, playerNum);
			break;
		}
		// get the next player 
		else  {
			playerIndex = (playerIndex + 1) % playerNum;
		}
	}

	printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n\n\t%s Wins!\n", playerNames[playerIndex]);
	printf("\tScores:" );
	for (i = 0; i < playerNum; i++) {
		printf("\n\t\t%s: \t%d", playerNames[playerIndex], scores[i]);
	}
	printf("\n\n\n+++++++++++++++++++++++++++++++++++++++++++\n");

	return 0;
}