#pragma once

#include <stdint.h>
#include <stddef.h>

#include "utils/types/integer.h"

/*
	M = "HELLO"
	K = "WORLD"
	E(M, K) = 
			('H' = 72) ^ 'W' = 31
			('E' = 69) ^ 'O' = 10
			('L' = 76) ^ 'R' = 30
			('L' = 76) ^ 'L' = 76
			('O' = 79) ^ 'D' = 11
		C = 31 10 30 76 11
	D(C, K) = 
			31 ^ 'W' = 72
			10 ^ 'O' = 69
			30 ^ 'R' = 76
			76 ^ 'L' = 76
			11 ^ 'D' = 79
		M = "HELLO"
*/

extern char xor_wordkey (
	__INTEGER__ * to, 
	uint8_t * const key,
	const size_t length,
	const __INTEGER__ * from
);
