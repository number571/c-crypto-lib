#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z'
	M = "HELLO"
	K = lambda x: x * 2 + 1
	E(M, K) = 
			('H' + (K(0) = 0 * 2 + 1 = 1)) mod A = 'I'
			('E' + (K(1) = 1 * 2 + 1 = 3)) mod A = 'H'
			('L' + (K(2) = 2 * 2 + 1 = 5)) mod A = 'Q'
			('L' + (K(3) = 3 * 2 + 1 = 7)) mod A = 'S'
			('O' + (K(4) = 4 * 2 + 1 = 9)) mod A = 'X'
		C = "IHQSX"
	D(M, K) =
			('I' + (K(0) = 0 * 2 + 1 = 1)) mod A = 'H'
			('H' + (K(1) = 1 * 2 + 1 = 3)) mod A = 'E'
			('Q' + (K(2) = 2 * 2 + 1 = 5)) mod A = 'L'
			('S' + (K(3) = 3 * 2 + 1 = 7)) mod A = 'L'
			('X' + (K(4) = 4 * 2 + 1 = 9)) mod A = 'O'
		M = "HELLO"
*/

extern char set_alpha_trithemius (const uint8_t * const alpha);
extern char trithemius (
	uint8_t * to, 
	const int8_t mode, 
	int8_t (* const key) (const int8_t x), 
	uint8_t * const from
);
