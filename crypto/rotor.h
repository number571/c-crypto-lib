#pragma once

/*
	A = 'A' .. 'Z'
	M = "HELLO"
	K = {
		{1, [5, 8, 3]}
		{2, [7, 2, 4]}
	}
	E(M, K) = 
			('H' + 5 + 7) mod A = 'T'
			('E' + 8 + 7) mod A = 'T'
			('L' + 3 + 2) mod A = 'Q'
			('L' + 5 + 2) mod A = 'S'
			('O' + 8 + 4) mod A = 'A'
		C = "TTQSA"
	D(C, K) =
			('T' - 5 - 7) mod A = 'H'
			('T' - 8 - 7) mod A = 'E'
			('Q' - 3 - 2) mod A = 'L'
			('S' - 5 - 2) mod A = 'L'
			('A' - 8 - 4) mod A = 'O'
		M = "HELLO"
*/

extern char set_alpha_rotor (const unsigned char * const alpha);
extern char rotor (
	unsigned char * to, 
	const signed char mode, 
	const unsigned char period, 
	signed char * const rot, 
	const unsigned char * const from
);
