#pragma once
#include "filters.h"

void filter(Instance* ip, bool showPacks, bool showShops, bool showBosses, bool showTags) {
	
	int cards[5] = { 0, 0, 0, 0, 0 };
	int packIdx = 0;
	int jokerEdition = 0;
	int shopAmount = 2;
	int rerollAmount = 1;

	for (int ante = 1; ante < 2; ante++) {
		SetAnte(ip, ante);

		if (showPacks || showShops || showBosses || showTags) {
			printf("\nANTE %d", ante);
		}

		if (showBosses) {
			printf("\n\tBOSS: %d", GetNextBoss(ip));
		}

		if (showTags) {
			printf("\n\tTAGS: %d | %d", GetNextTag(ip), GetNextTag(ip));
		}

		for (int s = 0; s < shopAmount; s++) {
			if (showShops) {
				printf("\n\tSHOP %d", s + 1);

				for (int r = 0; r < rerollAmount; r++) {
					printf("\n\t\tREROLL %d", r + 1);

					GetCardsForShop(ip, cards, 2);

					for (int i = 0; i < 5; i++) {

						if (cards[i] > 0) { printf("\n\t\t\tCard %d: %3d", i + 1, cards[i]); }

						if (cards[i] > JOKERSTART && cards[i] < JOKEREND) {
							jokerEdition = GetJokerEdition(ip, "sho");
							if (jokerEdition > 0) {
								printf(" EDITION: %d", jokerEdition);
							}

							JokerModifiers modifiers = { modifiers.eternal = false, modifiers.perishable = false, modifiers.rental = false };

							GetJokerModifiers(ip, &modifiers, false);

							if (modifiers.eternal) {
								printf(" Eternal");
							}
							if (modifiers.perishable) {
								printf(" Perishable");
							}
							if (modifiers.rental) {
								printf(" Rental");
							}

							/*
							printf("\nModifier Eternal    %s", modifiers.eternal ? "true" : "false");
							printf("\nModifier Perishable %s", modifiers.perishable ? "true" : "false");
							printf("\nModifier Rental     %s", modifiers.rental ? "true" : "false");
							*/
						}
					}

					for (int i = 0; i < 5; i++) {
						cards[i] = 0;
					}
				}
			}

			if (showPacks) {
				printf("\n\n\t\tPACKS");
				for (int j = 0; j < 2; j++) {
					packIdx = GetRandomPack(ip);
					printf("\n\t\t\tPack %d type %d", j + 1, packIdx);
					GetCardsFromPack(ip, cards, packIdx);

					for (int i = 0; i < 5; i++) {
						if (cards[i] > 0) {
							printf("\n\t\t\t\tCard %d: %3d", i + 1, cards[i]);

							if (packIdx >= Buffoon_Pack && packIdx <= Mega_Buffoon_Pack) {
								JokerModifiers modifiers = { modifiers.eternal = false, modifiers.perishable = false, modifiers.rental = false };

								GetJokerModifiers(ip, &modifiers, true);

								if (modifiers.eternal) {
									printf(" Eternal");
								}
								if (modifiers.perishable) {
									printf(" Perishable");
								}
								if (modifiers.rental) {
									printf(" Rental");
								}
								
								/*
								printf("\nModifier Eternal    %s", modifiers.eternal ? "true" : "false");
								printf("\nModifier Perishable %s", modifiers.perishable ? "true" : "false");
								printf("\nModifier Rental     %s", modifiers.rental ? "true" : "false");
								*/
							}
						}
					}
					for (int i = 0; i < 5; i++) {
						cards[i] = 0;
					}
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