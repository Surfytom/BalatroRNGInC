#ifndef FILTERS_H
#define FILTERS_H

#include <stdio.h>

#include "Instance.h"
#include "debug.h"

typedef void (*FuncWrapper)(Instance* ip);

typedef struct FunctionItem {
	const char* strName;
	FuncWrapper func;
} FunctionItem;

extern FunctionItem FunctionTable[1];

FuncWrapper CallFunction(char* funcName);

#endif