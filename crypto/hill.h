#pragma once

#include <stdint.h>

/*
	A = 'A'..'Z'
	M = "HELLO" + 'Z'
	K = "GYBNQKURP"
	len(MATRIX) = 3
	E(M, K) = 
			( G Y B )   ( H )   (  6 24  1 )   (  7 )   ( 19 )
			( N Q K ) * ( E ) = ( 13 16 10 ) * (  4 ) = (  5 ) 
			( U R P )   ( L )   ( 20 17 15 )   ( 11 )   (  9 )

			( G Y B )   ( L )   (  6 24  1 )   ( 11 )   ( 11 )
			( N Q K ) * ( O ) = ( 13 16 10 ) * ( 14 ) = ( 19 )
			( U R P )   ( Z )   ( 20 17 15 )   ( 25 )   (  1 )
		C = 19 5 9 11 19 1 = "TFJLTB"
	D(C, K) = 
			(  6 24  1 ) -1   (  8  5 10 )
			( 13 16 10 )    = ( 21  8 21 )
			( 20 17 15 )      ( 21 12  8 )

			(  8  5 10 )   ( 19 )   (  7 )
			( 21  8 21 ) * (  5 ) = (  4 )
			( 21 12  8 )   (  9 )   ( 11 )

			(  8  5 10 )   ( 11 )   ( 11 )
			( 21  8 21 ) * ( 19 ) = ( 14 )
			( 21 12  8 )   (  1 )   ( 25 )
		M = 7 4 11 11 14 25 = "HELLOZ"
*/

extern void set_char_hill (const uint8_t ch);
extern char set_alpha_hill (const uint8_t * const alpha);
extern char hill (
	uint8_t * to,
	const int8_t mode,
	uint8_t * key,
	uint8_t * from
);
