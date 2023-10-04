#include <stdio.h>
#include <math.h>

int main(void) {
	double aa = 0.0;
	double bb = 0.0;
	double cc = 0.0;
	double discrim = 0;
	double r1 = 0.0;
	double r2 = 0.0;

	printf("please enter 3 numbers to be entered into the quadratic formula.\n");
	printf("enter your first number\n");
	scanf_s("%f", &aa);
	printf("enter your second number\n");
	scanf_s("%f", &bb);
	printf("enter your third number\n");
	scanf_s("%f", &cc);

	discrim = pow(bb, 2) - (4 * aa * cc);
	discrim = sqrt(discrim);

	if (bb > 0) {
		r1 = (discrim - bb) / (2 * aa);
		r2 = (2 * cc) / (discrim - bb);
	}
	else if (bb < 0) {
		r1 = -(2 * cc) / (discrim + bb);
		r2 = -(discrim + bb) / (2 * aa);
	}
	else {
		r1 = sqrt(cc / aa);
		r2 = -r1;
	}

	printf("r1: %15.20f r2: %15.20f", r1, r2);
}