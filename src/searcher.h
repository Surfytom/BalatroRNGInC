#ifndef SEARCHER_H
#define SEARCHER_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "instance.h"
#include "debug.h"

extern char POSSIBLECHARS[37];

bool NextSeed(char** previousChar);
bool SearchSeed(char* seed);
bool StartSearch(char* startingSeed, int searchLength);

#endif
