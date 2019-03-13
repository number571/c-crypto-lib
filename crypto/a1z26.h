#pragma once

#include <stdint.h>

/*
	M = 'A' .. 'Z'
	C =  1  .. 26
*/

extern void to_string_a1z26 (uint8_t * const to, const int8_t * from);
extern void to_bytes_a1z26 (int8_t * to, const uint8_t * from);
extern char a1z26 (
	int8_t * to, 
	const int8_t mode, 
	const int8_t * from
);
