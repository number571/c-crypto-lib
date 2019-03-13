#pragma once

#include <stdint.h>

/*
	A[1] = "ACEGIKMOQSUWY"
	A[2] = "BDFHJLNPRTVXZ"
		(
			A[1] <-> A[2]
		)
	M = "HELLO"
	E(M) = 
			'H' = 'G'
			'E' = 'F'
			'L' = 'K'
			'O' = 'P'
		C = "GFKKP"
	E(C) = 
			'G' = 'H'
			'F' = 'E'
			'K' = 'L'
			'P' = 'O'
		M = "HELLO"
*/

extern char set_alpha_couple (uint8_t * const alph1, uint8_t * const alph2);
extern char couple (
	uint8_t * to, 
	const uint8_t * from
);
