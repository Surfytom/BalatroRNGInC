#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <crtdbg.h>
#include <time.h>
#include <windows.h>

#include "instance.h"
#include "searcher.h"
#include "filters.h"
#include "VectorLib/vector.h"
#include "debug.h"

const size_t HASHMAPSIZE = 100;

void RunTests(char* fileName);

/*
for comparing ante as an int
if (ante[0] - '0' == 1) {
	printf("\nITS TRUE");
}
*/

// TODO: 
// check if planet packs work
// using tags
// using spectral cards
// Write test cases to quickly test if all the functions are working as expected | done 1 need more

// Done:
// joker packs edition generation - done
// standard packs edition seal bonus and card generation - done
// Create function to generate shop cards - Done
// Implement enhanced and base card generation - done
// Implement joker edition generation - might be done
// Implement vouchers
// Vouchers pool : check if voucher needs another vouchar to be picked
// check if spectral packs work when getting cards from them
// Seed searcher - generate all seeds
// planet rate fixed now shows right in shop
// Boss blind ability randomisation
// tags generation for each blind
// using abilities that are random (judgment etc)

// Ideas
// - Cards are a struct with certain attributes such as the soul
// - You can then call a function to use these cards to see what they will reveal

uint64_t factorial(uint64_t x, int iterations) {

	uint64_t factorialOfX = 1;
	for (int i = x; i > iterations; i--) {
		factorialOfX *= i;
	}

	return factorialOfX;
}

uint64_t Permute(uint64_t total, uint64_t choose) {
	return factorial(total, (total - choose));
}

uint64_t Combine(uint64_t total, uint64_t choose) {

	// total! / (total - choose)!
	uint64_t first = factorial(total, (total - choose));

	// choose!
	uint64_t second = factorial(choose, 0);

	// total! / (choose! * ((total - choose)!))
	return first / second;
}

typedef struct Voucher1 {
	char voucher[11];
}Voucher1;

int main() {

	int noOfNums = 10;
	int noOfVouchers = 100000;
	uint64_t* state = RandomStateFromSeed(1.0);

	Voucher1* vouchers = malloc(noOfVouchers * sizeof(Voucher1));
	Voucher1* tempVoucher = malloc(1 * sizeof(Voucher1));

	clock_t start = clock();

	uint64_t lowerOrUpper = 0;

	for (int i = 0; i < noOfVouchers; i++) {
		for (int j = 0; j < noOfNums; j++) {

			lowerOrUpper = RandomInt(state, 0, 1);

			if (lowerOrUpper == 0) {
				tempVoucher->voucher[j] = (char)RandomInt(state, 97, 122);
			} else {
				tempVoucher->voucher[j] = (char)RandomInt(state, 65, 90);
			}
		}

		tempVoucher->voucher[noOfNums] = '\0';
		
		vouchers[i] = *(tempVoucher);

		if (i % 10000 == 0) {
			printf("Created %d vouchers in %d ms\n", i, (int)((clock() - start) * 1000 / CLOCKS_PER_SEC));
			printf("Voucher %d: %s\n", i, vouchers[i].voucher);
		}
	}

	printf("Created %d vouchers in %d ms\n", noOfVouchers, (int)((clock() - start) * 1000 / CLOCKS_PER_SEC));

	free(tempVoucher);
	free(vouchers);
	free(state);

	/*
	Vector* vec = VectorCreate(sizeof(int), 10);

	int a = 10;
	int b = 20;
	int c = 30;

	VectorAdd(vec, &a);
	VectorAdd(vec, &b);
	VectorAdd(vec, &c);

	printf("Vector size: %d\n", (int)vec->size);
	for (int i = 0; i < vec->size; i++) {
		printf("Element at index %d: %d\n", i, *(int*)VectorGet(vec, i));
	}

	VectorRemove(vec, 1);
	printf("Vector size: %d\n", (int)vec->size);

	for (int i = 0; i < vec->size; i++) {
		printf("Element at index %d: %d\n", i, *(int*)VectorGet(vec, i));
	}

	VectorDelete(vec);
	*/
	// Dont need all this probability stuff as you can just run the rng to find what cards could come next
	/*
	Instance* ip = InstanceCreate("A", HASHMAPSIZE);
	
	GetCards(ip);

	printf("Hand Size: %d\n", ip->deck->currentHandSize);
	for (int i = 0; i < ip->deck->currentHandSize; i++) {
		printf("\nCard %2d: suit ", i + 1);
		PrintItem(ip->deck->hand[i]->suit);
		printf(" | rank %c", ip->deck->hand[i]->rank);
	}

	InstanceDelete(ip);
	*/
	//char* seed = "B";
	// You have to keep track of what is discarded in each hand
	// Then append them to the back of the deck (index 0) before shuffling at the end of each round
	/*
	uint64_t deckSize = 52;
	uint64_t choose = 5;

	uint64_t fac52div5 = factorial(52, (deckSize - choose));

	printf("52!/5!: % " PRIu64 "\n", fac52div5);

	uint64_t second = factorial(choose, 0);

	printf("second: % " PRIu64 "\n", fac52div5);

	uint64_t facDeck = fac52div5 / second;

	printf("combinations of choosing 5 cards from deck: %" PRIu64 "\n", facDeck);

	double percent = 1.0 / facDeck;

	printf("percentage chance: %0.50f\n", percent);

	uint64_t a = 10;

	uint64_t fac10 = factorial(10, 0);
	uint64_t fac3 = factorial(3, 0);

	printf("Factorial of 10: %" PRIu64 "\n", fac10);
	printf("Factorial of 3: %" PRIu64 "\n", fac3);

	double chance = fac10 / fac3;

	printf("Factorial of 10/3: %0.5f\n", chance);

	uint64_t fac10div3 = factorial(10, 3);

	printf("Factorial of 10/3: %" PRIu64 "\n", fac10div3);

	printf("Factorial of 10!*7!: %" PRIu64 "\n", fac10div3 * factorial(7, 0));
	*/
	/*
	Instance* ip = InstanceCreate(seed, HASHMAPSIZE);

	ShuffleDeck(ip, "shuffle");
	//ShuffleDeck(ip, "nr");
	ShuffleDeck(ip, "cashout");

	printf("\n\nHAND DRAWN:");

	Card* cards[10];

	GetNextHand(ip, cards);

	for (int i = 0; i < 8; i++) {
		printf("\nCard %2d: suit ", i + 1);
		PrintItem(cards[i]->suit);
		printf(" | rank %c", cards[i]->rank);
	}

	ShuffleDeck(ip, "cashout");

	GetNextHand(ip, cards);

	printf("\n\nHAND DRAWN:");

	for (int i = 0; i < 8; i++) {
		printf("\nCard %2d: suit ", i + 1);
		PrintItem(cards[i]->suit);
		printf(" | rank %c", cards[i]->rank);
	}

	InstanceDelete(ip);

	//RunTests("testseedA.txt");
	*/
	// Dynamic function calling
	/*
	Instance* ip = InstanceCreate("ABC", HASHMAPSIZE);

	FuncWrapper func = CallFunction("filter");

	(*func)(ip, true, true, true, true);

	InstanceDelete(ip);
	*/
	/*
	char* seed = malloc(2);
	strcpy_s(seed, 2, "C");
	int seedTotal = 1;

	Instance* ip;

	FuncWrapper func = CallFunction("filter");

	clock_t startTime = clock();
	clock_t endTime;
	double totalTimeTaken = 0.0;

	do {

		if (seedTotal % 10000 == 0) {
			endTime = clock();
			printf("\nTime taken for seed %s: %0.25f", seed, (((double)(endTime - startTime)) / CLOCKS_PER_SEC) * 1000);
			totalTimeTaken += (((double)(endTime - startTime)) / CLOCKS_PER_SEC) * 1000;
			startTime = clock();
		}

		ip = InstanceCreate(seed, HASHMAPSIZE);

		(*func)(ip, false, false, false, false);

		InstanceDelete(ip);

		seedTotal++;

		NextSeed(&seed);

	} while (seedTotal <= 1000000);

	printf("\nAverage time taken per 10000 seeds: %0.10f", totalTimeTaken / (seedTotal / 10000));
	
	free(seed);
	
	/*
	Instance* ip = InstanceCreate("K8D23YF1", 100);

	int cards[5] = { 0 };

	GetCardsFromPack(ip, cards, Mega_Arcana_Pack);

	for (int i = 0; i < 5; i++) {
		printf("\nCard %d: %d", i + 1, cards[i]);
		cards[i] = 0;
	}

	printf("\nSoul card: %d", UseSoul(ip));

	InstanceDelete(ip);
	*/

	_CrtDumpMemoryLeaks();

	return 0;
}

void RunTests(char* fileName) {

	FILE* fp;
	errno_t err = fopen_s(&fp, fileName, "r");

	if (err != 0) {
		printf("\nFile could not be opened!!!");
		return NULL;
	}

	char line[50];
	int tempInt1 = 0;
	int tempInt2 = 0;
	int64_t cardsTruth[5] = { 0, 0, 0, 0, 0 };
	int64_t cardsPred[5] = { 0, 0, 0, 0, 0 };

	int shopCardTruth = 0;
	int shopCardPred = 0;

	int editionTruth = 0;
	int editionPred = 0;
	int sealTruth = 0;
	int sealPred = 0;
	int bonusTruth = 0;
	int bonusPred = 0;

	int voucherTruth = 0;
	int voucherPred = 0;

	char* tempPtr;

	// Grabs seed from file
	fgets(line, 50, fp);
	line[strcspn(line, "\n")] = 0;
	Instance* ip = InstanceCreate(line, HASHMAPSIZE);

	bool test = false;

	while (fgets(line, 50, fp)) {

		printf("\nLINE: %s", line);

		if (strcmp(line, "ante\n") == 0) {
			fgets(line, 50, fp);
			line[strcspn(line, "\n")] = 0;
			printf("\nANTE CHANGE FROM: %s TO: %s", ip->ante, line);
			strcpy_s(ip->ante, 2, line);
			printf("\nANTE NOW: %s", ip->ante);
			continue;
		}

		if (strcmp(line, "shop\n") == 0) {
			for (int i = 0; i < 2; i++) {
				fgets(line, 50, fp);
				line[strcspn(line, "\n")] = 0;

				shopCardTruth = strtol(line, &tempPtr, 10);
				shopCardPred = GetCardForShop(ip);

				if (shopCardPred == shopCardTruth) {
					printf("\nSHOP CARD %d PASSED: %d", i, shopCardPred);
				}
				else {
					printf("\nSHOP CARD %d FAILED: TRUTH: %d | PRED %d", i, shopCardTruth, shopCardPred);
				}
			}

			continue;
		}

		if (strcmp(line, "pack\n") == 0) {
			fgets(line, 50, fp);
			line[strcspn(line, "\n")] = 0;

			tempInt1 = strtol(line, &tempPtr, 10);

			tempInt2 = GetRandomPack(ip);

			if (tempInt1 == tempInt2) {
				printf("\nPACK PASSED: %d", tempInt1);

				printf("\nOPENING PACK...");

				GetCardsFromPack(ip, cardsPred, tempInt1);

				for (int i = 0; i < PACKS[tempInt1].size; i++) {

					fgets(line, 50, fp);
					line[strcspn(line, "\n")] = 0;
					cardsTruth[i] = strtol(line, &tempPtr, 10);

					if (cardsTruth[i] == cardsPred[i]) {
						printf("\nCARD IN PACK %d PASSED: %" PRIu64, i, cardsPred[i]);
					}
					else {
						printf("\nCARD IN PACK %d FAILED: TRUTH: %" PRIu64 " | PRED: %" PRIu64, i, cardsTruth[i], cardsPred[i]);
					}

					if (tempInt1 >= Standard_Pack && tempInt1 <= Mega_Standard_Pack) {

						fgets(line, 50, fp);
						line[strcspn(line, "\n")] = 0;

						editionTruth = strtol(line, &tempPtr, 10);

						fgets(line, 50, fp);
						line[strcspn(line, "\n")] = 0;

						sealTruth = strtol(line, &tempPtr, 10);

						fgets(line, 50, fp);
						line[strcspn(line, "\n")] = 0;

						bonusTruth = strtol(line, &tempPtr, 10);

						editionPred = GetStandardCardEdition(ip);
						sealPred = GetStandardCardSeal(ip);
						bonusPred = GetStandardCardBonus(ip);

						if (editionPred == editionTruth) {
							printf("\nCARD IN PACK %d EDITION PASSED: %d", i, editionPred);
						}
						else {
							printf("\nCARD IN PACK %d EDITION FAILED: TRUTH %d | PRED: %d", i, editionTruth, editionPred);
						}

						if (sealPred == sealTruth) {
							printf("\nCARD IN PACK %d SEAL PASSED: %d", i, sealPred);
						}
						else {
							printf("\nCARD IN PACK %d SEAL FAILED: TRUTH %d | PRED: %d", i, sealTruth, sealPred);
						}

						if (bonusPred == bonusTruth) {
							printf("\nCARD IN PACK %d BONUS PASSED: %d", i, bonusPred);
						}
						else {
							printf("\nCARD IN PACK %d BONUS FAILED: TRUTH %d | PRED: %d", i, bonusTruth, bonusPred);
						}
					}
				}
			}
			else {
				printf("\nPACK FAILED: TRUTH: %d | PRED: %d", tempInt1, tempInt2);
			}

			continue;
		}

		if (strcmp(line, "voucher\n") == 0) {
			fgets(line, 50, fp);
			line[strcspn(line, "\n")] = 0;

			voucherTruth = strtol(line, &tempPtr, 10);

			voucherPred = GetVoucher(ip, false);

			if (voucherPred == voucherTruth) {
				printf("\nVOUCHER PASSED: %d", voucherPred);
			}
			else {
				printf("\nVOUCHER FAILED: TRUTH: %d | PRED: %d", voucherTruth, voucherPred);
			}

			continue;
		}
	}

	free(fp);

	InstanceDelete(ip);
}