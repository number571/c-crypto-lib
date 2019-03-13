#pragma once

#include <stdint.h>

/*
	A = 'A'..'Z'
	M = "HELLO"
	K = RANDOM, len(K) = len(M)
	E(M, K) =
		'H' + K[0] = C[0]
		'E' + K[1] = C[1]
		'L' + K[2] = C[2]
		'L' + K[3] = C[3]
		'O' + K[4] = C[4]
	D(C, K) =
		C[0] - K[0] = 'H'
		C[1] - K[1] = 'E'
		C[2] - K[2] = 'L'
		C[3] - K[3] = 'L'
		C[4] - K[4] = 'O'
	M = "HELLO"
*/

extern char set_alpha_vernam (const uint8_t * const alpha);
extern char vernam (
	uint8_t * to, 
	const int8_t mode,
	uint8_t * const key, 
	uint8_t * const from
);
