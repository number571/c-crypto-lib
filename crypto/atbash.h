#pragma once

/*
	A = 'A' .. 'Z'
	M = 'A' .. 'Z'
	C = 'Z' .. 'A'
*/

extern char set_alpha_atbash (const unsigned char * const alpha);
extern char atbash (
	unsigned char * to,
	const unsigned char * from
);
