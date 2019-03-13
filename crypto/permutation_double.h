#pragma once

#include <stdint.h>

/*
	M = "HELLO, WORLD!"
	K1 = "HOME"
	K2 = "KEY"
	E(M,K1,K2) = 
		1.
			H O M E
			- - - -
			H E L L
			O ,   W
			O R L D
			! 
			  + X X X
		2.
			K1 = SORT(K1)
				E H M O
				- - - -
				L H L E
				W O   ,
				D O L R
				X ! X X
			C = "LWDXHOO!L LXE,RX"
		3.
			K | L X O   E X
			E | W H ! L ,   + Z
			Y | D O L X R     Z
		4.
			K2 = SORT(K2)
				E | W H ! L , Z
				K | L X O   E X
				Y | D O L X R Z
		C = "WLDHXO!OLL X,ERZXZ"

	D(C,K1,K2) = 
		1.
			K2 = SORT(K2)
				E | W H ! L , Z
				K | L X O   E X
				Y | D O L X R Z
		2.
			K2 = BACK(K2)
				K | L X O   E X
				E | W H ! L , Z
				Y | D O L X R Z
			C = "LWDXHOO!L LXE,RXZZ"
		3.
			K1 = SORT(K1)
				E H M O
				- - - -
				L H L E
				W O   ,
				D O L R
				X ! X X
					- Z Z
		4.
			K1 = BACK(K1)
				H O M E
				- - - -
				H E L L
				O ,   W
				O R L D
				! X X X
		M = "HELLO, WORLD!XXX"
*/

extern char set_char_permutation_double (const uint8_t ch1, const uint8_t ch2);
extern char permutation_double (
	uint8_t * const to,
	const int8_t mode,
	uint8_t * const key1,
	uint8_t * const key2,
	const uint8_t * const from
);
