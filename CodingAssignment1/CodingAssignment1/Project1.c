#include <stdio.h>
#include <math.h>

int main(void) {
	double term = 0;
	double manual_sum = 0.0;
	double last_sum = 0.1;
	
	printf("please enter the x value to evalute the series at\n");
	int x = 0;
	scanf_s("%d", &x);

	double n = 1;
	double fact = 1;
	while (manual_sum != last_sum){
		fact = 1;
		for (int ii = 1; ii <= n; ii++) {
			fact = fact * ii;
		}
		term = (pow(x, n)/fact);
		last_sum = manual_sum;
		manual_sum += term;
		printf("term: %.20f sum: %.20f\n", term, manual_sum);
		n += 1;
	}
	printf("the final output of the equation is %.20f\n", manual_sum);
	double actual = exp(x);
	printf("the actual value of the equation is %.20f\n", actual);
	printf("the error is %.20f", (manual_sum - actual));
}