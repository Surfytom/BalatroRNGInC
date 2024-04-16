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

Instance* InstanceCreate(char* seed) {

	Instance* ip = malloc(sizeof(Instance));

	if (ip == NULL) {
		return NULL;
	}

	ip->seed = seed;
	ip->hashedSeed = PseudoHashChar(seed);

	ip->deck = malloc(sizeof(CardArray));

	if (ip->deck == NULL) {
		free(ip);
		return NULL;
	}

	ip->deck->size = 52;

	ip->deck->array = calloc(ip->deck->size, sizeof(Card*));

	ip->NodeMap = HashMapCreate(30);

	return ip;
}

void InstanceDelete(Instance* ip) {

	for (int i = 0; i < ip->deck->size; i++) {
		free(ip->deck->array[i]);
	}

	free(ip->deck->array);
	free(ip->deck);

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

double NodeIDRandom(Instance* ip, char* id, char* seed, double hashedSeed) {
	// The num if is for if the node has already been calculated and therefore dosent need to be reset and instead re-rolled

	// Keep track of the rng states of nodes
	// If a key is passed that has already been hashed then you need to use the saved rng state not make a new one

	size_t bufferSize = sizeof(char) * (strlen(id) + strlen(seed) + 1);
	char* combineChar = malloc(bufferSize);

	if (combineChar == NULL) {
		return -1.0;
	}

	strcpy_s(combineChar, bufferSize, id);
	strcat_s(combineChar, bufferSize, seed);

	entry* e = HashMapGet(ip->NodeMap, combineChar);

	if (e == NULL) {
		e = HashMapInsert(ip->NodeMap, combineChar, -1.0);

		if (e == NULL) {
			return -1.0;
		}
	}

	if (e->value < 0.0) {
		e->value = PseudoHashChar(combineChar);
	}

	free(combineChar);

	// num needs to be saved as somehow
	e->value = RoundDigits(fract(e->value * 1.72431234 + 2.134453429141), 13);

	printf("\nRng state: %0.10f", e->value);

	return (e->value + hashedSeed) / 2;
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