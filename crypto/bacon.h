#pragma once

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

extern void set_char_bacon  (const unsigned char ch1, const unsigned char ch2);
extern char set_alpha_bacon (const unsigned char * const alpha);
extern void to_string_bacon (unsigned char * to, signed char * const from);
extern void to_bytes_bacon  (signed char * to, const unsigned char * from);
extern void print_bacon     (const signed char * from);
extern void println_bacon   (const signed char * from);
extern char bacon (
	signed char * const to, 
	const signed char mode, 
	const signed char * const from
);
