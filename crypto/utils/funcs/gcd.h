#pragma once

#include <stdint.h>

static inline uint64_t _gcd (uint64_t x, uint64_t y) {
	uint64_t z;

	while (x != 0) {
		z = x;
		x = y % x;
		y = z;
	}
	
	return y;
}
