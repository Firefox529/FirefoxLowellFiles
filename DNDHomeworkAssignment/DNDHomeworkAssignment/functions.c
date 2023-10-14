#include <stdio.h>
#include <math.h>

int random_number(seed) {
	const MULTIPLIER = 40;
	const BIAS = 3641;
	const MODULOUS = 729;

	seed = (MULTIPLIER * seed + BIAS) % MODULOUS;
	return seed;
}

int die_roll(num_sides, init_seed) {
	int roll;
	static seed;

	if ((init_seed >= 0) && (init_seed < 729)) {
		seed = init_seed;
		roll = 0;
	}
	else {
		seed = random_number(seed);

		roll = (1 + (seed % num_sides));
	}
	return roll;
}

int roll_dice(num_dice, num_sides, init_flag) {
	const INIT_SEED = 696;
	int roll;
	int sum = 0;

	if (init_flag) {
		roll = roll_dice(num_sides, INIT_SEED);
	}

	for (int ii = 1; ii <= num_dice, ii++;) {
		sum += die_roll(num_sides);
	}

	return sum;
}