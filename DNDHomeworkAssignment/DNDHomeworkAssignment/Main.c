#include <stdio.h>
#include <math.h>

int main(void) {
	int dexterity, charisma, strength, wisdom, intelligence, constitution;
	int str_mod, cha_mod, dex_mod, wis_mod, int_mod, con_mod;
	char ans;
	strength = roll_dice(1, 1, 1);

	do {
		strength = roll_dice(3, 6, 0);
		dexterity = roll_dice(3, 6, 0);
		constitution = roll_dice(3, 6, 0);
		intelligence = roll_dice(3, 6, 0);
		wisdom = roll_dice(3, 6, 0);
		charisma = roll_dice(3, 6, 0);

		str_mod = (strength - 10) / 2;
		dex_mod = (dexterity - 10) / 2;
		con_mod = (constitution - 10) / 2;
		int_mod = (intelligence - 10) / 2;
		wis_mod = (wisdom - 10) / 2;
		cha_mod = (charisma - 10) / 2;

		printf("Strength: %d (%d)\n", strength, str_mod);
		printf("Dexterity: %d (%d)\n", dexterity, dex_mod);
		printf("Constitution: %d (%d)\n", constitution, con_mod);
		printf("Intelligence: %d (%d)\n", intelligence, int_mod);
		printf("Wisdon: %d (%d)\n", wisdom, wis_mod);
		printf("Charisma: %d (%d)\n", charisma, cha_mod);

		printf("would you like to keep this character? (y/n)\n");
		do {
			scanf_s("%c", &ans);
		} while ((ans != 'y') && (ans != 'n'));
	} while (ans != 'y');


}

int random_number(int seed) {
	int const MULTIPLIER = 40;
	int const BIAS = 3641;
	int const MODULOUS = 729;

	seed = (MULTIPLIER * seed + BIAS) % MODULOUS;
	return seed;
}

int die_roll(int num_sides, int init_seed) {
	int static seed;
	int roll;

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

int roll_dice(int num_dice, int num_sides, int init_flag) {
	int const INIT_SEED = 427;
	int roll;
	int sum;

	if (init_flag != 0) {
		roll = die_roll(num_sides, INIT_SEED);
	}
	sum = 0;
	for (int ii = 1; ii <= num_dice; ii++) {
		sum += die_roll(num_sides, -1);
	}
	return sum;
}

