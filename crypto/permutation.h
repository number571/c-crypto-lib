#pragma once

#include <stdint.h>

/*
	M = "HELLO"
	K = "HOME"
	E(M,K) = 
		1.
			H O M E
			- - - -
			H E L L
			O 
			+ X X X

		2.
			K = SORT(K)
				E H M O
				- - - -
				L H L E
				X O X X
		C = "LXHOLXEX"
	D(C,K) = 
		1.
			K = SORT(K)
				E H M O
				- - - -
				L H L E
				X O X X
		2.
			K = BACK(K)
				H O M E
				- - - -
				H E L L
				O X X X
		M = "HELLOXXX"
*/

extern char set_char_permutation (const uint8_t ch);
extern char permutation (
	uint8_t * const to,
	const int8_t mode,
	uint8_t * const key,
	const uint8_t * const from
);
