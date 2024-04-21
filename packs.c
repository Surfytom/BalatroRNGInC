#include "packs.h"

char NUMOFPACKS = 16;

weighteditem PACKS[17] = {
   {RETRY, 22.42, 0, 0, 0, "", ""}, //total
   {Arcana_Pack, 4, 3, TAROTSTART, TAROTEND, "Tarot", "ar1"},
   {Jumbo_Arcana_Pack, 2, 5, TAROTSTART, TAROTEND, "Tarot", "ar1"},
   {Mega_Arcana_Pack, 0.5, 5, TAROTSTART, TAROTEND, "Tarot","ar1"},
   {Celestial_Pack, 4, 3, PLANETSTART, PLANETEND, "Planet", "pl1"},
   {Jumbo_Celestial_Pack, 2, 5, PLANETSTART, PLANETEND, "Planet", "pl1"},
   {Mega_Celestial_Pack, 0.5, 5, PLANETSTART, PLANETEND, "Planet","pl1"},
   {Standard_Pack, 4, 3, DECKSTART, DECKEND, "stdset", "sta"},
   {Jumbo_Standard_Pack, 2, 5, DECKSTART, DECKEND, "stdset", "sta"},
   {Mega_Standard_Pack, 0.5, 5, DECKSTART, DECKEND, "stdset", "sta"},
   {Buffoon_Pack, 1.2, 2, JOKERSTART, JOKEREND, "Joker", "buf"},
   {Jumbo_Buffoon_Pack, 0.6, 4, JOKERSTART, JOKEREND, "Joker", "buf"},
   {Mega_Buffoon_Pack, 0.15, 4, JOKERSTART, JOKEREND, "Joker", "buf"},
   {Spectral_Pack, 0.6, 2, SPECTRALSTART, SPECTRALEND, "Spectral", "spe"},
   {Jumbo_Spectral_Pack, 0.3, 4, SPECTRALSTART, SPECTRALEND, "Spectral", "spe"},
   {Mega_Spectral_Pack, 0.07, 4, SPECTRALSTART, SPECTRALEND, "Spectral", "spe"},
   {Vouchers, 0.0, 4, VOUCHERSTART, VOUCHEREND, "Spectral", "spe"},
};

char* GetPackKey(int n) {

    int sizeOfMaxChar = 9;

    char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

    if (returnCharPtr == NULL) {
        return NULL;
    }

    switch (n) {
    case 1:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "ar1");
        break;
    case 2:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "ar1");
        break;
    case 3:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "ar1");
        break;
    case 4:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "pl1");
        break;
    case 5:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "pl1");
        break;
    case 6:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "pl1");
        break;
    case 7:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "stdset");
        break;
    case 8:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "stdset");
        break;
    case 9:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "stdset");
        break;
    case 10:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "buf");
        break;
    case 11:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "buf");
        break;
    case 12:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "buf");
        break;
    case 13:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "ar2");
        break;
    case 14:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "ar2");
        break;
    case 15:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "ar2");
        break;
    default:
        strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoPack");
    }

    return returnCharPtr;
}

char* GetPackType(int n) {

    int sizeOfMaxChar = 9;

    char* returnCharPtr = malloc(sizeOfMaxChar * sizeof(char));

    if (returnCharPtr == NULL) {
        return NULL;
    }

    switch (n) {
        case 1:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Tarot");
            break;
        case 2:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Tarot");
            break;
        case 3:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Tarot");
            break;
        case 4:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Planet");
            break;
        case 5:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Planet");
            break;
        case 6:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Planet");
            break;
        case 7:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "stdset");
            break;
        case 8:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "stdset");
            break;
        case 9:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "stdset");
            break;
        case 10:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Joker");
            break;
        case 11:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Joker");
            break;
        case 12:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Joker");
            break;
        case 13:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Spectral");
            break;
        case 14:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Spectral");
            break;
        case 15:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "Spectral");
            break;
        default:
            strcpy_s(returnCharPtr, sizeOfMaxChar * sizeof(char), "NoPack");
    }

    return returnCharPtr;
}

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