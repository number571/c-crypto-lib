#pragma once

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

extern char set_alpha_caesar (const unsigned char * const alpha);
extern char caesar (
	unsigned char * to, 
	const signed char mode, 
	signed char nkey, 
	const unsigned char * from
);
