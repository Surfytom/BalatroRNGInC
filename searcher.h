#pragma once

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "instance.h"
#include "debug.h"

char POSSIBLECHARS[37];

bool NextSeed(char* previousChar);
bool SearchSeed(char* seed);
bool StartSearch(char* startingSeed, int searchLength);
