#pragma once

/*
	M = 'A' .. 'Z'
	C =  1  .. 26
*/

extern void to_string_a1z26 (unsigned char * const to, const signed char * from);
extern void to_bytes_a1z26 (signed char * to, const unsigned char * from);
extern char a1z26 (
	signed char * to, 
	const signed char mode, 
	const signed char * from
);
