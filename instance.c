#include "instance.h"
#include "packs.h"

char** SUITS[4] = {
	"Spades",
	"Hearts",
	"Clubs",
	"Diamonds",
};

char** BASE_DECK[52] = {
	"H_2",
	"H_3",
	"H_4",
	"H_5",
	"H_6",
	"H_7",
	"H_8",
	"H_9",
	"H_T",
	"H_J",
	"H_Q",
	"H_K",
	"H_A",
	"C_2",
	"C_3",
	"C_4",
	"C_5",
	"C_6",
	"C_7",
	"C_8",
	"C_9",
	"C_T",
	"C_J",
	"C_Q",
	"C_K",
	"C_A",
	"D_2",
	"D_3",
	"D_4",
	"D_5",
	"D_6",
	"D_7",
	"D_8",
	"D_9",
	"D_T",
	"D_J",
	"D_Q",
	"D_K",
	"D_A",
	"S_2",
	"S_3",
	"S_4",
	"S_5",
	"S_6",
	"S_7",
	"S_8",
	"S_9",
	"S_T",
	"S_J",
	"S_Q",
	"S_K",
	"S_A",
};

RateObject RATES[7] = {
	{20, "Joker", JOKERSTART, JOKEREND},
	{4, "Tarot",  TAROTSTART, TAROTEND},
	{0, "Planet",  PLANETSTART, PLANETEND},
	{4, "Base",  JOKERSTART, JOKEREND},
	{0, "Spectral",  SPECTRALSTART, SPECTRALEND},
	{1, "Edition", JOKERSTART, JOKEREND},
	{28, "", 0, 0},
};

double BASERATES[7] = {
	20,
	4,
	4,
	0,
	0,
	1,
	28,
};

char* RATETYPES[7] = {
	"Joker",
	"Tarot",
	"Base",
	"Planet",
	"Spectral",
	"Base",
	"a",
};

char* CombineChars(int count, ...) {

	va_list list;

	va_start(list, count);
	
	char* tmpChar = va_arg(list, char*);
	size_t charSize = strlen(tmpChar) + 1;

	char* combinedChar = malloc(charSize);

	if (combinedChar == NULL) {
		return NULL;
	}

	strcpy_s(combinedChar, charSize, tmpChar);

	char* ReallocChar = NULL;

	int i;
	for (i = 1; i < count; i++) {
		
		tmpChar = va_arg(list, char*);
		charSize = strlen(tmpChar) + 1;

		ReallocChar = realloc(combinedChar, strlen(combinedChar) + charSize);

		if (ReallocChar == NULL) {
			free(combinedChar);
			return NULL;
		}

		combinedChar = ReallocChar;

		strcat_s(combinedChar, strlen(combinedChar) + charSize, tmpChar);
	}

	va_end(list);

	return combinedChar;
}

Instance* InstanceCreate(char* seed, size_t hashMapSize) {

	Instance* ip = malloc(sizeof(Instance));

	if (ip == NULL) {
		return NULL;
	}

	ip->seed = malloc(strlen(seed) + 1);

	if (ip->seed == NULL) {
		free(ip);
		return NULL;
	}

	strcpy_s(ip->seed, strlen(seed) + 1, seed);
	ip->hashedSeed = PseudoHashChar(ip->seed);

	ip->ante = malloc(sizeof(char) * 2);

	if (ip->ante == NULL) {
		free(ip);
		free(ip->seed);
		return NULL;
	}

	strcpy_s(ip->ante, 2, "1");

	ip->deck = malloc(sizeof(CardArray));

	if (ip->deck == NULL) {
		free(ip);
		free(ip->seed);
		free(ip->ante);
		return NULL;
	}

	ip->deck->size = 52;

	ip->deck->array = calloc(ip->deck->size, sizeof(Card*));

	/*
	ip->rates = malloc(sizeof(RatesObject) * 7);

	if (ip->rates == NULL) {
		free(ip);
		free(ip->seed);
		free(ip->ante);

		for (int i = 0; i < ip->deck->size; i++) {
			free(ip->deck->array[i]);
		}

		free(ip->deck->array);
		free(ip->deck);

		return NULL;
	}

	for (int i = 0; i < 7; i++) {
		ip->rates[i].rate = BASERATES[i];
		strcpy_s(ip->rates[i].type, strlen(RATETYPES[i]) + 1, RATETYPES[i]);
	}
	*/
	/*
	ip->rates->editionRate = 1;
	ip->rates->jokerRate = 20;
	ip->rates->tarotRate = 4;
	ip->rates->planetRate = 4;
	ip->rates->spectralRate = 0;
	ip->rates->playingCardRate = 0;
	*/

	ip->locked = calloc(CONSUMABLEEND, sizeof(bool));

	if (ip->locked == NULL) {
		free(ip);
		free(ip->seed);
		free(ip->ante);

		for (int i = 0; i < ip->deck->size; i++) {
			free(ip->deck->array[i]);
		}

		free(ip->deck->array);
		free(ip->deck);

		return NULL;
	}

	// Initialize things that should be locked from the beggining

	for (int i = 1; i < (VOUCHEREND - VOUCHERSTART); i++) {
		printf("\nI initial: %d", i);
		printf("\nI actual: %d", VOUCHERSTART + i);
		if (VOUCHERS[i].required != -1) {
			ip->locked[VOUCHERSTART + i] = true;
		}
	}

	ip->NodeMap = HashMapCreate(hashMapSize);

	return ip;
}

void InstanceDelete(Instance* ip) {

	for (int i = 0; i < ip->deck->size; i++) {
		free(ip->deck->array[i]);
	}

	free(ip->deck->array);
	free(ip->deck);

	free(ip->seed);
	free(ip->ante);

	free(ip->locked);

	//free(ip->rates);

	HashMapDelete(ip->NodeMap);

	free(ip);
}

entry* NodeIDGet(Instance* ip, char* id) {
	return HashMapGet(ip->NodeMap, id);
}

bool NodeIDInsert(Instance* ip, char* id, double value) {
	return HashMapInsert(ip->NodeMap, id, value);
}

bool NodeIDRemove(Instance* ip, char* id) {
	return HashMapRemove(ip->NodeMap, id);
}

double NodeIDRandom(Instance* ip, char* id) {

	entry* e = HashMapGet(ip->NodeMap, id);

	if (e == NULL) {
		e = HashMapInsert(ip->NodeMap, id, -1.0);

		if (e == NULL) {
			return -1.0;
		}
	}

	if (e->value < 0.0) {
		e->value = PseudoHashChar(id);
	}

	e->value = RoundDigits(fract(e->value * 1.72431234 + 2.134453429141), 13);

	printf("\nNODEID UPDATE | state of '%s': %0.10f", id, e->value);

	return (e->value + ip->hashedSeed) / 2;
}

uint64_t RandomChoice(Instance* ip, char* id, uint64_t min, uint64_t max) {

	char* combinedChar = CombineChars(2, id, ip->seed);

	if (combinedChar == NULL) {
		return -1;
	}

	int64_t* state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

	combinedChar = NULL;
	free(combinedChar);

	return RandomInt(state, min, max);
}

int GetRandomPack(Instance* ip) {
	char* packSeed = "shop_pack";

	double it = 0.0;
	int center = 0;

	char* combinedChar = CombineChars(3, packSeed, ip->ante, ip->seed);

	if (combinedChar == NULL) {
		return -1;
	}

	int64_t* state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

	free(combinedChar);

	dbllong poll = RandomDouble(state);

	free(state);

	poll.d *= PACKS[0].weight;

	int idx = 1;
	while (it < poll.d) {
		it += PACKS[idx].weight;
		idx++;
	}

	return idx - 1;
}

char* GetPool(Instance* ip, char* type, int typeStart, int typeEnd, int rarity, char* keyAppend, uint64_t* poolArray) {

	char* poolKey = NULL;

	int poolStart = 0;
	int poolEnd = 0;

	if (typeStart == JOKERSTART) {

		char* rarityChar = "rarity";

		char* combinedChar = CombineChars(4, rarityChar, ip->ante, keyAppend, ip->seed);

		int64_t* state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar, ip->hashedSeed));

		dbllong dbl = RandomDouble(state);

		free(combinedChar);
		free(state);

		if (dbl.d > 0.95) {
			poolStart = JOKER3START;
			poolEnd = JOKER3END;
			rarityChar = "3";
		}
		else if (dbl.d > 0.7) {
			poolStart = JOKER2START;
			poolEnd = JOKER2END;
			rarityChar = "2";
		}
		else {
			poolStart = JOKER1START;
			poolEnd = JOKER1END;
			rarityChar = "1";
		}

		poolKey = CombineChars(3, type, rarityChar, keyAppend);
	}
	else if (typeStart == DECKSTART){

		poolStart = typeStart;
		poolEnd = typeEnd;
		poolKey = CombineChars(2, "front", keyAppend, ip->ante);
	}
	else {
		poolStart = typeStart;
		poolEnd = typeEnd;
		poolKey = CombineChars(2, type, keyAppend);
	}

	char* returnKey = CombineChars(3, poolKey, ip->ante, ip->seed);

	free(poolKey);

	poolArray[0] = poolStart;
	poolArray[1] = poolEnd;

	return returnKey;
}

int PollEdition(Instance* ip, char* key, double mod, bool noNegative, bool force) {
	if (mod == -1.0) {
		mod = 1.0;
	}

	uint64_t* state = RandomStateFromSeed(NodeIDRandom(ip, key));

	dbllong dbl = RandomDouble(state);

	free(state);

	if (force) {
		if (dbl.d > 1 - 0.003 * 25 && !noNegative) {
			return negative;
		}
		if (dbl.d > 1 - 0.006 * 25) {
			return polychrome;
		}
		if (dbl.d > 1 - 0.02 * 25) {
			return holo;
		}
		if (dbl.d > 1 - 0.04 * 25) {
			return foil;
		}
	}

	if (dbl.d > 1 - 0.003 * mod && !noNegative) {
		return negative;
	}
	if (dbl.d > 1 - 0.006 * RATES[5].rate * mod) {
		return polychrome;
	}
	if (dbl.d > 1 - 0.02 * RATES[5].rate * mod) {
		return holo;
	}
	if (dbl.d > 1 - 0.04 * RATES[5].rate * mod) {
		return foil;
	}

	return -1;
}

uint64_t CreateCard(Instance* ip, char* type, int typeStart, int typeEnd, int rarity, char* forcedKey, char* keyAppend) {

	uint64_t* state = NULL;

	if (typeStart == PLANETSTART || typeStart == TAROTSTART || typeStart == PLANETSTART || typeStart == SPECTRALSTART) {

		char* soulChar = "soul_";

		char* combinedSoulChar = CombineChars(4, soulChar, type, ip->ante, ip->seed);

		if (typeStart == TAROTSTART || typeStart == SPECTRALSTART) {
			// Roll for soul
			state = RandomStateFromSeed(NodeIDRandom(ip, combinedSoulChar, ip->hashedSeed));
			dbllong dbl = RandomDouble(state);
			free(state);

			if (dbl.d > 0.997) {
				return c_soul;
			}
		}
		if (typeStart == PLANETSTART || typeStart == SPECTRALSTART) {
			// Roll for black hole
			state = RandomStateFromSeed(NodeIDRandom(ip, combinedSoulChar, ip->hashedSeed));
			dbllong dbl = RandomDouble(state);
			free(state);

			if (dbl.d > 0.997) {
				return c_black_hole;
			}
		}

		free(combinedSoulChar);
	}

	uint64_t* rangeValues = malloc(sizeof(uint64_t) * 2);

	if (rangeValues == NULL) {
		return NULL;
	}

	char* returnKey = NULL;
	returnKey = GetPool(ip, type, typeStart, typeEnd, rarity, keyAppend, rangeValues, returnKey);

	state = RandomStateFromSeed(NodeIDRandom(ip, returnKey, ip->hashedSeed));

	int64_t diff = rangeValues[1] - rangeValues[0];
	int64_t lower = rangeValues[0];

	printf("\nrange: lower: %" PRIu64, rangeValues[0]);
	printf(" higher: %" PRIu64, rangeValues[1]);
	printf("\nDiff: %" PRIu64, diff);

	int64_t returnInt = RandomInt(state, 1, (rangeValues[1] - rangeValues[0]) - 1);
	
	// make sure to free these in the loop to not lose pointers
	free(rangeValues);
	free(state);
	free(returnKey);

	return returnInt + lower;
}

int GetJokerEdition(Instance* ip, char* keyAppend) {

	char* combinedChar = CombineChars(4, "edi", keyAppend, ip->ante, ip->seed);

	int returnInt = PollEdition(ip, combinedChar, -1.0, false, false);

	free(combinedChar);

	printf("\nRETURN INT FOR EDITION: %d", returnInt);

	return returnInt;
}

int GetStandardCardEdition(Instance* ip) {

	char* combinedChar = CombineChars(3, "standard_edition", ip->ante, ip->seed);

	int returnInt = PollEdition(ip, combinedChar, 2.0, true, false);

	free(combinedChar);

	return returnInt;
}

int GetStandardCardSeal(Instance* ip) {

	char* combinedChar = CombineChars(3, "stdseal", ip->ante, ip->seed);

	int64_t* state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

	dbllong dbl = RandomDouble(state);

	int returnInt = -1;

	if (dbl.d > (1.0 - 0.02 * 10.0)) {
		// Seal garunteed now choose which type of seal
		free(state);
		free(combinedChar);

		combinedChar = CombineChars(3, "stdsealtype", ip->ante, ip->seed);	

		state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

		dbl = RandomDouble(state);

		if (dbl.d > 0.75) {
			returnInt = s_red;
		}
		else if (dbl.d > 0.5) {
			returnInt = s_blue;
		}
		else if (dbl.d > 0.25) {
			returnInt = s_gold;
		}
		else {
			returnInt = s_purple;
		}
	}

	free(state);
	free(combinedChar);

	return returnInt;
}

uint64_t GetStandardCardBonus(Instance* ip) {
	
	char* combinedChar = CombineChars(3, "stdset", ip->ante, ip->seed);
	
	int64_t* state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

	dbllong dbl = RandomDouble(state);
	
	uint64_t returnInt = 0;

	if (dbl.d > 0.6) {

		free(combinedChar);
		free(state);

		combinedChar = CombineChars(4, "Enhanced", "sta", ip->ante, ip->seed);

		state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

		int64_t diff = (BONUSEND - BONUSSTART) - 1;
		int64_t lower = BONUSSTART;

		printf("\nDiff in bonus: %" PRIu64, diff);

		returnInt = RandomInt(state, 1, diff);
		returnInt += lower;
	}

	free(combinedChar);
	free(state);

	return returnInt;
}

void GetCardsFromPack(Instance* ip, uint64_t* cards, int packIdx) {

	char* c = NULL;

	uint64_t card = 0;
	int cardInt = 0;

	for (int i = 0; i < PACKS[packIdx].size; i++) {

		card = CreateCard(ip, PACKS[packIdx].type, PACKS[packIdx].start, PACKS[packIdx].end, 0, NULL, PACKS[packIdx].key);

		int resample = 1;
		bool foundUniqueCard = false;
		while (!foundUniqueCard) {
			bool inCards = false;
			for (int t = 0; t < i+1; t++) {
				if (card == cards[t]) {
					inCards = true;
				}
				if (PACKS[packIdx].start == VOUCHERSTART) {
					cardInt = card;
					printf("\nindex: %d", VOUCHERS[VOUCHEREND - cardInt].required);
					printf("\nbool val: %d", ip->locked[VOUCHERS[VOUCHEREND - cardInt].required]);
					printf("\ncard: %d", cardInt);
					if (ip->locked[VOUCHERS[VOUCHEREND - cardInt].required] == true) {
						inCards = true;
					}
				}
			}

			if (inCards && PACKS[packIdx].start != DECKSTART) {

				char* resampleIt = malloc(sizeof(char) * 2);

				if (resampleIt == NULL) {
					return NULL;
				}

				resampleIt[0] = (resample % 10) + '1';
				resampleIt[1] = '\0';

				char* re = "_resample";
				char* resampleChar = CombineChars(2, re, resampleIt);

				card = CreateCard(ip, PACKS[packIdx].type, PACKS[packIdx].start, PACKS[packIdx].end, 0, NULL, resampleChar);

				resample++;

				free(resampleIt);
				free(resampleChar);
			}
			else {
				foundUniqueCard = true;
			}
		}

		cards[i] = card;

		c = GetPack(packIdx);

		printf("\nPack: %s card: %" PRIu64, c, card);
		printf(" start: %d end : %d", PACKS[packIdx].start, PACKS[packIdx].end);

		free(c);
	}
}

uint64_t GetCardForShop(Instance* ip) {

	char* combinedChar = CombineChars(3, "cdt", ip->ante, ip->seed);

	uint64_t* state = RandomStateFromSeed(NodeIDRandom(ip, combinedChar));

	dbllong dbl = RandomDouble(state);

	free(combinedChar);
	free(state);

	double polledRate = dbl.d * RATES[6].rate;
	double checkRate = 0.0;
	/*
	// Roll for enhanced vs base card
	// Only if the playing card voucher is gotten
	uint64_t* state = RandomStateFromSeed(NodeIDRandom(ip, "illusion"));

	dbllong dbl = RandomDouble(state);

	if (dbl.d > 0.6) {
		// Get enhanced card
	}
	else {
		// Get base card
	}
	*/
	double currentRate = 0.0;
	uint64_t card = NULL;

	for (int i = 0; i < 5; i++) {
		printf("\ni: %d rate: %0.10f type: %s polled rate: %0.10f", i, RATES[i].rate, RATES[i].type, polledRate);
		currentRate = RATES[i].rate;

		
		if (polledRate > checkRate && polledRate <= (checkRate + currentRate)) {

			card = CreateCard(ip, RATES[i].type, RATES[i].typeStart, RATES[i].typeEnd, 0, NULL, "sho");
			return card;
		}

		checkRate += RATES[i].rate;
	}

	return 0;
}

void GetCardsForShop(Instance* ip, int64_t* cards, int shopSize) {

	for (int i = 0; i < shopSize; i++) {
		cards[i] = GetCardForShop(ip);
	}
}

int GetVoucher(Instance* ip, bool fromTag) {

	uint64_t cards[1] = {0};
	int returnCard = 0;

	GetCardsFromPack(ip, cards, fromTag ? VouchersFromTag : Vouchers);
	//CreateCard(ip, fromTag ? "Voucher_fromtag" : "Voucher", VOUCHERSTART, VOUCHEREND, 0, NULL, "");

	returnCard = cards[0];

	return returnCard;
}

char* GetPackTypeForRates(int n) {

	int sizeOfMaxChar = 9;

	char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

	if (returnCharPtr == NULL) {
		return NULL;
	}

	switch (n) {
	case 1:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Joker");
		break;
	case 2:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Tarot");
		break;
	case 3:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Planet");
		break;
	case 4:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Base");
		break;
	case 5:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Spectral");
		break;
	default:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoPack");
	}

	return returnCharPtr;
}

char* GetSuit(int n) {

	int sizeOfMaxChar = 9;

	char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

	if (returnCharPtr == NULL) {
		return NULL;
	}

	switch (n) {
	case 0:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Spades");
		break;
	case 1:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Hearts");
		break;
	case 2:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Clubs");
		break;
	case 3:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Diamonds");
		break;
	default:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoSuit");
	}

	return returnCharPtr;
}

char* GetRank(int n) {

	int sizeOfMaxChar = 7;

	char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

	if (returnCharPtr == NULL) {
		return NULL;
	}

	switch (n) {
	case 0:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "2     ");
		break;
	case 1:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "3     ");
		break;
	case 2:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "4     ");
		break;
	case 3:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "5     ");
		break;
	case 4:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "6     ");
		break;
	case 5:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "7     ");
		break;
	case 6:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "8     ");
		break;
	case 7:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "9     ");
		break;
	case 8:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "10    ");
		break;
	case 9:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Jack  ");
		break;
	case 10:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Queen ");
		break;
	case 11:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "King  ");
		break;
	case 12:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Ace   ");
		break;
	default:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoRank");
	}

	return returnCharPtr;
}

char* GetBonus(int n) {

	int sizeOfMaxChar = 9;

	char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

	if (returnCharPtr == NULL) {
		return NULL;
	}

	switch (n) {
	case 0:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Chips");
		break;
	case 1:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Multiply");
		break;
	case 2:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Gold");
		break;
	case 3:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Steel");
		break;
	default:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoBonus");
	}

	return returnCharPtr;
}

char* GetEffect(int n) {

	int sizeOfMaxChar = 11;

	char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

	if (returnCharPtr == NULL) {
		return NULL;
	}

	switch (n) {
	case 0:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Multiply");
		break;
	case 1:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Polychrome");
		break;
	case 2:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Foil");
		break;
	default:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoEffect");
	}

	return returnCharPtr;
}

char* GetSeal(int n) {

	int sizeOfMaxChar = 7;

	char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

	if (returnCharPtr == NULL) {
		return NULL;
	}

	switch (n) {
	case 0:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Gold");
		break;
	case 1:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Red");
		break;
	case 2:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Blue");
		break;
	default:
		strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoSeal");
	}

	return returnCharPtr;
}