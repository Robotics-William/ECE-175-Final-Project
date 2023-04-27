#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "functions.h"
#include "cards.c"

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
	int playerIndex;
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

	/* MAIN GAME LOOP*/
	playerIndex = rand() % playerNum;
	/*while (true) {

		//add two cards to the center row if less than two

		//prompt current player to play card(s) or to draw a card

		//check if player wins

		//else:

		//prompt current player to play bonus cards and distribute any cards to other players

		//check if player wins

		//else:

		//remove matches from the center row

		//change current player to next player

		playerIndex++;
		if (playerIndex == playerNum) {
			playerIndex = 0;

		}
	} */


	/* Declare Current Player the Winner */

	char string[10] = "Blue";

	printCard(3, string);
	

	//Create player hands
	//dealHands(players, deck, deckSize);
	//	//create function to add card

	//printf("\n%d\n", players[0].cardNum);
	//printCardArray(players[0].hand, 7);

	//printf("\n%d\n", players[1].cardNum);
	//printCardArray(players[1].hand, 7);

	////add a card to hand
	//addCard(players, 0, deck, deckSize);

	//printf("\n%d\n", players[0].cardNum);
	//printCardArray(players[0].hand, 8);

	//addCard(players, 1, deck, deckSize);

	//printf("\n%d\n", players[1].cardNum);
	//printCardArray(players[1].hand, 8);

	////remove the third card from hand
	//removeCard(players, 0, 0);
	//
	//printf("\n%d\n", players[0].cardNum);
	//printCardArray(players[0].hand, 7);

	//removeCard(players, 1, 0);

	//printf("\n%d\n", players[1].cardNum);
	//printCardArray(players[1].hand, 7);


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