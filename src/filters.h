#ifndef FILTERS_H
#define FILTERS_H

#include <stdio.h>

#include "Instance.h"
#include "debug.h"

typedef void (*FuncWrapper)(Instance* ip, bool showPacks, bool showShops, bool showBosses, bool showTags);

typedef struct FunctionItem {
	const char* strName;
	FuncWrapper func;
} FunctionItem;

extern FunctionItem FunctionTable[1];

FuncWrapper CallFunction(char* funcName);

#endif