#pragma once

/*
	A = ('A' .. 'O') * ('A' .. 'O') = 
		A B C D E F G H I J K L M N O
		B C D E F G H I J K L M N O A
		C D E F G H I J K L M N O A B
		D E F G H I J K L M N O A B C
		E F G H I J K L M N O A B C D
		F G H I J K L M N O A B C D E
		G H I J K L M N O A B C D E F
		H I J K L M N O A B C D E F G
		I J K L M N O A B C D E F G H
		J K L M N O A B C D E F G H I
		K L M N O A B C D E F G H I J
		L M N O A B C D E F G H I J K
		M N O A B C D E F G H I J K L
		N O A B C D E F G H I J K L M
		O A B C D E F G H I J K L M N
	M = "HELLO"
	K = "BEEF"
	E(M, K) = 
			('H' + 'B') mod A = 'I'
			('E' + 'E') mod A = 'I'
			('L' + 'E') mod A = 'A'
			('L' + 'F') mod A = 'B'
			('O' + 'B') mod A = 'A'
		C = "IIABA"
	D(C, K) = 
			('I' - 'B') mod A = 'H'
			('I' - 'E') mod A = 'E'
			('A' - 'E') mod A = 'L'
			('B' - 'F') mod A = 'L'
			('A' - 'B') mod A = 'O'
		M = "HELLO"
*/

extern char set_alpha_vigenere (const unsigned char * const alpha);
extern char vigenere (
	unsigned char * to,
	const signed char mode,
	const unsigned char * const key,
	unsigned char * const from
);
