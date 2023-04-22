#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "functions.h"

//#include "cards.c"

#define deckSize 5

int main(void) {

	FILE* inputFile = NULL;
	FILE* userFile = NULL;
	card deck[deckSize];
	char p1[20];
	char p2[20];
	char i = 'a';
	char fileName[20];
	bool deckCreated = false;


	printf("Let's play a game of DOS\nPlayer 1 Enter your name: ");
	fgets(p1, 20, stdin);
	printf("\nPlayer 2 Enter your name: ");
	fgets(p2, 20, stdin);

	
	while (!deckCreated) {
		while ((i != '1') && (i != '2')) {
			printf("\nPress 1 to shuffle the DOS deck or 2 to load a deck from a file: ");
			scanf(" %c", &i);

			if (i == '1') {
				//suffles the deck
				//shuffleCard(deck, deckSize);
				//opens file
				//inputFile = fopen("cards.txt", "r");
			}
			else if (i == '2') {
				//opens file
				printf("Enter the name of the data file: ");
				scanf("%s", fileName);

				// Open file and read data into array
				userFile = fopen(fileName, "r");
				if (userFile == NULL) {
					printf("Error: Unable to open file try again\n");
					i = 'a';
				}
				else {
					printf("load a deck from a file\n");
				}
			}
			else {
				printf("Invalid: Try it again\n");
			}
		}
	}

	//reads file contents into the deck of cards
	readCardFile(inputFile, deckSize, deck);



	//deal a card
	//dealCard();

	//prints the cards for code development 
	printCardArray(deck, deckSize);


	return 0;
}