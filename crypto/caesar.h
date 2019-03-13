#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z'
	M = "HELLO"
	K = 3
	E(M, K) = 
			('H' + 3) mod A = 'K'
			('E' + 3) mod A = 'H'
			('L' + 3) mod A = 'O'
			('O' + 3) mod A = 'R'
		C = "KHOOR"
	D(C, K) = 
			('K' - 3) mod A = 'H'
			('H' - 3) mod A = 'E'
			('O' - 3) mod A = 'L'
			('R' - 3) mod A = 'O'
		M = "HELLO"

*/

extern char set_alpha_caesar (const uint8_t * const alpha);
extern char caesar (
	uint8_t * to, 
	const int8_t mode, 
	uint8_t nkey, 
	const uint8_t * from
);
