#pragma once

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

extern char set_alpha_substitute (const unsigned char * const alph1, const unsigned char * const alph2);
extern char substitute (
	unsigned char * to, 
	const signed char mode, 
	unsigned char * const from
);
