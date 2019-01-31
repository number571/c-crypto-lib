#pragma once

#include "inc_power.h"
#include "get_determinant.h"

#include "../types/char.h"
#include "../types/integer.h"

static INTEGER_TYPE algebraic (const uchar_t x, const uchar_t y, uchar_t * key, const uchar_t sqrt, const INTEGER_TYPE det, const uchar_t length) {
	INTEGER_TYPE matrix[4];
	INTEGER_TYPE *p_matrix = matrix;

	for (uchar_t a = 0; a < sqrt; ++a) {
		if (a == x)
			continue;
		for (uchar_t b = 0; b < sqrt; ++b) {
			if (b == y)
				continue;
			*p_matrix++ = key[a * sqrt + b];
		}
	}

	const INTEGER_TYPE det2x2 = matrix[0 * 2 + 0] * matrix[1 * 2 + 1] - matrix[0 * 2 + 1] * matrix[1 * 2 + 0];
	const INTEGER_TYPE result = inc_power(-1, x + y) * det2x2 * get_inverse_determinant(det, length) % length;
	
	if (result < 0)
		return length + result;

	return result;
}

static inline void get_algebraic_additions (uchar_t * algbrs, uchar_t * key, const uchar_t sqrt, const INTEGER_TYPE det, const uchar_t length) {
	for (uchar_t x = 0; x < sqrt; ++x)
		for (uchar_t y = 0; y < sqrt; ++y)
			*algbrs++ = algebraic(x, y, key, sqrt, det, length);
}
