#pragma once

/*
	A = ('A' .. 'Z') mod (sqrt 'A' .. 'Z') =
		  1 2 3 4 5 6
		1 A B C D E F
		2 G H I J K L
		3 M N O P Q R
		4 S T U V W X
		5 Y Z * * * *
		6 * * * * * *
	M = "HELLO"
	E(M) = 
			'H' = 2 2
			'E' = 1 5
			'L' = 2 6
			'O' = 3 3
		C = 22 15 26 26 33
	D(C) =
			2 2 = 'H'
			1 5 = 'E'
			2 6 = 'L'
			3 3 = 'O'
		M = "HELLO"
*/

extern char set_alpha_polybius (const unsigned char * const alpha);
extern void to_string_polybius (unsigned char * const to, const signed char * from);
extern void to_bytes_polybius (signed char * to, const unsigned char * from);
extern char polybius (
	signed char * const to, 
	const signed char mode, 
	const signed char * const from
);
