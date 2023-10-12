#include <stdio.h>
#include <math.h>

int main(void) {
	float a = 1.0;
	float b = 3000.001;
	float c = 3.0;
	float discrimFloat = 0.0;
	float r1FloatOriginal = 0.0;
	float r2FloatOriginal = 0.0;
	float r1FloatReformulated = 0.0;
	float r2FloatReformulated = 0.0;
	double aa = 1.0;
	double bb = 3000.001;
	double cc = 3.0;
	double discrim = 0.0;
	double r1DoubleOriginal = 0.0;
	double r2DoubleOriginal = 0.0;
	double r1DoubleReformulated = 0.0;
	double r2DoubleReformulated = 0.0;

	discrim = pow(bb, 2) - (4 * aa * cc);
	discrim = sqrt(discrim);

	discrimFloat = pow(b, 2) - (4 * a * c);
	discrimFloat = sqrt(discrimFloat);

	r1DoubleOriginal = (discrim - bb) / (2 * aa);
	r2DoubleOriginal = -(discrim + bb) / (2 * aa);
	r1DoubleReformulated = -(2 * cc) / (discrim + bb);
	r2DoubleReformulated = (2 * cc) / (discrim - bb);

	r1FloatOriginal = (discrimFloat - b) / (2 * a);
	r2FloatOriginal = -(discrimFloat + b) / (2 * a);
	r1FloatReformulated = -(2 * c) / (discrimFloat + b);
	r2FloatReformulated = (2 * c) / (discrimFloat - b);


	printf("r1DoubleOriginal: %32.32f\n	Absolute Error: %32.32f\n Relative Error: %32.32f\n", r1DoubleOriginal, r1DoubleOriginal-(-0.001), (r1DoubleOriginal - (-0.001))/(-0.001));
	printf("r2DoubleOriginal: %32.32f\n	Absolute Error: %32.32f\n Relative Error: %32.32f\n", r2DoubleOriginal, r2DoubleOriginal - (-3000.0), (r2DoubleOriginal - (-3000.0)) / (-3000.0));
	printf("r1DoubleReformulated: %32.32f\n Absolute Error: %32.32f\n Relative Error: %32.32f\n", r1DoubleReformulated, r1DoubleReformulated - (-0.001), (r1DoubleReformulated - (-0.001)) / (-0.001));
	printf("r2DoubleReformulated: %32.32f\n	Absolute Error: %32.32f\n Relative Error: %32.32f\n", r2DoubleReformulated, r2DoubleReformulated - (-3000.0), (r2DoubleReformulated - (-3000.0)) / (-3000.0));
	printf("r1FloatOriginal: %32.32f\n Absolute Error: %32.32f\n Relative Error: %32.32f\n", r1FloatOriginal, r1FloatOriginal - (-0.001), (r1FloatOriginal - (-0.001)) / (-0.001));
	printf("r2FloatOriginal: %32.32f\n Absolute Error: %32.32f\n Relative Error: %32.32f\n", r2FloatOriginal, r2FloatOriginal - (-3000.0), (r2FloatOriginal - (-3000.0)) / (-3000.0));
	printf("r1FloatReformulated: %32.32f\n Absolute Error: %32.32f\n Relative Error: %32.32f\n", r1FloatReformulated, r1FloatReformulated - (-0.001), (r1FloatReformulated - (-0.001)) / (-0.001));
	printf("r2FloatReformulated: %32.32f\n Absolute Error: %32.32f\n Relative Error: %32.32f\n", r2FloatReformulated, r2FloatReformulated - (-3000.0), (r2FloatReformulated - (-3000.0)) / (-3000.0));
}