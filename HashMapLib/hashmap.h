#ifndef HASHMAP_H
#define HASHMAP_H
#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#include "../debug.h"

typedef struct entry {
	char* key;
	double value;
	struct entry* next;
} entry;

typedef struct hashmap {
	size_t size;
	entry** entries;
} hashmap;

uint64_t HashMapHash(char* key, size_t size);
hashmap* HashMapCreate(size_t size);
entry* HashMapGet(hashmap* hmp, char* key);
entry* HashMapInsert(hashmap* hmp, char* key, double value);
bool HashMapRemove(hashmap* hmp, char* key);
void HashMapPrint(hashmap* hmp);
void HashMapDelete(hashmap* hmp);

#endif