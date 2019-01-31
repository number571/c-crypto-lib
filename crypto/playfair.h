#pragma once

/*
	A = 'A' .. 'Z' (without 'J')
	M = "HELLO"
	K = "WORLD"
	E(M, K) =
		A' = (K + (A - K)) mod (sqrt A) =
			[ 
			  [W O R L D]
			  [A B C E F]
			  [G H I K M]
			  [N P Q S T]
			  [U V X Y Z] 
			]
		I. 	IF CoupleSymbols in "HELLO": INSERT 'X'
			(
				"HELXLO"
			)
		II. IF ("HELXLO" mod 2) = 1: APPEND 'X'
		III. "HE" + "LX" + "LO"
		IV. 
			'H' + 'E' [square] = 'B' + 'K'
			'L' + 'X' [square] = 'Y' + 'R'
			'L' + 'O' [line+1] = 'D' + 'R'
		"BK" + "YR" + "DR"
		C = "BKYRDR"
	D(C, K) =
		A' = (K + (A - K)) mod (sqrt A) =
			[ 
			  [W O R L D]
			  [A B C E F]
			  [G H I K M]
			  [N P Q S T]
			  [U V X Y Z] 
			]
		I. "BK" + "YR" + "DR"
		II.	
			'B' + 'K' [square] = 'H' + 'E'
			'Y' + 'R' [square] = 'L' + 'X'
			'D' + 'R' [line-1] = 'L' + 'O'
		"HE" + "LX" + "LO"
		M = "HELXLO"
*/

extern void set_char_playfair (const unsigned char ch);
extern char set_alpha_playfair (const unsigned char * const alpha);
extern char playfair (
	unsigned char * to,
	const signed char mode,
	unsigned char * const key,
	const unsigned char * const from
);
