#ifndef RANDOMUTILS_H
#define RANDOMUTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

#include "debug.h"

typedef union DoubleLong {
	double d;
	uint64_t ul;
} dbllong;

typedef struct LuaRandom {
	uint64_t state[4];
	dbllong out;
} lrandom;

void PrintBits(uint64_t number);
void RandomizeStateStep(uint64_t* rs, uint64_t* z, dbllong* r, int i, int k, int q, int s);
dbllong RandomizeState(uint64_t* rs);
uint64_t* RandomStateFromSeed(double seed);
dbllong RandomFloat(uint64_t* rs);
dbllong RandomDouble(uint64_t* rs);
uint64_t RandomInt(uint64_t* rs, uint64_t min, uint64_t max);
double fract(double f);
double PseudoHashChar(char* c);
double RoundDigits(double f, int d);
double RoundNFloorDigits(double f, int d);
//double NodeID(char* id, char* seed, double* rngstate, double hashedSeed);
void BubbleSort(char inputArray[52][4]);
//uint64_t RandomChoice(char* ID, char* seed, double* rngstate, double hashedSeed, uint64_t min, uint64_t max);
//int GetRandomPack(char* seed, int ante, double* rngState, int num, double hashedSeed);

#endif