#pragma once

#include <stdint.h>

/*
	A[1] = 'A' .. 'Z'
	A[2] = 'z' .. 'a'
	M = "HELLO"
	E(M) = 
			'H' = 'r'
			'E' = 'u'
			'L' = 'n'
			'O' = 'k'
		C = "runnk"
	D(C) = 
			'r' = 'H'
			'u' = 'E'
			'n' = 'L'
			'k' = 'O'
		M = "HELLO"
*/

extern char set_alpha_substitution (const uint8_t * const alph1, const uint8_t * const alph2);
extern char substitution (
	uint8_t * to, 
	const int8_t mode, 
	uint8_t * const from
);
