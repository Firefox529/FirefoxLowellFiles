#include <stdio.h>

int main(void) {
	int input = -1;
	int max = 0;
	do {
		printf("\nPlease input number : ");
		scanf_s("%d", &input);
		if (input > max) {
			max = input;
		}
	} while (input != 0);
	printf("\nThe max is % d.", max);
	printf("\nThe current input is % d", input);
}