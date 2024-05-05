#pragma once
#include "filters.h"

void filter(Instance* ip) {
	
	int cards[5] = { 0, 0, 0, 0, 0 };
	int packIdx = 0;
	int jokerEdition = 0;
	int shopAmount = 2;

	for (int ante = 1; ante < 4; ante++) {
		SetAnte(ip, ante);
		printf("\nANTE %d", ante);

		for (int s = 0; s < shopAmount; s++) {

			GetCardsForShop(ip, cards, 2);
			printf("\n\tSHOP %d", s+1);
			for (int i = 0; i < 5; i++) {

				if (cards[i] > 0) { printf("\n\t\tCard %d: %d", i + 1, cards[i]); }

				if (cards[i] > JOKERSTART && cards[i] < JOKEREND) {
					jokerEdition = GetJokerEdition(ip, "sho");
					if (jokerEdition > 0) {
						printf(" EDITION: %d", jokerEdition);
					}
				}
			}

			for (int i = 0; i < 5; i++) {
				cards[i] = 0;
			}

			printf("\n\n\t\tPACKS");
			for (int j = 0; j < 2; j++) {
				packIdx = GetRandomPack(ip);
				printf("\n\t\t\tPack %d type %d", j + 1, packIdx);
				GetCardsFromPack(ip, cards, packIdx);

				for (int i = 0; i < 5; i++) {
					if (cards[i] > 0) { printf("\n\t\t\t\tCard %d: %d", i + 1, cards[i]); }
				}
				for (int i = 0; i < 5; i++) {
					cards[i] = 0;
				}
			}
		}

		if (ante == 1) {
			shopAmount++;
		}
	}
}

FunctionItem FunctionTable[1] = {
	{"filter", &filter},
};

FuncWrapper CallFunction(char* funcName) {
	for (int i = 0; i < sizeof(FunctionTable) / sizeof(FunctionTable[0]); i++) {

#ifdef DEBUG
		printf("\nFunction %d: %s", i, FunctionTable[i].strName);
#endif

		if (strcmp(funcName, FunctionTable[i].strName) == 0) {
			return FunctionTable[i].func;
		}
	}

	return NULL;
}