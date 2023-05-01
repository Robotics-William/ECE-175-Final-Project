#ifndef CARDS_H
#define CARDS_H

#include <stdio.h>
#include <math.h>
#include <string.h>

void printCard(int cardNum, char x[]) {

	int length;
	int print;
	int i;

		length = strlen(x);
		print = (9 - length) / 2;

		printf(" ========= \n/");

		for (i = 0; i < print; i++) {
			printf(" ");

		}
		if (length % 2 == 0) {
			printf(" ");

		}
		printf("%s", x);

		for (i = 0; i < print; i++) {
			printf(" ");

		}

		printf("\\\n");
		switch (cardNum) {
		case 1:
			printf("|         |\n");
			printf("|    |    |\n");
			printf("|    |    |\n");
			printf("|         |\n");
			break;
		case 2:
			printf("|   __    |\n");
			printf("|   __|   |\n");
			printf("|  |__    |\n");
			printf("|         |\n");
			break;
		case 3:
			printf("|   __    |\n");
			printf("|   __|   |\n");
			printf("|   __|   |\n");
			printf("|         |\n");
			break;
		case 4:
			printf("|         |\n");
			printf("|  |__|   |\n");
			printf("|     |   |\n");
			printf("|         |\n");
			break;
		case 5:
			printf("|   __    |\n");
			printf("|  |__    |\n");
			printf("|   __|   |\n");
			printf("|         |\n");
			break;
		case 6:
			printf("|   __    |\n");
			printf("|  |__    |\n");
			printf("|  |__|   |\n");
			printf("|         |\n");
			break;
		case 7:
			printf("|   __    |\n");
			printf("|     |   |\n");
			printf("|     |   |\n");
			printf("|         |\n");
			break;
		case 8:
			printf("|   __    |\n");
			printf("|  |__|   |\n");
			printf("|  |__|   |\n");
			printf("|         |\n");
			break;
		case 9:
			printf("|   __    |\n");
			printf("|  |__|   |\n");
			printf("|   __|   |\n");
			printf("|         |\n");
			break;
		case 10:
			printf("|     __  |\n");
			printf("|  | |  | |\n");
			printf("|  | |__| |\n");
			printf("|         |\n");
			break;
		case 11:
			printf("|         |\n");
			printf("|  _/___/_|\n");
			printf("| _/___/_ |\n");
			printf("| /   /   |\n");
			printf("|         |\n");
			break;
		default:
			printf("error");
		}


		printf("\\");

		for (i = 0; i < print; i++) {
			printf(" ");

		}
		printf("%s", x);
		for (i = 0; i < print; i++) {
			printf(" ");

		}
		if (length % 2 == 0) {
			printf(" ");

		}

		printf("/\n");
		printf(" ========= \n");


}



#endif