#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {


	printf("Hello Michael!\n");
	printf("Hello William!\n");

	int steve;
	int patrick;
	int cornwallis;
	int jackson;

	int x = &steve - &patrick;
	int y = &patrick - &cornwallis;
	int z = &cornwallis - &jackson;
	int w = &steve - &jackson;

	printf("%d %d %d %d\n", x, y, z, w);


	return 0;
}