#ifndef INSTANCE_H
#define INSTANCE_H
#pragma once

#include <stdarg.h>
#include "HashMapLib/hashmap.h"
#include "randomutils.h"

typedef struct CharArray {
	char** array;
	int size;
} CharArray;

typedef struct Card {
	int suit;
	int rank;
	int effect;
	int bonus;
	int seal;
} Card;

typedef struct CardArray {
	Card** array;
	size_t size;
} CardArray;

typedef struct Instance {
	hashmap* NodeMap;
	CardArray* deck;
	char* seed;
	double hashedSeed;
	char ante;
} Instance;

char* CombineChars(int count, ...);

Instance* InstanceCreate(char* seed);
void InstanceDelete(Instance* ip);

entry* NodeIDGet(Instance* ip, char* id);
bool NodeIDInsert(Instance* ip, char* id, double value);
bool NodeIDRemove(Instance* ip, char* id);
double NodeIDRandom(Instance* ip, char* id, char* seed, double hashedseed);

char* GetSeal(int n);

typedef enum SUITS {
	Spades,
	Hearts,
	Clubs,
	Diamonds
};

typedef enum RANKS {
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
};

typedef enum BONUSES {
	chips,
	multiplyBonus,
	goldBonus,
	steel
};

typedef enum EFFECTS {
	multiplyEffect,
	polychrome,
	foil
};

typedef enum SEALS {
	goldSeal,
	red,
	blue
};


extern char** SUITS[4];

extern char** BASE_DECK[52];

#endif