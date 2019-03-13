#pragma once

#include <stdint.h>

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

extern void set_char_ancient_sparta (const uint8_t ch);
extern char ancient_sparta (
	uint8_t * const to, 
	const int8_t mode, 
	const uint8_t key, 
	const uint8_t * const from
);
