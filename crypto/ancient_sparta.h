#pragma once

/*
	M = "HELLO"
	K = 3
	E(M, K) = 
		I. "HELLO" + "Z" = "HELLOZ"
		II. 
			1 - 'H' 'E'
			2 - 'L' 'L'
			3 - 'O' 'Z'
		"HLO" + "ELZ"
		C = "HLOELZ"
	D(C, K) =
			1 - 'H' 'E'
			2 - 'L' 'L'
			3 - 'O' 'Z'
		"HE" + "LL" + "OZ"
		M = "HELLOZ"
*/

extern void set_char_ancient_sparta (const unsigned char ch);
extern char ancient_sparta (
	unsigned char * const to, 
	const signed char mode, 
	const unsigned char key, 
	const unsigned char * const from
);
