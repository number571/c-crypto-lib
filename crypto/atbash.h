#pragma once

#include <stdint.h>

/*
	A = 'A' .. 'Z'
	M = 'A' .. 'Z'
	C = 'Z' .. 'A'
*/

extern char set_alpha_atbash (const uint8_t * const alpha);
extern char atbash (
	uint8_t * to,
	const uint8_t * from
);
