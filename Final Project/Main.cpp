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
	char fileName[20];
	char scan[12];

	int i;
	int j;
	int playerIndex;
	int playerNum;
	int centerNum;
	int discards;
	int draws;

	bool valid = false;

	card drawnCard;
	card centerCard;
	card playCard[2];
	
	card* temp = NULL;
	card* center = NULL;
	card* players[4] = {NULL, NULL, NULL, NULL};


	//input number of players
	printf("Let's play a game of DOS\nInput answers as (color number) with # = 11\n");
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
	
	//deal out seven alternating cards to each player
	for (i = 0; i < 7; i++) {
		for (j = 0; j < playerNum; j++) {
			drawnCard = dealCard(deck, deckSize);
			players[j] = addCard(players[j], drawnCard);

		}
		
	}
	drawnCard = dealCard(deck, deckSize);

	//initalize variables for playCard, centerCard, and drawnCard
	playCard[0].pt = NULL;
	playCard[1].pt = NULL;
	centerCard.pt = NULL;
	drawnCard.pt = NULL;
	strcpy(playCard[0].action, "none");
	strcpy(playCard[1].action, "none");
	strcpy(centerCard.action, "none");
	strcpy(drawnCard.action, "none");

	centerNum = 0;
	playerIndex = rand() % playerNum;

	// game loop
	//TODO reshuffle and deal new cards
	//TODO create more functions
	// 
	//add up to two cards to the center
	for (i = centerNum; i < 2; i++) {
		drawnCard = dealCard(deck, deckSize);
		center = addCard(center, drawnCard);
		centerNum++;
	}

	while (true) {
		
		
		//TODO add player names
		//print the first center row and player hand
		printGame(players, center, playerIndex);

		//prompt the current player to do a valid action
		//TODO add multiple plays 
		discards = 0;
		draws = 0;

		printf("Enter 'draw' or 'play' to take an action: ");
		scanf("%s", scan);
		while (true) {
			if (strcmp(scan, "draw") == 0) {
				//printf("You drew!!!");
				drawnCard = dealCard(deck, deckSize);
				players[playerIndex] = addCard(players[playerIndex], drawnCard);
				printGame(players, center, playerIndex);
				break;

			}
			else if (strcmp(scan, "play") == 0) {
				printf("Choose a card on the center row: ");
				scanf("%s %d", &centerCard.color, &centerCard.value);
				printf("Enter a card to play: ");
				scanf("%s %d", &playCard[0].color, &playCard[0].value);
				playCard[1].value = 0;
				//checks if the play is valid
				if (checkPlay(center, players[playerIndex], centerCard, playCard)) {
					//removes cards from player hand and center row,  
					players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
					center = deleteCard(center, centerCard);
					centerNum--;
					printGame(players, center, playerIndex);
					if (strcmp(centerCard.color, playCard[0].color) == 0) {
						discards++;
					}
					break;
				}
				//if not, prompts for an additional card
				else if (playCard[0].value < centerCard.value) {
					printf("Enter another card to play: ");
					scanf("%s %d", &playCard[1].color, &playCard[1].value);
					if (checkPlay(center, players[playerIndex], centerCard, playCard)) {
						players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
						players[playerIndex] = deleteCard(players[playerIndex], playCard[1]);
						center = deleteCard(center, centerCard);
						centerNum--;
						printGame(players, center, playerIndex);
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
		while (strcmp(scan, "continue") != 0) {
			printf("Enter 'play' to play anothor card or 'continue' to continue your turn: ");
			scanf("%s", scan);
			if (strcmp(scan, "play") == 0) {
				printf("Choose a card on the center row: ");
				scanf("%s %d", &centerCard.color, &centerCard.value);
				printf("Enter a card to play: ");
				scanf("%s %d", &playCard[0].color, &playCard[0].value);
				playCard[1].value = 0;
				//checks if the play is valid
				if (checkPlay(center, players[playerIndex], centerCard, playCard)) {
					//removes cards from player hand and center row,  
					players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
					center = deleteCard(center, centerCard);
					centerNum--;
					printGame(players, center, playerIndex);
					if (strcmp(centerCard.color, playCard[0].color) == 0) {
						discards++;
					}
				}
				//if not, prompts for an additional card
				else if (playCard[0].value < centerCard.value) {
					printf("Enter another card to play: ");
					scanf("%s %d", &playCard[1].color, &playCard[1].value);
					if (checkPlay(center, players[playerIndex], centerCard, playCard)) {
						players[playerIndex] = deleteCard(players[playerIndex], playCard[0]);
						players[playerIndex] = deleteCard(players[playerIndex], playCard[1]);
						center = deleteCard(center, centerCard);
						centerNum--;
						printGame(players, center, playerIndex);
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

			}
		}

		//checks if there is a winner
		if (players[playerIndex] == NULL) {
			break;
		}

		for (i = centerNum; i < 2; i++) {
			drawnCard = dealCard(deck, deckSize);
			center = addCard(center, drawnCard);
			centerNum++;
		}

		printGame(players, center, playerIndex);

		//discard to the center row
		i = 0;
		while (i < discards) {
			
			printf("Enter a card to add to the center row: ");
			scanf("%s %d", &centerCard.color, &centerCard.value);
			temp = players[playerIndex];
			while (temp != NULL) {

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
		for (i = 0; i < draws; i++) {
			for (j = 0; j < playerNum; j++) {
				if (j != playerIndex) {
					drawnCard = dealCard(deck, deckSize);
					players[j] = addCard(players[j], drawnCard);

				}
			}
		}

		//check if there is a winner 
		if (players[playerIndex] == NULL) {
			break;
		}
		
		//get the next player 
		playerIndex = (playerIndex + 1) % playerNum;

	}
	
	for (i = 0; i < playerNum; i++) {
		if (i != playerIndex) {
			printList(players[i]);
		}

	}

	printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n\n\n\t\tPlayer %d Wins\n", playerIndex + 1);
	printf("\t\tScore: %d points\n\n\n", getPoints(players, playerIndex, playerNum));
	printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");

	return 0;
}