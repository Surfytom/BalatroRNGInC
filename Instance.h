#ifndef INSTANCE_H
#define INSTANCE_H
#pragma once

#include <stdarg.h>

#include "HashMapLib/hashmap.h"
#include "randomutils.h"
#include "packs.h"
#include "debug.h"

typedef struct CharArray {
	char** array;
	int size;
} CharArray;

typedef struct Card {
	int suit;
	char rank;
	int effect;
	int bonus;
	int seal;
} Card;

typedef struct CardArray {
	Card** array;
	size_t size;
	int handSize;
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

typedef struct JokerModifiers {
	bool eternal;
	bool perishable;
	bool rental;
} JokerModifiers;

typedef struct Boss {
	int bossIndex;
	int timesUsed;
};

extern double BASERATES[7];
extern char* RATETYPES[7];
extern RateObject RATES[7];
extern char** BASE_DECK[52];
extern Card BASE_DECK_2[52];

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
	int deckType;
	//double* rates;
	//RateObject* rates;
} Instance;

char* CombineChars(int count, ...);

Instance* InstanceCreate(char* seed, size_t hashMapSize);
void InstanceDelete(Instance* ip);

void InstanceSetDeck(Instance* ip, int deckType);
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
void GetJokerModifiers(Instance* ip, JokerModifiers* modifiers, bool fromPack);
int GetStandardCardEdition(Instance* ip);
int GetStandardCardSeal(Instance* ip);
int GetStandardCardBonus(Instance* ip);
int GetVoucher(Instance* ip, bool fromTag);
int GetNextBoss(Instance* ip);
int GetNextTag(Instance* ip);

void ShuffleDeck(Instance* ip, char* shuffleSeed);
void GetNextHand(Instance* ip, Card** cards);

int UseAura(Instance* ip);
int UseSigil(Instance* ip);
int UseOuija(Instance* ip);
void UseEmporer(Instance* ip, int* cards);
void UseHighPriestess(Instance* ip, int* cards);
int UseJudgement(Instance* ip);
int UseSoul(Instance* ip);
int UseWraith(Instance* ip);

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

typedef enum DECKS {
	redDeck,
	blueDeck,
	yellowDeck,
	greenDeck,
	blackDeck,
	magicDeck,
	nebulaDeck,
	ghostDeck,
	abandonedDeck,
	checkeredDeck,
	zodiacDeck,
	paintedDeck,
	analglyphDeck,
	plasmaDeck,
	erraticDeck,
};

extern char** SUITS[4];

extern char** BASE_DECK[52];

#endif