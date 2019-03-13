#pragma once

#include <stdint.h>
#include <string.h>

static void _index_vector (uint8_t * const indexed, uint8_t * const vector, uint8_t * const sorted, const size_t length) {
	uint8_t checked[length];
	memset(checked, 0, length * sizeof(uint8_t));

	for (uint8_t *p_sorted = sorted; (p_sorted - sorted) < length; ++p_sorted)
		for (uint8_t *p_vector = vector; (p_vector - vector) < length; ++p_vector)
			if (*p_vector == *p_sorted && !checked[p_vector - vector]) {
				indexed[p_sorted - sorted] = p_vector - vector;
				checked[p_vector - vector] = 1;
				break;
			}
}
