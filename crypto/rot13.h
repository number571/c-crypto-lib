#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z'
	M = "HELLO"
	E(M) = 
			('H' + 13) mod A = 'U'
			('E' + 13) mod A = 'R'
			('L' + 13) mod A = 'Y'
			('O' + 13) mod A = 'B'
		C = "URYYB"
	E(C) =
			('U' + 13) mod A = 'H'
			('R' + 13) mod A = 'E'
			('Y' + 13) mod A = 'L'
			('B' + 13) mod A = 'O'
		M = "HELLO"
*/

extern char rot13 (
	uint8_t * to, 
	const uint8_t * from
);
