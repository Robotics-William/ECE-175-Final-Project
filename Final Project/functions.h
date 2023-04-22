#ifndef FILENAME_H
#define FILENAME_H
#include "cards.c"

void readCardFile(FILE *inp, int size, card carray[]) {
	FILE *inp;

	for (int i = 0; i < size; i++) {
		fscanf(inp, "%s %d %s", carray[i].color, &carray[i].value, carray[i].action);
	}



}

#endif