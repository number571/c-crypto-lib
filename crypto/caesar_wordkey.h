#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z'
	M = "HELLO"
	K[n] = 3
	K[s] = "WORLD"
	E(M, K[n], K[s]) =
		A' = (K[s] + (A - K[s])) >> K[n] = ("WORLD" + "ABCEFGHIJKMNPQSTUVXYZ") >> K[n]
			= "WORLDABCEFGHIJKMNPQSTUVXYZ" >> 3 = "XYZWORLDABCEFGHIJKMNPQSTUV"
		A  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		A' = "XYZWORLDABCEFGHIJKMNPQSTUV"
			'H' = 'D'
			'E' = 'O'
			'L' = 'E'
			'O' = 'H'
		C = "DOEEH"
	D(C, K[n], K[s]) = 
		A' = (K[s] + (A - K[s])) >> K[n] = ("WORLD" + "ABCEFGHIJKMNPQSTUVXYZ") >> K[n]
			= "WORLDABCEFGHIJKMNPQSTUVXYZ" >> 3 = "XYZWORLDABCEFGHIJKMNPQSTUV"
		A' = "XYZWORLDABCEFGHIJKMNPQSTUV"
		A  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			'D' = 'H'
			'O' = 'E'
			'E' = 'L'
			'H' = 'O'
		M = "HELLO"
*/

extern char set_alpha_caesar_wordkey (const uint8_t * const alpha);
extern char caesar_wordkey (
	uint8_t * to, 
	const int8_t mode, 
	int8_t nkey, 
	uint8_t * const skey,
	const uint8_t * from
);
