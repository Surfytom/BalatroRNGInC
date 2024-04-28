#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <crtdbg.h>

#include "instance.h"

const size_t HASHMAPSIZE = 100;

/*
for comparing ante as an int
if (ante[0] - '0' == 1) {
	printf("\nITS TRUE");
}
*/

// TODO: check if spectral packs work when getting cards from them
// Same with planet packs
// Seed searcher
// Boss blind ability randomisation

// Done:
// joker packs edition generation - done
// standard packs edition seal bonus and card generation - done
// Create function to generate shop cards - Done
// Implement enhanced and base card generation - done
// Implement joker edition generation - might be done
// Implement vouchers
//	Vouchers pool : check if voucher needs another vouchar to be picked

// Ideas
// - Cards are a struct with certain attributes such as the soul
// - You can then call a function to use these cards to see what they will reveal
int main() {
	
	char* testKey = "ABC";

	Instance* ip = InstanceCreate(testKey, HASHMAPSIZE);

	int voucher = 0;

	uint64_t cards[1] = { 0 };

	for (int i = 0; i < CONSUMABLEEND; i++) {
		printf("\n[%d] Bool Value: %s", i, ip->locked[i] ? "True" : "False");
	}

	voucher = GetVoucher(ip, false);

	printf("\nVoucher index: %d", voucher);


	/*
	uint64_t cards[5] = {0, 0, 0, 0, 0};

	int edition = 0;
	int seal = 0;
	uint64_t bonus = 0;

	for (int i = 0; i < 2; i++) {
		randomPackIndex = GetRandomPack(ip);

		GetCardsFromPack(ip, cards, randomPackIndex);

		printf("\nPACK %s", PACKS[randomPackIndex].type);
		for (int j = 0; j < PACKS[randomPackIndex].size; j++) {
			if (cards[i] > DECKSTART && cards[i] < DECKEND) {
				edition = GetStandardCardEdition(ip);
				seal = GetStandardCardSeal(ip);
				bonus = GetStandardCardBonus(ip);
				printf("\nCard %d: ACTUAL CARD: %" PRIu64, j, cards[j]);
				printf("\nEdition: %d", edition);
				printf("\nSeal: %d", seal);
				printf("\nBonus: %" PRIu64, bonus);
			}
			else {
				printf("\nCard %d: %" PRIu64, j, cards[j]);
			}
		}
		printf("\n");
	}
	*/
	/*
	uint64_t* cards[5] = { 0, 0, 0, 0, 0 };

	GetCardsForShop(ip, cards, 2);
	int edition = -1;
	for (int i = 0; i < 4; i++) {
		if (cards[i] > JOKER1START && cards[i] < JOKER4END) {
			edition = GetJokerEdition(ip, "buf");
		}
		if (cards[i] > DECKSTART && cards[i] < DECKEND) {
			printf("\nCard %d: edition: %d ACTUAL CARD: %s" , i, edition, BASE_DECK[(int)cards[i]]);
		}
		else {
			printf("\nCard %d: edition: %d: %" PRIu64, i, edition, cards[i]);
		}
	}
	*/
	InstanceDelete(ip);
	
	/*
	char* c = NULL;
	int randomPackIndex = 0;

	uint64_t card = 0;
	uint64_t* cards = malloc(sizeof(uint64_t) * 5);

	for (int i = 0; i < 2; i++) {
		randomPackIndex = GetRandomPack(ip);

		GetCardsFromPack(ip, cards, randomPackIndex);

		printf("\nPACK %s", PACKS[randomPackIndex].type);
		for (int j = 0; j < PACKS[randomPackIndex].size; j++) {
			printf("\nCard %d: %" PRIu64, j, cards[j]);
		}
		printf("\n");
	}

	free(cards);
	*/

	/*
	for (int j = 0; j < 2; j++) {

		randomPackIndex = GetRandomPack(ip);

		for (int i = 0; i < PACKS[randomPackIndex].size; i++) {

			card = CreateCard(ip, PACKS[randomPackIndex].type, PACKS[randomPackIndex].start, PACKS[randomPackIndex].end, 0, NULL, PACKS[randomPackIndex].key);
			
			int resample = 1;
			bool foundUniqueCard = false;
			while (!foundUniqueCard) {
				bool inCards = false;
				for (int t = 0; t < i; t++) {
					if (card == cards[t]) {
						inCards = true;
					}
				}

				if (inCards) {

					char* resampleIt = malloc(sizeof(char) * 2);
					resampleIt[0] = (resample % 10) + '0';
					resampleIt[1] = '\0';

					char* re = "_resample";
					char* resampleChar = CombineChars(4, PACKS[randomPackIndex].key, re, resampleIt, ip->seed);

					card = CreateCard(ip, PACKS[randomPackIndex].type, PACKS[randomPackIndex].start, PACKS[randomPackIndex].end, 0, NULL, resampleChar);

					resample++;

					free(resampleIt);
					free(resampleChar);
				}
				else {
					foundUniqueCard = true;
				}
			}

			cards[i] = card;

			c = GetPack(randomPackIndex);

			printf("\nPack: %s card: %" PRIu64, c, PACKS[randomPackIndex].start + card);
			printf(" start: %d end : %d", PACKS[randomPackIndex].start, PACKS[randomPackIndex].end);

			free(c);
		}

		printf("\n");
	}*/
	
	/*
	size_t size = 2;
	
	hashmap* hmp = HashMapCreate(size);

	char* testKey = "hello";
	char* testKey1 = "qweqwe";
	char* testKey2 = "zxcaca";
	char* testKey4 = "zxcacaaa";
	char* testKey5 = "zxcacaa";
	char* testKey3 = "qwjqiwej";

	HashMapInsert(hmp, testKey, 0.55);

	HashMapPrint(hmp);

	HashMapInsert(hmp, testKey1, 0.55);
	HashMapInsert(hmp, testKey4, 0.55);
	HashMapInsert(hmp, testKey5, 0.55);

	HashMapPrint(hmp);

	HashMapInsert(hmp, testKey2, 0.55);

	HashMapPrint(hmp);

	HashMapInsert(hmp, testKey3, 0.55);

	HashMapRemove(hmp, testKey);

	HashMapDelete(hmp);
	*/
	/*
	size_t size = 10;

	char* testKey = "hello";

	hashmap* hmp = HashMapCreate(size);

	printf("\nHashMap size: %zu", hmp->size);

	bool isInserted = HashMapInsert(hmp, testKey, 0.55);

	printf("\nInserted: %s", isInserted ? "true" : "false");

	HashMapGet(hmp, testKey);

	isInserted = HashMapInsert(hmp, testKey, 0.55);

	printf("\nInserted: %s", isInserted ? "true" : "false");

	entry* e = HashMapGet(hmp, testKey);

	printf("\nKey: %s | Value: %0.10f", e->key, *e->value);

	HashMapPrint(hmp);

	char* tmpChar = malloc(strlen(testKey) + 1);
	strcpy_s(tmpChar, 6, testKey);

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < strlen(tmpChar); j++) {
			tmpChar[j] += 1;
		}
		isInserted = HashMapInsert(hmp, tmpChar, 0.7);
		printf("\nInserted: %s", isInserted ? "true" : "false");
	}

	free(tmpChar);

	HashMapPrint(hmp);

	testKey = "khoor";

	e = HashMapGet(hmp, testKey);

	printf("\nKey: %s | Value: %0.10f", e->key, *e->value);

	HashMapDelete(hmp);
	*/
	_CrtDumpMemoryLeaks();
	

	// Get first pack

	/*
	char seed[4] = "ABC\0";

	double hashedSeed = PseudoHashChar(seed);

	double rngState = 0.0;

	int num = -1;

	int pack = 0;

	char* packName = NULL;
	
	for (int i = 0; i < 10; i++) {

		printf("\nPack Index: %d", i+1);
		pack = GetRandomPack(seed, 1, &rngState, num, hashedSeed);

		packName = GetPack(pack);

		printf("\nPack: %-20s\n", packName);

		num += 1;
	}

	free(packName);
	packName = NULL;
	*/

	/*
	int BASE_DECKSize = (int)(sizeof(BASE_DECK) / sizeof(BASE_DECK[0]));

	char seed[4] = "ABC\0";
	char nodeSeed[8] = "erratic\0";

	double hashedSeed = PseudoHashChar(seed);
	//double hashedNode = NodeID(nodeSeed, seed, hashedSeed);

	char outputArray[53][4];

	printf("\nsize: %d size2: %d", (int)sizeof(BASE_DECK[0]), (int)(BASE_DECKSize * sizeof(char*)));

	for (int i = 1; i < 53; i++){
		printf("\nDECK CARD %d: %s", i, BASE_DECK[i]);
		strcpy_s(outputArray[i], 4, BASE_DECK[i]);
	}

	BubbleSort(outputArray);

	
	for (int i = 0; i < BASE_DECKSize; i++) {
		printf("\nSORTED DECK %d: %s", i, outputArray[i]);
	}
	

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
	}*/


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
/*

Card array dynamic allocation

struct CardArray* arr = malloc(sizeof(CardArray));

int64_t* state = RandomStateFromSeed(0.9);

int deckSize = 52;

if (arr == NULL) {
	return 1;
}

arr->size = calloc(1, sizeof(size_t));

if (arr->size == NULL) {
	return 1;
}

arr->array = malloc(deckSize * sizeof(Card));

if (arr->array == NULL) {
	return 1;
}

for (int i = 0; i < deckSize; i++) {

	arr->array[i] = malloc(sizeof(Card));

	if (arr->array[i] == NULL) {
		return 1;
	}

	arr->array[i]->seal = (int)RandomInt(state, 0, 2);
	arr->array[i]->bonus = (int)RandomInt(state, 0, 3);
	arr->array[i]->effect = (int)RandomInt(state, 0, 2);
	arr->array[i]->rank = (int)RandomInt(state, 0, 12);
	arr->array[i]->suit = (int)RandomInt(state, 0, 3);
}

char* suit = NULL;
char* rank = NULL;
char* seal = NULL;
char* effect = NULL;
char* bonus = NULL;

for (int i = 0; i < deckSize; i++) {

	suit = GetSuit(arr->array[i]->suit);
	rank = GetRank(arr->array[i]->rank);
	seal = GetSeal(arr->array[i]->seal);
	effect = GetEffect(arr->array[i]->effect);
	bonus = GetBonus(arr->array[i]->bonus);

	if (suit == NULL) {
		return 1;
	}

	printf("\n[  card %-3d ]", i);
	printf(" Suit: %-8s |", suit);
	printf(" Rank: %-6s |", rank);
	printf(" Bonus: %-8s |", bonus);
	printf(" Effect: %-10s |", effect);
	printf(" Seal: %-6s", seal);
}

free(suit);
suit = NULL;

free(rank);
rank = NULL;

free(seal);
seal = NULL;

free(effect);
effect = NULL;

free(bonus);
bonus = NULL;

for (int i = 0; i < deckSize; i++) {
	free(arr->array[i]);
	arr->array[i] = NULL;
}

free(arr->array);
arr->array = NULL;

free(arr->size);
arr->size = NULL;

free(arr);
arr = NULL;

free(state);
state = NULL;
*/