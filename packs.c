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

void PrintItem(int item) {
    switch (item) {
        case retry: printf("retry"); break;
        case JOKERSTART: printf("JOKERSTART"); break;
        case JOKER1START: printf("JOKER1START"); break;
        case j_joker: printf("j_joker"); break;
        case j_greedy_joker: printf("j_greedy_joker"); break;
        case j_lusty_joker: printf("j_lusty_joker"); break;
        case j_wrathful_joker: printf("j_wrathful_joker"); break;
        case j_gluttenous_joker: printf("j_gluttenous_joker"); break;
        case j_jolly: printf("j_jolly"); break;
        case j_zany: printf("j_zany"); break;
        case j_mad: printf("j_mad"); break;
        case j_crazy: printf("j_crazy"); break;
        case j_droll: printf("j_droll"); break;
        case j_sly: printf("j_sly"); break;
        case j_wily: printf("j_wily"); break;
        case j_clever: printf("j_clever"); break;
        case j_devious: printf("j_devious"); break;
        case j_crafty: printf("j_crafty"); break;
        case j_half: printf("j_half"); break;
        case j_credit_card: printf("j_credit_card"); break;
        case j_banner: printf("j_banner"); break;
        case j_mystic_summit: printf("j_mystic_summit"); break;
        case j_8_ball: printf("j_8_ball"); break;
        case j_misprint: printf("j_misprint"); break;
        case j_raised_fist: printf("j_raised_fist"); break;
        case j_chaos: printf("j_chaos"); break;
        case j_scary_face: printf("j_scary_face"); break;
        case j_abstract: printf("j_abstract"); break;
        case j_delayed_grat: printf("j_delayed_grat"); break;
        case j_gros_michel: printf("j_gros_michel"); break;
        case j_even_steven: printf("j_even_steven"); break;
        case j_odd_todd: printf("j_odd_todd"); break;
        case j_scholar: printf("j_scholar"); break;
        case j_business: printf("j_business"); break;
        case j_supernova: printf("j_supernova"); break;
        case j_ride_the_bus: printf("j_ride_the_bus"); break;
        case j_egg: printf("j_egg"); break;
        case j_runner: printf("j_runner"); break;
        case j_ice_cream: printf("j_ice_cream"); break;
        case j_splash: printf("j_splash"); break;
        case j_blue_joker: printf("j_blue_joker"); break;
        case j_faceless: printf("j_faceless"); break;
        case j_green_joker: printf("j_green_joker"); break;
        case j_superposition: printf("j_superposition"); break;
        case j_todo_list: printf("j_todo_list"); break;
        case j_cavendish: printf("j_cavendish"); break;
        case j_red_card: printf("j_red_card"); break;
        case j_square: printf("j_square"); break;
        case j_riff_raff: printf("j_riff_raff"); break;
        case j_photograph: printf("j_photograph"); break;
        case j_reserved_parking: printf("j_reserved_parking"); break;
        case j_mail: printf("j_mail"); break;
        case j_hallucination: printf("j_hallucination"); break;
        case j_fortune_teller: printf("j_fortune_teller"); break;
        case j_juggler: printf("j_juggler"); break;
        case j_drunkard: printf("j_drunkard"); break;
        case j_golden: printf("j_golden"); break;
        case j_popcorn: printf("j_popcorn"); break;
        case j_walkie_talkie: printf("j_walkie_talkie"); break;
        case j_smiley: printf("j_smiley"); break;
        case j_ticket: printf("j_ticket"); break;
        case j_swashbuckler: printf("j_swashbuckler"); break;
        case j_hanging_chad: printf("j_hanging_chad"); break;
        case j_shoot_the_moon: printf("j_shoot_the_moon"); break;
        case JOKER1END: printf("JOKER1END"); break;
        case JOKER2START: printf("JOKER2START"); break;
        case j_stencil: printf("j_stencil"); break;
        case j_four_fingers: printf("j_four_fingers"); break;
        case j_mime: printf("j_mime"); break;
        case j_ceremonial: printf("j_ceremonial"); break;
        case j_marble: printf("j_marble"); break;
        case j_loyalty_card: printf("j_loyalty_card"); break;
        case j_dusk: printf("j_dusk"); break;
        case j_fibonacci: printf("j_fibonacci"); break;
        case j_steel_joker: printf("j_steel_joker"); break;
        case j_hack: printf("j_hack"); break;
        case j_pareidolia: printf("j_pareidolia"); break;
        case j_space: printf("j_space"); break;
        case j_burglar: printf("j_burglar"); break;
        case j_blackboard: printf("j_blackboard"); break;
        case j_sixth_sense: printf("j_sixth_sense"); break;
        case j_constellation: printf("j_constellation"); break;
        case j_hiker: printf("j_hiker"); break;
        case j_card_sharp: printf("j_card_sharp"); break;
        case j_madness: printf("j_madness"); break;
        case j_seance: printf("j_seance"); break;
        case j_vampire: printf("j_vampire"); break;
        case j_shortcut: printf("j_shortcut"); break;
        case j_hologram: printf("j_hologram"); break;
        case j_cloud_9: printf("j_cloud_9"); break;
        case j_rocket: printf("j_rocket"); break;
        case j_midas_mask: printf("j_midas_mask"); break;
        case j_luchador: printf("j_luchador"); break;
        case j_gift: printf("j_gift"); break;
        case j_turtle_bean: printf("j_turtle_bean"); break;
        case j_erosion: printf("j_erosion"); break;
        case j_to_the_moon: printf("j_to_the_moon"); break;
        case j_stone: printf("j_stone"); break;
        case j_lucky_cat: printf("j_lucky_cat"); break;
        case j_bull: printf("j_bull"); break;
        case j_diet_cola: printf("j_diet_cola"); break;
        case j_trading: printf("j_trading"); break;
        case j_flash: printf("j_flash"); break;
        case j_trousers: printf("j_trousers"); break;
        case j_ramen: printf("j_ramen"); break;
        case j_selzer: printf("j_selzer"); break;
        case j_castle: printf("j_castle"); break;
        case j_mr_bones: printf("j_mr_bones"); break;
        case j_acrobat: printf("j_acrobat"); break;
        case j_sock_and_buskin: printf("j_sock_and_buskin"); break;
        case j_troubadour: printf("j_troubadour"); break;
        case j_certificate: printf("j_certificate"); break;
        case j_smeared: printf("j_smeared"); break;
        case j_throwback: printf("j_throwback"); break;
        case j_rough_gem: printf("j_rough_gem"); break;
        case j_bloodstone: printf("j_bloodstone"); break;
        case j_arrowhead: printf("j_arrowhead"); break;
        case j_onyx_agate: printf("j_onyx_agate"); break;
        case j_glass: printf("j_glass"); break;
        case j_ring_master: printf("j_ring_master"); break;
        case j_flower_pot: printf("j_flower_pot"); break;
        case j_merry_andy: printf("j_merry_andy"); break;
        case j_oops: printf("j_oops"); break;
        case j_idol: printf("j_idol"); break;
        case j_seeing_double: printf("j_seeing_double"); break;
        case j_matador: printf("j_matador"); break;
        case j_satellite: printf("j_satellite"); break;
        case j_cartomancer: printf("j_cartomancer"); break;
        case j_astronomer: printf("j_astronomer"); break;
        case j_bootstraps: printf("j_bootstraps"); break;
        case JOKER2END: printf("JOKER2END"); break;
        case JOKER3START: printf("JOKER3START"); break;
        case j_dna: printf("j_dna"); break;
        case j_vagabond: printf("j_vagabond"); break;
        case j_baron: printf("j_baron"); break;
        case j_obelisk: printf("j_obelisk"); break;
        case j_baseball: printf("j_baseball"); break;
        case j_ancient: printf("j_ancient"); break;
        case j_campfire: printf("j_campfire"); break;
        case j_blueprint: printf("j_blueprint"); break;
        case j_wee: printf("j_wee"); break;
        case j_hit_the_road: printf("j_hit_the_road"); break;
        case j_duo: printf("j_duo"); break;
        case j_trio: printf("j_trio"); break;
        case j_family: printf("j_family"); break;
        case j_order: printf("j_order"); break;
        case j_tribe: printf("j_tribe"); break;
        case j_stuntman: printf("j_stuntman"); break;
        case j_invisible: printf("j_invisible"); break;
        case j_brainstorm: printf("j_brainstorm"); break;
        case j_drivers_license: printf("j_drivers_license"); break;
        case j_burnt: printf("j_burnt"); break;
        case JOKER3END: printf("JOKER3END"); break;
        case JOKER4START: printf("JOKER4START"); break;
        case j_caino: printf("j_caino"); break;
        case j_triboulet: printf("j_triboulet"); break;
        case j_yorick: printf("j_yorick"); break;
        case j_chicot: printf("j_chicot"); break;
        case j_perkeo: printf("j_perkeo"); break;
        case JOKER4END: printf("JOKER4END"); break;
        case JOKEREND: printf("JOKEREND"); break;
        case CONSUMABLESTART: printf("CONSUMABLESTART"); break;
        case TAROTSTART: printf("TAROTSTART"); break;
        case c_fool: printf("c_fool"); break;
        case c_magician: printf("c_magician"); break;
        case c_high_priestess: printf("c_high_priestess"); break;
        case c_empress: printf("c_empress"); break;
        case c_emperor: printf("c_emperor"); break;
        case c_heirophant: printf("c_heirophant"); break;
        case c_lovers: printf("c_lovers"); break;
        case c_chariot: printf("c_chariot"); break;
        case c_justice: printf("c_justice"); break;
        case c_hermit: printf("c_hermit"); break;
        case c_wheel_of_fortune: printf("c_wheel_of_fortune"); break;
        case c_strength: printf("c_strength"); break;
        case c_hanged_man: printf("c_hanged_man"); break;
        case c_death: printf("c_death"); break;
        case c_temperance: printf("c_temperance"); break;
        case c_devil: printf("c_devil"); break;
        case c_tower: printf("c_tower"); break;
        case c_star: printf("c_star"); break;
        case c_moon: printf("c_moon"); break;
        case c_sun: printf("c_sun"); break;
        case c_judgement: printf("c_judgement"); break;
        case c_world: printf("c_world"); break;
        case TAROTEND: printf("TAROTEND"); break;
        case PLANETSTART: printf("PLANETSTART"); break;
        case c_mercury: printf("c_mercury"); break;
        case c_venus: printf("c_venus"); break;
        case c_earth: printf("c_earth"); break;
        case c_mars: printf("c_mars"); break;
        case c_jupiter: printf("c_jupiter"); break;
        case c_saturn: printf("c_saturn"); break;
        case c_uranus: printf("c_uranus"); break;
        case c_neptune: printf("c_neptune"); break;
        case c_pluto: printf("c_pluto"); break;
        case c_planet_x: printf("c_planet_x"); break;
        case c_ceres: printf("c_ceres"); break;
        case c_eris: printf("c_eris"); break;
        case PLANETEND: printf("PLANETEND"); break;
        case SPECTRALSTART: printf("SPECTRALSTART"); break;
        case c_familiar: printf("c_familiar"); break;
        case c_grim: printf("c_grim"); break;
        case c_incantation: printf("c_incantation"); break;
        case c_talisman: printf("c_talisman"); break;
        case c_aura: printf("c_aura"); break;
        case c_wraith: printf("c_wraith"); break;
        case c_sigil: printf("c_sigil"); break;
        case c_ouija: printf("c_ouija"); break;
        case c_ectoplasm: printf("c_ectoplasm"); break;
        case c_immolate: printf("c_immolate"); break;
        case c_ankh: printf("c_ankh"); break;
        case c_deja_vu: printf("c_deja_vu"); break;
        case c_hex: printf("c_hex"); break;
        case c_trance: printf("c_trance"); break;
        case c_medium: printf("c_medium"); break;
        case c_cryptid: printf("c_cryptid"); break;
        case c_soul: printf("c_soul"); break;
        case c_black_hole: printf("c_black_hole"); break;
        case SPECTRALEND: printf("SPECTRALEND"); break;
        case VOUCHERSTART: printf("VOUCHERSTART"); break;
        case v_overstock_norm: printf("v_overstock_norm"); break;
        case v_overstock_plus: printf("v_overstock_plus"); break;
        case v_clearance_sale: printf("v_clearance_sale"); break;
        case v_liquidation: printf("v_liquidation"); break;
        case v_hone: printf("v_hone"); break;
        case v_glow_up: printf("v_glow_up"); break;
        case v_reroll_surplus: printf("v_reroll_surplus"); break;
        case v_reroll_glut: printf("v_reroll_glut"); break;
        case v_crystal_ball: printf("v_crystal_ball"); break;
        case v_omen_globe: printf("v_omen_globe"); break;
        case v_telescope: printf("v_telescope"); break;
        case v_observatory: printf("v_observatory"); break;
        case v_grabber: printf("v_grabber"); break;
        case v_nacho_tong: printf("v_nacho_tong"); break;
        case v_wasteful: printf("v_wasteful"); break;
        case v_recyclomancy: printf("v_recyclomancy"); break;
        case v_tarot_merchant: printf("v_tarot_merchant"); break;
        case v_tarot_tycoon: printf("v_tarot_tycoon"); break;
        case v_planet_merchant: printf("v_planet_merchant"); break;
        case v_planet_tycoon: printf("v_planet_tycoon"); break;
        case v_seed_money: printf("v_seed_money"); break;
        case v_money_tree: printf("v_money_tree"); break;
        case v_blank: printf("v_blank"); break;
        case v_antimatter: printf("v_antimatter"); break;
        case v_magic_trick: printf("v_magic_trick"); break;
        case v_illusion: printf("v_illusion"); break;
        case v_hieroglyph: printf("v_hieroglyph"); break;
        case v_petroglyph: printf("v_petroglyph"); break;
        case v_directors_cut: printf("v_directors_cut"); break;
        case v_retcon: printf("v_retcon"); break;
        case v_paint_brush: printf("v_paint_brush"); break;
        case v_palette: printf("v_palette"); break;
        case VOUCHEREND: printf("VOUCHEREND"); break;
        case CONSUMABLEEND: printf("CONSUMABLEEND"); break;
        case DECKSTART: printf("DECKSTART"); break;
        case C_2: printf("C_2"); break;
        case C_3: printf("C_3"); break;
        case C_4: printf("C_4"); break;
        case C_5: printf("C_5"); break;
        case C_6: printf("C_6"); break;
        case C_7: printf("C_7"); break;
        case C_8: printf("C_8"); break;
        case C_9: printf("C_9"); break;
        case C_A: printf("C_A"); break;
        case C_J: printf("C_J"); break;
        case C_K: printf("C_K"); break;
        case C_Q: printf("C_Q"); break;
        case C_T: printf("C_T"); break;
        case D_2: printf("D_2"); break;
        case D_3: printf("D_3"); break;
        case D_4: printf("D_4"); break;
        case D_5: printf("D_5"); break;
        case D_6: printf("D_6"); break;
        case D_7: printf("D_7"); break;
        case D_8: printf("D_8"); break;
        case D_9: printf("D_9"); break;
        case D_A: printf("D_A"); break;
        case D_J: printf("D_J"); break;
        case D_K: printf("D_K"); break;
        case D_Q: printf("D_Q"); break;
        case D_T: printf("D_T"); break;
        case H_2: printf("H_2"); break;
        case H_3: printf("H_3"); break;
        case H_4: printf("H_4"); break;
        case H_5: printf("H_5"); break;
        case H_6: printf("H_6"); break;
        case H_7: printf("H_7"); break;
        case H_8: printf("H_8"); break;
        case H_9: printf("H_9"); break;
        case H_A: printf("H_A"); break;
        case H_J: printf("H_J"); break;
        case H_K: printf("H_K"); break;
        case H_Q: printf("H_Q"); break;
        case H_T: printf("H_T"); break;
        case S_2: printf("S_2"); break;
        case S_3: printf("S_3"); break;
        case S_4: printf("S_4"); break;
        case S_5: printf("S_5"); break;
        case S_6: printf("S_6"); break;
        case S_7: printf("S_7"); break;
        case S_8: printf("S_8"); break;
        case S_9: printf("S_9"); break;
        case S_A: printf("S_A"); break;
        case S_J: printf("S_J"); break;
        case S_K: printf("S_K"); break;
        case S_Q: printf("S_Q"); break;
        case S_T: printf("S_T"); break;
        case DECKEND: printf("DECKEND"); break;
        case EDITIONSTART: printf("EDITIONSTART"); break;
        case negative: printf("negative"); break;
        case polychrome: printf("polychrome"); break;
        case holo: printf("holo"); break;
        case foil: printf("foil"); break;
        case EDITIONEND: printf("EDITIONEND"); break;
        case SEALSTART: printf("SEALSTART"); break;
        case s_red: printf("s_red"); break;
        case s_blue: printf("s_blue"); break;
        case s_gold: printf("s_gold"); break;
        case s_purple: printf("s_purple"); break;
        case SEALEND: printf("SEALEND"); break;
        case BONUSSTART: printf("BONUSSTART"); break;
        case bonusCard: printf("bonusCard"); break;
        case multCard: printf("multCard"); break;
        case wildCard: printf("wildCard"); break;
        case glassCard: printf("glassCard"); break;
        case steelCard: printf("steelCard"); break;
        case stoneCard: printf("stoneCard"); break;
        case goldCard: printf("goldCard"); break;
        case luckyCard: printf("luckyCard"); break;
        case BONUSEND: printf("BONUSEND"); break;
        case TAGSTART: printf("TAGSTART"); break;
        case Uncommon_Tag: printf("Uncommon_Tag"); break;
        case Rare_Tag: printf("Rare_Tag"); break;
        case Negative_Tag: printf("Negative_Tag"); break;
        case Foil_Tag: printf("Foil_Tag"); break;
        case Holographic_Tag: printf("Holographic_Tag"); break;
        case Polychrome_Tag: printf("Polychrome_Tag"); break;
        case Investment_Tag: printf("Investment_Tag"); break;
        case Voucher_Tag: printf("Voucher_Tag"); break;
        case Boss_Tag: printf("Boss_Tag"); break;
        case Standard_Tag: printf("Standard_Tag"); break;
        case Charm_Tag: printf("Charm_Tag"); break;
        case Meteor_Tag: printf("Meteor_Tag"); break;
        case Buffoon_Tag: printf("Buffoon_Tag"); break;
        case Handy_Tag: printf("Handy_Tag"); break;
        case Garbage_Tag: printf("Garbage_Tag"); break;
        case Ethereal_Tag: printf("Ethereal_Tag"); break;
        case Coupon_Tag: printf("Coupon_Tag"); break;
        case Double_Tag: printf("Double_Tag"); break;
        case Juggle_Tag: printf("Juggle_Tag"); break;
        case D6_Tag: printf("D6_Tag"); break;
        case Topup_Tag: printf("Topup_Tag"); break;
        case Skip_Tag: printf("Skip_Tag"); break;
        case Orbital_Tag: printf("Orbital_Tag"); break;
        case Economy_Tag: printf("Economy_Tag"); break;
        case TAGEND: printf("TAGEND"); break;
        case BOSSSTART: printf("BOSSSTART"); break;
        case The_Arm: printf("The_Arm"); break;
        case The_Club: printf("The_Club"); break;
        case The_Eye: printf("The_Eye"); break;
        case Amber_Acorn: printf("Amber_Acorn"); break;
        case Cerulean_Bell: printf("Cerulean_Bell"); break;
        case Crimson_Heart: printf("Crimson_Heart"); break;
        case Verdant_Leaf: printf("Verdant_Leaf"); break;
        case Violet_Vessel: printf("Violet_Vessel"); break;
        case The_Fish: printf("The_Fish"); break;
        case The_Flint: printf("The_Flint"); break;
        case The_Goad: printf("The_Goad"); break;
        case The_Head: printf("The_Head"); break;
        case The_Hook: printf("The_Hook"); break;
        case The_House: printf("The_House"); break;
        case The_Manacle: printf("The_Manacle"); break;
        case The_Mark: printf("The_Mark"); break;
        case The_Mouth: printf("The_Mouth"); break;
        case The_Needle: printf("The_Needle"); break;
        case The_Ox: printf("The_Ox"); break;
        case The_Pillar: printf("The_Pillar"); break;
        case The_Plant: printf("The_Plant"); break;
        case The_Psychic: printf("The_Psychic"); break;
        case The_Serpent: printf("The_Serpent"); break;
        case The_Tooth: printf("The_Tooth"); break;
        case The_Wall: printf("The_Wall"); break;
        case The_Water: printf("The_Water"); break;
        case The_Wheel: printf("The_Wheel"); break;
        case The_Window: printf("The_Window"); break;
        case BOSSEND: printf("BOSSEND"); break;
        case SUITSTART: printf("SUITSTART"); break;
        case SPADES: printf("SPADES"); break;
        case HEARTS: printf("HEARTS"); break;
        case DIAMONDS: printf("DIAMONDS"); break;
        case CLUBS: printf("CLUBS"); break;
        case SUITEND: printf("SUITEND"); break;
        default: printf("NO ITEM FOUND!!!");
    }
}