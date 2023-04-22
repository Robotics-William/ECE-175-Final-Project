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
	card deck[deckSize];

	//opens file
	inputFile = fopen("cards.txt", "r");

	//reads file contents into the deck of cards
	readCardFile(inputFile, deckSize, deck);

	//suffles the deck
	shuffleCard(deck, deckSize);

	//deal a card
	dealCard();

	//prints the cards for code development 
	printCardArray(deck, deckSize);


	return 0;
}