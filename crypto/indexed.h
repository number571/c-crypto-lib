#pragma once

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

extern void to_string_indexed (unsigned char * const to, const signed char * from);
extern void to_bytes_indexed (signed char * to, const unsigned char * from);
extern char indexed (
	signed char * to,
	const signed char mode,
	unsigned char * key,
	const signed char * from
);
