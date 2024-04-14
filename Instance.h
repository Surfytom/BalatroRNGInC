#pragma once

typedef struct Instance {
	char** locked;
	char* seed;
	double* hashedSeed;

} Instance;


/*

psedo hash the seed and save the original seed and hashed seed
	if erratic deck start pseudorandom the deck


*/

const char** BASE_DECK[52] = {
	"H_2",
	"H_3",
	"H_4",
	"H_5",
	"H_6",
	"H_7",
	"H_8",
	"H_9",
	"H_T",
	"H_J",
	"H_Q",
	"H_K",
	"H_A",
	"C_2",
	"C_3",
	"C_4",
	"C_5",
	"C_6",
	"C_7",
	"C_8",
	"C_9",
	"C_T",
	"C_J",
	"C_Q",
	"C_K",
	"C_A",
	"D_2",
	"D_3",
	"D_4",
	"D_5",
	"D_6",
	"D_7",
	"D_8",
	"D_9",
	"D_T",
	"D_J",
	"D_Q",
	"D_K",
	"D_A",
	"S_2",
	"S_3",
	"S_4",
	"S_5",
	"S_6",
	"S_7",
	"S_8",
	"S_9",
	"S_T",
	"S_J",
	"S_Q",
	"S_K",
	"S_A",
};
