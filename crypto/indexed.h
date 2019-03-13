#pragma once

#include <stdint.h>

/*
	M = "OHLEHELLO"
	E(M) =
			'O' = 0
			'H' = 1
			'L' = 2
			'E' = 3
		C = 0 1 2 3 1 3 2 2 0
		K = "OHLE"
	D(C, K) = 
			0 = 'O'
			1 = 'H'
			2 = 'L'
			3 = 'E'
		M = "OHLEHELLO"
*/

extern void to_string_indexed (uint8_t * const to, const int8_t * from);
extern void to_bytes_indexed (int8_t * to, const uint8_t * from);
extern char indexed (
	int8_t * to,
	const int8_t mode,
	uint8_t * key,
	const int8_t * from
);
