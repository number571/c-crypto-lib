#pragma once

#include <stdint.h>

#include "determinant.h"

#include "../types/integer.h"

static inline int __inc_power (int x, int y) {
	int mul = 1;
	while (y-- > 0)
		mul *= x;
	return mul;
}

static __INTEGER__ __algebraic_addition (const uint8_t x, const uint8_t y, uint8_t * key, const uint8_t sqrt, const __INTEGER__ det, const uint8_t length) {
	__INTEGER__ matrix[4];
	__INTEGER__ *p_matrix = matrix;

	for (uint8_t a = 0; a < sqrt; ++a) {
		if (a == x)
			continue;
		for (uint8_t b = 0; b < sqrt; ++b) {
			if (b == y)
				continue;
			*p_matrix++ = key[a * sqrt + b];
		}
	}

	const __INTEGER__ det2x2 = matrix[0 * 2 + 0] * matrix[1 * 2 + 1] - matrix[0 * 2 + 1] * matrix[1 * 2 + 0];
	const __INTEGER__ result = __inc_power(-1, x + y) * det2x2 * _inverse_determinant(det, length) % length;

	if (result < 0)
		return length + result;

	return result;
}

static inline void _algebraic (uint8_t * algbrs, uint8_t * key, const uint8_t sqrt, const __INTEGER__ det, const uint8_t length) {
	for (uint8_t x = 0; x < sqrt; ++x)
		for (uint8_t y = 0; y < sqrt; ++y)
			*algbrs++ = __algebraic_addition(x, y, key, sqrt, det, length);
}
