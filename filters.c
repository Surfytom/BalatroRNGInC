#pragma once
#include "filters.h"

void filter(Instance* ip) {
	
	int cards[5] = { 0, 0, 0, 0, 0 };

	for (int ante = 1; ante < 2; ante++) {
		SetAnte(ip, ante);

		int packIdx = GetRandomPack(ip);
		GetCardsFromPack(ip, cards, packIdx);

		for (int i = 0; i < 5; i++) {
			printf("\nCard %d: %d", i, cards[i]);
		}
	}
}

FunctionItem FunctionTable[1] = {
	{"filter", &filter},
};

FuncWrapper CallFunction(char* funcName) {
	for (int i = 0; i < sizeof(FunctionTable) / sizeof(FunctionTable[0]); i++) {
		printf("\nFunction %d: %s", i, FunctionTable[i].strName);
		if (strcmp(funcName, FunctionTable[i].strName) == 0) {
			return FunctionTable[i].func;
		}
	}

	return NULL;
}