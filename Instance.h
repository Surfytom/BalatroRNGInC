#ifndef INSTANCE_H
#define INSTANCE_H
#pragma once

#include <stdarg.h>
#include "HashMapLib/hashmap.h"
#include "randomutils.h"
#include "packs.h"

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

typedef struct RateObject {
	double rate;
	char* type;
	int typeStart;
	int typeEnd;
} RateObject;

typedef struct RatesObject {
	double editionRate;
	double jokerRate;
	double tarotRate;
	double planetRate;
	double spectralRate;
	double playingCardRate;
} RatesObject;

extern double BASERATES[7];
extern char* RATETYPES[7];
extern RateObject RATES[7];
extern char** BASE_DECK[52];

enum RATESINDEX {
	JOKERRATE,
	TAROTRATE,
	PLANETRATE,
	PLAYINGCARDRATE,
	SPECTRALRATE,
	EDITIONRATE,
	TOTALRATE,
};

typedef struct Instance {
	hashmap* NodeMap;
	CardArray* deck;
	char* seed;
	double hashedSeed;
	char* ante;
	bool* locked;
	bool firstPack;
	//double* rates;
	//RateObject* rates;
} Instance;

char* CombineChars(int count, ...);

Instance* InstanceCreate(char* seed, size_t hashMapSize);
void InstanceDelete(Instance* ip);

void SetAnte(Instance* ip, int ante);

entry* NodeIDGet(Instance* ip, char* id);
bool NodeIDInsert(Instance* ip, char* id, double value);
bool NodeIDRemove(Instance* ip, char* id);
double NodeIDRandom(Instance* ip, char* id);

uint64_t RandomChoice(Instance* ip, char* id, uint64_t min, uint64_t max);
int GetRandomPack(Instance* ip);
char* GetPool(Instance* ip, char* type, int typeStart, int typeEnd, int rarity, char* keyAppend, uint64_t* poolArray);
uint64_t CreateCard(Instance* ip, char* type, int typeStart, int typeEnd, int rarity, char* forcedKey, char* keyAppend);
void GetCardsFromPack(Instance* ip, int* cards, int packIdx);
int GetCardForShop(Instance* ip);
void GetCardsForShop(Instance* ip, int* cards, int shopSize);

int GetJokerEdition(Instance* ip, char* keyAppend);
int GetStandardCardEdition(Instance* ip);
int GetStandardCardSeal(Instance* ip);
int GetStandardCardBonus(Instance* ip);
int GetVoucher(Instance* ip, bool fromTag);

char* GetPackTypeForRates(int n);
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
/*
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
*/

extern char** SUITS[4];

extern char** BASE_DECK[52];

#endif