#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"
//#include "cards.c"

#define deckSize 5

int main(void) {

	FILE* inputFile = NULL;
	card deck[deckSize];

	inputFile = fopen("cards.txt", "r");

	readCardFile(inputFile, deckSize, deck);
	printCardArray(deck, deckSize);


	return 0;
}