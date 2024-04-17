#include "randomutils.h"
#include "packs.h"

void RandomizeStateStep(uint64_t* rs, uint64_t* z, dbllong* r, int i, int k, int q, int s) {
	*z = rs[i];

	uint64_t x1 = *z << q;
	uint64_t x2 = x1 ^ *z;
	uint64_t x3 = x2 >> (k - s);
	uint64_t x4 = (uint64_t)(int64_t)-1 << (64 - k);
	uint64_t x5 = *z & x4;
	uint64_t x6 = x5 << s;
	uint64_t x7 = x3 ^ x6;

	r->ul ^= x7;
	rs[i] = x7;

	*z = x7;

	//for (int i = 0; i < 4; i++) {
	//	printf("\nStep State element {%d}: %" PRIu64, i, rs[i]);
	//}
	//printf("\n");
}

//void RandomizeStateStep(uint64_t* rs, uint64_t* z, uint64_t* r, int i, int k, int q, int s) {
//	*z = rs[i];
//	*z = (((*z << q) ^ *z) >> (k - s)) ^ ((*z & ((uint64_t)(int64_t)-1 << (64 - k))) << s);
//	*r ^= *z;
//	rs[i] = *z;
//
//	for (int i = 0; i < 4; i++) {
//		printf("\nStep State element {%d}: %" PRIu64, i, rs[i]);
//	}
//	printf("\n");
//}

dbllong RandomizeState(uint64_t* rs) {

	uint64_t z = 0;
	dbllong r;
	r.ul = 0;
	r.d = 0.0;

	RandomizeStateStep(rs, &z, &r, 0, 63, 31, 18);
	RandomizeStateStep(rs, &z, &r, 1, 58, 19, 28);
	RandomizeStateStep(rs, &z, &r, 2, 55, 24, 7);
	RandomizeStateStep(rs, &z, &r, 3, 47, 21, 8);

	return r;
}

uint64_t* RandomStateFromSeed(double seed) {
	double d = seed;
	uint32_t r = 0x11090601;

	uint64_t* state = malloc(sizeof(uint64_t) * 4);

	if (state == NULL) {
		return NULL;
	}

	uint64_t u = 0;

	int i;
	for (i = 0; i < 4; i++) {
		uint32_t m = 1u << (r & 255u);

		dbllong u;
		u.ul = 0;
		u.d = 0.0;

		r = r >> 8u;

		d *= 3.14159265358979323846;
		d += 2.7182818284590452354;

		//printf("\nd: %0.25f", d);

		u.d = d;

		if (u.ul < m) u.ul += m;

		//printf("\nu: %" PRIu64, u.ul);

		state[i] = u.ul;
	}

	//for (i = 0; i < 4; i++) {
		//printf("\nStart State element {%d}: %" PRIu64, i, state[i]);
	//}

	//printf("\n");

	for (i = 0; i < 10; i++) {
		RandomizeState(state);
	}

	return state;
}

dbllong RandomFloat(uint64_t* rs) {

	dbllong r = RandomizeState(rs);

	r.ul = (r.ul & 4503599627370495) | 4607182418800017408;

	return r;
}

dbllong RandomDouble(uint64_t* rs) {

	dbllong r = RandomFloat(rs);

	r.d = r.d - 1.0;

	return r;
}

uint64_t RandomInt(uint64_t* rs, uint64_t min, uint64_t max) {

	dbllong r = RandomDouble(rs);

	return (uint64_t)(r.d * (max - min + 1)) + min;
}

double fract(double f) {
	return f - floor(f);
}

double PseudoHashChar(char* c) {
	double num = 1.0;

	int k = 32;

	for (int i = (strlen(c) - 1); i >= 0; i--) {
		//printf("\nchar at {%d}: %c", i, c[i]);

		int64_t intPart = (1.1239285023 / num * c[i] * 3.141592653589793116 + 3.141592653589793116 * (i + 1)) * (1 << k);
		double fract_part = fract(fract((1.1239285023 / num * c[i] * 3.141592653589793116) * (1 << k)) + fract((3.141592653589793116 * (i + 1)) * (1 << k)));
		num = fract(((double)(intPart)+fract_part) / (1 << k));
	}
	//printf("\nNum: %0.25f", num);
	return num;
}

double RoundDigits(double f, int d) {
	// Remember this rounds but not actually as there are sometimes trailing numbers (might be accurate enough for task)
	double power = pow(10, d);
	return round(f * power) / power;
}

void BubbleSort(char inputArray[52][4]) {

	char sorted = 0;

	char tempChar[4];

	int i;
	int j;
	for (i = 0; i < 52 - 1; i++) {
		printf("\nInput Array Element %d: %s", i, inputArray[i]);
		for (j = 0; j < 52 - 1 - i; j++) {

			if (strcmp(inputArray[j], inputArray[j + 1]) > 0) {
				strcpy_s(tempChar, 4, inputArray[j]);
				strcpy_s(inputArray[j], 4, inputArray[j + 1]);
				strcpy_s(inputArray[j + 1], 4, tempChar);
			}
		}
	}
}
/*
uint64_t RandomChoice(char* ID, char* seed, double* rngstate, double hashedSeed, uint64_t min, uint64_t max) {
	int64_t* state = RandomStateFromSeed(NodeID(ID, seed, rngstate, hashedSeed));

	return RandomInt(state, min, max);
}

int GetRandomPack(char* seed, int ante, double* rngState, int num, double hashedSeed) {
	char packSeed[10] = "shop_pack";

	double cume = 0.0;
	double it = 0.0;
	int center = 0;

	int i;
	for (i = 1; i < NUMOFPACKS; i++) {
		cume += PACKS[i].weight;
	}

	size_t bufferSize = sizeof(char) * (2 + strlen(packSeed) + 1);
	char* combineChar = malloc(bufferSize);

	//strcpy_s(combineChar, bufferSize, packSeed);
	//strcat_s(combineChar, bufferSize, ante);
	//strcat_s(combineChar, bufferSize, seed);

	snprintf(combineChar, bufferSize, "%s%d", packSeed, ante);

	//printf("\ncombinechar: %s", combineChar);

	int64_t* state = RandomStateFromSeed(NodeID(combineChar, seed, rngState, hashedSeed));

	free(combineChar);
	combineChar = NULL;

	dbllong poll = RandomDouble(state);
	poll.d *= cume;

	printf("\nDouble Returned: %0.10f", poll.d);

	int idx = 1;
	while (it < poll.d) {
		it += PACKS[idx].weight;
		idx++;
	}

	printf("\nit: %0.10f", it);

	return idx - 1;
}
*/