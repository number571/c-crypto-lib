#pragma once

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

extern char set_alpha_caesar_wordkey (const unsigned char * const alpha);
extern char caesar_wordkey (
	unsigned char * to, 
	const signed char mode, 
	signed char nkey, 
	unsigned char * const skey,
	const unsigned char * from
);
