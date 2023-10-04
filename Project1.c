#include <stdio.h>
#include <math.h>

int main(void) {
	double term = 0;
	double sum = 0.0;
	double last_sum = 0.1;
	
	printf("please enter the x value to evalute the series at\n");
	int x = 0;
	scanf_s("%d", &x);

	double n = 1;
	double fact = 1;
	double power = 1;
	while (sum != last_sum){
		fact = 1;
		power = pow(x, n);
		for (int ii = 1; ii <= n; ii++) {
			fact = fact * ii;
		}
		term = (power/fact);
		last_sum = sum;
		sum = sum + term;
		printf("term: %f sum: %f\n", term, sum);
		n = n + 1;
	}
	printf("the final output of the equation is %f\n", sum);
	double actual = 0;
	actual = exp(x);
	printf("the actual value of the equation is %f\n", actual);
	printf("the error is %f", (sum - actual));
}