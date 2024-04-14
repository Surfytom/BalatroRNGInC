#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include "Instance.h"

typedef union DoubleLong {
	double d;
	uint64_t ul;
} dbllong;

typedef struct LuaRandom {
	uint64_t state[4];
	dbllong out;
} lrandom;

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

	uint64_t state[4] = {0, 0, 0, 0};

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

double NodeID(char* id, char* seed, double* num, double hashedSeed) {

	if (*num < 0.0){
		size_t bufferSize = sizeof(char) * (strlen(id) + strlen(seed) + 1);
		char* combineChar = malloc(bufferSize);

		strcpy_s(combineChar, bufferSize, id);
		strcat_s(combineChar, bufferSize, seed);

		*num = PseudoHashChar(combineChar);

		free(combineChar);
		combineChar = NULL;
	}

	// num needs to be saved as somehow
	*num = RoundDigits(fract(*num * 1.72431234 + 2.134453429141), 13);

	printf("\nnum: %0.25f", *num);

	return (*num + hashedSeed) / 2;
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

uint64_t RandomChoice(char* ID, char* seed, double* num, double hashedSeed, uint64_t min, uint64_t max) {
	int64_t* state = RandomStateFromSeed(NodeID(ID, seed, num, hashedSeed));

	return RandomInt(state, min, max);
}

int main() {

	int BASE_DECKSize = (int)(sizeof(BASE_DECK) / sizeof(BASE_DECK[0]));

	char seed[9] = "7LB2WVPK\0";
	char nodeSeed[8] = "erratic\0";

	double hashedSeed = PseudoHashChar(seed);
	//double hashedNode = NodeID(nodeSeed, seed, hashedSeed);

	char outputArray[52][4];

	printf("\nsize: %d size2: %d", (int)sizeof(BASE_DECK[0]), (int)(BASE_DECKSize * sizeof(char*)));

	for (int i = 0; i < BASE_DECKSize; i++){
		printf("\nDECK CARD %d: %s", i, BASE_DECK[i]);
		strcpy_s(outputArray[i], 4, BASE_DECK[i]);
	}

	BubbleSort(outputArray);

	/*
	for (int i = 0; i < BASE_DECKSize; i++) {
		printf("\nSORTED DECK %d: %s", i, outputArray[i]);
	}
	*/

	char finalDeck[52][4];
	
	double num = -1.0;

	int randomInt;
	for (int i = 0; i < 52; i++) {
		randomInt = RandomChoice(nodeSeed, seed, &num, hashedSeed, 1, 52);
		printf("\nRandom int choice: %" PRIu64, randomInt);
		strcpy_s(finalDeck[i], 4, outputArray[randomInt-1]);
	}

	for (int i = 0; i < 52; i++) {
		printf("\nFINAL DECK CARD %d: %s", i, finalDeck[i]);
	}

	//testing github

	/*
	double nodeID = 0.47327633048185414;
	
	int64_t* s = RandomStateFromSeed(nodeID);
	
	for (int i = 0; i < 4; i++) {
		printf("\nState element {%d}: %" PRIu64, i, s[i]);
	}

	dbllong r = RandomFloat(s);

	printf("\nRandomFloat return: %" PRIu64, r.ul);

	dbllong d = RandomDouble(s);

	printf("\nRandomDouble return: %0.25f", d.d);

	uint64_t a;

	for (int i = 0; i < 10; i++) {
		a = RandomInt(s, 1, 10);
		printf("\nRandomInt return {%d}: %" PRIu64, i, a);
	}

	char c[9] = "IMMOLATE\0";

	double num = PseudoHashChar(c);

	printf("\nSeed Starting double: %0.25f", num);

	char nodeid[8] = "erratic\0";

	double id = NodeID(nodeid, c, num);

	printf("\nnode id output: %0.25f", id);
	*/

	return 0;
}