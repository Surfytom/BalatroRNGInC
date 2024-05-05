#include "hashmap.h"

hashmap* HashMapCreate(size_t size) {

	hashmap* hmp = malloc(sizeof(hashmap));

	if (hmp == NULL) {
		return NULL;
	}

	hmp->size = size;

	hmp->entries = calloc(hmp->size, sizeof(entry*));

	return hmp;
}

uint64_t HashMapHash(char* key, size_t size) {
	
	uint64_t hashVal = 1;

	for (int i = 0; i < strlen(key); i++) {
		hashVal += key[i];
		hashVal = (hashVal * key[i]) % size;
	}

	return hashVal;
}

entry* HashMapGet(hashmap* hmp, char* key) {
	if (hmp == NULL || key == NULL) {
		return NULL;
	}

	uint64_t idx = HashMapHash(key, hmp->size);
	entry* node = hmp->entries[idx];

	while (node != NULL && strcmp(node->key, key) != 0) {
		node = node->next;
	}

	if (node == NULL) return NULL;
	return node;
}

entry* HashMapInsert(hashmap* hmp, char* key, double value) {
	if (hmp == NULL || key == NULL) {
		return NULL;
	}

	entry* tmp = HashMapGet(hmp, key);

	if (tmp != NULL) {
		return NULL;
	}

	uint64_t idx = HashMapHash(key, hmp->size);

	entry* e = malloc(sizeof(entry));

	if (e == NULL) {
		return NULL;
	}

	e->key = malloc(strlen(key)+1);

	if (e->key == NULL) {
		free(e);
		return NULL;
	}

#ifdef DEBUG
	printf("\nHASHMAP INSERT | Size of '%s': %zu", key, strlen(key));
#endif

	strcpy_s(e->key, strlen(key) + 1, key);

	e->value = value;

	e->next = hmp->entries[idx];
	hmp->entries[idx] = e;

	return e;
}

void freeEntry(entry* e) {
	free(e->key);
	free(e);
}

bool HashMapRemove(hashmap* hmp, char* key) {
	if (hmp == NULL || key == NULL) {
		return false;
	}

	uint64_t idx = HashMapHash(key, hmp->size);

	entry* node = hmp->entries[idx];
	entry* prev = NULL;

	while (node != NULL && strcmp(node->key, key) != 0) {
		prev = node;
		node = node->next;
	}

	if (node == NULL) return false;
	if (prev == NULL) {
		hmp->entries[idx] = node->next;
	}
	else {
		prev->next = node->next;
	}

	freeEntry(node);

	return true;
}

void HashMapPrint(hashmap* hmp) {

	entry* node = NULL;

	printf("\nStart");
	for (int i = 0; i < hmp->size; i++) {
		printf("\n[%-3d]: ", i);
		node = hmp->entries[i];
		while (node != NULL) {
			printf("%-10s - %0.4f| ", node->key, node->value);
			node = node->next;
		}
	}
	printf("\nEnd");
}

void HashMapDelete(hashmap* hmp) {
	if (hmp == NULL) {
		return;
	}

	entry* tmp = NULL;

	for (int i = 0; i < hmp->size; i++) {

		while (hmp->entries[i] != NULL) {
			tmp = hmp->entries[i];
			hmp->entries[i] = hmp->entries[i]->next;
			freeEntry(tmp);
		}

		free(hmp->entries[i]);
	}

	free(hmp->entries);
	free(hmp);
}