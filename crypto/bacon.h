#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z' 
		(
			C1 = ('A' = 0)
			C2 = ('B' = 1)
		)
	M = "HELLO"
	E(M) = 
			'H' = "AAAAABBB"
			'E' = "AAAAABAA"
			'L' = "AAAABABB"
			'O' = "AAAABBBA"
		C = "AAAAABBBAAAAABAAAAAABABBAAAABABBAAAABBBA"
	D(C) =
			"AAAAABBB" = 'H'
			"AAAAABAA" = 'E'
			"AAAABABB" = 'L'
			"AAAABBBA" = 'O'
		M = "HELLO"
*/

extern void set_char_bacon  (const uint8_t ch1, const uint8_t ch2);
extern char set_alpha_bacon (const uint8_t * const alpha);
extern void to_string_bacon (uint8_t * to, int8_t * const from);
extern void to_bytes_bacon  (int8_t * to, const uint8_t * from);
extern void print_bacon     (const int8_t * from);
extern void println_bacon   (const int8_t * from);
extern char bacon (
	int8_t * const to, 
	const int8_t mode, 
	const int8_t * const from
);
