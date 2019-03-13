#pragma once

#include <stdint.h>

static inline uint64_t _expmod (uint64_t x, uint64_t y, uint64_t q) {
	uint64_t result = 1;

	for (uint64_t bit = 1; bit <= y; bit *= 2) {
		if (bit & y)
			result = (result * x) % q;
		x = (x * x) % q;
	}

	return result;
}
