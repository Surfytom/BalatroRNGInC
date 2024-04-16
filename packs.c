#include "packs.h"

char NUMOFPACKS = 16;

weighteditem PACKS[16] = {
   {RETRY, 22.42}, //total
   {Arcana_Pack, 4},
   {Jumbo_Arcana_Pack, 2},
   {Mega_Arcana_Pack, 0.5},
   {Celestial_Pack, 4},
   {Jumbo_Celestial_Pack, 2},
   {Mega_Celestial_Pack, 0.5},
   {Standard_Pack, 4},
   {Jumbo_Standard_Pack, 2},
   {Mega_Standard_Pack, 0.5},
   {Buffoon_Pack, 1.2},
   {Jumbo_Buffoon_Pack, 0.6},
   {Mega_Buffoon_Pack, 0.15},
   {Spectral_Pack, 0.6},
   {Jumbo_Spectral_Pack, 0.3},
   {Mega_Spectral_Pack, 0.07}
};


/*
uint64_t GetCard() {

}

uint64_t GetCardsFromPack(char* packType, ) {

}
*/

char* GetPack(int n) {

    int sizeOfMaxChar = 21;

    char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

    if (returnCharPtr == NULL) {
        return NULL;
    }

    switch (n) {
    case 1:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Arcana_Pack");
        break;
    case 2:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Jumbo_Arcana_Pack");
        break;
    case 3:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Mega_Arcana_Pack");
        break;
    case 4:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Celestial_Pack");
        break;
    case 5:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Jumbo_Celestial_Pack");
        break;
    case 6:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Mega_Celestial_Pack");
        break;
    case 7:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Standard_Pack");
        break;
    case 8:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Jumbo_Standard_Pack");
        break;
    case 9:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Mega_Standard_Pack");
        break;
    case 10:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Buffoon_Pack");
        break;
    case 11:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Jumbo_Buffoon_Pack");
        break;
    case 12:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Mega_Buffoon_Pack");
        break;
    case 13:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Spectral_Pack");
        break;
    case 14:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Jumbo_Spectral_Pack");
        break;
    case 15:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Mega_Spectral_Pack");
        break;
    default:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoPack");
    }

    return returnCharPtr;
}