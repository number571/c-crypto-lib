#pragma once

#include <stdint.h>

static void _transpose (uint8_t * matrix, const uint8_t length) {
	uint8_t trans[length * length];

	for (uint8_t x = 0; x < length; ++x)
		for (uint8_t y = 0; y < length; ++y)
			trans[y * length + x] = matrix[x * length + y];

	const size_t matrix_size = length * length;
	uint8_t *p_trans = trans;
	uint8_t *p_matrix = matrix;

	while ((p_trans - trans) < matrix_size)
		*p_matrix++ = *p_trans++;
}
