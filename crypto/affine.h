#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z'
	M = "HELLO"
	K1 = 3
	K2 = 4
	E(M,K1,K2) = 
			(K1 * 'H' + K2) mod A = 'Z'
			(K1 * 'E' + K2) mod A = 'Q'
			(K1 * 'L' + K2) mod A = 'L'
			(K1 * 'O' + K2) mod A = 'U'
		C = "ZQLLU"
	D(C,K1,K2) = 
		K^(-1) = 9
			(K1^(-1) * ('Z' - K2)) mod A = 'H'
			(K1^(-1) * ('Q' - K2)) mod A = 'E'
			(K1^(-1) * ('L' - K2)) mod A = 'L'
			(K1^(-1) * ('U' - K2)) mod A = 'O'
		M = "HELLO"
*/

extern char set_alpha_affine (const uint8_t * const alpha);
extern char affine (
	uint8_t * to, 
	const int8_t mode, 
	uint8_t key1, 
	const uint8_t key2,
	const uint8_t * from
);
