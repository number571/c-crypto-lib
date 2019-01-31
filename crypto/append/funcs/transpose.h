#pragma once

#include "../types/char.h"

static void transpose(uchar_t * matrix, const uchar_t sqrt) {
	uchar_t trans[sqrt * sqrt];

	for (uchar_t x = 0; x < sqrt; ++x)
		for (uchar_t y = 0; y < sqrt; ++y)
			trans[y * sqrt + x] = matrix[x * sqrt + y];

	const size_t matrix_size = sqrt * sqrt;
	uchar_t *p_trans = trans;
	uchar_t *p_matrix = matrix;

	while ((p_trans - trans) < matrix_size)
		*p_matrix++ = *p_trans++;
}
