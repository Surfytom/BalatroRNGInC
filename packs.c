#include "packs.h"

char NUMOFPACKS = 16;

weighteditem PACKS[19] = {
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
   {Vouchers, 0.0, 1, VOUCHERSTART, VOUCHEREND, "Voucher", ""},
   {VouchersFromTag, 0.0, 1, VOUCHERSTART, VOUCHEREND, "Voucher_fromtag", ""},
   {Tags, 0.0, 1, TAGSTART, TAGEND, "Tag", ""},
};

Voucher VOUCHERS[32] = {
    {v_overstock_norm, -1},
    {v_overstock_plus, v_overstock_norm},
    {v_clearance_sale, -1},
    {v_liquidation, v_clearance_sale},
    {v_hone, -1},
    {v_glow_up, v_hone},
    {v_reroll_surplus, -1},
    {v_reroll_glut, v_reroll_surplus},
    {v_crystal_ball, -1},
    {v_omen_globe, v_crystal_ball},
    {v_telescope, -1},
    {v_observatory, v_telescope},
    {v_grabber, -1},
    {v_nacho_tong, v_grabber},
    {v_wasteful, -1},
    {v_recyclomancy, v_wasteful},
    {v_tarot_merchant, -1},
    {v_tarot_tycoon, v_tarot_merchant},
    {v_planet_merchant, -1},
    {v_planet_tycoon, v_planet_merchant},
    {v_seed_money, -1},
    {v_money_tree, v_seed_money},
    {v_blank, -1},
    {v_antimatter, v_blank},
    {v_magic_trick, -1},
    {v_illusion, v_magic_trick},
    {v_hieroglyph, -1},
    {v_petroglyph, v_hieroglyph},
    {v_directors_cut, -1},
    {v_retcon, v_directors_cut},
    {v_paint_brush, -1},
    {v_palette, v_paint_brush},
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