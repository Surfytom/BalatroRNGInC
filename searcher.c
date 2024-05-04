#include "searcher.h"

char* POSSIBLECHARSSTRING = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char POSSIBLECHARS[37] = {
	'/',
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
	'G',
	'H',
	'I',
	'J',
	'K',
	'L',
	'M',
	'N',
	'O',
	'P',
	'Q',
	'R',
	'S',
	'T',
	'U',
	'V',
	'W',
	'X',
	'Y',
	'Z',
};

bool NextSeed(char* previousChar) {

	int size = strlen(previousChar);
	int total = 0;

	for (int i = 0; i < size; i++) {
		total += previousChar[i];
	}

	if (total == (8 * 90)) {
		return false;
	}

	if (total == (size * 90)) {

		char* reAllocChar = realloc(previousChar, strlen(previousChar) + 2);

		if (reAllocChar == NULL) {
			return false;
		}

		previousChar = reAllocChar;

		int stop = strlen(previousChar);

		strcpy_s(previousChar, strlen(previousChar) + 2, "0");

		for (int i = 0; i < stop; i++) {
			strcat_s(previousChar, strlen(previousChar) + 2, "0");
		}

		return true;
	}

	for (int i = size-1; i > 0; i--) {
		if (previousChar[i] == 'Z') {
			if (i > 0) {

				if (previousChar[i - 1] == 'Z') {
					previousChar[i] = '0';
					continue;
				}

				if (previousChar[i - 1] == 57) {
					previousChar[i - 1] = 64;
				}

				previousChar[i - 1]++;
				previousChar[i] = POSSIBLECHARS[1];
				return true;
			}
			else {
				previousChar[i]++;
				previousChar[i + 1] = POSSIBLECHARS[1];
				return true;
			}
		}
		else {
			if (previousChar[i] == 57) {
				previousChar[i] = 64;
			}
			previousChar[i]++;
			return true;
		}
	}

	if (previousChar[size - 1] == 57) {
		previousChar[size - 1] = 64;
	}
	previousChar[size - 1]++;
	return true;
}

bool SearchSeed(char* seed) {

	Instance* ip = InstanceCreate(seed, 100);

	if (ip == NULL) {
		return false;
	}

	int pack = GetRandomPack(ip);
	printf("\nPack: %d", pack);

	InstanceDelete(ip);

	return true;
}

bool StartSearch(char* seed, int searchLength) {

	// Checks if starting seed is valid

	if (strlen(seed) > 8) {
		printf("\nINVALID TOO MANY CHARACTER IN STARTING SEED: %s | 8 Characters MAX", seed);
		return false;
	}

	for (int i = 0; i < strlen(seed); i++) {
		//printf("\nchar: %d %c", startingSeed[i], startingSeed[i]);
		if (!((seed[i] >= '0' && seed[i] <= '9') || (seed[i] >= 'A' && seed[i] <= 'Z'))) {
			printf("\nINVALID CHARACTERS IN STARTING SEED: %s | Only contains 8 of these characters: '%s'", seed, POSSIBLECHARSSTRING);
			return false;
		}
	}

	if (searchLength == -1) {
		do {
			if (SearchSeed(seed) == false) { return false; };
		} while (NextSeed(seed));
	}
	else {
		for (int i = 0; i < searchLength; i++) {
			if (SearchSeed(seed) == false) { return false; };
			if (NextSeed(seed) == false) { return false; };
		}
	}

	return true;
}