#pragma once
#include "Instance.h"

typedef void (*FuncWrapper)(Instance* ip);

typedef struct FunctionItem {
	const char* strName;
	FuncWrapper func;
} FunctionItem;

extern FunctionItem FunctionTable[1];

FuncWrapper CallFunction(char* funcName);