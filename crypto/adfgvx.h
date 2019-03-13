#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z' + '0' .. '9'
	M = "HELLO"
	K = "HOME"
	E(M, K) =
		I. 
				    A D F G V X
				    - - - - - -
				A | A B C D E F
				D | G H I J K L
				F | M N O P Q R 
				G | S T U V W X
				V | Y Z 0 1 2 3
				X | 4 5 6 7 8 9
			C = "DD AV DX DX FF"
		II.
				H O M E
				- - - -
				D D A V
				D X D X
				F F 
					+ X X
		III. 
			K = SORT(K)
				E H M O
				- - - -
				V D A D
				X D D X
				X F X F
		C = "VXXDDFADXDXF"
	D(C, K) = 
		I.
			K = SORT(K)
				E H M O
				- - - -
				V D A D
				X D D X
				X F X F
		II.
			K = BACK(K)
				H O M E
				- - - -
				D D A V
				D X D X
				F F X X
			C = "DD AV DX DX FF XX"
		III.
			    	A D F G V X
				    - - - - - -
				A | A B C D E F
				D | G H I J K L
				F | M N O P Q R 
				G | S T U V W X
				V | Y Z 0 1 2 3
				X | 4 5 6 7 8 9
		M = "HELLO9"
*/

extern char set_char_adfgvx  (const uint8_t ch);
extern char set_alpha_adfgvx (const uint8_t * const alph1, const uint8_t * const alph2);
extern char adfgvx (
	uint8_t * const to,
	const int8_t mode,
	uint8_t * const key,
	const uint8_t * const from
);
