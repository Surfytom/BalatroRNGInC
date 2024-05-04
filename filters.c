#pragma once
#include "filters.h"

void filter(Instance* ip) {
	printf("\nYou are in dynamic filter");
}

FunctionItem FunctionTable[1] = {
	{"filter", &filter},
};

FuncWrapper CallFunction(char* funcName) {
	for (int i = 0; i < sizeof(FunctionTable) / sizeof(FunctionTable[0]); i++) {
		printf("\nFunction %d: %s", i, FunctionTable[i].strName);
		if (strcmp(funcName, FunctionTable[i].strName) == 0) {
			return FunctionTable[i].func;
		}
	}

	return NULL;
}