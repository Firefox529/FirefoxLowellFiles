#include <stdio.h>
#include <math.h>

int main(void) {
	int dexterity, charisma, strength, wisdom, intelligence, constitution;
	int str_mod, cha_mod, dex_mod, wis_mod, int_mod, con_mod;
	char ans='n';
	roll_dice(1, 1, 1);

	while (ans != 'y') {
		strength = roll_dice(3, 6);
		dexterity = roll_dice(3, 6);
		constitution = roll_dice(3, 6);
		intelligence = roll_dice(3, 6);
		wisdom = roll_dice(3, 6);
		charisma = roll_dice(3, 6);

		str_mod = (strength - 10) / 2;
		dex_mod = (dexterity - 10) / 2;
		con_mod = (constitution - 10) / 2;
		int_mod = (intelligence - 10) / 2;
		wis_mod = (wisdom - 10) / 2;
		cha_mod = (charisma - 10) / 2;

		printf("Strength: %d (%d)\n", strength, str_mod);
		printf("Dexterity: %d (%d)\n", dexterity, dex_mod);
		printf("Constitution: %d (%d)\n", constitution, str_mod);
		printf("Intelligence: %d (%d)\n", intelligence, int_mod);
		printf("Wisdon: %d (%d)\n", wisdom, wis_mod);
		printf("Charisma: %d (%d)\n", charisma, cha_mod);

		printf("would you like to keep this character? (y/n)\n");
		scanf_s("%c", &ans);
	}


}

int random_number(seed) {
	const MULTIPLIER = 40;
	const BIAS = 3641;
	const MODULOUS = 729;

	seed = (MULTIPLIER * seed + BIAS) % MODULOUS;
	return seed;
}

int die_roll(num_sides, init_seed) {
	static seed;
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
	printf("roll: %d\n", roll);
}

int roll_dice(num_dice, num_sides, init_flag) {
	const INIT_SEED = 696;
	int roll;
	int sum;

	if (init_flag != 0) {
		roll = die_roll(num_sides, INIT_SEED);
	}
	sum = 0;
	for (int ii = 1; ii <= num_dice; ii++) {
		sum += die_roll(num_sides);
	}

	return sum;
}